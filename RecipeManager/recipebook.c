// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for the linked list of recipees
#define _CRT_SECURE_NO_WARNINGS
#include "recipebook.h"
#include "recipe.h"
#include <stdio.h>
#include <stdlib.h>

const char* mealTypes[] = { "BREAK", "LUNCH", "DIN", "APPS", "DESS" };

bool AddRecipeToBook(PRECIPEBOOK* Book, RECIPE Recipe) {
	PRECIPEBOOK newBookEntry = (PRECIPEBOOK)malloc(sizeof(PRECIPEBOOK));
	if (newBookEntry == NULL) {
		fprintf(stderr, "Error, failed to allocate memory for recipe entry in book\n");
		exit(EXIT_FAILURE);
	}
	newBookEntry->recipe = Recipe;
	newBookEntry->next = *Book;
	*Book = newBookEntry;

	return true;
}

bool RemoveRecipeFromBook(RECIPE Recipe, PRECIPEBOOK* Book) {
	PRECIPEBOOK current = *Book;
	if (current != NULL && CompareRecipes(current->recipe, Recipe)) {
		*Book = current->next;
		free(current);
		return true;
	}
	PRECIPEBOOK prev = NULL;
	while (current != NULL && !CompareRecipes(current->recipe, Recipe)) {
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return false;
	else {
		prev->next = current->next;
		free(current);
		return true;
	}
}

void DisplayRecipebook(PRECIPEBOOK Book) {

}

void DestroyRecipeBook(PRECIPEBOOK* Book) {

}

// Loads the data from a file
void load_data(PRECIPEBOOK* head) {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';

        // Read recipe name
        RECIPE newRecipe;
        strcpy(newRecipe.recipeName, line);

        // Read meal type
        fgets(line, sizeof(line), file);
        line[strcspn(line, "\n")] = '\0';
        if (strncmp(line, "MealType: ", 10) == 0) {
            char* mealTypeStr = line + 10;
            newRecipe.mealType = BREAK; // Default value
            for (int i = 0; i < sizeof(mealTypes) / sizeof(mealTypes[0]); i++) {
                if (strcmp(mealTypeStr, mealTypes[i]) == 0) {
                    newRecipe.mealType = (MEALTYPE)i;
                    break;
                }
            }
        }

        // Read ingredients
        fgets(line, sizeof(line), file);
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "Ingredients:") == 0) {
            int ingredientIndex = 0;
            while (fgets(line, sizeof(line), file) && strncmp(line, "Instructions:", 12) != 0) {
                line[strcspn(line, "\n")] = '\0'; // Remove trailing newline
                strcpy(newRecipe.ingredients[ingredientIndex++], line);
            }
        }

        // Read instructions
        if (strncmp(line, "Instructions:", 12) == 0) {
            int instructionIndex = 0;
            while (fgets(line, sizeof(line), file)) {
                line[strcspn(line, "\n")] = '\0'; // Remove trailing newline

                // Parse "Step X: " from the instruction line
                if (strncmp(line, "Step ", 5) == 0) {
                    char* instruction = strchr(line, ':');
                    if (instruction) {
                        instruction++; // Move past ": "
                        while (*instruction == ' ') instruction++; // Skip leading spaces
                        strcpy(newRecipe.instructions[instructionIndex++], instruction);
                    }
                }
            }
        }

        // Create a new linked list node
        PRECIPEBOOK newNode = (PRECIPEBOOK)malloc(sizeof(RECIPEBOOK));
        newNode->recipe = newRecipe;
        newNode->next = NULL;

        // Add to linked list
        if (*head == NULL) {
            *head = newNode;
        }
        else {
            PRECIPEBOOK temp = *head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    fclose(file);
}



// Saves the data to a file
void save_data(PRECIPEBOOK head) {
    FILE* file = fopen(FILENAME, "w");
    if (!file) {
        perror("Error saving data");
        return;
    }

    PRECIPEBOOK temp = head;
    while (temp) {
        RECIPE recipe = temp->recipe;

        // Write recipe name and meal type on separate lines
        fprintf(file, "%s\n", recipe.recipeName);
        fprintf(file, "MealType: %s\n", mealTypes[recipe.mealType]);

        // Write ingredients with label
        fprintf(file, "Ingredients:\n");
        for (int i = 0; i < MAX_LINES && recipe.ingredients[i][0] != '\0'; i++) {
            fprintf(file, "%s\n", recipe.ingredients[i]);
        }

        // Write instructions with label and numbered steps
        fprintf(file, "Instructions:\n");
        for (int i = 0; i < MAX_LINES && recipe.instructions[i][0] != '\0'; i++) {
            fprintf(file, "Step %d: %s\n", i + 1, recipe.instructions[i]);
        }

        temp = temp->next;
    }

    fclose(file);
}

void add_recipe(PRECIPEBOOK* head) {
    RECIPE newRecipe;

    // Ask for the recipe name
    printf("Enter the recipe name: ");
    fgets(newRecipe.recipeName, MAX_LENGTH, stdin);
    newRecipe.recipeName[strcspn(newRecipe.recipeName, "\n")] = '\0';  // Remove trailing newline

    // Ask for the meal type
    printf("Enter the meal type (0 - BREAK, 1 - LUNCH, 2 - DIN, 3 - APPS, 4 - DESS): ");
    int mealChoice;
    scanf("%d", &mealChoice);
    while (mealChoice < 0 || mealChoice > 4) {
        printf("Invalid choice. Enter the meal type (0 - BREAK, 1 - LUNCH, 2 - DIN, 3 - APPS, 4 - DESS): ");
        scanf("%d", &mealChoice);
    }
    newRecipe.mealType = (MEALTYPE)mealChoice;

    // Clear input buffer
    while (getchar() != '\n');  // To clear the leftover '\n' character in the input buffer

    // Ask for ingredients
    printf("Enter ingredients (type 'done' to finish):\n");
    int ingredientIndex = 0;
    while (ingredientIndex < MAX_LINES) {
        printf("Ingredient %d: ", ingredientIndex + 1);
        fgets(newRecipe.ingredients[ingredientIndex], MAX_LENGTH, stdin);
        newRecipe.ingredients[ingredientIndex][strcspn(newRecipe.ingredients[ingredientIndex], "\n")] = '\0'; // Remove newline
        if (strcmp(newRecipe.ingredients[ingredientIndex], "done") == 0) {
            break;
        }
        ingredientIndex++;
    }

    // Ask for instructions
    printf("Enter instructions (type 'done' to finish):\n");
    int instructionIndex = 0;
    while (instructionIndex < MAX_LINES) {
        printf("Step %d: ", instructionIndex + 1);
        fgets(newRecipe.instructions[instructionIndex], MAX_LENGTH, stdin);
        newRecipe.instructions[instructionIndex][strcspn(newRecipe.instructions[instructionIndex], "\n")] = '\0'; // Remove newline
        if (strcmp(newRecipe.instructions[instructionIndex], "done") == 0) {
            break;
        }
        instructionIndex++;
    }

    // Create a new node and add it to the linked list
    PRECIPEBOOK newNode = (PRECIPEBOOK)malloc(sizeof(RECIPEBOOK));
    newNode->recipe = newRecipe;
    newNode->next = *head;
    *head = newNode;  // Add the new node at the beginning of the list
}

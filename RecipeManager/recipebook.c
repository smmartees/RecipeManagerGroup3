// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for the linked list of recipees
#define _CRT_SECURE_NO_WARNINGS
#include "recipebook.h"

#include "recipe.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

const char* mealTypeStrings[] = { "BREAK", "LUNCH", "DIN", "APPS", "DESS" };
typedef char* PSTRING;
//
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
//
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
//
void DisplayRecipebook(PRECIPEBOOK Book) {
	printf("Recipe Book:\n");
	
	PRECIPEBOOK temp = Book;
	int recipeNum = 1;
	while (temp != NULL) {
		printf("%d) ", recipeNum);
		printf("%s\n", temp->recipe.recipeName);
		recipeNum++;
		temp = temp->next;
	}
}
//
bool DisplayRecipesByType(PRECIPEBOOK Book, MEALTYPE Type, char* MealType) {
	PRECIPEBOOK temp = Book;
	if (temp == NULL) {
		fprintf(stderr, "The recipe book is empty\n");
		return false;
	}

	int recipeNum = 1;
	printf("Recipes in the %s category: \n", MealType);
	while (temp != NULL) {
		if (temp->recipe.mealType == Type) {
			printf("%d) %s\n", recipeNum, temp->recipe.recipeName);
			recipeNum++;
		}
		temp = temp->next;
	}
	return true;
}
//
bool DisplayRecipeByName(PRECIPEBOOK Book, char* Name) {
	PRECIPEBOOK temp = Book;
	if (temp == NULL) {
		fprintf(stderr, "The recipe book is empty\n");
		return false;
	}
	while (temp != NULL) {
		if (temp->recipe.recipeName == Name) {
			DisplayWholeRecipe(temp->recipe);
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool DisplayRecipeByDisplayNumberFromBook(PRECIPEBOOK Book, int DisplayNumber) {
	PRECIPEBOOK temp = Book;
	int recipeNum = 1;
	while (temp != NULL && recipeNum <= DisplayNumber) {
		if (DisplayNumber == recipeNum) {
			DisplayWholeRecipe(temp->recipe);
			return true;
		}
		temp = temp->next;
		recipeNum++;
	}
	if (temp == NULL) {
		printf("Could not find the recipe,\n");
		return false;
	}
	return false;
}

bool DisplayRecipeByDisplayNumberFromMealType(PRECIPEBOOK Book, int DisplayNumber, MEALTYPE MealType) {
	PRECIPEBOOK temp = Book;
	if (temp == NULL) {
		fprintf(stderr, "Could not find recipe\n");
		return false;
	}

	int recipeNum = 1;
	while (temp != NULL) {
		if (temp->recipe.mealType == MealType) {
			if (recipeNum == DisplayNumber) {
				DisplayWholeRecipe(temp->recipe);
				return true;
			}
			recipeNum++;
		}
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Could not find recipe\n");
		return false;
	}
	return false;
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
		line[strcspn(line, "\n")] = '\0'; // Remove trailing newline

		// Initialize a new recipe
		RECIPE newRecipe = { 0 };
		newRecipe.ingredients = malloc(MAX_LINES * sizeof(PSTRING));
		newRecipe.instructions = malloc(MAX_LINES * sizeof(PSTRING));
		for (int i = 0; i < MAX_LINES; i++) {
			newRecipe.ingredients[i] = NULL;
			newRecipe.instructions[i] = NULL;
		}

		// Read recipe name
		strcpy(newRecipe.recipeName, line);

		// Read meal type
		fgets(line, sizeof(line), file);
		line[strcspn(line, "\n")] = '\0';
		if (strncmp(line, "MealType: ", 10) == 0) {
			char* mealTypeStr = line + 10;
			for (int i = 0; i < 5; i++) {
				if (strcmp(mealTypeStr, mealTypeStrings[i]) == 0) {
					newRecipe.mealType = (MEALTYPE)i;
					break;
				}
			}
		}

		// Read ingredients
		fgets(line, sizeof(line), file);
		line[strcspn(line, "\n")] = '\0';
		int ingredientIndex = 0;
		if (strcmp(line, "Ingredients:") == 0) {
			while (fgets(line, sizeof(line), file) && strncmp(line, "Instructions:", 12) != 0) {
				line[strcspn(line, "\n")] = '\0'; // Remove trailing newline
				newRecipe.ingredients[ingredientIndex] = malloc(strlen(line) + 1);
				strcpy(newRecipe.ingredients[ingredientIndex], line);
				ingredientIndex++;
			}
		}

		// Read instructions
		int instructionIndex = 0;
		if (strncmp(line, "Instructions:", 12) == 0) {
			while (fgets(line, sizeof(line), file)) {
				line[strcspn(line, "\n")] = '\0'; // Remove trailing newline
				if (strncmp(line, "Step ", 5) == 0) {
					char* instruction = strchr(line, ':');
					if (instruction) {
						instruction++; // Move past ": "
						while (*instruction == ' ') instruction++; // Skip leading spaces
						newRecipe.instructions[instructionIndex] = malloc(strlen(instruction) + 1);
						strcpy(newRecipe.instructions[instructionIndex], instruction);
						instructionIndex++;
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

        // Write recipe name
        fprintf(file, "%s\n", recipe.recipeName);

        // Write meal type
        fprintf(file, "MealType: %s\n", mealTypeStrings[recipe.mealType]);

        // Write ingredients
        fprintf(file, "Ingredients:\n");
        for (int i = 0; i < MAX_LINES && recipe.ingredients[i] != NULL; i++) {
            fprintf(file, "%s\n", recipe.ingredients[i]);
        }

        // Write instructions
        fprintf(file, "Instructions:\n");
        for (int i = 0; i < MAX_LINES && recipe.instructions[i] != NULL; i++) {
            fprintf(file, "Step %d: %s\n", i + 1, recipe.instructions[i]);
        }

        temp = temp->next;
    }

    fclose(file);
}



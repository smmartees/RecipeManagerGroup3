// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for the linked list of recipees
#define _CRT_SECURE_NO_WARNINGS
#include "recipebook.h"

#include "recipe.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>


const char* mealTypeStrings[] = { "BREAK", "LUNCH", "DIN", "APPS", "DESS" };

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
//range
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
//
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

bool UpdateRecipeName(PRECIPEBOOK* Book, char* OldName, char* NewName) {
	PRECIPEBOOK temp = *Book;
	if (temp == NULL) {
		fprintf(stderr, "The recipe book is empty\n");
		return false;
	}
	while (temp != NULL) {
		if (temp->recipe.recipeName == OldName) {
			ChangeRecipeName(&temp->recipe.recipeName, NewName);
			return true;
		}
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Could not find that recipe\n");
		return false;
	}
	return false;
}

bool UpdateRecipeMealType(PRECIPEBOOK* Book, char* Name, MEALTYPE MealType) {
	PRECIPEBOOK temp = *Book;
	if (temp == NULL) {
		fprintf(stderr, "The recipe book is empty\n");
		return false;
	}
	while (temp != NULL) {
		if (temp->recipe.recipeName == Name) {
			ChangeMealType(&temp->recipe.mealType, MealType);
			return true;
		}
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Could not find that recipe\n");
		return false;
	}
	return false;
}

void DestroyRecipeBook(PRECIPEBOOK* Book) {

}

// Loads the data from a file
void load_data(PRECIPEBOOK* head) {
	FILE* file = fopen(FILENAME, "r");
	if (file == NULL) {
		perror("Error opening file");
		return;
	}

	char line[MAX_LENGTH];
	PRECIPEBOOK* current = head;

	while (fgets(line, sizeof(line), file)) {
		// Remove trailing newline
		line[strcspn(line, "\n")] = '\0';

		// Allocate memory for a new recipe node
		PRECIPEBOOK newRecipe = (PRECIPEBOOK)malloc(sizeof(RECIPEBOOK));
		if (!newRecipe) {
			perror("Memory allocation failed");
			fclose(file);
			return;
		}
		newRecipe->next = NULL;

		// Read recipe name and meal type
		char mealTypeStr[MAX_LENGTH];
		sscanf(line, "%s %s", newRecipe->recipe.recipeName, mealTypeStr);

		// Parse meal type
		newRecipe->recipe.mealType = OTHER; // Default value
		for (int i = 0; i < sizeof(mealTypeStrings) / sizeof(mealTypeStrings[0]); i++) {
			if (strcmp(mealTypeStr, mealTypeStrings[i]) == 0) {
				newRecipe->recipe.mealType = (MEALTYPE)i;
				break;
			}
		}

		// Initialize ingredients and instructions
		newRecipe->recipe.ingredients = NULL;
		newRecipe->recipe.instructions = NULL;

		// Read ingredients
		fgets(line, sizeof(line), file); // "Ingredients:"
		PSTRING* ingredientTail = &newRecipe->recipe.ingredients;
		while (fgets(line, sizeof(line), file) && strcmp(line, "Instructions:\n") != 0) {
			line[strcspn(line, "\n")] = '\0';
			PSTRING newIngredient = (PSTRING)malloc(sizeof(STRING));
			strcpy(newIngredient->line, line);
			newIngredient->next = NULL;
			*ingredientTail = newIngredient;
			ingredientTail = &newIngredient->next;
		}

		// Read instructions
		PSTRING* instructionTail = &newRecipe->recipe.instructions;
		while (fgets(line, sizeof(line), file) && strcmp(line, "---\n") != 0) {
			line[strcspn(line, "\n")] = '\0';
			PSTRING newInstruction = (PSTRING)malloc(sizeof(STRING));
			strcpy(newInstruction->line, line);
			newInstruction->next = NULL;
			*instructionTail = newInstruction;
			instructionTail = &newInstruction->next;
		}

		// Add the new recipe to the linked list
		*current = newRecipe;
		current = &newRecipe->next;
	}

	fclose(file);
}



// Saves the data to a file
void save_data(PRECIPEBOOK head) {
	FILE* file = fopen(FILENAME, "w");
	if (file == NULL) {
		perror("Error saving data");
		return;
	}

	PRECIPEBOOK temp = head;
	while (temp) {
		// Write the recipe name and meal type
		fprintf(file, "%s %s\n", temp->recipe.recipeName, mealTypeStrings[temp->recipe.mealType]);

		// Write the ingredients
		fprintf(file, "Ingredients:\n");
		PSTRING ingredient = temp->recipe.ingredients;
		while (ingredient) {
			fprintf(file, "%s\n", ingredient->line);
			ingredient = ingredient->next;
		}

		// Write the instructions
		fprintf(file, "Instructions:\n");
		PSTRING instruction = temp->recipe.instructions;
		while (instruction) {
			fprintf(file, "%s\n", instruction->line);
			instruction = instruction->next;
		}

		fprintf(file, "---\n"); // Separator for recipes
		temp = temp->next;
	}

	fclose(file);
}


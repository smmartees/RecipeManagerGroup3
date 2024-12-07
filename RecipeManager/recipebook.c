// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for the linked list of recipees
#define _CRT_SECURE_NO_WARNINGS
#include "recipebook.h"

#include "recipe.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//const char* mealTypeStrings[] = { "BREAK", "LUNCH", "DIN", "APPS", "DESS" };

bool AddRecipeToBook(PRECIPEBOOK* Book, RECIPE Recipe) {
	PRECIPEBOOK newBookEntry = (PRECIPEBOOK)malloc(sizeof(RECIPEBOOK));
	if (newBookEntry == NULL) {
		fprintf(stderr, "Error, failed to allocate memory for recipe entry in book\n");
		exit(EXIT_FAILURE);
	}
	//strncpy(newBookEntry->recipe.recipeName, Recipe.recipeName, MAX_LENGTH);
	newBookEntry->recipe = Recipe;
	newBookEntry->next = *Book;
	*Book = newBookEntry;

	//printf("%s", newBookEntry->recipe.recipeName);

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

bool UpdateRecipeIngredients(PRECIPEBOOK* Book, char* RecipeName, char* NewLine, int LineNum) {
	PRECIPEBOOK temp = *Book;
	if (temp == NULL) {
		fprintf(stderr, "The recipe book is empty\n");
		return false;
	}
	while (temp != NULL) {
		if (temp->recipe.recipeName == RecipeName) {
			UpdateLine(temp->recipe.ingredients, LineNum, NewLine);
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

bool UpdateRecipeInstructions(PRECIPEBOOK* Book, char* RecipeName, char* NewLine, int LineNum) {
	PRECIPEBOOK temp = *Book;
	if (temp == NULL) {
		fprintf(stderr, "The recipe book is empty\n");
		return false;
	}
	while (temp != NULL) {
		if (temp->recipe.recipeName == RecipeName) {
			UpdateLine(temp->recipe.instructions, LineNum, NewLine);
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




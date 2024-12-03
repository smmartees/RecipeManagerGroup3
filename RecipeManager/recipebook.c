// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for the linked list of recipees

#include "recipebook.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

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
	}
}

bool DisplayRecipesByType(PRECIPEBOOK Book, MEALTYPE Type, char* MealType) {
	PRECIPEBOOK temp = Book;
	if (temp == NULL) {
		fprintf(stderr, "The recipe book is empty\n");
		return false;
	}

	int recipeNum = 1;
	printf("Recipes in the %s category: \n", MealType);
	while (temp != NULL) {
		if (temp->recipe.type == Type) {
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
		if (temp->recipe.type == MealType) {
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
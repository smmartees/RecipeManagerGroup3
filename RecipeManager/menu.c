#define _CRT_SECURE_NO_WARNINGS


#include "menu.h"
#include "globals.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void displayRangeOfRecipe(PRECIPEBOOK Book, RECIPE newRecipe) {

	int mealTypeInput = 0;
	int userInput = 0;
//	char buffer[MAX_LENGTH];

	char* MealType;
	bool result = false;

	printf("1 - BREAK,2 - LUNCH,3 - DIN,4 - APPS,5 - DESS,6 - OTHER");
	printf_s("Enter meal type to display a recipe from Meal Type:\n");
	scanf("%d", &mealTypeInput);
	if (mealTypeInput < 0 || mealTypeInput > 6)
	{
		fprintf(stderr, "Invalid number entered.\n");
		exit(EXIT_FAILURE);
	}
	//switch
	switch (mealTypeInput)
	{
	case 1:

		Book->recipe.mealType = BREAK;
		MealType = "BREAK";
		break;
	case 2:
		Book->recipe.mealType = LUNCH;
		MealType = "LUNCH";
		break;
	case 3:
		Book->recipe.mealType = DIN;
		MealType = "DIN";
		break;
	case 4:
		Book->recipe.mealType = APPS;
		MealType = "APPS";
		break;
	case 5:
		Book->recipe.mealType = DESS;
		MealType = "DESS";
		break;
	case 6:
		Book->recipe.mealType = OTHER;
		MealType = "OTHER";
		break;
	default:
		Book->recipe.mealType = OTHER;
		MealType = "OTHER";
		break;
	}
	if (Book == NULL) {
		printf("Book is empty.\n");
	}
	else
	{
		DisplayRecipesByType(Book, Book->recipe.mealType, MealType);
		printf("Enter the number to display recipe (enter 0 to go back to main menu): ");
		scanf("%d", &userInput);
		if (userInput == 0) {
			return;
		}
		if (userInput > 0) {
			DisplayRecipeByDisplayNumberFromMealType(Book, userInput, Book->recipe.mealType);
		}
	}
	
	
	//DisplayRecipeByDisplayNumberFromMealType(PRECIPEBOOK Book, int DisplayNumber, MEALTYPE MealType)
	
	//DisplayRecipesByType( Book, MEALTYPE Type, char* MealType)

}


int PrintMenu() {
	printf_s("************************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**    Recipe Book     **\n");
	printf_s("************************\n");


	printf_s("1. Add a new recipe\n");
	printf_s("2. Delete an existing recipes\n");
	printf_s("3. Display a recipe by name\n");
	printf_s("4. Display range of recipes\n");
	printf_s("5. Display all recipes\n");
	printf_s("6. Search for a recipe\n");
	printf_s("0. Exit Program\n");
}



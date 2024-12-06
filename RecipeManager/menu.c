#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include "globals.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void displayRangeOfRecipe(PRECIPEBOOK Book) {

	int mealTypeInput = 0;
	int userInput = 0;
	char buffer[MAX_LENGTH];

	RECIPE newRecipe = CreateRecipe(buffer);
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
		newRecipe.mealType = BREAK;
		MealType = "BREAK";
		break;
	case 2:
		newRecipe.mealType = LUNCH;
		MealType = "LUNCH";
		break;
	case 3:
		newRecipe.mealType = DIN;
		MealType = "DIN";
		break;
	case 4:
		newRecipe.mealType = APPS;
		MealType = "APPS";
		break;
	case 5:
		newRecipe.mealType = DESS;
		MealType = "DESS";
		break;
	case 6:
		newRecipe.mealType = OTHER;
		MealType = "OTHER";
		break;
	default:
		newRecipe.mealType = OTHER;
		MealType = "OTHER";
		break;
	}
	DisplayRecipesByType(Book, newRecipe.mealType, MealType);
	printf("Enter the number to display recipe (enter 0 to go back to main menu): ");
	scanf("%d", &userInput);
	if (userInput == 0) {
		return;
	}
	if (userInput > 0) {
		DisplayRecipeByDisplayNumberFromMealType(Book, userInput, newRecipe.mealType);
	}
	
	//DisplayRecipeByDisplayNumberFromMealType(PRECIPEBOOK Book, int DisplayNumber, MEALTYPE MealType)
	
	//DisplayRecipesByType( Book, MEALTYPE Type, char* MealType)

}
#include <stdio.h>

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


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "utils.h"
#include "menu.h"
#include <stdlib.h>


bool updateRecipeMenu(PRECIPEBOOK* Book, char* RecipeName) {
	DisplayRecipeByName(*Book, RecipeName);

	printf("\nWhat would you like to update: \n");
	printf("0. Back\n");
	printf("1. Recipe Name\n");
	printf("2. Ingredients\n");
	printf("3. Instructions\n");
	int selection;
	scanf("%d", &selection);

	switch (selection)
	{
	case 0:
		return true;
	case 1:
		printf("\n");
		char* prompt = "Enter new recipe name";
		char newName[MAX_LENGTH];
		getInput(prompt, newName);

		UpdateRecipeName(&Book, RecipeName, newName);
		return true;
	case 2:
		printf("Which line number: ");

	default:
		break;
	}

}

bool displayRangeOfRecipe(PRECIPEBOOK Book, RECIPE newRecipe) {

	int mealTypeInput = 0;
	int userInput = 0;
//	char buffer[MAX_LENGTH];

	char* MealType;
	bool result = false;

	printf_s("Select meal type to display a recipe from Meal Type:\n");
	printf("1. Breakfast\n");
	printf("2. Lunch\n");
	printf("3. Dinner\n");
	printf("4. Appetizer\n");
	printf("5. Dessert\n");
	printf("6. Other\n");

	scanf("%d", &mealTypeInput);
	if (mealTypeInput < 0 || mealTypeInput > 6)
	{
		fprintf(stderr, "Invalid number entered.\n");
		return true;
	}
		switch (mealTypeInput)
		{
		case 1:			
			MealType = "Breakfast";
			DisplayRecipesByType(Book, BREAK, MealType);
			printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
			scanf("%d", &userInput);
			if (userInput == 0) {
				return true;
			}
			else 
				return DisplayRecipeByDisplayNumberFromMealType(Book, userInput, BREAK);
			
		case 2:
			MealType = "Lunch";
			DisplayRecipesByType(Book, LUNCH, MealType);
			printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
			scanf("%d", &userInput);
			if (userInput == 0) {
				return true;
			}
			else
			return DisplayRecipeByDisplayNumberFromMealType(Book, userInput, LUNCH);
		case 3:
			
			MealType = "Dinner";
			DisplayRecipesByType(Book,DIN, MealType);
			printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
			scanf("%d", &userInput);
			if (userInput == 0) {
				return true;
			}
			else
				return DisplayRecipeByDisplayNumberFromMealType(Book, userInput, DIN);
		case 4:
			
			MealType = "Appetizer";

			DisplayRecipesByType(Book, APPS, MealType);
			printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
			scanf("%d", &userInput);
			if (userInput == 0) {
				return true;
			}
			else
				return DisplayRecipeByDisplayNumberFromMealType(Book, userInput, APPS);
		case 5:
			
			MealType = "Dessert";

			DisplayRecipesByType(Book,DESS, MealType);
			printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
			scanf("%d", &userInput);
			if (userInput == 0) {
				return true;
			}
			else
				return DisplayRecipeByDisplayNumberFromMealType(Book, userInput, DESS);
		case 6:
			
			MealType = "Other";

			DisplayRecipesByType(Book,OTHER, MealType);
			printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
			scanf("%d", &userInput);
			if (userInput == 0) {
				return true;
			}
			else
				return DisplayRecipeByDisplayNumberFromMealType(Book, userInput, OTHER);
		default:
			MealType = "Other";

			DisplayRecipesByType(Book, OTHER, MealType);
			printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
			scanf("%d", &userInput);
			if (userInput == 0) {
				return true;
			}
			else
				return DisplayRecipeByDisplayNumberFromMealType(Book, userInput, OTHER);
		}
	

	//DisplayRecipeByDisplayNumberFromMealType(PRECIPEBOOK Book, int DisplayNumber, MEALTYPE MealType)
	
	//DisplayRecipesByType( Book, MEALTYPE Type, char* MealType)

}
bool searchRecipeByNameMenu(PRECIPEBOOK Book, RECIPE newRecipe) {
	char* userInputName = NULL;

	printf_s("Enter the name of the recipe to display:\n");
	scanf("%s",userInputName);

	if (!DisplayRecipeByName(Book, userInputName))
	{
		printf("Recipe Name entered is not found");
		return true;
	}
	else {
		printf("Search recipe by name successful");
		return true;
	}

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
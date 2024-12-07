#define _CRT_SECURE_NO_WARNINGS


#include "menu.h"
#include "globals.h"
#include "utils.h"
#include "recipebook.h"
#include "ingrestruction.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool updateRecipeMenu(PRECIPEBOOK* Book, char* RecipeName) {
	DisplayRecipeByName(*Book, RecipeName);

	printf("\nWhat would you like to update: \n");
	printf("0. Back\n");
	printf("1. Recipe Name\n");
	printf("2. Ingredients\n");
	printf("3. Instructions\n");
	printf("4. Meal Type\n");
	int selection;
	scanf("%d", &selection);

	char prompt[MAX_LENGTH];

	switch (selection)
	{
	case 0:
		return true;
	case 1:	//case to change recipe name
		printf("\n");
		*prompt = "Enter new recipe name";
		char newName[MAX_LENGTH];
		getInput(prompt, newName);

		return UpdateRecipeName(&Book, RecipeName, newName);
	case 2:	//case to change ingredients by line
		printf("Enter line number to rewrite: ");
		int ingredientLineNum;
		scanf("%d", &ingredientLineNum);
		*prompt = "Enter new line";
		char newLine[MAX_LENGTH];
		getInput(prompt, newLine);
		return UpdateRecipeIngredients(Book, RecipeName, newLine, ingredientLineNum);
	case 3:
		printf("Enter line number to rewrite: ");
		int instructionLineNum;
		scanf("%d", &instructionLineNum);
		*prompt = "Enter new line";
		char newInstLine[MAX_LENGTH];
		getInput(prompt, newInstLine);
		return UpdateRecipeInstructions(Book, RecipeName, newInstLine, instructionLineNum);
	case 4:
		printf("Select number of new meal type: \n");
		printf("0. Return\n");
		printf("1. Breakfast\n");
		printf("2. Lunch\n");
		printf("3. Dinner\n");
		printf("4. Appetizer\n");
		printf("5. Dessert\n");
		printf("6. Other\n");
		int mealTypeSelection;
		scanf("%d", &mealTypeSelection);
		switch (mealTypeSelection)
		{
		case 0: return true;
		case 1:
			return UpdateRecipeMealType(&Book, RecipeName, BREAK);
		case 2:
			return UpdateRecipeMealType(&Book, RecipeName, LUNCH);
		case 3:
			return UpdateRecipeMealType(&Book, RecipeName, DIN);
		case 4:
			return UpdateRecipeMealType(&Book, RecipeName, APPS);
		case 5:
			return UpdateRecipeMealType(&Book, RecipeName, DESS);
		case 6:
			return UpdateRecipeMealType(&Book, RecipeName, OTHER);
		default:
			printf("Invalid input.\n");
			return false;
		}
	default:
		printf("Invalid input.\n");
		return false;
	}

}

void displayRangeOfRecipe(PRECIPEBOOK Book) {

	int mealTypeInput = 0;
	int userInput = 0;
//	char buffer[MAX_LENGTH];

	char MealType[MAX_LENGTH];
	bool result = false;

	printf("0. Return\n");
	printf("1. Breakfast\n");
	printf("2. Lunch\n");
	printf("3. Dinner\n");
	printf("4. Appetizer\n");
	printf("5. Dessert\n");
	printf("6. Other\n");
	printf_s("Select meal type number to display: \n");
	scanf("%d", &mealTypeInput);
	/*if (mealTypeInput < 0 || mealTypeInput > 6)
	{
		fprintf(stderr, "Invalid number entered.\n");
		exit(EXIT_FAILURE);
	}*/
	//switch
	MealType[MAX_LENGTH];
	switch (mealTypeInput)
	{
	case 1:
		*MealType = "Breakfast";
		DisplayRecipesByType(Book, BREAK, MealType);
		break;
	case 2:
		*MealType = "Lunch";
		DisplayRecipesByType(Book, LUNCH, MealType);
		break;
	case 3:
		*MealType = "Dinner";
		DisplayRecipesByType(Book, DIN, MealType);
		break;
	case 4:
		*MealType = "Appetizers";
		DisplayRecipesByType(Book, APPS, MealType);
		break;
	case 5:
		*MealType = "Dessert";
		DisplayRecipesByType(Book, DESS, MealType);
		break;
	case 6:
		*MealType = "Other";
		DisplayRecipesByType(Book, OTHER, MealType);
		break;
	default:
		printf("Invalid input\n");
		break;
	}
	/*if (Book == NULL) {
		printf("Book is empty.\n");
	}
	else
	{
		DisplayRecipesByType(Book, , MealType);
		printf("Enter the number to select recipe (enter 0 to go back to main menu): ");
		scanf("%d", &userInput);
		if (userInput == 0) {
			return;
		}
		if (userInput > 0) {
			DisplayRecipeByDisplayNumberFromMealType(Book, userInput, Book->recipe.mealType);
		}*/
}
	
	
	//DisplayRecipeByDisplayNumberFromMealType(PRECIPEBOOK Book, int DisplayNumber, MEALTYPE MealType)
	
	//DisplayRecipesByType( Book, MEALTYPE Type, char* MealType)


void searchRecipeByNameMenu(PRECIPEBOOK Book, RECIPE newRecipe) {
	char* userInputName;

	printf_s("Enter the name of the recipe to display:\n");
	scanf("%s",&userInputName);

	if (!DisplayRecipeByName(Book, userInputName))
	{
		printf("Recipe Name entered is not found");
		return;
	}
	else {
		printf("Search recipe by name successful");
	}

}



int PrintMenu() {
	printf_s("************************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**    Recipe Book     **\n");
	printf_s("************************\n\n");


	printf_s("1. Add a new recipe\n");
	printf_s("2. Delete an existing recipes\n");
	printf_s("3. Display a recipe by name\n");
	printf_s("4. Display range of recipes\n");
	printf_s("5. Display all recipes\n");
	printf_s("6. Search for a recipe\n");
	printf_s("0. Exit Program\n");
}
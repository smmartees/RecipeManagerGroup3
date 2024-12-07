#define _CRT_SECURE_NO_WARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha

// 11. you may add additional features, increasing your group’s overall
// mark to a maximum of 100 % .
#include "globals.h"
#include "utils.h"
#include "recipe.h"
#include "recipebook.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() 
{
	//RECIPE test;
	//MEALTYPE type = 0;
	/*char tests = "\0";
	int N = 0;*/
	
	PRECIPEBOOK recipeBook = load_data();

	//load_data(&recipeBook);
	//printf("%s\n", recipeBook->recipe.recipeName);

	DisplayWholeRecipe(recipeBook->recipe);

	char recipeName[MAX_LENGTH];
	char* prompt = "enter recipe name";

	getInput(prompt, recipeName);
	CleanNewLineFromString(recipeName);

	RECIPE newRecipe = CreateRecipe(recipeName);

	AddRecipeToBook(&recipeBook, newRecipe);

	prompt = "enter ingredients";
	char buf[MAX_LENGTH];
	while (getLoopedInput(prompt, buf)) {
		CleanNewLineFromString(buf);
		AddLine(&recipeBook->recipe.ingredients, buf);
	}
	
	prompt = "enter instructions";
	while (getLoopedInput(prompt, buf)) {
		CleanNewLineFromString(buf);
		AddLine(&recipeBook->recipe.instructions, buf);
	}

	DisplayWholeRecipe(recipeBook->recipe);

	save_data(recipeBook);


	/*bool AddrecipeResult = false;
	bool deleterecipeResult = false;
	bool displayrecipeResult = false;*/

	//RECIPE newRecipe = {0};
	//char newRecipeName[MAX_LENGTH] = {0};
	//char recipeToDelete[MAX_LENGTH] = {0};
	
	//load_data(&recipeBook);
	//clear_input_buffer();

	//bool ProgramLoop = true;
	//while (ProgramLoop) {
	//	clear_input_buffer();

	//	int Choice;
	//	PrintMenu();
	//	printf_s("Choose a function: ");
	//	//scanf_s("%1o", &Choice);
	//	scanf("%d", &Choice);
	//	//char prompt[MAX_LENGTH];

	//	switch (Choice)
	//	{
	//	case 1:

	//		AddRecipeUI(&recipeBook);
	//		printf("\n**** %s ****\n", recipeBook->recipe.recipeName);
	//		break;

	//	case 2:
	//		//printf("Enter the name of the recipe to delete: ");
	//		//scanf("%s", recipeToDelete);

	//		//// Search for the recipe and delete it
	//		//RECIPE tempRecipe = CreateRecipe(recipeToDelete); // Creating a temp recipe with the name to compare

	//		// deleterecipeResult = RemoveRecipeFromBook(tempRecipe, &recipeList);
	//		// if (deleterecipeResult == true) {
	//		//	 printf("The recipe '%s' was successfully deleted from the recipe book.\n", recipeToDelete);
	//		// }
	//		// else {
	//		//	 printf("Could not find the recipe '%s' in the recipe book.\n", recipeToDelete);
	//		// }
	//		/*printf("");
	//		char buff[MAX_LENGTH];
	//		getInput("getInput was called", buff);
	//		printf("%s", buff);*/

	//		DeleteRecipeUI(&recipeBook);
	//		break;
	//	case 3:

	//		printf("\n");
	//		char* prompt = "Enter the name of the recipe you want to update";
	//		char recName[MAX_LENGTH];
	//		getInput(prompt, recName);
	//		
	//		bool updateRec = false;
	//		while(!updateRec)
	//			updateRec = updateRecipeMenu(&recipeBook, recName);
	//		break;

	//		//printf("Enter the name of the recipe to display: ");
	//		//scanf("%s", newRecipeName);  // Read the recipe name
	//		// displayrecipeResult = DisplayRecipeByName(recipeList, newRecipeName);

	//	case 4:
	//		displayRangeOfRecipe(recipeBook);
	//	//	DisplayRecipesByType(recipeList, type, tests);
	//		
	//		break;
	//	case 5:
	//		//DisplayRecipebookUI(recipeList);
	//		DisplayRecipebook(recipeBook);
	//		break;
	//	case 6:
	//		//searchRecipeByNameMenu(recipeBook, newRecipe);
	//		printf("");
	//		char* ask = "Enter the name of the recipe you are searching for";
	//		char name[MAX_LENGTH];
	//		getInput(ask, name);

	//		DisplayRecipeByName(recipeBook, name);
	//		
	//		break;
	//	case 0:
	//		save_data(recipeBook);
	//		ProgramLoop = false;
	//		break;
	//	default:
	//		clear_input_buffer();
	//		printf_s("Invalid option.\n");
	//		break;
	//	}
	//	
	//}


	return 0;
}



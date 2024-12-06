#define _CRT_SECURE_NO_WARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha

// 11. you may add additional features, increasing your group’s overall
// mark to a maximum of 100 % .
#define _CRT_SECURE_NO_WARNINGS
#include "recipe.h"
#include "recipebook.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() 
{
	RECIPE test;
	MEALTYPE type = 0;
	char tests = "\0";
	int N = 0;
	
	PRECIPEBOOK recipeList = NULL;
	bool AddrecipeResult = false;
	bool deleterecipeResult = false;
	bool displayrecipeResult = false;

	RECIPE newRecipe = {0};
	char newRecipeName[MAX_LENGTH] = {0};
	char recipeToDelete[MAX_LENGTH] = {0};
	load_data(&recipeList);
	
	bool ProgramLoop = true;
	while (ProgramLoop) {

		int Choice;
		PrintMenu();
		printf_s("Choose a function: ");
		scanf_s("%1o", &Choice);

		switch (Choice)
		{
		case 1:

			AddRecipeUI(recipeList);
			break;

		case 2:
			//printf("Enter the name of the recipe to delete: ");
			//scanf("%s", recipeToDelete);

			//// Search for the recipe and delete it
			//RECIPE tempRecipe = CreateRecipe(recipeToDelete); // Creating a temp recipe with the name to compare

			// deleterecipeResult = RemoveRecipeFromBook(tempRecipe, &recipeList);
			// if (deleterecipeResult == true) {
			//	 printf("The recipe '%s' was successfully deleted from the recipe book.\n", recipeToDelete);
			// }
			// else {
			//	 printf("Could not find the recipe '%s' in the recipe book.\n", recipeToDelete);
			// }
			DeleteRecipeUI(recipeList);
			break;
		case 3:
		
			printf("Enter the name of the recipe to display: ");
			scanf("%s", newRecipeName);  // Read the recipe name
			 displayrecipeResult = DisplayRecipeByName(recipeList, newRecipeName);

			if (!displayrecipeResult) {
				printf("The recipe '%s' was not found in the recipe book.\n", newRecipeName);
			}
			break;
		case 4:
			displayRangeOfRecipe(recipeList, newRecipe);
		//	DisplayRecipesByType(recipeList, type, tests);
			
			break;
		case 5:
			DisplayRecipebookUI(recipeList);
			break;
		case 6:
			searchRecipeByNameMenu(recipeList, newRecipe);
			break;
		case 0:
			save_data(recipeList);
			ProgramLoop = false;
			break;
		default:
			clear_input_buffer();
			printf_s("Invalid option.\n");
			break;
		}
		
	}
	return 0;
}



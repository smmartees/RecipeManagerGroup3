#define _CRT_SECURE_NO_WARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha


#include "globals.h"
#include "utils.h"
#include "recipe.h"
#include "recipebook.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 11. you may add additional features, increasing your group’s overall
// mark to a maximum of 100 % .

int main() 
{
	
	PRECIPEBOOK recipeBook = load_data();
	

	bool ProgramLoop = true;
	while (ProgramLoop) {
		clear_input_buffer();

		int Choice;
		PrintMenu();
		printf_s("Choose a function: ");
		//scanf_s("%1o", &Choice);
		scanf("%d", &Choice);
		//char prompt[MAX_LENGTH];

		switch (Choice)
		{
		case 1:

			AddRecipeUI(&recipeBook);
			break;

		case 2:

			DeleteRecipeUI(&recipeBook);
			break;

		case 3:

			printf("\n");
			char* prompt = "Enter the name of the recipe you want to update";
			char recName[MAX_LENGTH];
			getInput(prompt, recName);
			
			bool updateRec = false;
			while(!updateRec)
				updateRec = updateRecipeMenu(&recipeBook, recName);
			break;

		case 4:
			displayRangeOfRecipe(recipeBook);
		//	DisplayRecipesByType(recipeList, type, tests);
			
			break;
		case 5:
			//DisplayRecipebookUI(recipeList);
			DisplayRecipebook(recipeBook);
			break;
		case 6:
			//searchRecipeByNameMenu(recipeBook, newRecipe);
			printf("");
			char* ask = "Enter the name of the recipe you are searching for";
			char name[MAX_LENGTH];
			getInput(ask, name);

			DisplayRecipeByName(recipeBook, name);
			
			break;
		case 0:
			save_data(recipeBook);
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



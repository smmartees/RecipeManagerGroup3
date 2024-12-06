// Group 3: Recipe Manager - Sam, Johan, Ridha

// 11. you may add additional features, increasing your group’s overall
// mark to a maximum of 100 % .

#include "recipe.h"
#include "recipebook.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() 
{
	
	PRECIPEBOOK BOOK = NULL;
	RECIPE test;
	MEALTYPE type = 0;
	char tests = "\0";
	char i = "\0";
	int N = 0;

	load_data(&BOOK);
	
	bool ProgramLoop = true;
	while (ProgramLoop) {

		int Choice;
		PrintMenu();
		printf_s("Choose a function: ");
		scanf_s("%1o", &Choice);

		switch (Choice)
		{
		case 1:
			printf_s("Enter a name for the recipe:\n");

			printf_s("Enter the ingredients for the recipe:\n");

			printf_s("Enter the instructions for the recipe:\n");
			//change test and maybe BOOK when done
			AddRecipeToBook(&BOOK , test);
			break;
		case 2:
			printf_s("Enter the name of a recipe to delete it:\n");
			// user input fun here when its done
			RemoveRecipeFromBook(test, BOOK);

			break;
		case 3:
			printf_s("Enter the name of a recipe to display:\n");
			//change test when done
			DisplayRecipeByName(BOOK , tests);
			break;
		case 4:
			printf_s("Enter meal type to display a range of recipes:\n");
			//change test and maybe type when done
			DisplayRecipesByType(BOOK, type, tests);
			i = "T";
			break;
		case 5:
			printf_s("All the recipes are being displayed\n");
			DisplayRecipebook(BOOK);
			i = "B";
			break;
		case 6:
			printf_s("Enter the number of the recipe to display it:\n");

			if (i == "B")
			{
				//change N when done
				DisplayRecipeByDisplayNumberFromBook(BOOK, N);
			
			}
			else if (i == "T")
			{
				//change N and maybe type when done
				DisplayRecipeByDisplayNumberFromMealType(BOOK, N, type);
			}
			break;
		case 0:
			save_data(BOOK);
			ProgramLoop = false;
			break;
		default:
			clear_input_buffer();
			//system("cls");
			printf_s("Invalid option.\n");
			break;
		}
		
	}
	return 0;
}

int PrintMenu() {
	printf_s("************************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s("************************\n");


	printf_s("1. Add a new recipe\n");
	printf_s("2. Delete an existing recipes\n");
	printf_s("3. Display a recipe by name\n");
	printf_s("4. Display range of recipes\n");
	printf_s("5. Display all recipes\n");
	printf_s("6. Search for a recipe\n");
	printf_s("0. Exit Program\n");
}

void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
}

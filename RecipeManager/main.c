#define _CRT_SECURE_NO_WARNINGS

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

	PRECIPEBOOK recipeList = NULL;
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
			
			break;
		case 2:
			
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 0:
			save_data(recipeList);
			ProgramLoop = false;
			break;
		default:
			clear_input_buffer();
			system("cls");
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
	printf_s("3. Display a single recipe\n");
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

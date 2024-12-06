#define _CRT_SECURE_NO_WARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha
// imple for the menh

#include "menu.h"
#include "utils.h"
#include "recipebook.h"
#include <stdio.h>
#include <stdbool.h>























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
		char* newName;
		getInput(prompt, newName);

		UpdateRecipeName(&Book, RecipeName, newName);
		return true;
	case 2:
		printf("Which line number: ");
		
	default:
		break;
	}

}
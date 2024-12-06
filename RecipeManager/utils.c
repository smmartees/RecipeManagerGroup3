#define _CRT_SECURE_NO_WARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha
// imple for the linked list of recipees

#include "globals.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool getInput(char* prompt, char* buf) {
	printf("%s: ", prompt);
	fgets(buf, MAX_LENGTH, stdin);
	return true;
}

bool getLoopedInput(char* prompt, char* buf) {
	printf("%s: ", prompt);
	fgets(buf, MAX_LENGTH, stdin);
	if (strcmp(buf, 'q') == 0)
		return false;
	return true;
}

void AddRecipeUI(RECIPEBOOK recipeBook) {
	char buffer[MAX_LENGTH];
	int mealTypeInput = 0;

	getInput("Enter recipe name", buffer);
	RECIPE newRecipe = CreateRecipe(buffer);

	// OTHER, BREAK, LUNCH, DIN, APPS, DESS
	printf("1 - BREAK,2 - LUNCH,3 - DIN,4 - APPS,5 - DESS,6 - OTHER");
	printf("Enter the meal type option from the list: ");
	scanf("%d", &mealTypeInput);
	if (mealTypeInput < 0 || mealTypeInput > 6) {
		printf("Invalid Input entered\nTry again:");
			scanf("%d", &mealTypeInput);
	}
	switch (mealTypeInput)
	{
	case 1:
		newRecipe.mealType = "BREAK";
		break;
	case 2:
		newRecipe.mealType = "LUNCH";
		break;
	case 3:
		newRecipe.mealType = "DIN";
		break;
	case 4:
		newRecipe.mealType = "APPS";
		break;
	case 5:
		newRecipe.mealType = "DESS";
		break;
	case 6:
		newRecipe.mealType = "OTHER";
		break;
	default:
		newRecipe.mealType = "OTHER";
		break;
	}

	*buffer = "\0";
	
	while (getLoopedInput("Enter ingredients (1 per line)", buffer))
		AddLine(newRecipe.ingredients, buffer);

	*buffer = "\0";

	while (getLoopedInput("Enter instructions (1 per line)", buffer))
		AddLine(newRecipe.instructions, buffer);

	AddRecipeToBook(&recipeBook, newRecipe);
}

void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
}

void DeleteRecipeUI(RECIPEBOOK recipeBook) {
	char buffer[MAX_LENGTH] = {0};
	bool deleterecipeResult = false;

	getInput("Enter recipe name to delete: ", buffer);
	RECIPE tempRecipe = CreateRecipe(buffer);
	deleterecipeResult = RemoveRecipeFromBook(tempRecipe, &recipeBook);
	if (deleterecipeResult == true) {
		printf("The recipe '%s' was successfully deleted from the recipe book.\n", buffer);
	}
	else {
		printf("Could not find the recipe '%s' in the recipe book.\n", buffer);
	}
}


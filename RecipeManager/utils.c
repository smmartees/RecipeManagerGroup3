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

	getInput("Enter recipe name", buffer);
	RECIPE newRecipe = CreateRecipe(buffer);

	*buffer = "\0";

	while (getLoopedInput("Enter ingredients (1 per line)", buffer))
		AddLine(newRecipe.ingredients, buffer);

	*buffer = "\0";

	while (getLoopedInput("Enter instructions (1 per line)", buffer))
		AddLine(newRecipe.instructions, buffer);

	AddRecipeToBook(&recipeBook, newRecipe);
}
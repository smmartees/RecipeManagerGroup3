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
	clear_input_buffer();
	printf("%s: ", prompt);
	fgets(buf, MAX_LENGTH, stdin);
	return true;
}

bool getLoopedInput(char* prompt, char* buf) {
	clear_input_buffer();
	printf("%s: ", prompt);
	fgets(buf, MAX_LENGTH, stdin);
	if (buf[0] == 'q')
		return false;
	return true;
}

void AddRecipeUI(PRECIPEBOOK* recipeBook) {
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
		newRecipe.mealType = BREAK;
		break;
	case 2:
		newRecipe.mealType = LUNCH;
		break;
	case 3:
		newRecipe.mealType = DIN;
		break;
	case 4:
		newRecipe.mealType = APPS;
		break;
	case 5:
		newRecipe.mealType = DESS;
		break;
	case 6:
		newRecipe.mealType = OTHER;
		break;
	default:
		newRecipe.mealType = OTHER;
		break;
	}

	*buffer = "\0";
	
	while (getLoopedInput("Enter ingredients (1 per line)", buffer))
		AddLine(&newRecipe.ingredients, buffer);

	*buffer = "\0";

	while (getLoopedInput("Enter instructions (1 per line)", buffer))
		AddLine(&newRecipe.instructions, buffer);

	AddRecipeToBook(&recipeBook, newRecipe);
}

void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
}

void CleanNewLineFromString(char* Buf) {
	for (int i = 0; i < strlen(Buf); i++)
		if (Buf[i] == '\n')
			Buf[i] = '\0';
}

bool DeleteRecipeUI(PRECIPEBOOK* recipeBook) {
	char buffer[MAX_LENGTH] = {0};

	getInput("Enter recipe name to delete", buffer);

	RECIPE tempRecipe = CreateRecipe(buffer);
	return RemoveRecipeFromBook(tempRecipe, &recipeBook);
}

void DisplayRecipebookUI(PRECIPEBOOK recipeBook)
{
	int input;

	DisplayRecipebook(recipeBook);
	if (recipeBook == NULL)
	{
		printf("The recipe book is empty\n");
		return 0;
	}
	else if (recipeBook != NULL)
	{
		printf("Enter 0 to return to the main menu.\n Enter the number of a recipe to diplay:\n");
		scanf_s("%d", &input);
		if (input == 0)
		{
			return 0;
		}
		else
		{
			DisplayRecipeByDisplayNumberFromBook(recipeBook, input);
		}

	}
	return 0;
}

// Loads the data from a file
void load_data(PRECIPEBOOK* head) {
	FILE* file = fopen(FILENAME, "r");
	if (file == NULL) {
		perror("Error opening file for reading");
		exit(EXIT_FAILURE);
	}

	char buf[MAX_LENGTH];
	
	PRECIPEBOOK current = *head;
	
	while (fgets(buf, MAX_LENGTH, file)) {
		CleanNewLineFromString(buf);
		RECIPE newRecipe = CreateRecipe(buf);

		int mealType;
		fscanf(file, "%d\n", &mealType);
		newRecipe.mealType = mealType;

		int count = 0;
		fscanf(file, "%d\n", &count);
		for (int i = 0; i < count; i++) {
			fgets(buf, MAX_LENGTH, file);
			CleanNewLineFromString(buf);
			AddLine(&newRecipe.ingredients, buf);
		}

		count = 0;
		fscanf(file, "%d\n", &count);
		for (int i = 0; i < count; i++) {
			fgets(buf, MAX_LENGTH, file);
			CleanNewLineFromString(buf);
			AddLine(&newRecipe.instructions, buf);
		}
		AddRecipeToBook(&head, newRecipe);
	}
	fclose(file);
}



// Saves the data to a file
void save_data(PRECIPEBOOK head) {
	FILE* file = fopen(FILENAME, "w");
	if (file == NULL) {
		fprintf(stderr, "Error saving data");
		exit(EXIT_FAILURE);
	}

	PRECIPEBOOK temp = head;
	while (temp != NULL) {
		// Write the recipe name
		fprintf(file, "%s\n", temp->recipe.recipeName);

		// Writ meal type
		fprintf(file, "%d\n", temp->recipe.mealType);

		// Write the ingredients
		PSTRING ingredient = temp->recipe.ingredients;
		int count = GetLineCount(ingredient);
		fprintf(file, "%d\n", count);
		while (ingredient != NULL) {
			fprintf(file, "%s\n", ingredient->line);
			ingredient = ingredient->next;
		}

		// Write the instructions
		count = 0;
		PSTRING instruction = temp->recipe.instructions;
		count = GetLineCount(instruction);
		fprintf(file, "%d\n", count);
		while (instruction != NULL) {
			fprintf(file, "%s\n", instruction->line);
			instruction = instruction->next;
		}

		//fprintf(file, "---\n"); // Separator for recipes
		free(ingredient);
		free(instruction);
		temp = temp->next;
	}

	fclose(file);
	free(head);
}
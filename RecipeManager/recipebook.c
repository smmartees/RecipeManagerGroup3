// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for the linked list of recipees

#include "recipebook.h"
#include <stdio.h>
#include <stdlib.h>

void AddRecipeToBook(PRECIPEBOOK* BookEntry, RECIPE Recipe) {
/*PRECIPEBOOK newBook = (PRECIPEBOOK)malloc(sizeof(RECIPEBOOK));
	if (!newBook) {
		fprintf(stderr, "error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	else {
		newBook->recipe = CopyRecipe(Recipe);
		newBook->next = *BookEntry;

		*BookEntry = newBook;
	}*/	
}

void RemoveRecipeFromBook(PRECIPEBOOK* BookEntry, RECIPE Recipe) {
	/*PRECIPEBOOK current = *BookEntry;
	if (current != NULL && CompareParticipant(current->recipe, Recipe)) {
		*BookEntry = current->next;
		free(current);
		return;
	}

	PRECIPEBOOK prev = NULL;
	while (current != NULL && !CompareParticipant(current->recipe, Recipe)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;			// we hit end of list and did not match
	else {	// we found item in list
		prev->next = current->next;
		free(current);
	}*/
}

void DisplayRecipebook(PRECIPEBOOK Book) {
	/*PRECIPEBOOK current = Book;
	while (current != NULL) {
		PrintItem(current->recipe);
		current = current->next;
	}*/
}

void DestroyRecipeBook(PRECIPEBOOK* Book) {
/*
	PRECIPEBOOK current = *Book;
	while (current != NULL) {
		PRECIPEBOOK tmp = current;
		DestroyParticipant(current->recipe);
		current = current->next;
		free(tmp);
	}
	*/
}
void EmptyRecipeBook(PRECIPEBOOK* Book) {
	//DestroyRecipeBook(Book);
	//*Book = NULL;
}
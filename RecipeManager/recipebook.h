#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for the linked list of recipees

#include "recipe.h"

typedef struct recipebook {
	RECIPE recipe;
	struct recipebook* next;
}RECIPEBOOK, *PRECIPEBOOK;


void AddRecipeToBook(PRECIPEBOOK* BookEntry, RECIPE Recipe);

void RemoveRecipeFromBook(PRECIPEBOOK* BookEntry, RECIPE Recipe);

void DisplayRecipebook(PRECIPEBOOK Book);

void DestroyRecipeBook(PRECIPEBOOK* Book);


// 1. add a new recipe
// 9. save accumulated data to disk (write file)
// 10. load accumulated data from disk (read from file - Create linked list)
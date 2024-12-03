#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for the linked list of recipees

#include "recipe.h"
#include "ingrestruction.h"
#include <stdbool.h>

typedef struct recipebook {
	RECIPE recipe;
	struct recipebook* next;
}RECIPEBOOK, *PRECIPEBOOK;


bool AddRecipeToBook(PRECIPEBOOK* Book, RECIPE Recipe);

bool RemoveRecipeFromBook(RECIPE Recipe, PRECIPEBOOK* Book);

void DisplayRecipebook(PRECIPEBOOK Book);

void DestroyRecipeBook(PRECIPEBOOK* Book);

// 4. display single recipe
// 5. display range recipe
// 6. display all recipe

// 1. add a new recipe. 2 parts:
// -1 create recipe
// -2 add to recipe book.
// 9. save accumulated data to disk (write file) 4 parts:
// -1 fprintf recipe
// -2 Open file
// -3 write loop display recipe through all recipes
// - free memory? 2 save functions? One that just saves, another that saves and frees on exit?
// -4 close file
// 10. load accumulated data from disk (read from file - Create linked list)
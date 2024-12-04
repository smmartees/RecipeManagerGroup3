#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for the linked list of recipees

#include "recipe.h"
#include <stdbool.h>

#define FILENAME "recipebook.txt"

typedef struct recipebook {
	RECIPE recipe;
	struct recipebook* next;
}RECIPEBOOK, *PRECIPEBOOK;


bool AddRecipeToBook(PRECIPEBOOK* Book, RECIPE Recipe);

bool RemoveRecipeFromBook(RECIPE Recipe, PRECIPEBOOK* Book);

void DisplayRecipebook(PRECIPEBOOK Book);

void DestroyRecipeBook(PRECIPEBOOK* Book);

void load_data(PRECIPEBOOK* head);

void save_data(PRECIPEBOOK head);

//test
void add_recipe(PRECIPEBOOK* head);


// 1. add a new recipe
// 9. save accumulated data to disk (write file)
// 10. load accumulated data from disk (read from file - Create linked list)
#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for menu (user interface)


// 8. friendly / easy to use UI(or menu system)

#include "recipebook.h"
#include <stdbool.h>

int PrintMenu();



bool updateRecipeMenu(PRECIPEBOOK* Book, char* RecipeName);

void displayRangeOfRecipe(PRECIPEBOOK Book, RECIPE newRecipe);

void searchRecipeByNameMenu(PRECIPEBOOK Book, RECIPE newRecipe);


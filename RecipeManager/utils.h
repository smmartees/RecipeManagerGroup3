#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for utils

#include "globals.h"
#include "recipebook.h"
#include "recipe.h"
#include "ingrestruction.h"
#include <stdbool.h>

bool getInput(char* prompt, char* buf);

// User can enter 'q' to exit.
bool getLoopedInput(char* prompt, char* buf);

 

void clear_input_buffer();
void AddRecipeUI(RECIPEBOOK recipeBook);

void DeleteRecipeUI(RECIPEBOOK recipeBook);
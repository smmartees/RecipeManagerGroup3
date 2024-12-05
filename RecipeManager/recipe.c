// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for recipe

#include "recipe.h"


//C


RECIPE CreateRecipe(char* RecipeName) {
	
	RECIPE newRecipe = {0};

	strncmp(newRecipe.recipeName, RecipeName, MAX_LENGTH - 1);
	newRecipe.recipeName[MAX_LENGTH - 1] = "\0";
	
	// Initialize ingredients and instructions as NULL

	//newRecipe.ingredients = NULL;
	//newRecipe.instructions = NULL;

	// Set the default meal type (can update later)
	newRecipe.mealType = BREAK;

	return newRecipe;
}

// 1. add a new  recipe 
// 9. save accumulated data to disk

//R
// 4. display single appt/task/recipe/other
// 5. display range appt/task/recipe/other
// 6. display all appt/task/recipe/other
// 7. search for appt / task / recipe / other
// 10. load accumulated data from disk


//U
// 3. update an existing appt/task/recipe/other

//D
// 2. delete an existing appt/task/recipe/other
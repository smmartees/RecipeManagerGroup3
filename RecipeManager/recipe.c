#define _CRT_SECURE_NO_WARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for recipe

#include "recipe.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>


//C
// 1. add a new recipe
// 9. save accumulated data to disk

RECIPE CreateRecipe(char* RecipeName) {
	
}

//R
// 4. display single recipe
// 5. display range recipe
// 6. display all recipe
// 7. search for recipe
// 10. load accumulated data from disk

void DisplayWholeRecipe(RECIPE r) {
	printf("Recipe Name: %s\n", r.recipeName);
	printf("Ingredients:\n");
	DisplayAllLines(r.ingredients);
	printf("Instructions:\n");
	DisplayAllLines(r.instructions);
}

//int GetLineCount(RECIPE r) {
//	int count;
//	char reader[MAX_LENGTH];
//	while(fgets(reader, MAX_LENGTH-1, )) // need to read from file or stream....
//}


//U
// 3. update an existing recipe


//D
// 2. delete an existing recipe

//Compare recipes
bool CompareRecipes(RECIPE lhs, RECIPE rhs) {	//WARNING** using a lot of stack space.
	//return (strcmp(lhs.recipeName, rhs.recipeName));  **cannot convert string to char
	//return (lhs.recipeName == rhs.recipeName);	// make sure to move recipe to heap.
	int nameDiff = strcmp(lhs.recipeName, rhs.recipeName);
	if (nameDiff != 0)
		return false;
	return true;
}

//Copy recipe
RECIPE CopyRecipe(RECIPE src) {
	/*RECIPE dest = { 0 };
	strcpy(dest.recipeName, src.recipeName);
	return dest;*/
}
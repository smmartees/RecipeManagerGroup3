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
	RECIPE newRecipe;
	strncpy(newRecipe.recipeName, RecipeName, MAX_LENGTH);
	SetIngredients(&newRecipe);
	SetInstructions(&newRecipe);

	return newRecipe;
}

//R
// 4. display single recipe
// 5. display range recipe
// 6. display all recipe
// 7. search for recipe
// 10. load accumulated data from disk

//int GetLineCount(RECIPE r) {
//	int count;
//	char reader[MAX_LENGTH];
//	while(fgets(reader, MAX_LENGTH-1, )) // need to read from file or stream....
//}


//U
// 3. update an existing recipe
bool SetIngredients(RECIPE* r) {
	printf("Please input 1 ingredient & its amount per line. Input 'q' to exit.\n");
	char ingredient[MAX_LENGTH];
	char exitChar = { 0 };
	int count = 0;

	while (exitChar != 'q' || count < MAX_LINES) {
		if ((scanf(" %c"), &exitChar) == 'q')
			return true;
		fgets(ingredient, MAX_LENGTH - 1, stdin);
		strncpy(r->ingredients[count], ingredient, MAX_LENGTH);
		count++;
	}
	
}

bool SetInstructions(RECIPE* r) {
	printf("Please input 1 istructions per line. Input 'q' to exit.\n");
	char instruction[MAX_LENGTH];
	char exitChar = { 0 };
	int count = 0;

	while (exitChar != 'q' || count < MAX_LINES) {
		if ((scanf(" %c"), &exitChar) == 'q')
			return true;
		fgets(instruction, MAX_LENGTH - 1, stdin);
		strncpy(r->instructions[count], instruction, MAX_LENGTH);
		count++;
	}
}

//D
// 2. delete an existing recipe

//Compare recipes
bool CompareRecipes(RECIPE lhs, RECIPE rhs) {	//WARNING** using a lot of stack space.
	return (strcmp(lhs.recipeName, rhs.recipeName));
	//return (lhs.recipeName == rhs.recipeName);	// make sure to move recipe to heap.
}

//Copy recipe
RECIPE CopyRecipe(RECIPE src) {
	RECIPE dest = { 0 };
	strcpy(dest.recipeName, src.recipeName);


	return dest;

}
#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for recipe

#include <stdbool.h>

#define MAX_LENGTH		120
#define MAX_LINES		40

typedef enum mealtype { BREAK, LUNCH, DIN, APPS, DESS }MEALTYPE;

typedef struct recipe {
	char recipeName[MAX_LENGTH];
	char ingredients[MAX_LINES][MAX_LENGTH];	//number of array items first, size of items second.
	char instructions[MAX_LINES][MAX_LENGTH];	// may make ingredients & instructions their own structs later.
	MEALTYPE mealType;
}RECIPE, *PRECIPE;


//C


//R
// Display recipe 
// 4. display single recipe
// 5. display range recipe
// 6. display all recipe
// 7. search for recipe



//U
// 3. update an existing recipe

//D
// 2. delete an existing recipe

//Create


/// <summary>
/// Compare
/// recipes taking up a lot of stack space.
/// Week 13, steve went over how to store strings of unknownlength
/// </summary>
/// <param name="lhs"></param>
/// <param name="rhs"></param>
/// <returns></returns>
bool CompareRecipes(RECIPE lhs, RECIPE rhs);	// this take up to much stack space.

//Copy
RECIPE CopyRecipe(RECIPE src);

//Print
//Destroy

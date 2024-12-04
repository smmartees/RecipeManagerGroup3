#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for recipe

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
RECIPE CreateRecipe(char* RecipeName,char* ingredients,char* instructions,MEALTYPE Type);
// 1. add a new recipe
// 9. save accumulated data to disk (write file) File I/O

//R
// 4. display single recipe
// 5. display range recipe
// 6. display all recipe
// 7. search for recipe
// 10. load accumulated data from disk (read from file - Create linked list)


//U
// 3. update an existing recipe

//D
// 2. delete an existing recipe
RECIPE DeleteRecipe();

//Create
//Compare
//CopyRecipe
//Print
//Destroy
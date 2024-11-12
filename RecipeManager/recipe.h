#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for recipe

#define MAX_LENGTH		120
#define MAX_LINES		40

typedef enum mealtype { BREAK, LUNCH, DINNER }MEALTYPE;

typedef struct recipe {
	char recipeName[MAX_LENGTH];
	char ingredients[MAX_LINES][MAX_LENGTH];	//number of array items first, size of items second.
	char instructions[MAX_LINES][MAX_LENGTH];	// may make ingredients & instructions their own structs later.
	MEALTYPE mealType;
}RECIPE, *PRECIPE;


//C
// 1. add a new appt/task/recipe/other
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
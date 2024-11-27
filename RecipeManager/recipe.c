// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for recipe

#include "recipe.h"


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

//Compare recipes
bool CompareRecipes(RECIPE lhs, RECIPE rhs) {	//WARNING** using a lot of stack space.
	return (lhs.recipeName == rhs.recipeName);	// make sure to move recipe to heap.
}
// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for recipe

#include "recipe.h"


//C
// 1. add a new recipe
// 9. save accumulated data to disk

//R
// 4. display single recipe
// 5. display range recipe
// 6. display all recipe
// 7. search for recipe
// 10. load accumulated data from disk


//U
// 3. update an existing recipe

//D
// 2. delete an existing recipe

//Compare recipes
bool CompareRecipes(RECIPE lhs, RECIPE rhs) {	//WARNING** using a lot of stack space.
	return (lhs.recipeName == rhs.recipeName);	// make sure to move recipe to heap.
}
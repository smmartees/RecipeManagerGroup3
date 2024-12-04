// Group 3: Recipe Manager - Sam, Johan, Ridha
// implementation for recipe

#include "recipe.h"


//C
RECIPE CreateRecipe(char* RecipeName, char Ingredients[MAX_LINES][MAX_LENGTH], char Instructions[MAX_LINES][MAX_LENGTH], MEALTYPE Type) {
    RECIPE newRecipe = {0};
	strncpy(newRecipe.recipeName,RecipeName, MAX_LENGTH);
    newRecipe.recipeName[MAX_LENGTH - 1] = '\0';

     
    for (int i = 0; i < MAX_LINES; i++) {
        strncpy(newRecipe.ingredients[i], Ingredients[i], MAX_LENGTH - 1);
        newRecipe.ingredients[i][MAX_LENGTH - 1] = '\0'; // Ensure null-termination
    }

     
    for (int i = 0; i < MAX_LINES; i++) {
        strncpy(newRecipe.instructions[i], Instructions[i], MAX_LENGTH - 1);
        newRecipe.instructions[i][MAX_LENGTH - 1] = '\0'; // Ensure null-termination
    }

     
    newRecipe.mealType = Type;

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
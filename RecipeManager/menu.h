#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for menu (user interface)


// 8. friendly / easy to use UI(or menu system)



int PrintMenu();



bool updateRecipeMenu(PRECIPEBOOK* Book, char* RecipeName);

bool displayRangeOfRecipe(PRECIPEBOOK Book, RECIPE newRecipe);

bool searchRecipeByNameMenu(PRECIPEBOOK Book, RECIPE newRecipe);


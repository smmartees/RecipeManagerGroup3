#pragma once

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for the linked list of instructions & ingredients

#include "globals.h"
#include <stdbool.h>

typedef struct string {
	char line[MAX_LENGTH];
	struct string* next;
}STRING, *PSTRING;


//Add
bool AddLine(PSTRING* Head, char* Line);

//Display
bool DisplayLine(PSTRING Head);
bool DisplayAllLines(PSTRING Head);

//Update
bool UpdateLine(PSTRING* Head, int lineNum, char* newLine);

//Read
int GetLineCount(PSTRING Head);

//Remove
bool RemoveLine(PSTRING* Head, int lineNum);


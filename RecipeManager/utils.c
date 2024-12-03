#define _CRT_SECURE_NO_WAARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha
// imple for the linked list of recipees

#include "globals.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool getInput(char* prompt, char** userInput) {
	char input[MAX_LENGTH] = { 0 };

	printf("%s", prompt);
	fgets(input, MAX_LENGTH, stdin);
	size_t length = strlen(input);
	length += 1;	//leaves trailing \0, but would this be out of bounds if MAX_LENGTH is reached?
	*userInput = malloc(length * sizeof(char));
	if (!*userInput)
		return false;
	
	memset(*userInput, 'A', length);
	strncpy(*userInput, input, length);
	return true;
}
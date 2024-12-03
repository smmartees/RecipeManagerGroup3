#define _CRT_SECURE_NO_WAARNINGS

// Group 3: Recipe Manager - Sam, Johan, Ridha
// interface for the linked list of instructions & ingredients

#include "globals.h"
#include "ingrestruction.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Add
bool AddLine(PSTRING* Head, char* Line) {
	// malloc new line node
	PSTRING newLine = (PSTRING)malloc(sizeof(STRING));
	if (newLine == NULL) {
		printf("New Line Malloc failed.\n");
		return false;
	}

	// assign value & point to Null as new tail of list
	*newLine->line = Line;
	newLine->next = NULL;

	// if list is empty (i.e. first entry in list) assign newLine to Head pointer.
	PSTRING temp = *Head;
	if (temp == NULL) {
		*Head = newLine;
		return true;
	}

	// checking for end of the list
	while (temp->next != NULL)
		temp = temp->next;
	// if temp is pointing to the last node (which is pointing to NULL)..
	// temp-> will point to newLine (newLine node already points to NULL).
	if (temp->next == NULL) {
		temp->next = newLine;
		return true;
	}


}

//Update
bool UpdateLine(PSTRING* Head, int lineNum, char* newLine) {
	PSTRING temp = *Head;
	if (temp == NULL) {
		printf("Empty List\n");
		return false;
	}
	int count = 0;
	while (temp != NULL && count <= lineNum)
		temp = temp->next;
	if (temp == NULL) {
		printf("Line not found.\n");
		return false;
	}
	else {
		strncpy(temp->line, newLine, MAX_LENGTH);
		return true;
	}
}

//Remove
bool RemoveLine(PSTRING* Head, int lineNum) {
	PSTRING temp = *Head;
	if (temp == NULL) {
		printf("Empty List\n");
		return false;
	}
	PSTRING prev = NULL;
	int count = 0;
	while (temp != NULL && count <= lineNum) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Line not found.\n");
		return false;
	}
	else {
		prev->next = temp->next;
		free(temp);
		return true;
	}
}

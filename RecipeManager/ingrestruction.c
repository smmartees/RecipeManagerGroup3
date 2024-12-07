#define _CRT_SECURE_NO_WARNINGS

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
		fprintf(stderr, "New Line Malloc failed.\n");
		return false;
	}

	// assign value & point to Null as new tail of list
	strncpy(newLine->line, Line, MAX_LENGTH);
	newLine->next = NULL;

	// if list is empty (i.e. first entry in list) assign newLine to Head pointer.
	PSTRING temp = *Head;
	if (temp == NULL) {
		temp = newLine;
		*Head = temp;
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

bool DisplayLine(PSTRING Line) {
	if (Line == NULL)
		return false;
	printf("%s\n", Line->line);
	return true;
}

bool DisplayAllLines(PSTRING Head) {
	if (Head == NULL) {
		fprintf(stderr, "This section is empty.\n");
		return false;
	}
	PSTRING currentLine = Head;
	int lineNum = 1;
	while (currentLine != NULL) {
		printf("%d) ", lineNum);
		DisplayLine(currentLine);
		currentLine = currentLine->next;
		lineNum++;
	}
	return true;
}

//Update
bool UpdateLine(PSTRING* Head, int lineNum, char* newLine) {
	PSTRING temp = *Head;
	if (temp == NULL) {
		fprintf(stderr, "Empty List\n");
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

// Read
int GetLineCount(PSTRING Head) {
	PSTRING temp = Head;
	int count = 0;
	if (temp == NULL)
		return count;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}


//Remove
bool RemoveLine(PSTRING* Head, int lineNum) {
	PSTRING temp = *Head;
	if (temp == NULL) {
		fprintf(stderr, "Empty List\n");
		return false;
	}
	PSTRING prev = NULL;
	int count = 0;
	while (temp != NULL && count <= lineNum) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		fprintf(stderr, "Line not found.\n");
		return false;
	}
	else {
		prev->next = temp->next;
		free(temp);
		return true;
	}
}

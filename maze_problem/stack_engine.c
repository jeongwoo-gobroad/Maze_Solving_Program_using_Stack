// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#include "stack_engine.h"

top = -1;
initialStackSize = 1;
currentStackSize = 1;

// functions for allocating 
void initialAlloc(void) {
	stack = (element*)malloc(sizeof(element) * initialStackSize);

	if (stack == NULL) {
		puts("Cannot realloc stack memory.");
		puts("Terminate program.");
		exit(EXIT_FAILURE);
	}

	return;
}

void double_realloc(void) {
	stack = (element*)realloc(stack, sizeof(element) * currentStackSize * 2);
	//stack = (element*)realloc(stack, sizeof(element) * (currentStackSize + 1));
	currentStackSize *= 2;
	//currentStackSize += 1;

	if (stack == NULL) {
		puts("Cannot realloc stack memory.");
		puts("Terminate program.");
		exit(EXIT_FAILURE);
	}

	return;
}

// function for stack empty
int isStackEmpty(void) {
	if (top == -1) return 1;
	
	return 0;
}

// function for stack push
void stack_push(element input) {
	top += 1;

	if (top == currentStackSize)
		double_realloc();

	stack[top] = input;

	return;
}

// functions for stack pop
element stack_pop(void) {
	return stack[top--];
}

void erase_stack_pop(void) {
	top--;

	return;
}

// functions for free stack memory
void freeAllStack(void) {
	free(stack);

	return;
}
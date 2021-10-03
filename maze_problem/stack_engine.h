// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#pragma once
#define MAX_STACK_SIZE 1000
#include "operations.h"

int top;
int initialStackSize;
int currentStackSize;

// functions for allocating 
void initialAlloc(void);
void double_realloc(void);

// function for stack empty
int isStackEmpty(void);

// function for stack push
void stack_push(element input);

// functions for stack pop
element stack_pop(void);
void erase_stack_pop(void);

// functions for free stack memory
void freeAllStack(void);
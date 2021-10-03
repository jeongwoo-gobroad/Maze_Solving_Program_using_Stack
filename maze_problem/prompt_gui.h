// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#pragma once

#include "operations.h"
#include "stack_engine.h"
#include "maze_core.h"
#include <stddef.h> // Headers for printing multi-byte characters.
#include <locale.h> // Headers for printing multi-byte characters.

int submissionMode;
wchar_t** visualMap; // In order to use multi-byte characters, wchar_t should be considered.

// function for asking users an operating mode 
void askOpMode(void);

// functions for initalizing visual map array
void allocVisualMap(void);
void initVisualMap(void);

// functions for visualizing the map
int returnDirection(void);
void createVisualMap(void);
void printVisualMap(void);

// function for delaying prompt refresh
void cr_delay(clock_t n);

// function for free array
void freeVisualMap(void);
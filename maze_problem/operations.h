// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#pragma once
#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////
/*Define indexes of array of moves for each direction*/
///////////////////////////////////////////////////////
#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SW 5
#define W 6
#define NW 7
///////////////////////////////////////////////////////
//#include <windows.h> This header causes a problem on my VS2019
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct offsets {
	int vert;
	int horiz;
} offsets;

typedef struct positions {
	int row;
	int col;
} pos;

typedef struct element {
	int row;
	int col;
	int dir; // DIR CONTAINS INFORMATION OF "WHERE IT HEADS TO"
} element;

// An array for movement offsets
offsets move[8];

// A variable for a stack
element* stack;

// Two dimensional arrays
int** maze;
int** mark;

// Coordinate storage
pos startPos;
pos finishPos;

// Maze size storage
pos size;

// Function for offset initialize
void initOffset(void);

// Function for file IO
void readFile(FILE** f);

// Functions for initial operations
void allocMap(pos mazeSize);
void allocMarkPos(pos mazeSize);
void insertMap(pos index, int data);
void insertWayPoint(pos* target);
void initMarkPos(pos mazeSize);
void fillBoundary(pos mazeSize);

// functions for free arrays
void freeMazeArray(void);
void freeMarkArray(void);

// functions for standard output
void printInputMaze(void);
void printMazeAnswer(void);

// Functions for debugging
void DBG_showMaze(void);
void DBG_printSttFin(void);
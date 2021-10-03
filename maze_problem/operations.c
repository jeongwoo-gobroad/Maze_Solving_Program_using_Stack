// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#include "operations.h"

// Function for offset initialize
void initOffset(void) {
	// North
	move[N].vert = -1; move[N].horiz = 0;
	// North-East
	move[NE].vert = -1; move[NE].horiz = 1;
	// East
	move[E].vert = 0; move[E].horiz = 1;
	// South-East
	move[SE].vert = 1; move[SE].horiz = 1;
	// South
	move[S].vert = 1; move[S].horiz = 0;
	// South-West
	move[SW].vert = 1; move[SW].horiz = -1;
	// West
	move[W].vert = 0; move[W].horiz = -1;
	// North-West
	move[NW].vert = -1; move[NW].horiz = -1;

	return;
}

// Function for file IO
void readFile(FILE** f) {
	pos curr;
	pos wayPoint[2];
	int temp = 0;
	
	fscanf(*f, "%d %d\n", &size.row, &size.col);
	allocMap(size);
	fillBoundary(size);
	for (int i = 1; i <= size.row; i++) {
		for (int j = 1; j <= size.col; j++) {
			fscanf(*f, "%d", &temp);
			curr.row = i;
			curr.col = j;
			insertMap(curr, temp);
		}
	}
	fscanf(*f, "%d %d", &wayPoint[0].row, &wayPoint[0].col);
	fscanf(*f, "%d %d", &wayPoint[1].row, &wayPoint[1].col);
	insertWayPoint(wayPoint);

	return;
}

// Functions for initial operations
void allocMap(pos mazeSize) {
	maze = (int**)malloc(sizeof(int*) * (mazeSize.row + 2));
	//maze = malloc(sizeof(int*) * (mazeSize.row + 2));
	for (int i = 0; i < mazeSize.row + 2; i++) {
		maze[i] = (int*)malloc(sizeof(int) * (mazeSize.col + 2));
		//maze[i] = malloc(sizeof(int) * mazeSize.col + 2);
	}

	return;
}

void allocMarkPos(pos mazeSize) {
	mark = (int**)malloc(sizeof(int*) * (mazeSize.row + 2));
	for (int i = 0; i < mazeSize.row + 2; i++) {
		mark[i] = (int*)malloc(sizeof(int) * (mazeSize.col + 2));
	}

	return;
}

void insertMap(pos index, int data) {
	maze[index.row][index.col] = data;

	return;
}

void insertWayPoint(pos* target) {
	startPos = target[0];
	finishPos = target[1];

	return;
}

void initMarkPos(pos mazeSize) {
	for (int i = 0; i < mazeSize.row + 2; i++) {
		for (int j = 0; j < mazeSize.col + 2; j++) {
			if (i == 0 || i == mazeSize.row + 1) {
				mark[i][j] = 2;
			}
			else if (j == 0 || j == mazeSize.col + 1) {
				mark[i][j] = 2;
			}
			else {
				mark[i][j] = 0;
			}
		}
	}

	return;
}

void fillBoundary(pos mazeSize) {
	for (int i = 0; i < mazeSize.col + 2; i++)
		maze[0][i] = 1;
	for (int i = 1; i <= mazeSize.row; i++) {
		maze[i][0] = 1;
		maze[i][mazeSize.col + 1] = 1;
	}
	for (int i = 0; i < mazeSize.col + 2; i++)
		maze[mazeSize.row + 1][i] = 1;

	return;
}

// functions for free arrays
void freeMazeArray(void) {
	for (int i = 0; i < size.row + 2; i++) {
		int* currentPtr = maze[i];
		free(currentPtr);
	}
	free(maze);

	return;
}

void freeMarkArray(void) {
	for (int i = 0; i < size.row + 2; i++) {
		free(mark[i]);
	}
	free(mark);

	return;
}

// functions for standard output
void printInputMaze(void) {
	puts("MAZE");
	for (int i = 1; i < size.row + 1; i++) {
		for (int j = 1; j < size.col + 1; j++) {
			printf("%3d", maze[i][j]);
		}
		puts("");
	}

	return;
}

void printMazeAnswer(void) {
	puts("The path is: ");
	for (int i = 1; i < size.row + 1; i++) {
		for (int j = 1; j < size.col + 1; j++) {
			if (i - 1 == startPos.row && j - 1 == startPos.col)
				printf("%3c", 'S');
			else if (i - 1 == finishPos.row && j - 1 == finishPos.col)
				printf("%3c", 'F');
			else {
				if (mark[i][j] == 1)
					printf("%3c", 'X');
				else
					printf("%3d", maze[i][j]);
			}
		}
		puts("");
	}

	return;
}

// Functions for debugging
void DBG_showMaze(void) {
	for (int i = 0; i < size.row + 2; i++) {
		for (int j = 0; j < size.col + 2; j++) {
			printf("%3d", maze[i][j]);
		}
		puts("");
	}

	return;
}
void DBG_printSttFin(void) {
	printf("%d %d %d %d", startPos.row, startPos.col
		, finishPos.row, finishPos.col);

	return;
}
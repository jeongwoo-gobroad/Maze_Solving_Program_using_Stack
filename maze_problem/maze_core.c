// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#include "maze_core.h"
#include "prompt_gui.h"

isFirstStart = 0;

// function for initializing virtual coordinates
void initVirtCoordinate(void) {
	virtualSttPos.row = startPos.row + 1;
	virtualSttPos.col = startPos.col + 1;
	virtualFinPos.row = finishPos.row + 1;
	virtualFinPos.col = finishPos.col + 1;

	return;
}

// function for main loop call
int findPath(void) {
	//int isCapaValue = 0;
	element temp;
	temp.row = virtualSttPos.row;
	temp.col = virtualSttPos.col;
	temp.dir = N;
	stack_push(temp);

	///////////////////////////////////////////////////////////////
	/*dir is defined as an progression from current stack element*/
	///////////////////////////////////////////////////////////////

	while (chkReached() != 1) { // Segment for progressing the rat in the maze
		if (submissionMode == 2) printVisualMap();
		if (isNoPathAtAll() == 0) break;
		/*
		isCapaValue = isCapable();
		if (isCapaValue == 0) { 
			mark[stack[top].row][stack[top].col] = 2; // visited sector: not progressible zone is defined by integer 2
			erase_stack_pop();
		}
		else if (isCapaValue == 1) {
			DBG_printStack();
			mark[stack[top].row][stack[top].col] = 1;
			temp.row = stack[top].row + move[stack[top].dir].vert;
			temp.col = stack[top].col + move[stack[top].dir].horiz;
			stack_push(temp);
		}
		*/

		//mark[stack[top].row][stack[top].col] = 1;
		switch (isCapable()) {
		case 0: case 1:
			mark[stack[top].row][stack[top].col] = 1;
			temp.row = stack[top].row + move[stack[top].dir].vert;
			temp.col = stack[top].col + move[stack[top].dir].horiz;
			temp.dir = stack[top].dir;
			stack_push(temp);
			// mark[stack[top].row][stack[top].col] = 1;
			break;
		default:
			mark[stack[top].row][stack[top].col] = 2; // visited sector: not progressible zone is defined by integer 2
			erase_stack_pop();
			break;
		}
		//DBG_printMark();
		//DBG_printStack();
		//DBG_printNoPathAtAll();
		//puts("");
		//isFirstStart = 1;
	}

	if (isNoPathAtAll() == 0) {
		return 0;
	}

	return 1;
}

// functions for checking possiblities
int chkReached(void) {
	if (stack[top].col == virtualFinPos.col && stack[top].row == virtualFinPos.row) {
		return 1;
	}

	return 0;
}

int isCapable(void) {
	int progRowPos = 0, progColPos = 0;
	int prevRowPos = 0, prevColPos = 0;
	int currRowPos = 0, currColPos = 0;
	int flipDirection = 0;

	currRowPos = stack[top].row;
	currColPos = stack[top].col;
	progRowPos = stack[top].row + move[stack[top].dir].vert;
	progColPos = stack[top].col + move[stack[top].dir].horiz;

	if (maze[progRowPos][progColPos] != 1 && mark[progRowPos][progColPos] != 2) {
		return 0; // Case 0 if it can keep progressing in same direction
	}

	for (int i = 0; i < 8; i++) { // Case 1 if if can keep progressing but in another direction
		if (i == stack[top].dir)
			continue;

		progRowPos = stack[top].row + move[i].vert;
		progColPos = stack[top].col + move[i].horiz;

		if (top == 0 /* && isFirstStart != 0 */) {
			if (maze[progRowPos][progColPos] != 1 && mark[progRowPos][progColPos] == 0) {
				stack[top].dir = i;
				return 1; 
			}
		}
		else {
			flipDirection = stack[top].dir - 4;
			if (flipDirection < 0)
				flipDirection += 8;

			//if (i == flipDirection)
			//	continue;

			if (maze[progRowPos][progColPos] != 1 && mark[progRowPos][progColPos] == 0) {
				stack[top].dir = i;
				return 1;
			}
		}
	}

	/*
	for (int i = 0; i < 8; i++) { // Case 1 if if can keep progressing but in another direction
		if (i == stack[top].dir)
			continue;

		progRowPos = stack[top].row + move[i].vert;
		progColPos = stack[top].col + move[i].horiz;

		if (top == 0 && isFirstStart == 0) {
			if (maze[progRowPos][progColPos] != 1 && mark[progRowPos][progColPos] != 2) {
				stack[top].dir = i;
				return 1;
			}
		}
		else {
			flipDirection = stack[top].dir - 4;
			if (flipDirection < 0)
				flipDirection += 8;

			if (i == flipDirection)
				continue;

			if (maze[progRowPos][progColPos] != 1 && mark[progRowPos][progColPos] != 2) {
				stack[top].dir = i;
				return 2;
			}
		}
	}
	*/

	return 2; // case 2 if keeping progression is not possible at all
}

int isNoPathAtAll(void) {
	////////////////////////////////////////////////////////////////////////
	/*A segment for terminating pathfinding sequence when its not possible*/
	////////////////////////////////////////////////////////////////////////
	int possiblePaths = 8;
	int progRowPos = 0, progColPos = 0;

	for (int i = 0; i < 8; i++) {
		progRowPos = stack[top].row + move[i].vert;
		progColPos = stack[top].col + move[i].horiz;

		if (maze[progRowPos][progColPos] == 1 || mark[progRowPos][progColPos] == 2)
			possiblePaths--;
	}

	return possiblePaths;
}

// functions for debugging
void DBG_printMark(void) {
	for (int i = 0; i < size.row + 2; i++) {
		for (int j = 0; j < size.col + 2; j++) {
			printf("%2d ", mark[i][j]);
		}
		puts("");
	}

	return;
}

void DBG_printStack(void) {
	printf("Current stack top ROW: %d COL: %d POS: %d\n", stack[top].row, stack[top].col, stack[top].dir);

	return;
}

void DBG_printNoPathAtAll(void) {
	printf("isNoPathAtAll: %d\n", isNoPathAtAll());

	return;
}
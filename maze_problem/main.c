// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
// Version 1.1b: Please refer to the readme.txt to get more specific information.
#include "stack_engine.h"
#include "prompt_gui.h"
#include "maze_core.h"

int main(void)
{
	FILE* f;
	char* fileName = "maze2.txt";
	char DBG_fileName[20] = { '\0', };
	int ansExist = 0;

	askOpMode();

	getchar();
	scanf("%s", DBG_fileName);
	f = fopen(DBG_fileName, "r");
	readFile(&f);

	initOffset();          //
	allocMarkPos(size);    // initializing core operation arrays
	initMarkPos(size);     //
	initVirtCoordinate();  //

	initialAlloc(); // initalizing stack

	if (submissionMode == 1) {
		puts("");
		printInputMaze();
		puts("");
		ansExist = findPath(); // CORE FUNCTION

		if (ansExist == 0) {
			puts("No path found!");
			exit(EXIT_FAILURE);
		}

		printMazeAnswer();
	}
	else {
		allocVisualMap();
		initVisualMap();

		ansExist = findPath(); // CORE FUNCTION

		if (ansExist == 0) {
			puts("No path found!");
			exit(EXIT_FAILURE);
		}

		printMazeAnswer();
	}

	/* switch() causes inuput buffer flush problem
	switch (askOpMode()) { 
	default:
		getchar();
		scanf("%s", DBG_fileName);
		f = fopen(DBG_fileName, "r");
		readFile(&f);

		initOffset();          //
		allocMarkPos(size);    // initializing core operation arrays
		initMarkPos(size);     //
		initVirtCoordinate();  //

		initialAlloc(); // initalizing stack
	case 1:
		printInputMaze();
		ansExist = findPath(); // CORE FUNCTION

		if (ansExist == 0) {
			puts("No path found!");
			exit(EXIT_FAILURE);
		}

		printMazeAnswer();
		break;
	case 2:
		allocVisualMap();
		initVisualMap();

		ansExist = findPath(); // CORE FUNCTION

		if (ansExist == 0) {
			puts("No path found!");
			exit(EXIT_FAILURE);
		}

		printMazeAnswer();
		break;
	}
	*/

	/*
	scanf("%s", DBG_fileName);
	f = fopen(DBG_fileName, "r");

	//f = fopen(fileName, "r");

	readFile(&f);
	
	initOffset();          //
	allocMarkPos(size);    // initializing core operation arrays
	initMarkPos(size);     //
	initVirtCoordinate();  //

	initialAlloc(); // initalizing stack

	printInputMaze();

	ansExist = findPath(); // CORE FUNCTION

	// printf("Does answer exist?: %d\n", ansExist); Debug feature

	if (ansExist == 0) {
		puts("No path found!");
		exit(EXIT_FAILURE);
	}

	printMazeAnswer();
	*/

	//DBG_printMark();

	//DBG_showMaze();
	//DBG_printSttFin();

	freeAllStack();//
	// printf("%d %d\n", size.row + 2, size.col); // Debug feature
	freeMarkArray();   // free
	freeMazeArray();   //
	freeVisualMap();

	return 0;
}
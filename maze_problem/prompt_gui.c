// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#pragma once
#include "prompt_gui.h"

int submissionMode;
wchar_t** visualMap;

// function for asking users an operating mode 
void askOpMode(void) {
	submissionMode = 0;

	puts("A rat in a maze: Maze solving problem using stack operations.");
	puts("This program has two operating modes: 1. Assignment submission mode. 2. Rat visualizing mode.");
	printf("Your selection: ");

	scanf("%d", &submissionMode);

	switch (submissionMode) {
	case 1:
		puts("Operating in assignment submission mode.");
		printf("Please type the full file name of a maze including extension: ");
		return;
	case 2:
		puts("Operating in rat movement visualizing mode.");
		printf("Please type the full file name of a maze including extension: ");
		return;
	default:
		puts("You have typed in the wrong input.");
		exit(EXIT_FAILURE);
	}

	return;
}

// functions for initalizing visual map array
void allocVisualMap(void) {
	visualMap = (wchar_t**)malloc(sizeof(wchar_t*) * (size.row + 2));
	for (int i = 0; i < size.row + 2; i++) {
		visualMap[i] = (wchar_t*)malloc(sizeof(wchar_t) * (size.col + 2));
	}

	return;
}

void initVisualMap(void) {
	for (int i = 0; i < size.row + 2; i++) {
		for (int j = 0; j < size.col + 2; j++) {
			if (maze[i][j] == 1) {
				visualMap[i][j] = L'¡á';
			}
			else {
				visualMap[i][j] = L'¡¡';
			}
		}
	}

	return;
}

// functions for visualizing the map
int returnDirection(void) {
	return stack[top].dir;
}

void createVisualMap(void) {
	for (int i = 1; i < size.row + 1; i++) {
		for (int j = 1; j < size.col + 1; j++) {
			if (i == stack[top].row && j == stack[top].col) {
				switch (returnDirection()) {
				case 0:
					visualMap[i][j] = L'¡è';
					break;
				case 1:
					visualMap[i][j] = L'¢Ö';
					break;
				case 2:
					visualMap[i][j] = L'¡æ';
					break;
				case 3:
					visualMap[i][j] = L'¢Ù';
					break;
				case 4:
					visualMap[i][j] = L'¡é';
					break;
				case 5:
					visualMap[i][j] = L'¢×';
					break;
				case 6:
					visualMap[i][j] = L'¡ç';
					break;
				case 7:
					visualMap[i][j] = L'¢Ø';
					break;
				}
			}
			else if (mark[i][j] == 2) {
				visualMap[i][j] = L'¢Ì';
			}
			else if (mark[i][j] == 1) {
				visualMap[i][j] = L'¡Ý';
			}

			if (i == virtualSttPos.row && j == virtualSttPos.col) {
				visualMap[i][j] = L'¢Ã';
			}
			else if (i == virtualFinPos.row && j == virtualFinPos.col) {
				visualMap[i][j] = L'¢Ã';
			}
		}
	}

	return;
}

void printVisualMap(void) {
	setlocale(LC_ALL, "");
	system("cls");
	initVisualMap();
	puts("Maze: ");
	for (int i = 0; i < size.row + 2; i++) {
		for (int j = 0; j < size.col + 2; j++) {
			printf("%lc", visualMap[i][j]);
		}
		puts("");
	}
	puts("");
	puts("Current Status: ");
	createVisualMap();
	for (int i = 0; i < size.row + 2; i++) {
		for (int j = 0; j < size.col + 2; j++) {
			printf("%lc", visualMap[i][j]);
		}
		puts("");
	}
	puts("");

	//Sleep(500); Can't use it since winnt.h causes a problem
	cr_delay(500);


	return;
}

// function for delaying prompt refresh
void cr_delay(clock_t n) {
	clock_t start = clock();
	while (clock() - start < n);

	return;
}

// function for free array
void freeVisualMap(void) {
	for (int i = 0; i < size.row + 2; i++) {
		free(visualMap[i]);
	}
	free(visualMap);

	return;
}
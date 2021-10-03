// KNU CSE 2021****** Jeongwoo Kim
// Maze Problem Source Code
#pragma once

#include "operations.h"
#include "stack_engine.h"
#include "prompt_gui.h"

pos virtualSttPos;
pos virtualFinPos;

int isFirstStart;

// function for initializing virtual coordinates
void initVirtCoordinate(void);

// function for main loop call
int findPath(void);

// functions for checking possiblities
int chkReached(void);
int isCapable(void);
int isNoPathAtAll(void);

// functions for debugging
void DBG_printMark(void);
void DBG_printStack(void);
void DBG_printNoPathAtAll(void);
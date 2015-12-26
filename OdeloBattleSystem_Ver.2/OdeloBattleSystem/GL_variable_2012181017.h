#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define B_SIZE_2012181017 8
#define NONE_STONE_2012181017 0
#define WHITE_STONE_2012181017 2
#define BLACK_STONE_2012181017 1

#define BLACK_TURN_MIN_2012181017 18
#define WHITE_TURN_MIN_2012181017 15


typedef struct _boardStone{
	int x, y;
	bool checkFlag;
}STONE_2012181017;


typedef struct _boardUnit{
	STONE_2012181017 stone;
	_boardUnit*	link;
}B_UNIT_2012181017;


void checkMaxTurnStone_2012181017(int userStone, int* resultX, int* resultY);


void	changeStone_2012181017(int x, int y, int userStone);
bool	changeStone_2012181017(int x, int y, int userStone, int tX, int tY);

int		maxTurn_2012181017(int userStone, int x, int y);

//----------------------------¸®½ºÆ®
B_UNIT_2012181017*	createHeadSL_2012181017();

void	insertSL_2012181017(B_UNIT_2012181017*	head, B_UNIT_2012181017* unit);

void	putStone_2012181017(int userStone, int* resultX, int* resultY);

void	checkPutStone_2012181017(int userStone, int x, int y);

void	clearSL_2012181017();

bool	checkStone_2012181017(B_UNIT_2012181017 unit, int userStone);

void	checkTurnStone_2012181017(int userStone, int* resultX, int* resultY);

void	changeStoneSL_2012181017(int x, int y, int userStone);

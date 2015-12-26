#ifndef _Attack_2_2012181017_H_
#define _Attack_2_2012181017_H_

#include "GL_variable_2012181017.h"

void WhiteAttack_2012181017( int *x, int *y )
{
	checkTurnStone_2012181017(WHITE_STONE_2012181017, x, y);
	//changeStone_2012181017(*x, *y, WHITE_STONE_2012181017);
	if(*x != -1 && *y != -1)
		changeStoneSL_2012181017(*x, *y, WHITE_STONE_2012181017);
	printf("WHITE_ATTACK : %d,%d\n",*x,*y);
}

void WhiteDefence_2012181017( int x, int y )
{
	if(x != -1 && y != -1)
		changeStoneSL_2012181017(x, y, BLACK_STONE_2012181017);
	printf("WHITE_DEFENCE : %d,%d\n",x,y);
}
#endif

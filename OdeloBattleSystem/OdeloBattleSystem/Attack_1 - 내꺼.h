#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

#include "OdeloBattleSystem.h"

typedef struct Odelo_Count
{
	int Attack_Point;
	bool check_position;
}OC;
OC Black_Attack_Check[g_nMax][g_nMax];
OC White_Attack_Check[g_nMax][g_nMax];

void BlackAttack_2012180004( int *x, int *y );
void BlackDefence_2012180004( int x, int y );


#endif
#include "stdafx.h"

void C_REVERSI :: cpyBd(int (*cpyedBd)[8], int (*mainBd)[8])
{
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			cpyedBd[i][j] = mainBd[i][j];
		}
	}
}
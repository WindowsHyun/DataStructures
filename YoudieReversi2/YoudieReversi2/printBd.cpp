#include "stdafx.h"

void C_REVERSI :: printBd(int (*arrBd)[8])
{
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			printf("%2d",arrBd[i][j]);
		}
		printf("\n");
	}
}
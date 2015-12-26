#include "stdafx.h"

void C_REVERSI:: releaseIsReverse(int (*arrBd)[8])
{
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(arrBd[i][j] == 3)
			{
				arrBd[i][j] = 0;
			}
		}
	}
}
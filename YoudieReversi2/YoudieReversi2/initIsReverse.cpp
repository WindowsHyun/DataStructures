#include "stdafx.h"

void C_REVERSI :: initIsReverse(int (*arrBd)[8], bool isTurn)
{
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(isReverse(arrBd,j,i,isTurn))
				arrBd[i][j] = 3;
		}
	}
}
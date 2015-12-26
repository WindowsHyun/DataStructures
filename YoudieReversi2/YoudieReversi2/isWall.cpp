#include "stdafx.h"

bool C_REVERSI :: isWall(int (*arrBd)[8])
{
	for(int i = 0 ; i < 8 ; i ++ )
	{
		if(arrBd[0][i] == 1 || arrBd[0][i] == 2)
			return true;
		if(arrBd[0][i] == 1 || arrBd[0][i] == 2)
			return true;
		if(arrBd[0][i] == 1 || arrBd[0][i] == 2)
			return true;
		if(arrBd[0][i] == 1 || arrBd[0][i] == 2)
			return true;
	}

	return false;
}
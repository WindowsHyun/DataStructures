#include "stdafx.h"

int C_REVERSI :: getBdScore(int (*arrBd)[8],int nX,int nY, bool isTurn)
{
	int tmpBd[8][8];
	int arrScore[8][8];
	int nBCnt = 0;
	int nWCnt = 0;
	
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			tmpBd[i][j] = arrBd[i][j];
		}
	}
	initBdScore(arrScore);
	doReverse(tmpBd,nX,nY,isTurn);

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(tmpBd[i][j] == 1)
				nBCnt ++;
			else if(tmpBd[i][j] == 2)
				nWCnt ++;
		}
	}

	if(isTurn)
		arrScore[nY][nX] += nBCnt;
	else
		arrScore[nY][nX] += nWCnt;

	return arrScore[nY][nX];
}
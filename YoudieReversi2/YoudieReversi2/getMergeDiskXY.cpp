#include "stdafx.h"

void C_REVERSI :: getMergeDiskXY(int (*arrBd)[8], int *pX, int *pY, bool isTurn)
{
	int tmpBd[8][8] = {0};
	int arrBdCnt[8][8] = {0};
	int nCnt = 0;
	int nMax = 0;

	int nX = 0;
	int nY = 0;

	cpyBd(tmpBd,arrBd);

	for(int i = 2 ; i < 6 ; i ++ )
	{
		for(int j = 2 ; j < 6 ; j ++ )
		{
			if(tmpBd[i][j] == 3)
			{
				doReverse(tmpBd,j,i,isTurn);
				releaseIsReverse(tmpBd);
				initIsReverse(tmpBd,!isTurn);

				for(int k = 2 ; k < 6 ; k ++ )
				{
					for(int l = 2 ; l < 6 ; l ++ )
					{
						if(tmpBd[k][l] == 3)
							nCnt ++;
					}
				}
				if(nCnt == 0)
				{
					arrBdCnt[i][j] += 1;
					nMax = arrBdCnt[nX][nY];
				}
				else
				{
					cpyBd(tmpBd,arrBd);
					getMinReverseXYRange(tmpBd,&nX,&nY,2,6,2,6,isTurn);
					arrBdCnt[nX][nY] += 1;
					nMax = arrBdCnt[nX][nY];
				}
			}
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMax <= arrBdCnt[i][j] && arrBd[i][j] == 3)
				nMax = arrBdCnt[i][j];
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMax == arrBdCnt[i][j])
			{
				*pX = j;
				*pY = i;
				return ;
			}
		}
	}
}
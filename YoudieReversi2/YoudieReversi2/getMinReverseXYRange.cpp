#include "stdafx.h"

void C_REVERSI :: getMinReverseXYRange(int (*arrBd)[8], int *pX, int *pY,int nI ,int nI_,int nJ, int nJ_,bool isTurn)
{
	int tmpBd[8][8] = {0};
	int arrBdCnt[8][8] = {0};
	int nVal = 0;
	int nMin = 0;

	if(isTurn)
		nVal = 1;
	else
		nVal = 2;

	cpyBd(tmpBd,arrBd);

	for(int i = nI ; i < nI_ ; i ++ )
	{
		for(int j = nJ ; j < nJ_ ; j ++ )
		{
			if(tmpBd[i][j] == 3)
			{
				doReverse(tmpBd,j,i,isTurn);
				
				for(int k = 0 ; k < 8 ; k ++ )
				{
					for(int l = 0 ; l < 8 ; l ++ )
					{
						if(tmpBd[k][l] == nVal)
							arrBdCnt[i][j] += 1;
					}
				}

				cpyBd(tmpBd,arrBd);
				nMin = arrBdCnt[i][j];
			}
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMin >= arrBdCnt[i][j] && arrBd[i][j] == 3)
				nMin = arrBdCnt[i][j];
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMin == arrBdCnt[i][j])
			{
				*pX = j;
				*pY = i;
				return ;
			}
		}
	}
}
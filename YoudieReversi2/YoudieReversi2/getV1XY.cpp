#include "stdafx.h"

void C_REVERSI :: getV1XY(int (*arrBd)[8], int *pX, int *pY, bool isTurn)
{
	int nMax = -3000;

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(arrBd[i][j] == 3)
			{
				if(nMax <= getBdScore(arrBd,j,i,isTurn))
				{
					nMax = getBdScore(arrBd,j,i,isTurn);
					m_arrBdScore[i][j] = getBdScore(arrBd,j,i,isTurn);
				}
				//printf("m_arrBdScore[%d][%d]: %d\n",i,j,getBdScore(arrBd,j,i,isTurn));
			}
		}
	}
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(m_arrBdStat[i][j] == 3)
			{
				if(m_arrBdScore[i][j] == nMax)
				{
					*pX = j;
					*pY = i;
					return ;
				}
			}
		}
	}
}
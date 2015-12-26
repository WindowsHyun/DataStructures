#include "stdafx.h"

void C_REVERSI :: getV4XY(int (*arrBd)[8], int *pX, int *pY, bool isTurn)
{
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			m_arrBdScore[i][j] = 0;
		}
	} 

	int tmpBd[8][8] = {0};
	int tmpBdScore[8][8] = {0};
	int nMax = -1000;


	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			tmpBd[i][j] = arrBd[i][j];
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(tmpBd[i][j] == 3)
			{
				if( (i==0 && j==0) || (i==7 && j==7) || (i==0 && j==7) || (i==7 && j==0) )
				{
					*pX = j;
					*pY = i;
					return ;
				}
			}
		}
	}

	if(isWall(tmpBd) == true && m_nTurnCnt < 26)
		m_nTurnCnt = 26;
	//printf("%d",m_nTurnCnt); Sleep(10000);

	if(m_nTurnCnt <  100 /*26*/)
	{
		getMinReverseXY(arrBd,pX,pY,isTurn);
		tmpBdScore[*pY][*pX] ++;
		getMergeDiskXY(arrBd,pX,pY,isTurn);
		tmpBdScore[*pY][*pX] ++;
		getLowWallXY(arrBd,pX,pY,isTurn);
		tmpBdScore[*pY][*pX] ++;
	}

	cpyBd(m_arrBdScore,tmpBdScore);
	/*else if(m_nTurnCnt >= 26 && m_nTurnCnt <= 50)
	{

	}
	else
	{

	}*/
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMax <= m_arrBdScore[i][j] && m_arrBdStat[i][j] == 3)
				nMax = m_arrBdScore[i][j];
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMax == m_arrBdScore[i][j])
			{
				printf("nY:%d nX:%d",i,j);Sleep(1000);
				*pX = j;
				*pY = i;
				return ;
			}
		}
	}
}
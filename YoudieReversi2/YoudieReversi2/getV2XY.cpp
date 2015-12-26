#include "stdafx.h"

void C_REVERSI :: getV2XY(int (*arrBd)[8],int *pX, int *pY, bool isTurn)
{
	int tmpBd[8][8];
	int tmpScore[8][8] = {0};
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			tmpBd[i][j] = m_arrBdStat[i][j];
		}
	}
	/*for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			printf("%2d",tmpBd[i][j]);
		}
		printf("\n");
	}
	Sleep(100000);*/
	initBdScore(tmpScore);

	releaseIsReverse(tmpBd);
	initIsReverse(tmpBd,isTurn);
	
	int nMax = -3000;

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(tmpBd[i][j] == 3)
			{
				tmpScore[i][j] = getBdScore(tmpBd,j,i,isTurn);

				doReverse(tmpBd,j,i,isTurn);
				releaseIsReverse(tmpBd);
				initIsReverse(tmpBd,!isTurn);
				
				for(int k = 0 ; k < 8 ; k ++ )
				{
					for(int l = 0 ; l < 8 ; l ++ )
					{
						if(tmpBd[k][l] == 3)
							if(nMax <= getBdScore(tmpBd,l,k,!isTurn))
								nMax = getBdScore(tmpBd,l,k,!isTurn);
					}
				}

				tmpScore[i][j] -= nMax;
				m_arrBdScore[i][j] = tmpScore[i][j];

			//	printf("tmpScore[%d][%d]: %d\n",i,j,tmpScore[i][j]);
				for(int m = 0 ; m < 8 ; m ++ )
				{
					for(int n = 0 ; n < 8 ; n ++ )
					{
						tmpBd[m][n] = m_arrBdStat[m][n];
					}
				}

				releaseIsReverse(tmpBd);
				initIsReverse(tmpBd,isTurn);
			}
		}
	}

	int nMaxScore = -3000;

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMaxScore <= m_arrBdScore[i][j] && m_arrBdStat[i][j] == 3)
				nMaxScore = m_arrBdScore[i][j];
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMaxScore == m_arrBdScore[i][j] && m_arrBdStat[i][j] == 3)
			{	
				*pX = j;
				*pY = i;
				return ;
			}
		}
	}
}
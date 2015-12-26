#include "stdafx.h"

void C_REVERSI :: getV3XY(int (*arrBd)[8], int *pX, int *pY, bool isTurn)
{
	int tmpBd[8][8];
	int nMax = -1000;
	int nMin;

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
				doReverse(tmpBd,j,i,isTurn);
				releaseIsReverse(tmpBd);
				initIsReverse(tmpBd,!isTurn);
				/*for(int i = 0 ; i < 8 ; i ++ )
				{
					for(int j = 0 ; j < 8 ; j ++ )
					{
						printf("%2d",tmpBd[i][j]);
					}
					printf("\n");
				}
				Sleep(10000);*/
				
				for(int k = 0 ; k < 8 ; k ++ )
				{
					for(int l = 0 ; l < 8 ; l ++ )
					{
						if(tmpBd[k][l] == 3)
						{
							if(nMax < getBdScore(tmpBd,l,k,!isTurn))
							{
								nMax = getBdScore(tmpBd,l,k,!isTurn);
							}
						}
					}
				}
				m_arrBdScore[i][j] = nMax;
			}
			for(int m = 0 ; m < 8 ; m ++ )
			{
				for(int n = 0 ; n < 8 ; n ++ )
				{
					tmpBd[m][n] = arrBd[m][n];
				}
			} 
		}
	}

	nMin = nMax;

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(m_arrBdScore[i][j] <= nMin && arrBd[i][j] == 3)
				nMin = m_arrBdScore[i][j];
		}
	}
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(m_arrBdScore[i][j] == nMin && arrBd[i][j] == 3)
			{
				*pX = j;
				*pY = i;
				return ;
			}
		}
	}

	/*for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			printf("%4d",tmpScore[i][j]);
		}
		printf("\n");
	}

	Sleep(100000);*/
}
#include "stdafx.h"

bool C_REVERSI :: getLowWallXY(int (*arrBd)[8], int *pX, int *pY, bool isTurn)
{
	int tmpBd[8][8] = {0};
	int arrBdCnt[8][8] = {0};
	int nCnt = 0;
	int nMin = 0;
	int nVal = 0;

	if(isTurn)
		nVal = 1;
	else
		nVal = 2;


	cpyBd(tmpBd,arrBd);

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(tmpBd[i][j] == 3)
			{
				doReverse(tmpBd,j,i,isTurn);
				releaseIsReverse(tmpBd);

				if(isTurn)
				{
					for(int k = 1 ; k < 7 ; k ++ )
					{
						for(int l = 1 ; l < 7 ; l ++ )
						{
							if(tmpBd[k][l]  == 1)
							{
								if(tmpBd[k-1][l] == 0)
								{
									nCnt++;
								}
								if(tmpBd[k+1][l] == 0)
								{
									nCnt++;
								}
								if(tmpBd[k][l-1] == 0)
								{
									nCnt++;
								}
								if(tmpBd[k][l+1] == 0)
								{
									nCnt++;
								}
							}
							
						}
					}
				}
				else if(!isTurn)
				{
					for(int k = 1 ; k < 7 ; k ++ )
					{
						for(int l = 1 ; l < 7 ; l ++ )
						{
							if(tmpBd[k][l]  == 2)
							{
								if(tmpBd[k-1][l] == 0)
								{
									nCnt++;
								}
								if(tmpBd[k+1][l] == 0)
								{
									nCnt++;
								}
								if(tmpBd[k][l-1] == 0)
								{
									nCnt++;
								}
								if(tmpBd[k][l+1] == 0)
								{
									nCnt++;
								}
							}
							
						}
					}
				}
				arrBdCnt[i][j] = nCnt;
				nMin = arrBdCnt[i][j];
				nCnt = 0;

				cpyBd(tmpBd,arrBd);
			}
			
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMin >= arrBdCnt[i][j] && arrBd[i][j] == 3 )
				nMin = arrBdCnt[i][j];
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(nMin == arrBdCnt[i][j] )
			{
				*pX = j;
				*pY = i;
				return true;
			}
		}
	}

	return false;
}
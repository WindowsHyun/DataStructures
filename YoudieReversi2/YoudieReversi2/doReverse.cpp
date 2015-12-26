#include "stdafx.h"

void C_REVERSI :: doReverse(int (*arrBd)[8],int nX, int nY, bool isTurn)
{
	int nCnt;
	int nPivotPos1;
	int nPivotPos2;
	int nSrc;
	int nDest;

	/// initialize ///

	nCnt = 0;
	nPivotPos1 = 0;
	nPivotPos2 = 0;
	if(isTurn == true)
	{
		nSrc = 1; 
		nDest = 2;
	}
	else
	{
		nSrc = 2;
		nDest = 1;
	}
	if(arrBd[nY][nX] == 1)
		return ;
	if(arrBd[nY][nX] == 2)
		return ;
	////////////////////

	nPivotPos1 = nX; //  <- 검사
	while(arrBd[nY][nPivotPos1 - 1] == nDest && nPivotPos1 > 1)
	{
		nPivotPos1 --; nCnt ++;
	}
	if(arrBd[nY][nPivotPos1 - 1] == nSrc && nCnt > 0 )
	{
		for(nPivotPos1 ; nPivotPos1 <= nX ; nPivotPos1++)
		{
			arrBd[nY][nPivotPos1] = nSrc;
		}
	}
	nCnt = 0;

	nPivotPos1 = nX; //  -> 검사
	while(arrBd[nY][nPivotPos1 + 1] == nDest && nPivotPos1 < 6)
	{
		nPivotPos1 ++; nCnt ++;
	}
	if(arrBd[nY][nPivotPos1 + 1] == nSrc && nCnt > 0 )
	{
		for(nPivotPos1 ; nPivotPos1 >= nX ; nPivotPos1--)
		{
			arrBd[nY][nPivotPos1] = nSrc;
		}
	}
	nCnt = 0;

	nPivotPos1 = nY; //  ↑ 검사
	while(arrBd[nPivotPos1 - 1][nX] == nDest && nPivotPos1 > 1)
	{
		nPivotPos1 --; nCnt ++;
	}
	if(arrBd[nPivotPos1 - 1][nX] == nSrc && nCnt > 0 )
	{
		for(nPivotPos1 ; nPivotPos1 <= nY ; nPivotPos1++)
		{
			arrBd[nPivotPos1][nX] = nSrc;
		}
	}
	nCnt = 0;

	nPivotPos1 = nY; //  ↓ 검사
	while(arrBd[nPivotPos1 + 1][nX] == nDest && nPivotPos1 < 6)
	{
		nPivotPos1 ++; nCnt ++;
	}
	if(arrBd[nPivotPos1 + 1][nX] == nSrc && nCnt > 0 )
	{
		for(nPivotPos1 ; nPivotPos1 >= nY ; nPivotPos1--)
		{
			arrBd[nPivotPos1][nX] = nSrc; /*printf("check↓\n");Sleep(1000);*/
		}
	}
	nCnt = 0;

	nPivotPos1 = nY; //
	nPivotPos2 = nX; //  ↘ 검사
	while(arrBd[nPivotPos1 + 1][nPivotPos2 + 1] == nDest && nPivotPos1 < 6 && nPivotPos2 < 6)
	{
		nPivotPos1 ++;
		nPivotPos2 ++;
		nCnt ++;
	}
	if(arrBd[nPivotPos1 + 1][nPivotPos2 + 1] == nSrc && nCnt > 0 )
	{
		for(nPivotPos1 ; nPivotPos1 >= nY ; nPivotPos1--,nPivotPos2 --)
		{
			arrBd[nPivotPos1][nPivotPos2] = nSrc;
		}
	}
	nCnt = 0;

	nPivotPos1 = nY; //
	nPivotPos2 = nX; //  ↖ 검사
	while(arrBd[nPivotPos1 - 1][nPivotPos2 - 1] == nDest && nPivotPos1 > 1 && nPivotPos2 > 1)
	{
		nPivotPos1 --;
		nPivotPos2 --;
		nCnt ++;
	}
	if(arrBd[nPivotPos1 - 1][nPivotPos2 - 1] == nSrc && nCnt > 0 )
	{
		for(nPivotPos1 ; nPivotPos1 <= nY ; nPivotPos1++,nPivotPos2 ++)
		{
			arrBd[nPivotPos1][nPivotPos2] = nSrc;
		}
	}
	nCnt = 0;

	nPivotPos1 = nY; //
	nPivotPos2 = nX; //  ↗ 검사
	while(arrBd[nPivotPos1 - 1][nPivotPos2 + 1] == nDest && nPivotPos1 > 1 && nPivotPos2 < 6 )
	{
		nPivotPos1 --;
		nPivotPos2 ++;
		nCnt ++;
	}
	if(arrBd[nPivotPos1 - 1][nPivotPos2 + 1] == nSrc && nCnt > 0 )
	{
		for(nPivotPos1 ; nPivotPos1 <= nY ; nPivotPos1++,nPivotPos2 --)
		{
			arrBd[nPivotPos1][nPivotPos2] = nSrc;
		}
	}
	nCnt = 0;

	nPivotPos1 = nY; //
	nPivotPos2 = nX; //  ↙ 검사
	while(arrBd[nPivotPos1 + 1][nPivotPos2 - 1] == nDest && nPivotPos1 < 6  && nPivotPos2 > 1 )
	{
		nPivotPos1 ++;
		nPivotPos2 --;
		nCnt ++;
	}
	if(arrBd[nPivotPos1 + 1][nPivotPos2 - 1] == nSrc && nCnt > 0 )
	{
		for(nPivotPos2 ; nPivotPos2 <= nX ; nPivotPos2++,nPivotPos1 --)
		{
			arrBd[nPivotPos1][nPivotPos2] = nSrc;
		}
	}

}
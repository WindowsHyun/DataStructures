#include "stdafx.h"

void C_REVERSI:: printResult()
{
	int nBCnt;
	int nWCnt;

	nBCnt = 0;
	nWCnt = 0;

	for(int i  = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(m_arrBdStat[i][j] == 1)
				nBCnt ++;
			else if(m_arrBdStat[i][j] == 2)
				nWCnt ++;
		}
	}
	system("cls");
	printf(" Youdie Reversi\n");
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(m_arrBdStat[i][j] == 0)
				printf("¦«");
			if(m_arrBdStat[i][j] == 1)
				printf("¡Ü");
			if(m_arrBdStat[i][j] == 2)
				printf("¡Û");
			if(m_arrBdStat[i][j] == 3)
				printf("¦«");
		}
		printf("\n");
	}
	printf("¡Ü%2d : %2d¡Û", nBCnt, nWCnt);
	printf("\n\n");

	if(nBCnt > nWCnt)
		printf("Ai '1' ½Â!\n");
	else if(nBCnt < nWCnt)
		printf("Ai '2' ½Â!\n");
	else
		printf("¹«½ÂºÎ!\n");
}

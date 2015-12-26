#include "stdafx.h"

bool C_REVERSI:: isGameEnd(int *pTurnCnt)
{
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(m_arrBdStat[i][j] == 3)
			{
				*pTurnCnt = 0;
				return false;
			}
		}
	}
	
	printf("둘자리 없음!\n");
	Sleep(100);

	m_isGameTurn == true ? m_isGameTurn = true : m_isGameTurn = false;
	*pTurnCnt += 1;

	for(int i = 0 ; i < 8 ; i ++)
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(isReverse(m_arrBdStat,j,i,m_isGameTurn))
				m_arrBdStat[i][j] = 3;
		}
	}

	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++ )
		{
			if(m_arrBdStat[i][j] == 3)
			{
				*pTurnCnt = 0;
				return false;
			}
		}
	}

	*pTurnCnt += 1;

	if(*pTurnCnt == 2)
		return true;
}
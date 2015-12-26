#include "stdafx.h"

void C_REVERSI :: printM_BdStat()
{
	printf(":m_arrBdStat:\n");
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++)
		{
			printf("%2d",m_arrBdStat[i][j]);
		}
		printf("\n");
	}
}
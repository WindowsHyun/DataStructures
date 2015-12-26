#include "stdafx.h"

void C_REVERSI :: printM_BdScore()
{
	printf(":m_arrBdScore:\n");
	for(int i = 0 ; i < 8 ; i ++ )
	{
		for(int j = 0 ; j < 8 ; j ++)
		{
			printf("%-4d",m_arrBdScore[i][j]);
		}
		printf("\n");
	}
}
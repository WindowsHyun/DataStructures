#include "stdafx.h"

void C_REVERSI :: BlackAttack(int *pPosX,int *pPosY)
{
	releaseIsReverse(m_arrBdStat);
	initIsReverse(m_arrBdStat,m_isGameTurn);
	initMemBdScore();
	updateBd();
	//getV1XY(m_arrBdStat,pPosX,pPosY,m_isGameTurn); // v1
	//getV2XY(m_arrBdStat,pPosX,pPosY,m_isGameTurn); // v2
	getV3XY(m_arrBdStat,pPosX,pPosY,m_isGameTurn); // v3
	//getV4XY(m_arrBdStat,pPosX,pPosY,m_isGameTurn); // v4
}
#include "stdafx.h"

void C_REVERSI :: BlackDefense(int nPosX, int nPoY)
{
	doReverse(m_arrBdStat,nPosX,nPoY,m_isGameTurn);
	changeTurn();
	/*releaseIsReverse(m_arrBdStat);	
	initIsReverse(m_arrBdStat,m_isGameTurn);*/
	updateBd();
}
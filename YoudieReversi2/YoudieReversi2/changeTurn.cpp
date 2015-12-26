#include "stdafx.h"

void C_REVERSI:: changeTurn()
{
	if(m_isGameTurn == true)
		m_isGameTurn = false;
	else
		m_isGameTurn = true;
}
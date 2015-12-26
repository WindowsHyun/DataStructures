// YoudieReversi2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
	int nTurnCnt = 0;
	int nPosX = 0;
	int nPosY = 0;
	int nKey = 0;
	int nInput = 0;

	C_REVERSI cRvs;
	cRvs.updateBd();

	while(1)
	{
		if(_kbhit())
		{
			nKey = _getch();

			if(cRvs.isGameEnd(&nTurnCnt))
				break;

			if(nKey == 13)
			{
				if(cRvs.getNowturn())
				{
					cRvs.BlackAttack(&nPosX,&nPosY);
					/*printf("nPosY : %d, nPosX:%d\n",nPosY,nPosX);
					cRvs.printM_BdStat();
					cRvs.printM_BdScore();
					scanf("%d", &nInput);*/
					cRvs.WhiteDefense(nPosX,nPosY);
				}
				else
				{
					cRvs.WhiteAttack(&nPosX,&nPosY);
					/*printf("nPosY : %d, nPosX:%d\n",nPosY,nPosX);
					cRvs.printM_BdStat();
					cRvs.printM_BdScore();
					scanf("%d", &nInput);*/
					cRvs.BlackDefense(nPosX,nPosY);
				}
				cRvs.addTurnCnt();
			}
		}
	}

	cRvs.printResult();

	return 0;
}


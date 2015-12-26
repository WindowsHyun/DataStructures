#pragma once

class C_REVERSI
{
private:
	int m_arrBdStat[8][8];
	int m_arrBdScore[8][8];
	bool m_isGameTurn;
	int m_nTurnCnt;
public:
	C_REVERSI()
	{
		for(int i = 0 ; i < 8 ; i ++ )
		{
			for(int j = 0 ; j < 8 ; j ++ )
			{
				m_arrBdStat[i][j] = 0;
				m_arrBdScore[i][j] = 0;
			}
		}
		m_arrBdStat[3][3] = 2; m_arrBdStat[3][4] = 1;
		m_arrBdStat[4][3] = 1; m_arrBdStat[4][4] = 2;
		m_isGameTurn = true;
		initIsReverse(m_arrBdStat,m_isGameTurn);
		m_nTurnCnt = 0;
	}

	void initMemBdScore();
	void initBdScore(int (*arrBd)[8]);
	void initBdScore2(int (*arrBd)[8]);
	int getBdScore(int (*arrBd)[8],int nX,int nY, bool isTurn);
	bool isReverse(int (*arrBd)[8],int nX, int nY, bool isTurn);
	void doReverse(int (*arrBd)[8],int nX, int nY, bool isTurn);
	void changeTurn();
	bool getNowturn();
	void cpyBd(int (*cpyedBd)[8], int (*mainBd)[8]);
	void initIsReverse(int (*arrBd)[8], bool isTurn);
	void releaseIsReverse(int (*arrBd)[8]);
	void getV1XY(int (*arrBd)[8], int *pX, int *pY, bool isTurn);
	void getV2XY(int (*arrBd)[8], int *pX, int *pY, bool isTurn);
	void getV3XY(int (*arrBd)[8], int *pX, int *pY, bool isTurn);
	void getV4XY(int (*arrBd)[8], int *pX, int *pY, bool isTurn);
	void addTurnCnt();
	void printBd(int (*arrBd)[8]);

	//Example
	void printM_BdStat();
	void printM_BdScore();

	//Conditions
	bool isWall(int (*arrBd)[8]);
	void getMinReverseXY(int (*arrBd)[8], int *pX, int *pY, bool isTurn);
	void getMinReverseXYRange(int (*arrBd)[8], int *pX, int *pY,int nI ,int nI_,int nJ, int nJ_,bool isTurn);
	void getMergeDiskXY(int (*arrBd)[8], int *pX, int *pY, bool isTurn);
	bool getLowWallXY(int (*arrBd)[8], int *pX, int *pY, bool isTurn);

	void BlackAttack(int *pPosX, int *pPosY);
	void BlackDefense(int nPosX, int nPosY);

	void WhiteAttack(int *pPosX, int *pPosY);
	void WhiteDefense(int nPosX, int nPosY);

	bool isGameEnd(int *pTurnCnt);
	void updateBd();
	void printResult();
};
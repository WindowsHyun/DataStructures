#ifndef _ATTACK_SH_W_H_
#define _ATTACK_SH_W_H_
#include "OdeloBattleSystem.h"
#include<time.h>

//���� ���� -1�� ���´�. 



int WhiteBoard[g_nMax][g_nMax] = {0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0,
									  0,0,0,1,2,0,0,0,
									  0,0,0,2,1,0,0,0,
								      0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0}; //8x8

void W_MyPutStone(int* x, int* y,int Board[8][8],int nNum)
{
	/*
	1)�ϴ� �� �Լ��� �����Լ������� ���۵ǰ� ���潺�Լ������� ���۵�
	2)��, �����Լ����� ���� ���� �ΰ� ���潺 �Լ����� �� ���� �дٰ� �����ϸ� ��
	*/
	int nX, nY; //�˻��� ���� Ű�� ���� x,y��ǥ�� ������ ������
	int nDir = 0, nChange = 0;
	int nDelta_x[8] = {1,1,0,-1,-1,-1,0,1};//����˻� x��ǥ
	int nDelta_y[8] = {0,1,1,1,0,-1,-1,-1};//����˻� y��ǥ
	int nI,nJ; 
	
	for(nDir = 0; nDir < 8 ; nDir++) //8���� ��� �˻��ϱ� ����
	{
		nX = *x; //Ű������ ���� x�� xi�� ����
		nY = *y; //Ű������ ���� y�� yi�� ����
		nJ = 0; //���� ���⿡�� ���ӵ� ����� �� �� 

		for( nI = 0; nI < 7; nI++) //�ڱ� �ڽ��� �����ϰ� 7��
		{
			nX += nDelta_x[nDir];
			nY += nDelta_y[nDir];

			if(nX < 0 || nX > 7 || nY < 0 || nY > 7 || Board[nY][nX] == NULL)
				break;
			
			if(Board[nY][nX] == nNum)
			{
				for( ; nI > 0 ; nI--)
				{
					nX -= nDelta_x[nDir];
					nY -= nDelta_y[nDir];
					Board[nY][nX] = nNum;
				}
				nChange += nJ;
				break;
			}
			nJ++; //���� �ִ� ��++
		}		
	}
	if(nChange != 0)
	{
		Board[*y][*x] = nNum;
	}
	else if(nChange == 0)
	{
		return;
	}
}
int wDirectionCheck(int* x, int* y, int Board[8][8])
{
	/*
	1)���� ���� ������ ���� �δµ�  8���� �˻縦 ���� ���� �� �ִ� �� ���� ���ϴ� ���� �˾Ƴ���
	  ���� ���ϴ� ���� ��� ���� ���� ã�Ƽ� �д�.
	*/
	int xi; //���� x,y��ǥ�� �����ؾ���
	int yi;
	int delta_x[8] = {1,1,0,-1,-1,-1,0,1}; //8����˻� x
	int delta_y[8] = {0,1,1,1,0,-1,-1,-1}; //8����˻� y
	int dir = 0;
	int i,j;
	int change = 0;
	
	for(dir = 0; dir < 8 ; dir++)
	{
		xi = *x;
		yi = *y;

		j = 0; //���� ���⿡�� ���ӵ� ����� �� ��
		
		for( i = 0 ; i < 7 ; i++)
		{
			xi += delta_x[dir];
			yi += delta_y[dir];

			if(xi < 0 || xi > 7 || yi < 0 || yi > 7 || Board[yi][xi] == 0)
			{//������ ����� ���߰�.
				break;
			}

			if(Board[yi][xi] == 2)//Ž�� �� �鵹�� ���� �ִٸ�
			{
				for( ; i > 0 ; i--) //�ݴ�� Ž���ϸ鼭
				{
					if(Board[yi][xi] == 0) break;
					xi = delta_x[dir];
					yi = delta_y[dir];
					Board[*y][*x] = 2; //�߰��� �ִ� ��� ���� �鵹�� �ٲٰ�
				}
				change += j; //�� ���� change�� �����Ѵ�.
				break;
			}
			j++;
		}
	}
	if(change != 0) //�ٲ�� �ִ� ���� �ִ� ��쿡�� ���� ���´�.
	{
		cout << change << endl;
		W_MyPutStone(x,y,WhiteBoard,2);
			
		return 1;
	}
	//else if(change != 0)
	//{
	//	//���� �ٲ� �� �ִ� ��� �켱������ �д�.
		//change���� ���� ��� �������� ���� �ΰ� �Ѵ�.
	//	return 1;
	//}
	else if(change == 0)
	{
		return -1;
	}

	return -1;
}

void wOdeloAI(int *x, int *y)
{
	int xi = 0;
	int yi = 0;
	int nTest;

	while(1)
	{
		*x = rand()%8;
		*y = rand()%8;

		if(WhiteBoard[*y][*x] == 0)
		{	
			return;
		}

	}

}


void WhiteAttack( int *x, int *y )
{
	//srand((unsigned int)time(NULL));
		
	int nNum;
	int nTest = 0;
	int xi = 0 , yi = 0;

	while(1)
	{
		xi = -1;
		yi = -1;
		wOdeloAI(&xi, &yi);
		nTest = wDirectionCheck(&xi,&yi,WhiteBoard);

		if(nTest != -1)
		{	
			*x = xi;
			*y = yi;
			break;
		}
		if(nTest == 0)
		{
			*x = -1;
			*y = -1;
			break;
		}
	}

	nNum = 2;

	/*cout << *x <<" "<< *y << endl;
	for(int i = 0 ; i < 8 ; i ++)
	{
		for(int j = 0 ; j < 8; j++)
		{
			cout << BlackBoard[i][j];
		}
		cout << endl;
	}*/
	//Sleep(1000);
	
}

void WhiteDefence( int x, int y )
{
	/*
	1)���⼭�� ���� ���α׷����� �Ѱ��� �鵹�� ��ǥ�� �޾Ƽ� �� ������ �ǿ��ٰ� �дٰ� �����ϸ� ��
	2)���⼭ �� ������ ���� Attack�Լ����� ����, �浹�� ���� �� ������ ������.
	3)�� ���⼭�� BlackBoard�� ������ ����ؼ� ������Ʈ �� ��������.
	*/
	//cout << "BlackBoard�� ����(�鵹�� �� ��ġ)" <<endl;
	//cout <<"( "<< x << "," << y<<" )" << endl;
	int nNum;
	nNum = 1;
	W_MyPutStone(&x,&y,WhiteBoard,nNum);
	//BlackBoard[y][x] = 2;

}

#endif
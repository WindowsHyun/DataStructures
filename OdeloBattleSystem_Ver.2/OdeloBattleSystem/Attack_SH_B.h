/*
Bug Reporting
1)흑에서 백으로 값을 넘겨줄 때에는 이상이 없는 듯 보임 (해결)
2)백에서 흑으로 값을 넘겨 줄 때에 돌이 BlackBoard의 돌들이 뒤집히지 않음 (해결)
3)백에서 흑으로 값을 넘겨 줄 때에 이상한 위치에 값이 저장됨 (해결)

New Bug
1)자꾸 말도안되는 곳에 돌을 놓음 ㅡㅡ(해결)
2)둘 자리가 없을 때 -1 -1을 리턴못해서 팅김 (해결)

*/
#include <time.h>

#ifndef _ATTACK_SH_B_H_
#define _ATTACK_SH_B_H_

#include "OdeloBattleSystem.h"

typedef struct Odelo_Count
{
	int Attack_Point;
	bool check_position;
}OC;

OC Black_Attack_Check[g_nMax][g_nMax];
OC White_Attack_Check[g_nMax][g_nMax];

//돌이 들어가면 -1로 놓는다. 
int BlackBoard[g_nMax][g_nMax] = {0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0,
									  0,0,0,1,2,0,0,0,
									  0,0,0,2,1,0,0,0,
								      0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0,
									  0,0,0,0,0,0,0,0}; //8x8

void B_MyPutStone(int* x, int* y,int Board[8][8],int nNum)
{
	/*
	1)일단 이 함수는 어택함수에서도 동작되고 디펜스함수에서도 동작됨
	2)즉, 어택함수에서 검은 돌을 두고 디펜스 함수에서 흰 돌을 둔다고 생각하면 됨
	*/
	int nX, nY; //검사을 위해 키로 받은 x,y좌표를 저장할 변수들
	int nDir = 0, nChange = 0;
	int nDelta_x[8] = {1,1,0,-1,-1,-1,0,1};//방향검사 x좌표
	int nDelta_y[8] = {0,1,1,1,0,-1,-1,-1};//방향검사 y좌표
	int nI,nJ; 
	
	for(nDir = 0; nDir < 8 ; nDir++) //8방향 모두 검사하기 위해
	{
		nX = *x; //키값으로 받은 x를 xi에 저장
		nY = *y; //키값으로 받은 y를 yi에 저장
		nJ = 0; //현재 방향에서 연속된 상대의 돌 수 

		for( nI = 0; nI < 7; nI++) //자기 자신을 제외하고 7번
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
			nJ++; //값이 있는 돌++
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
int DirectionCheck(int* x, int* y, int Board[8][8])
{
	/*
	1)먼저 돌을 적당한 곳에 두는데  8방향 검사를 통해 놓을 수 있는 곳 놓지 못하는 곳을 알아내서
	  두지 못하는 곳일 경우 다음 값을 찾아서 둔다.
	*/
	int xi; //받은 x,y좌표를 저장해야함
	int yi;
	int delta_x[8] = {1,1,0,-1,-1,-1,0,1}; //8방향검사 x
	int delta_y[8] = {0,1,1,1,0,-1,-1,-1}; //8방향검사 y
	int dir = 0;
	int i,j;
	int change = 0;
	
	for(dir = 0; dir < 8 ; dir++)
	{
		xi = *x;
		yi = *y;

		j = 0; //현재 방향에서 연속된 상대의 돌 수
		
		for( i = 0 ; i < 7 ; i++)
		{
			xi += delta_x[dir];
			yi += delta_y[dir];

			if(xi < 0 || xi > 7 || yi < 0 || yi > 7 || Board[yi][xi] == 0)
			{//범위를 벗어나면 멈추고.
				break;
			}

			if(Board[yi][xi] == 1)//탐색 중 흑돌의 값이 있다면
			{
				for( ; i > 0 ; i--) //반대로 탐색하면서
				{
					if(Board[yi][xi] == 0) break;
					xi = delta_x[dir];
					yi = delta_y[dir];
					Board[*y][*x] = 1; //중간에 있는 모든 돌을 흑돌로 바꾸고
				}
				change += j; //그 값을 change에 저장한다.
				break;
			}
			j++;
		}
	}
	if(change != 0) //바뀔수 있는 돌이 있는 경우에만 돌을 놓는다.
	{
		cout << change << endl;
		B_MyPutStone(x,y,BlackBoard,1);
			
		return 1;
	}
	//else if(change != 0)
	//{
	//	//돌이 바뀔 수 있는 경우 우선순위를 둔다.
		//change값이 많은 경우 그쪽으로 돌을 두게 한다.
	//	return 1;
	//}
	else if(change == 0)
	{
		return -1;
	}

	return -1;
}

void OdeloAI(int *x, int *y)
{
	int xi = 0;
	int yi = 0;
	int nTest;

	while(1)
	{
		*x = rand()%8;
		*y = rand()%8;

		if(BlackBoard[*y][*x] == 0)
		{	
			return;
		}

	}

}


void BlackAttack( int *x, int *y )
{

	srand((unsigned int)time(NULL));
		
	int nNum;
	int nTest = 0;
	int xi = 0 , yi = 0;

	while(1)
	{
		xi = -1;
		yi = -1;
		OdeloAI(&xi, &yi);
		nTest = DirectionCheck(&xi,&yi,BlackBoard);

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

	nNum = 1;

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

void BlackDefence( int x, int y )
{
	/*
	1)여기서는 심판 프로그램에서 넘겨준 백돌의 좌표를 받아서 내 오셀로 판에다가 둔다고 생각하면 됨
	2)여기서 둔 정보를 토대로 Attack함수에서 다음, 흑돌을 어디다 둘 것인지 결정함.
	3)즉 여기서는 BlackBoard의 정보를 계속해서 업데이트 해 나가야함.
	*/
	//cout << "BlackBoard의 정보(백돌이 둔 위치)" <<endl;
	//cout <<"( "<< x << "," << y<<" )" << endl;
	int nNum;
	nNum = 2;
	B_MyPutStone(&x,&y,BlackBoard,nNum);
	//BlackBoard[y][x] = 2;

}

#endif
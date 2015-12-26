/*오델로 만들기~

1. 판을 만든다 8x8------------성공
2. 좌표를 입력받아 판에 돌을 놓기---성공
3.검은색 흰돌 번갈아 놓도록 수정.---성공
4.바둑판에 놓인 검은 돌의 개수와 흰돌의 개수가 출력되도록 수정.-----------은근 어려벙

*/
#include <stdio.h>
#include <windows.h>

int Os[8][8];
int turncount=0;
int countO = 0;
int countX = 0;
int empty = 0;

int main()
{
	//판 그릴 배열이랑 정보 저장 배열
	int Os[8][8]={0};
	int O[8][8]={0};

	Os[3][3]=1;
	Os[4][4]=1;
	Os[3][4]=2;
	Os[4][3]=2;


	int i = 0;
	int j = 0;

	int putx = 0;
	int puty = 0;

	while(1)
	{

		system("cls");
		//		system("chcp 949");

		printf("\n\n");
		printf("  1 2 3 4 5 6 7 8\n"); //판의 숫자를 그릴떄 제일 윗줄
		//판 그리기
		for(i = 0; i < 8 ; ++i )
		{	
			for(j = 0; j <8; ++j)
			{	
				if(j==0){ //j=0즉 가로가 첫번째일경우 
					printf("%d ",i+1); // 가로열 첫번째의 세로열을 출력한다.
				}
				if(Os[j][i] == 1)
				{
					O[j][i]='X';
					printf("%c ",O[j][i]);

				}
				else if(Os[j][i]==2)
				{
					O[j][i]='O';
					printf("%c ",O[j][i]);

				} 
				else if(Os[j][i]==0)
				{	
					O[j][i]='+';				
					printf("%c ",O[j][i]);

				}			
			}
			printf("\n");

		}

		countO = 0;
		countX = 0;
		// 놓을때마다 확인을 해야하므로 계속 초기화한다.
		for(i = 0; i < 8 ; ++i ){	
			for(j = 0; j <8; ++j){	
				if(O[j][i]=='X')
					++countX; // 8*8배열에서 X가 있으면 CountX를 1씩올린다.
			}
		}

		for(i = 0; i < 8 ; ++i ){	
			for(j = 0; j <8; ++j){	
				if(O[j][i]=='O')
					++countO;
			}
		}

		printf("\nX : %d, O : %d \n\n", countX, countO);

		printf("x좌표를 입력하고 엔터를 치세요 : ");
		scanf("%d",&putx);
		printf("y 좌표를 입력하고 엔터를 치세요 : ");
		scanf("%d",&puty);

		if((putx > 8)||( puty > 8)||(putx < 1)||(puty < 1))
		{
			printf("1부터 8까지수 입력해! \n");
		}	
		else if(turncount %2 == 0)
		{
			Os[putx-1][puty-1] = 2;
		}
		else if(turncount %2 ==1)
		{
			Os[putx-1][puty-1] = 1;
		}


		for(i=0;i<8;++i)
		{
			for(j=0;j<8;++j)
			{
				if(O[j][i]=='X')
				{
					countX++;
				}
				else if(O[j][i]=='O')
				{
					countO++;
				}

				else if(O[j][i]=='+')
				{
					empty++;
				}

			}		
		}
		countO = 64-empty-countX ;
		countX = 64-empty-countO ;
		

		//Sleep(1000);

		turncount ++;

	}

	return 0;

}

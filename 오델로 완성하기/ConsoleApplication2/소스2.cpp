/*������ �����~

1. ���� ����� 8x8------------����
2. ��ǥ�� �Է¹޾� �ǿ� ���� ����---����
3.������ �� ������ ������ ����.---����
4.�ٵ��ǿ� ���� ���� ���� ������ ���� ������ ��µǵ��� ����.-----------���� �����

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
	//�� �׸� �迭�̶� ���� ���� �迭
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
		printf("  1 2 3 4 5 6 7 8\n"); //���� ���ڸ� �׸��� ���� ����
		//�� �׸���
		for(i = 0; i < 8 ; ++i )
		{	
			for(j = 0; j <8; ++j)
			{	
				if(j==0){ //j=0�� ���ΰ� ù��°�ϰ�� 
					printf("%d ",i+1); // ���ο� ù��°�� ���ο��� ����Ѵ�.
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
		// ���������� Ȯ���� �ؾ��ϹǷ� ��� �ʱ�ȭ�Ѵ�.
		for(i = 0; i < 8 ; ++i ){	
			for(j = 0; j <8; ++j){	
				if(O[j][i]=='X')
					++countX; // 8*8�迭���� X�� ������ CountX�� 1���ø���.
			}
		}

		for(i = 0; i < 8 ; ++i ){	
			for(j = 0; j <8; ++j){	
				if(O[j][i]=='O')
					++countO;
			}
		}

		printf("\nX : %d, O : %d \n\n", countX, countO);

		printf("x��ǥ�� �Է��ϰ� ���͸� ġ���� : ");
		scanf("%d",&putx);
		printf("y ��ǥ�� �Է��ϰ� ���͸� ġ���� : ");
		scanf("%d",&puty);

		if((putx > 8)||( puty > 8)||(putx < 1)||(puty < 1))
		{
			printf("1���� 8������ �Է���! \n");
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

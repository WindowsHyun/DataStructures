#include <stdio.h>
#include <Windows.h>
 
enum{ None, Black, White };

void isShowOdelloMap();
void isDrawBWstones(int);

int i,j;
int arr[8][8];
int numX, numY;
int isPlayUser = Black;
int isBlackNum =0;
int isWhiteNum = 0;

int main(){
	for(i=0; i <8; ++i){
		for(j=0; j<8; ++j){
			arr[i][j] =  None;
		}
	}
	arr[4][3] = Black; //������ ��
	arr[3][4] = Black; //������ ��

	arr[3][3] = White; //��� ��
	arr[4][4] = White; //��� ��
	while(1){
		system("chcp 949");
		system("cls");

		isShowOdelloMap();

		isBlackNum = 0;
		isWhiteNum = 0;

		for(i=0; i <8; ++i){
			for(j=0; j<8; ++j){
				if(arr[i][j] ==  Black)
					++isBlackNum;
				if(arr[i][j] ==  White)
					++isWhiteNum;
			}
		}
		printf("Black stones : %d, White stones : %d\n\n", isBlackNum,isWhiteNum);

		if(isPlayUser == Black){
			printf("Black ");
		}else{
			printf("White ");
		}
		printf("Coordinates ( X , Y ) : ");

		scanf_s("%d , %d",&numY, &numX); //���μ��� �Ǵ��� �߸��ؼ� �޾ƿö� �Ųٷ� �޾ƿ´�.

		if(isPlayUser == Black){
			arr[numX-1][numY-1] = Black; //������ �� [ -1�� �ϴ������� �迭�� 0���� �����ϹǷ� ]
			isPlayUser = White;
		}else{
			arr[numX-1][numY-1] = White; //��� �� [ -1�� �ϴ������� �迭�� 0���� �����ϹǷ� ]
			isPlayUser = Black;
		}


	} //while(1){
}

void isShowOdelloMap(){
	int k;
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(0);
	for(k=1; k<=6; ++k){
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(k);
	}
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(7);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n\n");
}

void isDrawBWstones(int line){
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[line][i] == None){
			printf("  ");
		}else{
			if( arr[line][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
}


/*
ó�� �ۼ��� ���� �����ϱ� ���ؼ� �����Ѱ�
printf("  ");
for(i=0; i<8; ++i){
if( arr[1][i] == 0){
printf("  ");
}else{
printf("��");
}
printf("  ");
}
printf("\n");
*/
/*
�򵹰� ������ �����ϱ� ���ؼ� �����Ѱ�
printf("  ");
for(i=0; i<8; ++i){
if( arr[0][i] == 0){
printf("  ");
}else{
if( arr[0][i] == 1){
printf("��");
}else{
printf("��");
}
}
printf("  ");
}
printf("\n");
*/
/*
��� �þ���� ���
void isShowOdelloMap(){
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[0][i] == None){
			printf("  ");
		}else{
			if( arr[0][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[1][i] == None){
			printf("  ");
		}else{
			if( arr[1][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[2][i] == None){
			printf("  ");
		}else{
			if( arr[2][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[3][i] == None){
			printf("  ");
		}else{
			if( arr[3][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[4][i] == None){
			printf("  ");
		}else{
			if( arr[4][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[5][i] == None){
			printf("  ");
		}else{
			if( arr[5][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[6][i] == None){
			printf("  ");
		}else{
			if( arr[6][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[7][i] == None){
			printf("  ");
		}else{
			if( arr[7][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n\n");
}
*/
/*
���ݴ� �ٿ���
void isShowOdelloMap(){
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(0);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(1);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(2);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(3);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(4);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(5);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(6);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(7);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n\n");
}

void isDrawBWstones(int line){
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[line][i] == None){
			printf("  ");
		}else{
			if( arr[line][i] == Black){
				printf("��");
			}else{
				printf("��");
			}
		}
		printf("  ");
	}
	printf("\n");
}
*/
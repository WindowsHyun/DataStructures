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
	arr[4][3] = Black; //검은색 돌
	arr[3][4] = Black; //검은색 돌

	arr[3][3] = White; //흰색 돌
	arr[4][4] = White; //흰색 돌
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

		scanf_s("%d , %d",&numY, &numX); //가로세로 판단을 잘못해서 받아올때 거꾸로 받아온다.

		if(isPlayUser == Black){
			arr[numX-1][numY-1] = Black; //검은색 돌 [ -1을 하는이유는 배열이 0부터 시작하므로 ]
			isPlayUser = White;
		}else{
			arr[numX-1][numY-1] = White; //흰색 돌 [ -1을 하는이유는 배열이 0부터 시작하므로 ]
			isPlayUser = Black;
		}


	} //while(1){
}

void isShowOdelloMap(){
	int k;
	printf("┌  ┬  ┬  ┬  ┬  ┬  ┬  ┬  ┐\n");
	isDrawBWstones(0);
	for(k=1; k<=6; ++k){
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(k);
	}
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(7);
	printf("└  ┴  ┴  ┴  ┴  ┴  ┴  ┴  ┘\n\n");
}

void isDrawBWstones(int line){
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[line][i] == None){
			printf("  ");
		}else{
			if( arr[line][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
}


/*
처음 작성시 돌만 구분하기 위해서 제작한것
printf("  ");
for(i=0; i<8; ++i){
if( arr[1][i] == 0){
printf("  ");
}else{
printf("●");
}
printf("  ");
}
printf("\n");
*/
/*
흰돌과 검은돌 구분하기 위해서 제작한것
printf("  ");
for(i=0; i<8; ++i){
if( arr[0][i] == 0){
printf("  ");
}else{
if( arr[0][i] == 1){
printf("●");
}else{
printf("○");
}
}
printf("  ");
}
printf("\n");
*/
/*
길게 늘어뜰인 방식
void isShowOdelloMap(){
	printf("┌  ┬  ┬  ┬  ┬  ┬  ┬  ┬  ┐\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[0][i] == None){
			printf("  ");
		}else{
			if( arr[0][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[1][i] == None){
			printf("  ");
		}else{
			if( arr[1][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[2][i] == None){
			printf("  ");
		}else{
			if( arr[2][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[3][i] == None){
			printf("  ");
		}else{
			if( arr[3][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[4][i] == None){
			printf("  ");
		}else{
			if( arr[4][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[5][i] == None){
			printf("  ");
		}else{
			if( arr[5][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[6][i] == None){
			printf("  ");
		}else{
			if( arr[6][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[7][i] == None){
			printf("  ");
		}else{
			if( arr[7][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
	printf("└  ┴  ┴  ┴  ┴  ┴  ┴  ┴  ┘\n\n");
}
*/
/*
조금더 줄여봄
void isShowOdelloMap(){
	printf("┌  ┬  ┬  ┬  ┬  ┬  ┬  ┬  ┐\n");
	isDrawBWstones(0);
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(1);
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(2);
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(3);
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(4);
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(5);
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(6);
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(7);
	printf("└  ┴  ┴  ┴  ┴  ┴  ┴  ┴  ┘\n\n");
}

void isDrawBWstones(int line){
	printf("  ");
	for(i=0; i<8; ++i){
		if( arr[line][i] == None){
			printf("  ");
		}else{
			if( arr[line][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
}
*/
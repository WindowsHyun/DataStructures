#include <stdio.h>
#include <Windows.h>
/*
1. 오델로 판 그리기
2. 오델로 기본돌 놓기
3. 오델로 충돌체크
4. 오델로 번갈아 놓기
5. 오델로 범위초과 막기
6. 오델로 값 입력받아 넣기
*/
enum{None, Black,White};

int arr[8][8];
int isPlayUser = Black;
int isGetX =0, isGetY =0, isCBlack=0, isCWhite=0;
void isOdelloDrawMap();
void isOdelloDrawStones(int);

int main(){
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			arr[i][j] = None;
	arr[4][4] =  Black;
	arr[3][4] = White;
	arr[3][3] =Black;
	arr[4][3] = White;
	while(1){
		system("cls");
		isCBlack = 0, isCWhite = 0;
		for(int i=0; i<8; ++i){
			for(int j=0; j<8; ++j){
				if(arr[i][j] == Black)
					++isCBlack;
				if(arr[i][j] == White)
					++isCWhite;
			}
		}
		isOdelloDrawMap();
		printf("Black : %d , White : %d\n\n",isCBlack, isCWhite);
		printf("좌표를 입력해주세요..! : ");
		scanf("%d,%d",&isGetX, &isGetY);
		if(isPlayUser == Black){
			if(arr[isGetY-1][isGetX-1] == None){
			arr[isGetY-1][isGetX-1] =  Black;
			isPlayUser =White;
			}
		}else{
			if(arr[isGetY-1][isGetX-1] == None){
			arr[isGetY-1][isGetX-1] =  White;
			isPlayUser =Black;
			}
		}
	}
}

void isOdelloDrawMap(){
	printf("┌  ┬  ┬  ┬  ┬  ┬  ┬  ┬  ┐\n");
	isOdelloDrawStones(0);
	for(int i=1; i<=7; ++i){
		printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┫\n");
		isOdelloDrawStones(i);
	}
	printf("└  ┴  ┴  ┴  ┴  ┴  ┴  ┴  ┘\n\n");
}

void isOdelloDrawStones(int line){
	printf("  ");
	for(int i=0; i<8; ++i){
		if (arr[line][i] == None){
			printf("  ");
		}else{
			if(arr[line][i] == Black){
				printf("●");
			}else{
				printf("○");
			}
		}
		printf("  ");
	}
	printf("\n");
}
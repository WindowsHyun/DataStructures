#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

// AI 만들때 돌의 우선순위를 가장 높은걸 바탕으로 만든다.

enum{ None, Black, White, Blank, tBlack, tWhite };

#define LEFT   75      // 좌측방향키
#define RIGHT  77      // 우측방향키
#define UP     72      // 위쪽방향키
#define DOWN   80      // 아래방향키
#define ENTER   13      // Enter키
#define SPACE   32      // Space키

void isShowOdelloMap();
void isDrawBWstones(int);
void isTempstones(int, int);
void isMoveTemp();
void isAddStones();
void isReverseStones();
//void isStonesCheck(int, int);

int i,j,k,l;
int zY , gX ;
int isGetInPutKey, isSetBlockTF=0;
int testGetGot=0;
int arr[8][8];
int isTempArr[8][8];

int isAiCoordinates[8][8];
int isAiCount[8] ={0};

int numX, numY, tempX=1, tempY=1;
int isPlayUser = Black, temp;
int isBlackNum =0, isWhiteNum = 0;

int main(){
	for(i=0; i <8; ++i){
		for(j=0; j<8; ++j){
			arr[i][j] =  None;
			isTempArr[i][j] = None;
			isAiCoordinates[i][j] =0;
			isAiCount[i] = 0;
		}
	}

	arr[4][3] = Black; //검은색 돌
	arr[3][4] = Black;
	arr[3][3] = White; //흰색 돌
	arr[4][4] = White;
	isTempArr[4][3] = Blank;
	isTempArr[3][4] = Blank;
	isTempArr[3][3] = Blank;
	isTempArr[4][4] = Blank;

	while(1){
		system("cls");
		isTempstones(tempY,tempX);
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

		if (isBlackNum == isWhiteNum){
			system("title Expected Winners : draw");
		}else{
			if (isBlackNum >= isWhiteNum){
				system("title Expected Winners : Black");
			}else{
				system("title Expected Winners : White");
			}
		}

		if(isPlayUser == Black){
			printf("Play User : Black\n\n");
		}else{
			printf("Play User : White\n\n");
		}

		printf("Coordinates ( %d , %d )\n", tempX, tempY);
		printf("Real Coordinates ( %d , %d )\n", tempX, tempY-1 );
		printf("Key : %d", isGetInPutKey );
		isGetInPutKey = getch();

		switch( isGetInPutKey ){
		case LEFT : 
			if(tempX <= 1){
			}else{
				isMoveTemp();
				--tempX;
			}
			break;
		case RIGHT : 
			if(tempX >= 8){
			}else{
				isMoveTemp();
				++tempX;
			}
			break;
		case UP :
			if(tempY <= 1){
			}else{
				isMoveTemp();
				--tempY;
			}
			break;
		case DOWN :
			if(tempY >=8){
			}else{
				isMoveTemp();
				++tempY;
			}
			break;
		case ENTER :
			isAddStones();
			break;
		case SPACE :
			isAddStones();
			break;
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
		if( arr[line][i] == None ){
			printf("  ");
		}else{
			if( arr[line][i] == tBlack || arr[line][i] == tWhite ){
				if( arr[line][i] == tBlack)
					printf("★");
				if( arr[line][i] == tWhite)
					printf("☆");
			}else{
				if( arr[line][i] == Black)
					printf("●");
				if( arr[line][i] == White)
					printf("○");
			}
		}
		printf("  ");
	} //for(i=0; i<8; ++i){
	printf("\n");
}

void isTempstones(int tY,int tX){
	if(isPlayUser == Black){
		if(isTempArr[tempY-1][tempX-1] != Blank){
			arr[tY-1][tX-1] = tBlack;
		}else{
			temp = arr[tY-1][tX-1];
			isTempArr[tY-1][tX-1] = arr[tY-1][tX-1];
			arr[tY-1][tX-1] = tBlack;
		}
	}else{
		if(isTempArr[tempY-1][tempX-1] != Blank){
			arr[tY-1][tX-1] = tWhite;
		}else{
			temp = arr[tY-1][tX-1];
			isTempArr[tY-1][tX-1] = arr[tY-1][tX-1];
			arr[tY-1][tX-1] = tWhite;
		}
	}

}

void isMoveTemp(){
	if(arr[tempY-1][tempX-1] == tBlack || arr[tempY-1][tempX-1] == tWhite){
		isTempArr[tempY-1][tempX-1] = Blank;
		arr[tempY-1][tempX-1] = temp;
		if(arr[tempY-1][tempX-1] !=0)
			temp = 0;

	}
}

void isAddStones(){
	// k, l
	if(isPlayUser == Black){
		if(isTempArr[tempY-1][tempX-1] == None){
			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = Black;
				isTempArr[tempY-1][tempX-1] = Blank;
				tempX= 1, tempY=1;
				isSetBlockTF = 0;
				isPlayUser = White;
			} // if(isSetBlockTF == 1){
		}
	}else{
		if(isTempArr[tempY-1][tempX-1] == None){


			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = White;
				isTempArr[tempY-1][tempX-1] = Blank;
				tempX= 1, tempY=1;
				isSetBlockTF = 0;
				isPlayUser = Black;
			} // if(isSetBlockTF == 1){
		}
	} 

}

void isReverseStones(){
	for(k=-1; k<=1; ++k){
		for(l=-1;l<=1; ++l){

			if(arr[tempY-1+k][tempX-1+l] != None){
				if( isPlayUser == Black){
					//검정색일경우 itPlayUser
					if( arr[tempY-1+k][tempX-1+l] == White){
						int tXt=tempX-1+l, tYt=tempY-1+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]!=White)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]==None)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=tempX-1||tYt!=tempY-1){
								arr[tYt][tXt]=Black;
								isTempArr[tYt][tXt] = Blank;
								tXt-=l;tYt-=k;
								isSetBlockTF = 1;
							}
						}
						break;
					}

				}else{
					//흰색일경우
					int tXt=tempX-1+l, tYt=tempY-1+k;
					while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(arr[tYt][tXt]!=Black)
							break;
						tYt+=k;
						tXt+=l;
					}

					if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(arr[tYt][tXt]==None)
							continue;

						tXt-=l; tYt-=k;
						while(tXt!=tempX-1||tYt!=tempY-1){
							arr[tYt][tXt]=White;
							isTempArr[tYt][tXt] = Blank;
							tXt-=l;tYt-=k;
							isSetBlockTF = 1;
						}
					}

				} // if( isPlayUser == Black){
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

/*
void isStonesCheck(int tY, int tX){

if(tX ==-1 && tY == 1){
//왼쪽 대각선 위
testGetGot  = 1;
}
if(tX ==0 && tY ==-1){
//중간 위
testGetGot  = 2;
}
if(tX ==1 && tY ==-1){
//오른쪽 대각선 위
testGetGot  = 3;
}
if(tX ==1 && tY == 0){
//오른쪽 3시방향
testGetGot  = 4;

for(int g=tempX-1; g<=8; ++g){
if(arr[tempY-1][g] == None){
testGetGot  = -4;
break;
}else{
if(arr[tempY-1][g] == isPlayUser){
for(int j=tempX-1; j<=g; ++j){
arr[tempY-1][j] = isPlayUser;
isTempArr[tempY-1][j] = Blank;
isSetBlockTF = 1;
} // for(int j=tempY-1; j>=g; --j){
} // if(arr[tempY-1][g] == isPlayUser){
} // if(arr[tempY-1][g] == None){
} // for(int g=tempX-1; g>=0; --g){





}
if(tX ==1 && tY ==1){
//오른쪽 대각선 아래
testGetGot  = 5;
zY = 0, gX = 0;
int g=tempX;
for(int z=tempY; z<8; ){

++g;
if(g<1){
--g;
break;
}
++z;
if(arr[z-1][g-1] == None){
testGetGot  = -5;
break;
}else{
if(arr[z-1][g-1] == isPlayUser){
zY = z, gX = g;
goto here;
printf("(%d, %d)",gX,zY);
} // if(arr[z-1][g-1] == isPlayUser){

here: //현재 에러가 있음...!
int g=tempX;
for(int z=tempY; z<=zY; ){

arr[z-1][g-1] = isPlayUser;
isTempArr[z-1][g-1] = Blank;
isSetBlockTF = 1;
++g;
if(g<1){
--g;
arr[z-1][g-1] = isPlayUser;
isTempArr[z-1][g-1] = Blank;
isSetBlockTF = 1;
break;
} // if(g<1){
++z;
} // for(int z=tempY; z<=zY; ){
} // if(arr[tempY-1][g] == None){
} // for(int z=tempY; z<8; ){


}

if(tX ==0 && tY ==1){
//중간 아래
testGetGot  = 6;
for(int g=tempY-1; g<=8; ++g){
if(arr[g][tempX-1] == None){
testGetGot  = -6;
break;
}else{
if(arr[g][tempX-1] == isPlayUser){
for(int j=tempY-1; j<=g; ++j){
arr[j][tempX-1] = isPlayUser;
isTempArr[j][tempX-1] = Blank;
isSetBlockTF = 1;
} // for(int j=tempY-1; j<=g; ++j){
} // if(arr[tempY-1][g] == isPlayUser){
} // if(arr[tempY-1][g] == None){
} // for(int g=tempY-1; g<=8; ++g){
} // if(tX ==0 && tY ==1){

if(tX ==-1 && tY == 1){
//왼쪽 대각선 아래
testGetGot  = 7;
zY = 0, gX = 0;
int g=tempX;
for(int z=tempY; z<8; ){
--g;
if(g<1){
++g;
break;
}
++z;
if(arr[z-1][g-1] == None){
testGetGot  = -7;
break;
}else{
if(arr[z-1][g-1] == isPlayUser){
zY = z, gX = g;
goto herek;
printf("(%d, %d)",gX,zY);
} // if(arr[z-1][g-1] == isPlayUser){

herek:
int g=tempX;
for(int z=tempY; z<=zY; ){
arr[z-1][g-1] = isPlayUser;
isTempArr[z-1][g-1] = Blank;
--g;
if(g<1){
++g;
arr[z-1][g-1] = isPlayUser;
isTempArr[z-1][g-1] = Blank;
isSetBlockTF = 1;
} // if(g<1){
++z;
} // for(int z=tempY; z<=zY; ){
} // if(arr[tempY-1][g] == None){
} // for(int z=tempY; z<8; ){
} // 	if(tX ==-1 && tY == 1){

if(tX ==-1 && tY ==0){
//왼쪽 9시방향
testGetGot  = 8;

for(int g=tempX-1; g>=0; --g){
if(arr[tempY-1][g] == None){
testGetGot  = -8;
break;
}else{
if(arr[tempY-1][g] == isPlayUser){
for(int j=tempY-1; j>=g; --j){
arr[tempY-1][j] = isPlayUser;
isTempArr[tempY-1][j] = Blank;
isSetBlockTF = 1;
} // for(int j=tempY-1; j>=g; --j){
} // if(arr[tempY-1][g] == isPlayUser){
} // if(arr[tempY-1][g] == None){
} // for(int g=tempX-1; g>=0; --g){
} // if(tX ==-1 && tY ==0){
}
*/

/*
(-1,-1) (0,-1) (1,-1)
(-1,0)  (0,0)  (1,0)
(-1,1)  (0,1)  (1,1)
*/
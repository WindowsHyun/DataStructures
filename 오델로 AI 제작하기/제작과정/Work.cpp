#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

// AI 만들때 돌의 우선순위를 가장 높은걸 바탕으로 만든다.
// 힌트를 주는 부분이 완전하지 않은거 같다. 좀 더 보완 수정을 해야할듯하다.
// 힌트를 주는것의 숫자를 파악하여, 해당 숫자가 0일경우 턴을 넘겨주는 방식을 제작한다.
// AI는 해당 힌트를 주는 위치에서의 돌갯수를 판단하여, 해당 돌의 갯수가 많은 쪽으로 AI를 놓는 방법으로 해야할듯하다.

enum{ None, Black, White, Hint };

#define LEFT   75      // 좌측방향키
#define RIGHT  77      // 우측방향키
#define UP     72      // 위쪽방향키
#define DOWN   80      // 아래방향키
#define ENTER   13      // Enter키
#define SPACE   32      // Space키

void isShowOdelloMap();
void isDrawBWstones(int);
void isAddStones();
void isTempBWStones();
int isTempReverseStones();
void isReverseStones();
void isHStones();
void isClearTempBW();

int isGetInPutKey, isSetBlockTF=0;
int arr[8][8], isSeroCheck[8], isSero[8];

int tempX=1, tempY=1;
int isPlayUser = Black, temp;
int isBlackNum =0, isWhiteNum = 0;
int isTempRx, isTempRy;

int main(){
	for(int i=0; i <8; ++i){
		for(int j=0; j<8; ++j){
			arr[i][j] =  None;
		}
	}

	arr[4][3] = Black; //검은색 돌
	arr[3][4] = Black;
	arr[3][3] = White; //흰색 돌
	arr[4][4] = White;

	while(1){
		system("cls");
		isTempBWStones();
		isShowOdelloMap();

		isBlackNum = 0;
		isWhiteNum = 0;

		for(int i=0; i <8; ++i){
			for(int j=0; j<8; ++j){
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
		printf("Real Coordinates ( %d , %d )", tempX-1, tempY-1 );
		//printf("Key : %d", isGetInPutKey );
		isGetInPutKey = getch();

		switch( isGetInPutKey ){
		case LEFT : 
			if(tempX <= 1){
				tempX = 8;
			}else{
				--tempX;
			}
			break;
		case RIGHT : 
			if(tempX >= 8){
				tempX = 1;
			}else{
				++tempX;
			}
			break;
		case UP :
			if(tempY <= 1){
				tempY=8;
			}else{
				--tempY;
			}
			break;
		case DOWN :
			if(tempY >=8){
				tempY=1;
			}else{
				++tempY;
			}
			break;
		case ENTER :
			isAddStones();
			break;
		case SPACE :
			isClearTempBW();
			break;
		}

	} //while(1){
}

void isShowOdelloMap(){
	printf("┌  ┬  ┬  ┬  ┬  ┬  ┬  ┬  ┐\n");
	isDrawBWstones(0);
	for(int k=1; k<=6; ++k){
		printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
		isDrawBWstones(k);
	}
	printf("├  ┼  ┼  ┼  ┼  ┼  ┼  ┼  ┤\n");
	isDrawBWstones(7);
	printf("└  ┴  ┴  ┴  ┴  ┴  ┴  ┴  ┘\n");
	isHStones();
	printf("\n");
}

void isDrawBWstones(int line){
	int isBlackData =0, isWhiteData =0;
	printf("  ");
	for(int i=0; i<8; ++i){
		if( arr[line][i] == None ){
			if(line == tempY-1  && i == tempX-1){
				if( isPlayUser == Black)
					printf("★");
				if( isPlayUser == White)
					printf("☆");
			}else{
				printf("  ");
			}

		}else{

			if(line == tempY-1  && i == tempX-1){
				if( isPlayUser == Black)
					printf("★");
				if( isPlayUser == White)
					printf("☆");
			}else{ // if(line == tempY-1  && i == tempX-1){

				if( arr[line][i] == Hint ){
					printf("＊");
				}

				if( arr[line][i] == Black){
					printf("●");
					++isBlackData;
				}
				if( arr[line][i] == White){
					printf("○");
					++isWhiteData;
				}

			} // if(line == tempY-1  && i == tempX-1){
		}
		printf("  ");
	} //for(i=0; i<8; ++i){
	printf("(%d,%d)", isBlackData, isWhiteData); //가로 연산
	//printf("  ");
	if(isBlackData == isWhiteData){
		//printf(" 검정색과 흰색의 돌이 모두 같습니다..!");
	}else if(isBlackData < isWhiteData){
		printf(" 흰색돌이 %d개 더 많이있습니다..!", isWhiteData-isBlackData);
	}else if(isBlackData > isWhiteData){
		printf(" 검정색돌이 %d개 더 많이있습니다..!", isBlackData-isWhiteData);
	}

	/*
	for(int i=0; i<8; ++i){
		printf("%2d", arr[line][i]); //가로 연산
	}
	*/
	printf("\n");
}

void isHStones(){
	int isBlackData =0, isWhiteData =0, isHS=0;;
	while(isHS < 8){
		for(int i=0; i< 8; ++i){
			if( arr[i][isHS] == Black){
				++isBlackData;
			}
			if( arr[i][isHS] == White){
				++isWhiteData;
			}
		}
		printf("(%d,%d)", isBlackData, isWhiteData); //세로 연산


		if(isBlackData == isWhiteData){
			isSeroCheck[isHS] =0;
	}else if(isBlackData < isWhiteData){
		isSeroCheck[isHS] =1;
		isSero[isHS] = isWhiteData-isBlackData;
	}else if(isBlackData > isWhiteData){
		isSeroCheck[isHS] =2;
		isSero[isHS] = isBlackData-isWhiteData;
	}

		isBlackData =0, isWhiteData =0;
		++isHS;
	}
	printf("\n");
for(int i=0; i<8; ++i){
	if(isSeroCheck[i] == 1){
	printf("세로 %d : 검정색돌이 %d개 더 많이있습니다..!\n",i+1, isSero[i]);
	}else if(isSeroCheck[i] == 2){
	printf("세로 %d : 흰색돌이 %d개 더 많이있습니다..!\n",i+1, isSero[i]);
	}
}



}

void isAddStones(){
	if(isPlayUser == Black){
		if(arr[tempY-1][tempX-1] == None || arr[tempY-1][tempX-1] == Hint ){
			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = Black;
				//tempX= 1, tempY=1;
				isSetBlockTF = 0;
				isPlayUser = White;
			} // if(isSetBlockTF == 1){
		}
	}else{
		if(arr[tempY-1][tempX-1] == None || arr[tempY-1][tempX-1] == Hint ){
			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = White;
				//tempX= 1, tempY=1;
				isSetBlockTF = 0;
				isPlayUser = Black;
			} // if(isSetBlockTF == 1){
		}
	} 

}

void isTempBWStones(){
	isTempRy= 0, isTempRx=0;
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if( arr[i][j] == None){
				isTempRy= i, isTempRx=j;
				if(isTempReverseStones() == 1){
					arr[i][j] = Hint;
				}
			}
		}
	}
}


void isClearTempBW(){
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if(arr[i][j] == Hint){
				arr[i][j] = None;
			}
		}
	}

}


int isTempReverseStones(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(arr[isTempRy+k][isTempRx+l] != None && arr[isTempRy+k][isTempRx+l] != Hint){
				if( isPlayUser == Black){
					//검정색일경우 itPlayUser
					if( arr[isTempRy+k][isTempRx+l] == White){
						int tXt=isTempRx+l, tYt=isTempRy+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]!=White || arr[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]==None || arr[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=tempX-1||tYt!=tempY-1){
								return 1;
								break;
							}
						}
						//break;
					}

				}else{
					//흰색일경우
					if( arr[isTempRy+k][isTempRx+l] == Black){
						int tXt=isTempRx+l, tYt=isTempRy+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]!=Black || arr[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]==None || arr[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=tempX-1||tYt!=tempY-1){
								return 1;
								break;
							}
						}
						//break;
					}

				} // if( isPlayUser == Black){
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
	return 0;
}

void isReverseStones(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(arr[tempY-1+k][tempX-1+l] != None && arr[tempY-1+k][tempX-1+l] != Hint){
				if( isPlayUser == Black){ //검정색일경우
					if( arr[tempY-1+k][tempX-1+l] == White){
						int tXt=tempX-1+l, tYt=tempY-1+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]!=White || arr[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]==None || arr[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=tempX-1||tYt!=tempY-1){
								arr[tYt][tXt]=Black;
								tXt-=l;tYt-=k;
								isSetBlockTF = 1;
								isClearTempBW();
							}
						}
					}

				}else{
					//흰색일경우
					if( arr[tempY-1+k][tempX-1+l] == Black){
						int tXt=tempX-1+l, tYt=tempY-1+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]!=Black || arr[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(arr[tYt][tXt]==None || arr[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=tempX-1||tYt!=tempY-1){
								arr[tYt][tXt]=White;
								tXt-=l;tYt-=k;
								isSetBlockTF = 1;
								isClearTempBW();
							}
						}
					}
				} // if( isPlayUser == Black){
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}
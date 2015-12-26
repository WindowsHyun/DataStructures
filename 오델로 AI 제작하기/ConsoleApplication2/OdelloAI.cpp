#include "권창현_2012180004.h"

// AI 만들때 돌의 우선순위를 가장 높은걸 바탕으로 만든다.
// 힌트를 주는 부분이 완전하지 않은거 같다. 좀 더 보완 수정을 해야할듯하다.
// 힌트를 주는것의 숫자를 파악하여, 해당 숫자가 0일경우 턴을 넘겨주는 방식을 제작한다.
// AI는 해당 힌트를 주는 위치에서의 돌갯수를 판단하여, 해당 돌의 갯수가 많은 쪽으로 AI를 놓는 방법으로 해야할듯하다.

enum{ None, Black, White, Hint };
enum{ GameStart, GameEnd, ComputerThink};
enum{ OneTurn, TwoTurn};

void isShowOdelloMap();
void isDrawBWstones(int);
void isAddStones();
void isTempBWStones();
void isTempReverseStones();
void isReverseStones();
void isHStones();
void isClearTempBW();
void isAiWhiteStones();

int isGetInPutKey, isSetBlockTF=0, isAiCheckTF=0;
int arr[isOdelloData][isOdelloData];
int isAIx[isAiArrangement], isAIy[isAiArrangement], isAiCount[isAiArrangement], istAiCount=0, ismovetemp[isAiTempData]; // AI 관련한 배열

int tempX=1, tempY=1;
int isPlayUser = Black, temp, isGameState = GameStart;
int isBlackNum =0, isWhiteNum = 0;
int isTempRx, isTempRy;

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// AI 관련 전역변수
int isAiNext[isOdelloData][isOdelloData];
int isAIxNext[isAiArrangement], isAIyNext[isAiArrangement], isAiCountNext[isAiArrangement];
int istAiCountNext=0, ismovetempNext[isAiTempData];
int isCheckStones[isAiArrangement];
int isTwoCheckStones[isAiArrangement];
int isAiPutX, isAiPutY, isAiNextCheck=0;
// AI 플레이 관련부분
int isWhatPlayScore =0;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
	for(int i=0; i <isOdelloData; ++i){
		for(int j=0; j<isOdelloData; ++j){
			arr[i][j] =  None;
			isAiNext[i][j] =  None;
		}
	}
	for(int i=0; i<isAiArrangement; ++i){
		isAIx[i] = 0,isAIy[i] = 0, isAiCount[i] = 0;
		isAIxNext[i] = 0,isAIyNext[i] = 0, isAiCountNext[i] = 0;
	}

	arr[4][3] = White; //검은색 돌
	arr[3][4] = White;
	arr[3][3] = Black; //흰색 돌
	arr[4][4] = Black;

	isAiNext[4][3] = White;//검은색 돌
	isAiNext[3][4] = White;
	isAiNext[3][3] = Black;  //흰색 돌
	isAiNext[4][4] = Black;

	while(isGameState == GameStart){
		system("cls");
		isTempBWStones();
		isShowOdelloMap();

		isBlackNum = 0;
		isWhiteNum = 0;

		for(int i=0; i <isOdelloData; ++i){
			for(int j=0; j<isOdelloData; ++j){
				if(arr[i][j] ==  Black)
					++isBlackNum;
				if(arr[i][j] ==  White)
					++isWhiteNum;
			}
		}

		if( isBlackNum + isWhiteNum == isGameTheEndData){//게임 끝..!
			isGameState = GameEnd;
			break;
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
			printf("Play User : Black\n");
		}else{
			printf("Play User : White\n");
		}
		printf("Real Coordinates ( %d , %d )", tempX-1, tempY-1 );
		/*
		printf("Coordinates ( %d , %d )\n", tempX, tempY);
		printf("Real Coordinates ( %d , %d )", tempX-1, tempY-1 );
		printf("Key : %d", isGetInPutKey );
		*/

		if(isAiCount[0] == 0 ){ //놓을수 있는곳이 없을경우
			if(isPlayUser == White){
				isPlayUser = Black;
			}else{
				isPlayUser = White;
			}
		}


		if(isPlayUser == White){
			Sleep(isWaitTime);
			isAiWhiteStones();
		}else{
			//Sleep(isWaitTime);
			//isAiWhiteStones();

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

		}//if(isPlayUser == White){
	} // while(isGameState == GameStart){


	while(isGameState == GameEnd){
		system("cls");

		tempX = -1, tempY = -1;

		isShowOdelloMap();

		isBlackNum = 0;
		isWhiteNum = 0;

		for(int i=0; i <isOdelloData; ++i){
			for(int j=0; j<isOdelloData; ++j){
				if(arr[i][j] ==  Black)
					++isBlackNum;
				if(arr[i][j] ==  White)
					++isWhiteNum;
			}
		}

		printf("Black stones : %d, White stones : %d\n\n", isBlackNum,isWhiteNum);

		if (isBlackNum == isWhiteNum){
			printf("Game Results : draw \n");
		}else{
			if (isBlackNum >= isWhiteNum){
				printf("Game Results : Black \n");
			}else{
				printf("Game Results : White \n");
			}
		}

		isGetInPutKey = getch();
		switch( isGetInPutKey ){

		}

	} // while(isGameState == GameEnd){

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
	printf("%c%c", isSpace,isSpace);
	for(int i=0; i<isOdelloData; ++i){
		if( arr[line][i] == None ){
			if(line == tempY-1  && i == tempX-1){
				if( isPlayUser == Black)
					printf("☆");
				if( isPlayUser == White)
					printf("★");
			}else{
				printf("%c%c", isSpace,isSpace);
			}

		}else{

			if(line == tempY-1  && i == tempX-1){
				if( isPlayUser == Black)
					printf("☆");
				if( isPlayUser == White)
					printf("★");
			}else{ // if(line == tempY-1  && i == tempX-1){

				if( arr[line][i] == Hint ){
					printf("＊");
				}

				if( arr[line][i] == Black){
					printf("○");
					++isBlackData;
				}
				if( arr[line][i] == White){
					printf("●");
					++isWhiteData;
				}

			} // if(line == tempY-1  && i == tempX-1){
		}
		printf("%c%c", isSpace,isSpace);
	} //for(i=0; i<8; ++i){
	printf("(%d,%d)", isBlackData, isWhiteData); //가로 연산
	for(int i=0; i<isOdelloData; ++i){
		printf("%2d", isAiNext[line][i]); //가로 연산
	}
	printf("\n");
}

void isHStones(){
	int isBlackData =0, isWhiteData =0, isHS=0;;
	while(isHS < isOdelloData){
		for(int i=0; i< isOdelloData; ++i){
			if( arr[i][isHS] == Black){
				++isBlackData;
			}
			if( arr[i][isHS] == White){
				++isWhiteData;
			}
		}
		printf("(%d,%d)", isBlackData, isWhiteData); //세로 연산
		isBlackData =0, isWhiteData =0;
		++isHS;
	}
	printf("\n");

}

void isAddStones(){
	if(isPlayUser == Black){
		if(arr[tempY-1][tempX-1] == None || arr[tempY-1][tempX-1] == Hint ){
			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = Black;
				//tempX= 1, tempY=1;
				isSetBlockTF = 0;
				isAIGetGPS(tempY-1,tempX-1);
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
	for(int i=0; i<isOdelloData; ++i){
		for(int j=0; j<isOdelloData; ++j){
			if( arr[i][j] == None){
				isTempRy= i, isTempRx=j;
				isTempReverseStones();

				if(istAiCount >= isAiArrangement)
					break;

				if( isAiCheckTF == 1){
					arr[i][j] = Hint;
					isAIx[istAiCount] = isTempRx;
					isAIy[istAiCount] = isTempRy;
					++istAiCount;
					isAiCheckTF=0;
				}
			}
		}
	}
}


void isClearTempBW(){
	for(int i=0; i<isOdelloData; ++i){
		for(int j=0; j<isOdelloData; ++j){
			if(arr[i][j] == Hint){
				arr[i][j] = None;
			}
		}
	}
	for(int i=0; i<isAiArrangement; ++i){
		isAIx[i] = 0, isAIy[i] = 0, isAiCount[i] = 0, istAiCount=0;
	}
	for(int i=0; i<isAiTempData; ++i){
		ismovetemp[i] =0;
	}
}


void isTempReverseStones(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(arr[isTempRy+k][isTempRx+l] != None && arr[isTempRy+k][isTempRx+l] != Hint){
				if( isPlayUser == Black){ //검정색일경우
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
							while(tXt!=isTempRx || tYt!=isTempRy){
								++isAiCount[istAiCount];
								tXt-=l;tYt-=k;
								isAiCheckTF=1;
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
							while(tXt!=isTempRx || tYt!=isTempRy){
								++isAiCount[istAiCount];
								tXt-=l;tYt-=k;
								isAiCheckTF=1;
							}
						}
						//break;
					}

				} // if( isPlayUser == Black){
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
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


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// AI 관련부분
void isAiWhiteStones(){
	isAiTotalPlus(OneTurn,isAiCount);
	for(int i=0; i<isAiArrangement-1; ++i){
		for(int j=i+1; j<isAiArrangement; ++j){
			if( isAiCount[i] < isAiCount[j] ){
				ismovetemp[0]=isAiCount[i];
				ismovetemp[1]=isAIx[i];
				ismovetemp[2]=isAIy[i];

				isAiCount[i] = isAiCount[j];
				isAIx[i] = isAIx[j];
				isAIy[i] = isAIy[j];

				isAiCount[j] = ismovetemp[0];
				isAIx[j] = ismovetemp[1];
				isAIy[j] = ismovetemp[2];
			} 
		} 
	}

	int tempArr[isOdelloData][isOdelloData];
	isHintClear();
	for( int i=0; i<isOdelloData; ++i){
		for( int j=0; j<isOdelloData; ++j){
			tempArr[i][j] = isAiNext[i][j];
		}
	}
	// ↑ tempArr 에다가 현제 데이터를 저장을 해놓은다..!

	// isAIx[0], isAIy[0] 이 가장 많이 뒤집는 경우이다.
	for(int i=0; i<isAiArrangement; ++i){
		// 가장 많이 뒤집는 경우부터 시작하여, 비교를 시작한다..!
		if( isAIx[i] == 0 && isAIy[i] == 0 && isAiCount[i] == 0)
			break;
		isAiPutX = isAIx[i], isAiPutY = isAIy[i];
		isAiNext[isAiPutY][isAiPutX] = Black;
		isBlackStonesChecker();
		// ↑ 검정색이 한번 놓은후
		isHintClear();
		isHintLoad();
		isAiTotalPlus(TwoTurn, isAiCountNext);
		// ↑ 상대방이 놓으려고 하는것중 최상위수
		for(int i=0; i<isAiArrangement-1; ++i){
			for(int j=i+1; j<isAiArrangement; ++j){
				if( isAiCountNext[i] < isAiCountNext[j] ){
					ismovetempNext[0]=isAiCountNext[i];
					ismovetempNext[1]=isAIxNext[i];
					ismovetempNext[2]=isAIyNext[i];

					isAiCountNext[i] = isAiCountNext[j];
					isAIxNext[i] = isAIxNext[j];
					isAIyNext[i] = isAIyNext[j];

					isAiCountNext[j] = ismovetempNext[0];
					isAIxNext[j] = ismovetempNext[1];
					isAIyNext[j] = ismovetempNext[2];
				} 
			} 
		}

		int tempB=0, tempW=0;
		for(int i=0; i<isOdelloData; ++i){
			for(int j=0; j<isOdelloData; ++j){
				if( arr[i][j] == Black){
					++tempB;
				}else if ( arr[i][j] == White){
					++tempW;
				}
			}
		}
		//printf("Black : %d, White : %d\n", tempB, tempW);
		isAiNext[isAIyNext[0]][isAIxNext[0]] = White;
		isAiPutX = isAIxNext[0], isAiPutY = isAIyNext[0];
		isWhiteStonesChecker();
		// ↑ 최상의 수중 가장 가중치 높은것을 넘기려 하는 부분
		int NtempNB=0, NtempNW=0;
		for(int i=0; i<isOdelloData; ++i){
			for(int j=0; j<isOdelloData; ++j){
				if( isAiNext[i][j] == Black){
					++NtempNB;
				}else if ( isAiNext[i][j] == White){
					++NtempNW;
				}
			}
		}

		/*printf("NBlack : %d, NWhite : %d\n", NtempNB, NtempNW);
		printf("Nblack-Black = %d\n", NtempNB-tempB);
		printf("NWhite-NWhite = %d\n", NtempNW-tempW);*/
		int isResult=0, isWhiteResult = NtempNB-tempB;
		if( (NtempNW-tempW) < 0){
			//음수
			isResult = (NtempNB-tempB)+(NtempNW-tempW);
			//printf("Result : %d\n", isResult);
		}else{
			isResult = (NtempNB-tempB)-(NtempNW-tempW);
			//printf("Result : %d\n", isResult);
		}

		//printf("(%d, %d) = %d : %d : %d --\n\n", isWhiteAIx[i], isWhiteAIy[i], isWhiteAiCount[i], isResult, isWhiteResult);

		isCheckStones[i] = isResult;
		isTwoCheckStones[i] = isWhiteResult;
		//system("pause");

		for( int i=0; i<isOdelloData; ++i){
			for( int j=0; j<isOdelloData; ++j){
				isAiNext[i][j] = tempArr[i][j];
			}
		}

	} // for(int i=0; i<isAiArrangement; ++i){

	for(int i=0; i<isAiArrangement-1; ++i){
		for(int j=i+1; j<isAiArrangement; ++j){
			if( isCheckStones[i] < isCheckStones[j] ){
				int tempData = isCheckStones[i];
				int tempTwoData = isTwoCheckStones[i];
				isCheckStones[i] = isCheckStones[j];
				isTwoCheckStones[i] = isTwoCheckStones[j];
				isCheckStones[j] = tempData;
				isTwoCheckStones[j] = tempTwoData;


				ismovetemp[0]=isAiCount[i];
				ismovetemp[1]=isAIx[i];
				ismovetemp[2]=isAIy[i];

				isAiCount[i] = isAiCount[j];
				isAIx[i] = isAIx[j];
				isAIy[i] = isAIy[j];

				isAiCount[j] = ismovetemp[0];
				isAIx[j] = ismovetemp[1];
				isAIy[j] = ismovetemp[2];
			} 
		} 
	}

	/*for(int i=0; i<isAiArrangement; ++i){
	printf("(%d, %d) = %d : %d : %d\n", isWhiteAIx[i], isWhiteAIy[i],isWhiteAiCount[i], isWhiteCheckStones[i], isWhiteTwoCheckStones[i]  );
	}
	system("pause");*/


	for(int i=0; i<isAiArrangement-1; ++i){
		for(int j=i+1; j<isAiArrangement; ++j){
			if( isAiCount[i] != 0){
				if( isTwoCheckStones[i] < isTwoCheckStones[j] ){
					int tempData = isTwoCheckStones[i];
					int tempTwoData = isCheckStones[i];
					isTwoCheckStones[i] = isTwoCheckStones[j];
					isCheckStones[i] = isCheckStones[j];
					isTwoCheckStones[j] = tempData;
					isCheckStones[j] = tempTwoData;

					ismovetemp[0]=isAiCount[i];
					ismovetemp[1]=isAIx[i];
					ismovetemp[2]=isAIy[i];

					isAiCount[i] = isAiCount[j];
					isAIx[i] = isAIx[j];
					isAIy[i] = isAIy[j];

					isAiCount[j] = ismovetemp[0];
					isAIx[j] = ismovetemp[1];
					isAIy[j] = ismovetemp[2];
				} 
			}
		}
	}

	int isRBlack=0, isRWhite=0;
	for(int i=0; i<isOdelloData; ++i){
		for(int j=0; j<isOdelloData; ++j){
			if( arr[i][j] == Black){
				++isRBlack;
			}else if ( arr[i][j] == White){
				++isRWhite;
			}
		}
	}

	if(isWhatPlayScore >= 10 && isRBlack >= isRWhite ){
		printf("AiTotalPlus Attack!!!\n");
		for(int i=0; i<isAiArrangement-1; ++i){
			for(int j=i+1; j<isAiArrangement; ++j){
				if( isAiCount[i] < isAiCount[j] ){
					int tempData = isTwoCheckStones[i];
					int tempTwoData = isCheckStones[i];
					isTwoCheckStones[i] = isTwoCheckStones[j];
					isCheckStones[i] = isCheckStones[j];
					isTwoCheckStones[j] = tempData;
					isCheckStones[j] = tempTwoData;

					ismovetemp[0]=isAiCount[i];
					ismovetemp[1]=isAIx[i];
					ismovetemp[2]=isAIy[i];

					isAiCount[i] = isAiCount[j];
					isAIx[i] = isAIx[j];
					isAIy[i] = isAIy[j];

					isAiCount[j] = ismovetemp[0];
					isAIx[j] = ismovetemp[1];
					isAIy[j] = ismovetemp[2];
				} 
			} 
		}
	}

	/*for(int i=0; i<isAiArrangement; ++i){
	printf("(%d, %d) = %d : %d : %d\n", isWhiteAIx[i], isWhiteAIy[i],isWhiteAiCount[i], isWhiteCheckStones[i], isWhiteTwoCheckStones[i]  );
	}
	system("pause");*/

	if(  isAIx[0] == 0 && isAIy[0] == 0 &&  isAiCount[0] == 0){
		for(int i=0; i<isAiArrangement; ++i){
			if(isAiCount[i] !=0){
				// 정렬을 성공하였지만, 공격할 돌이 없을경우
				isAIx[0] = isAIx[i], isAIy[0] = isAIy[i];
				isAiCount[0] =  isAiCount[i];
				break;
			}
		}
	}

	for(int i=0; i<isAiArrangement; ++i){
		isCheckStones[i] = 0; // 체크하는부분은 끝나면 초기화를 해줘야 한다..!
		isTwoCheckStones[i] = 0;
	}

	tempX = isAIx[0]+1, tempY = isAIy[0]+1;
	isAiPutX = isAIx[0], isAiPutY = isAIy[0];
	isWhiteStonesChecker();
	isAiNext[tempY-1][tempX-1] = White;
	isAddStones();
	isWhatPlayScore++;
}



void isAIGetGPS(int isY, int isX) {
	isAiPutX = isX, isAiPutY = isY;
	isBlackStonesChecker();
	isAiNext[isY][isX] = Black;
	isWhatPlayScore++;
}

void isBlackStonesChecker(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			if(isAiNext[isAiPutY+k][isAiPutX+l] != None && isAiNext[isAiPutY+k][isAiPutX+l] != Hint){
				if( isAiNext[isAiPutY+k][isAiPutX+l] == White){
					int tXt=isAiPutX+l, tYt=isAiPutY+k;
					while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(isAiNext[tYt][tXt]!=White || isAiNext[tYt][tXt]==Hint)
							break;
						tYt+=k;
						tXt+=l;
					}

					if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(isAiNext[tYt][tXt]==None || isAiNext[tYt][tXt]==Hint)
							continue;

						tXt-=l; tYt-=k;
						while(tXt!=isAiPutX || tYt!=isAiPutY){
							isAiNext[tYt][tXt]=Black;
							tXt-=l;tYt-=k;
						}
					}
				}
			}
		} 
	} 
}

void isWhiteStonesChecker(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			if(isAiNext[isAiPutY+k][isAiPutX+l] != None && isAiNext[isAiPutY+k][isAiPutX+l] != Hint){
				if( isAiNext[isAiPutY+k][isAiPutX+l] == Black){
					int tXt=isAiPutX+l, tYt=isAiPutY+k;
					while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(isAiNext[tYt][tXt]!=Black || isAiNext[tYt][tXt]==Hint)
							break;
						tYt+=k;
						tXt+=l;
					}

					if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(isAiNext[tYt][tXt]==None || isAiNext[tYt][tXt]==Hint)
							continue;

						tXt-=l; tYt-=k;
						while(tXt!=isAiPutX || tYt!=isAiPutY){
							isAiNext[tYt][tXt]=White;
							tXt-=l;tYt-=k;
						}
					}
				}
			}
		} 
	} 
}

void isHintLoad(){
	isTempRy= 0, isTempRx=0;
	for(int i=0; i<isOdelloData; ++i){
		for(int j=0; j<isOdelloData; ++j){
			if( isAiNext[i][j] == None){
				isAiPutY= i, isAiPutX=j;
				isHintCheck();

				if(istAiCountNext >= isAiArrangement)
					break;

				if( isAiNextCheck == 1){
					isAiNext[i][j] = Hint;
					isAIxNext[istAiCountNext] = isAiPutX;
					isAIyNext[istAiCountNext] = isAiPutY;
					++istAiCountNext;
					isAiNextCheck=0;
				}
			}
		}
	}
}

void isHintCheck(){ 
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			if(isAiNext[isAiPutY+k][isAiPutX+l] != None && isAiNext[isAiPutY+k][isAiPutX+l] != Hint){
				if( isAiNext[isAiPutY+k][isAiPutX+l] == Black){
					int tXt=isAiPutX+l, tYt=isAiPutY+k;
					while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(isAiNext[tYt][tXt]!=Black || isAiNext[tYt][tXt]==Hint)
							break;
						tYt+=k;
						tXt+=l;
					}

					if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
						if(isAiNext[tYt][tXt]==None || isAiNext[tYt][tXt]==Hint)
							continue;

						tXt-=l; tYt-=k;
						while(tXt!=isAiPutX || tYt!=isAiPutY){
							++isAiCountNext[istAiCountNext];
							tXt-=l;tYt-=k;
							isAiNextCheck=1;
						}
					}
				}
			}
		}
	}
}

void isHintClear(){
	for(int i=0; i<isOdelloData; ++i){
		for(int j=0; j<isOdelloData; ++j){
			if(isAiNext[i][j] == Hint){
				isAiNext[i][j] = None;
			}
		}
	}
	for(int i=0; i<isAiArrangement; ++i){
		isAIxNext[i] = 0, isAIyNext[i] = 0, isAiCountNext[i] = 0, istAiCountNext=0;
	}
	for(int i=0; i<isAiTempData; ++i){
		ismovetempNext[i] =0;
	}
}

void isAiTotalPlus(int whatPlay, int scoreData[]){
	//enum{ OneTurn, TwoTurn};
	int isRealX =0, isRealY =0;
	for(int i=0; i<isAiArrangement; ++i){
		if( whatPlay == OneTurn){
			isRealX =isAIx[i], isRealY = isAIy[i];
		}else{
			isRealX =isAIxNext[i], isRealY = isAIyNext[i];
		}
		// 가중치 계산
		if( isRealX == 0 && isRealY == 0 && scoreData[i] == 0)
			continue;
		if((isRealY == 0 && isRealX == 0) || (isRealY == 0 && isRealX ==7) || (isRealY == 7 && isRealX ==0) || (isRealY == 7 && isRealX ==7)){
			// 제일 끝
			scoreData[i]+=100;
		}else if(((isRealY == 0 || isRealY == 7) && (1<=isRealX && isRealX<=6))||((isRealX == 0 || isRealX == 7) && (1<=isRealY && isRealY<=6))){
			// 파란색
			if(isRealY  == 1 && isRealX == 0 || isRealY  == 0 && isRealX == 1 ){
				if(arr[0][0] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 0 && isRealX == 6 || isRealY  == 1 && isRealX == 7 ){
				if(arr[0][7] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 6 && isRealX == 0 || isRealY  == 7 && isRealX == 1 ){
				if(arr[7][0] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 6 && isRealX ==7 || isRealY  == 7 && isRealX == 6 ){
				if(arr[7][7] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else{
				int isFakeData =0;
				int tempArr[8][8];
				for(int i=0; i<8; ++i){
					for(int j=0; j<8; ++j){
						if( arr[i][j] == Black ){
							tempArr[i][j]  =Black;
						}else if ( arr[i][j] == White){
							tempArr[i][j]  =White;
						}else{
							tempArr[i][j]  =None;
						}
					}
				}
				if(2<=isRealY && isRealY<=5){
					// 파란색 왼쪽 오른쪽
					//printf("( %d, %d )\n", isRealX, isRealY);
					if( tempArr[isRealY-1][isRealX] == None && tempArr[isRealY+1][isRealX] == None ){
						//printf("---------------------Bingo---------------------\n");
						scoreData[i]+=90;
					}else{
						if(arr[isRealY-1][isRealX] == White){
							if(arr[isRealY-2][isRealX] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						if(arr[isRealY+1][isRealX] == White){
							if(arr[isRealY+2][isRealX] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						scoreData[i]+=isFakeData;
					}

				}else if(2<=isRealX && isRealX<=5){
					// 파란색 위쪽 아래쪽
					if( tempArr[isRealY][isRealX-1] == None && tempArr[isRealY][isRealX+1] == None ){
						//printf("---------------------Bingo---------------------\n");
						scoreData[i]+=90;
					}else{
						if(arr[isRealY][isRealX-1] == White){
							if(arr[isRealY][isRealX-2] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						if(arr[isRealY][isRealX+1] == White){
							if(arr[isRealY][isRealX+2] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						scoreData[i]+=isFakeData;
					}
				}
			}
		}else if( (2<=isRealY && isRealY<= 5) && (2<=isRealX && isRealX<= 5) ){
			// 초록색
			if(isRealY  == 2 && isRealX == 2 ){
				scoreData[i]+=70;
			}else if(isRealY  == 2 && isRealX == 5 ){
				scoreData[i]+=70;
			}else if(isRealY  == 5 && isRealX == 2 ){
				scoreData[i]+=70;
			}else if(isRealY  == 5 && isRealX == 5 ){
				scoreData[i]+=70;
			}else{
				scoreData[i]+=30;
			}
		}else if( (isRealY == 1 && isRealX == 1) || (isRealY == 1 && isRealX == 6) || (isRealY == 6 && isRealX == 1) || (isRealY == 6 && isRealX == 6) ){
			// 빨간색
			/*if(isRealX == 6 && isRealY == 1 && arr[7][0] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 1 && isRealY == 6 && arr[0][7] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 1 && isRealY == 1 && arr[7][7] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 6 && isRealY == 6 && arr[0][0] == Black ){
			scoreData[i]+=90;
			}else{
			scoreData[i]+=1;
			}*/
			scoreData[i]+=1;
		}else{
			// 노란색
			if(isRealY  == 1 && isRealX == 2 || isRealY  == 2 && isRealX == 1 ){
				scoreData[i]+=35;
			}else if(isRealY  == 5 && isRealX == 1 || isRealY  == 2 && isRealX == 6 ){
				scoreData[i]+=35;
			}else if(isRealY  == 1 && isRealX == 5 || isRealY  == 6 && isRealX == 2 ){
				scoreData[i]+=35;
			}else if(isRealY  == 5 && isRealX == 6 || isRealY  == 6 && isRealX == 5 ){
				scoreData[i]+=35;
			}else{
				//if(isRealY  == 6 && isRealX == 4  ){
				//	scoreData[i]+=90;
				//}else{
				scoreData[i]+=15;
				//}
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
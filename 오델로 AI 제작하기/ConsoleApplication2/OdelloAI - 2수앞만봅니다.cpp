#include "��â��_2012180004.h"

// AI ���鶧 ���� �켱������ ���� ������ �������� �����.
// ��Ʈ�� �ִ� �κ��� �������� ������ ����. �� �� ���� ������ �ؾ��ҵ��ϴ�.
// ��Ʈ�� �ִ°��� ���ڸ� �ľ��Ͽ�, �ش� ���ڰ� 0�ϰ�� ���� �Ѱ��ִ� ����� �����Ѵ�.
// AI�� �ش� ��Ʈ�� �ִ� ��ġ������ �������� �Ǵ��Ͽ�, �ش� ���� ������ ���� ������ AI�� ���� ������� �ؾ��ҵ��ϴ�.

enum{ None, Black, White, Hint };
enum{ GameStart, GameEnd, ComputerThink};

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
int isAIx[isAiArrangement], isAIy[isAiArrangement], isAiCount[isAiArrangement], istAiCount=0, ismovetemp[isAiTempData]; // AI ������ �迭

int tempX=1, tempY=1;
int isPlayUser = White, temp, isGameState = GameStart;
int isBlackNum =0, isWhiteNum = 0;
int isTempRx, isTempRy;

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// AI ���� ��������
int isAiNext[isOdelloData][isOdelloData];
int isAIxNext[isAiArrangement], isAIyNext[isAiArrangement], isAiCountNext[isAiArrangement];
int istAiCountNext=0, ismovetempNext[isAiTempData];
int isCheckStones[isAiArrangement];
int isTwoCheckStones[isAiArrangement];
int isAiPutX, isAiPutY, isAiNextCheck=0;
// AI �÷��� ���úκ�
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

	arr[4][3] = Black; //������ ��
	arr[3][4] = Black;
	arr[3][3] = White; //��� ��
	arr[4][4] = White;

	isAiNext[4][3] = Black; //������ ��
	isAiNext[3][4] = Black;
	isAiNext[3][3] = White; //��� ��
	isAiNext[4][4] = White;

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

		if( isBlackNum + isWhiteNum == isGameTheEndData){//���� ��..!
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

		if(isAiCount[0] == 0 ){ //������ �ִ°��� �������
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
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(0);
	for(int k=1; k<=6; ++k){
		printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
		isDrawBWstones(k);
	}
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	isDrawBWstones(7);
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��\n");
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
					printf("��");
				if( isPlayUser == White)
					printf("��");
			}else{
				printf("%c%c", isSpace,isSpace);
			}

		}else{

			if(line == tempY-1  && i == tempX-1){
				if( isPlayUser == Black)
					printf("��");
				if( isPlayUser == White)
					printf("��");
			}else{ // if(line == tempY-1  && i == tempX-1){

				if( arr[line][i] == Hint ){
					printf("��");
				}

				if( arr[line][i] == Black){
					printf("��");
					++isBlackData;
				}
				if( arr[line][i] == White){
					printf("��");
					++isWhiteData;
				}

			} // if(line == tempY-1  && i == tempX-1){
		}
		printf("%c%c", isSpace,isSpace);
	} //for(i=0; i<8; ++i){
	printf("(%d,%d)", isBlackData, isWhiteData); //���� ����
	for(int i=0; i<isOdelloData; ++i){
		printf("%2d", isAiNext[line][i]); //���� ����
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
		printf("(%d,%d)", isBlackData, isWhiteData); //���� ����
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
				if( isPlayUser == Black){ //�������ϰ��
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
					//����ϰ��
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
				if( isPlayUser == Black){ //�������ϰ��
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
					//����ϰ��
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
// AI ���úκ�
void isAiWhiteStones(){
	int tempArr[isOdelloData][isOdelloData];
	isHintClear();
	for( int i=0; i<isOdelloData; ++i){
		for( int j=0; j<isOdelloData; ++j){
			tempArr[i][j] = isAiNext[i][j];
		}
	}
	// �� tempArr ���ٰ� ���� �����͸� ������ �س�����..!
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
	// isAIx[0], isAIy[0] �� ���� ���� ������ ����̴�.
	for(int i=0; i<isAiArrangement; ++i){
		// ���� ���� ������ ������ �����Ͽ�, �񱳸� �����Ѵ�..!
		if( isAIx[i] == 0 && isAIy[i] == 0 && isAiCount[i] == 0){
			break; //���̻� ������ �����Ƿ� for�� �������´�.
		}
		isAiPutX = isAIx[i], isAiPutY = isAIy[i];
		isWhiteStonesChecker();
		isHintLoad();

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

		isCheckStones[i] = isAiCount[i] - isAiCountNext[0];

		//	printf("\n");
		//for(int i=0; i<20; ++i){
		//	printf("%3d", isAiCount[i]); //���� ����
		//}
		//printf("\n");
		//for(int i=0; i<10; ++i){
		//	printf("(%d,%d) ", isAIx[i],isAIy[i]); //���� ����
		//}
		//printf("\n");
		//for(int i=0; i<20; ++i){
		//	printf("%3d", isAiCountNext[i]); //���� ����
		//}
		//printf("\n");
		//for(int i=0; i<10; ++i){
		//	printf("(%d,%d) ", isAIxNext[i],isAIyNext[i]); //���� ����
		//}
		//printf("\n");
		//printf("\n");
		//for(int i=0; i<isAiArrangement; ++i){
		//	printf("%d ", isCheckStones[i]); //���� ����
		//}
		//Sleep(3000);

		for( int i=0; i<isOdelloData; ++i){
			for( int j=0; j<isOdelloData; ++j){
				isAiNext[i][j] = tempArr[i][j];
			}
		}
		if (i<isAiArrangement){
			istAiCountNext=0;
			for(int i=0; i<isAiArrangement; ++i){
				isAIxNext[i] = 0,isAIyNext[i] = 0, isAiCountNext[i] = 0;
			}
		}
	}

	for(int i=0; i<isAiArrangement-1; ++i){
		for(int j=i+1; j<isAiArrangement; ++j){
			if( isCheckStones[i] < isCheckStones[j] ){
				//printf("\nChange\n");
				int tempData = isCheckStones[i];
				isCheckStones[i] = isCheckStones[j];
				isCheckStones[j] = tempData;

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

	//printf("\n");
	//for(int i=0; i<20; ++i){
	//	printf("%3d", isAiCount[i]); //���� ����
	//}
	//printf("\n");
	//for(int i=0; i<10; ++i){
	//	printf("(%d,%d) ", isAIx[i],isAIy[i]); //���� ����
	//}
	//printf("\n");
	//for(int i=0; i<20; ++i){
	//	printf("%3d", isAiCountNext[i]); //���� ����
	//}
	//printf("\n");
	//for(int i=0; i<10; ++i){
	//	printf("(%d,%d) ", isAIxNext[i],isAIyNext[i]); //���� ����
	//}
	//printf("\n");
	//printf("\n");
	//for(int i=0; i<isAiArrangement; ++i){
	//	printf("%d ", isCheckStones[i]); //���� ����
	//}
	//Sleep(3000);
	if( isAIx[0] == 0 && isAIy[0] == 0 && isAiCount[0] == 0){
		for(int i=0; i<isAiArrangement; ++i){
			if(isAiCount[i] !=0){
				// ���� ������ �ִ� �ڸ��� ���δ� -1 �����ϰ�쿡�� ���� ���� �ֱٲ� ����Ѵ�..!
				isAIx[0] = isAIx[i], isAIy[0] = isAIy[i], isAiCount[0] =  isAiCount[i];
				break;
			}
		}
	}
	for(int i=0; i<isAiArrangement; ++i){
		isCheckStones[i] = 0; // üũ�ϴºκ��� ������ �ʱ�ȭ�� ����� �Ѵ�..!
	}

	for(int i=0; i<isAiArrangement; ++i){
		//���� �ڸ��� ��Ʈ�� ������찡 �����Ƿ� üũ�� �Ѵ�.
		// �켱���� 1���!!!
		if( isAIx[i] == 0 && isAIy[i] == 0 && isAiCount[i] != 0){
			isAIx[0] = isAIx[i], isAIy[0] = isAIy[i];
		}else if( isAIx[i] == 0 && isAIy[i] == 7 && isAiCount[i] != 0){
			isAIx[0] = isAIx[i], isAIy[0] = isAIy[i];															  
		}else if( isAIx[i] == 7 && isAIy[i] == 0 && isAiCount[i] != 0){
			isAIx[0] = isAIx[i], isAIy[0] = isAIy[i];														  
		}else if( isAIx[i] == 7 && isAIy[i] == 7 && isAiCount[i] != 0){
			isAIx[0] = isAIx[i], isAIy[0] = isAIy[i];
		}
	}

	tempX = isAIx[0]+1, tempY = isAIy[0]+1;
	isAiPutX = isAIx[0], isAiPutY = isAIy[0];
	isWhiteStonesChecker();
	isAiNext[tempY-1][tempX-1] = White;
	isAddStones();
}



void isAIGetGPS(int isY, int isX) {
	isAiPutX = isX, isAiPutY = isY;
	isBlackStonesChecker();
	isAiNext[isY][isX] = Black;
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

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
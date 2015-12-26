#pragma once

#include "OdeloBattleSystem.h"

#define isOdelloData_2012180004 8 // ������ ��
#define isAiArrangement_2012180004 20 // AI �迭 ��
#define isAiTempData_2012180004 3 // AI �迭 ��
// ������ ��[y][x]
enum{ None, Black, White, Hint };
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int isBlackArr_2012180004[8][8];
bool isBlackStart_2012180004 = false, isBlackAiCheckTF_2012180004 = false;
int isBlackAIx_2012180004[isAiArrangement_2012180004], isBlackAIy_2012180004[isAiArrangement_2012180004];
int isBlackAiCount_2012180004[isAiArrangement_2012180004]; // AI ������ �迭
int istBlackAiCount_2012180004=0, isBlackmovetemp_2012180004[isAiTempData_2012180004]; // AI ������ �迭
int isTempRy_2012180004, isTempRx_2012180004; // ��Ʈ�� �ٶ����� ��ġ�� �Ѱ��ش�.
// Next ������ �κ� ��
int isBlackAiNext_2012180004[isOdelloData_2012180004][isOdelloData_2012180004];
int isBlackAIxNext_2012180004[isAiArrangement_2012180004], isBlackAIyNext_2012180004[isAiArrangement_2012180004];
int isBlackAiCountNext_2012180004[isAiArrangement_2012180004];
int istBlackAiCountNext_2012180004=0, isBlackmovetempNext_2012180004[isAiTempData_2012180004];
int isBlackCheckStones_2012180004[isAiArrangement_2012180004];
int isBlackAiPutX_2012180004, isBlackAiPutY_2012180004, isBlackAiNextCheck_2012180004=0;
// AI �������
int isYourX =0, isYourY = 0, isYourCount =0, isAIScore =30;
int isGame=0;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void isBlackReverseStones_2012180004(); // BlackAttack �Ҷ�
void isWhiteReverseStones_2012180004(); // BlackDefence �Ҷ�
void isHintLoad_2012180004(); // ��Ʈ�κ��� Ȯ���� �Ҷ� ����Ѵ�.
void isHintCheck_2012180004(); // ��Ʈ�κ��� üŷ�Ϸ��� �Ҷ� ����Ѵ�.
void isHintClear_2012180004(); //Hint�� �ʱ�ȭ�Ѵ�.
void isAiPlus();

void isBlackStonesChecker_2012180004(); //AI �ڽ��� ���� �ѱ涧
void isWhiteStonesChecker_2012180004(); //AI ���� ���� �ѱ涧
void isNextHintClear_2012180004(); //Hint�� �ʱ�ȭ�Ѵ�.
void isNextHintLoad_2012180004(); // ��Ʈ�κ��� Ȯ���� �Ҷ� ����Ѵ�.
void isNextHintCheck_2012180004(); // ��Ʈ�κ��� üŷ�Ϸ��� �Ҷ� ����Ѵ�.
void isNextAiPlus();


void BlackAttack_2012180004( int *x, int *y ){
	if( isBlackStart_2012180004 == false){
		isBlackArr_2012180004[3][3] = Black;
		isBlackArr_2012180004[3][4] = White;
		isBlackArr_2012180004[4][3] = White;
		isBlackArr_2012180004[4][4] = Black;
		// Next AI �迭
		isBlackAiNext_2012180004[3][3] = Black;
		isBlackAiNext_2012180004[3][4] = White;
		isBlackAiNext_2012180004[4][3] = White;
		isBlackAiNext_2012180004[4][4] = Black;
		isBlackStart_2012180004 = true;
		//printf("FirstStart!!!\n"); ó�� ���۽ÿ��� �ǿ����� ������ �ƹ��͵� ������ ���� ����ش�.
	}
	isHintClear_2012180004(); // ��Ʈ�� �ʱ�ȭ ����
	isHintLoad_2012180004(); // ��Ʈ�� ����� ���ش�.
	isAiPlus();

	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isBlackAiCount_2012180004[i] < isBlackAiCount_2012180004[j] ){
				isBlackmovetemp_2012180004[0]=isBlackAiCount_2012180004[i];
				isBlackmovetemp_2012180004[1]=isBlackAIx_2012180004[i];
				isBlackmovetemp_2012180004[2]=isBlackAIy_2012180004[i];

				isBlackAiCount_2012180004[i] = isBlackAiCount_2012180004[j];
				isBlackAIx_2012180004[i] = isBlackAIx_2012180004[j];
				isBlackAIy_2012180004[i] = isBlackAIy_2012180004[j];

				isBlackAiCount_2012180004[j] = isBlackmovetemp_2012180004[0];
				isBlackAIx_2012180004[j] = isBlackmovetemp_2012180004[1];
				isBlackAIy_2012180004[j] = isBlackmovetemp_2012180004[2];
			} 
		} 
	}

	int tempArr[isOdelloData_2012180004][isOdelloData_2012180004];
	isNextHintClear_2012180004();
	for( int i=0; i<isOdelloData_2012180004; ++i){
		for( int j=0; j<isOdelloData_2012180004; ++j){
			tempArr[i][j] = isBlackAiNext_2012180004[i][j];
		}
	}

	for(int i=0; i<isAiArrangement_2012180004; ++i){
		// ���� ���� ������ ������ �����Ͽ�, �񱳸� �����Ѵ�..!
		if( isBlackAIx_2012180004[i] == 0 && isBlackAIy_2012180004[i] == 0 && isBlackAiCount_2012180004[i] == 0){
			printf("---------------------(%d, %d)---------------------\n",isBlackAIx_2012180004[0], isBlackAIy_2012180004[0]);
			break; //���̻� ������ �����Ƿ� for�� �������´�.
		}
		isBlackAiPutX_2012180004 = isBlackAIx_2012180004[i], isBlackAiPutY_2012180004 = isBlackAIy_2012180004[i];
		isBlackStonesChecker_2012180004();
		isNextHintLoad_2012180004();
		isNextAiPlus();

		for(int i=0; i<isAiArrangement_2012180004-1; ++i){
			for(int j=i+1; j<isAiArrangement_2012180004; ++j){
				if( isBlackAiCountNext_2012180004[i] < isBlackAiCountNext_2012180004[j] ){
					isBlackmovetempNext_2012180004[0]=isBlackAiCountNext_2012180004[i];
					isBlackmovetempNext_2012180004[1]=isBlackAIxNext_2012180004[i];
					isBlackmovetempNext_2012180004[2]=isBlackAIyNext_2012180004[i];

					isBlackAiCountNext_2012180004[i] = isBlackAiCountNext_2012180004[j];
					isBlackAIxNext_2012180004[i] = isBlackAIxNext_2012180004[j];
					isBlackAIyNext_2012180004[i] = isBlackAIyNext_2012180004[j];

					isBlackAiCountNext_2012180004[j] = isBlackmovetempNext_2012180004[0];
					isBlackAIxNext_2012180004[j] = isBlackmovetempNext_2012180004[1];
					isBlackAIyNext_2012180004[j] = isBlackmovetempNext_2012180004[2];
				} 
			} 
		}
		 isYourX =isBlackAIxNext_2012180004[0], isYourY = isBlackAIyNext_2012180004[0];

		isBlackCheckStones_2012180004[i] = isBlackAiCount_2012180004[i] - isBlackAiCountNext_2012180004[0];

		for( int i=0; i<isOdelloData_2012180004; ++i){
			for( int j=0; j<isOdelloData_2012180004; ++j){
				isBlackAiNext_2012180004[i][j] = tempArr[i][j];
			}
		}
		if (i<isAiArrangement_2012180004){
			istBlackAiCountNext_2012180004=0;
			for(int i=0; i<isAiArrangement_2012180004; ++i){
				isBlackAIxNext_2012180004[i] = 0,isBlackAIyNext_2012180004[i] = 0, isBlackAiCountNext_2012180004[i] = 0;
			}
		}
	}

	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isBlackCheckStones_2012180004[i] < isBlackCheckStones_2012180004[j] ){
				//printf("\nChange\n");
				int tempData = isBlackCheckStones_2012180004[i];
				isBlackCheckStones_2012180004[i] = isBlackCheckStones_2012180004[j];
				isBlackCheckStones_2012180004[j] = tempData;

				isBlackmovetemp_2012180004[0]=isBlackAiCount_2012180004[i];
				isBlackmovetemp_2012180004[1]=isBlackAIx_2012180004[i];
				isBlackmovetemp_2012180004[2]=isBlackAIy_2012180004[i];

				isBlackAiCount_2012180004[i] = isBlackAiCount_2012180004[j];
				isBlackAIx_2012180004[i] = isBlackAIx_2012180004[j];
				isBlackAIy_2012180004[i] = isBlackAIy_2012180004[j];

				isBlackAiCount_2012180004[j] = isBlackmovetemp_2012180004[0];
				isBlackAIx_2012180004[j] = isBlackmovetemp_2012180004[1];
				isBlackAIy_2012180004[j] = isBlackmovetemp_2012180004[2];
			} 
		} 
	}

	if( isBlackAIx_2012180004[0] == 0 && isBlackAIy_2012180004[0] == 0 && isBlackAiCount_2012180004[0] == 0){
		for(int i=0; i<isAiArrangement_2012180004; ++i){
			if(isBlackAiCount_2012180004[i] !=0){
				// ���� ������ �ִ� �ڸ��� ���δ� -1 �����ϰ�쿡�� ���� ���� �ֱٲ� ����Ѵ�..!
				isBlackAIx_2012180004[0] = isBlackAIx_2012180004[i], isBlackAIy_2012180004[0] = isBlackAIy_2012180004[i];
				isBlackAiCount_2012180004[0] =  isBlackAiCount_2012180004[i];
				break;
			}
		}
	}
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isBlackCheckStones_2012180004[i] = 0; // üũ�ϴºκ��� ������ �ʱ�ȭ�� ����� �Ѵ�..!
	}

	int isRealPut =0;


	//------------------------------------------------------------------------------------------------------------------------------------------
	isBlackArr_2012180004[isBlackAIy_2012180004[isRealPut]][isBlackAIx_2012180004[isRealPut]] = Black;
	isTempRy_2012180004=isBlackAIy_2012180004[isRealPut], isTempRx_2012180004=isBlackAIx_2012180004[isRealPut];
	isBlackReverseStones_2012180004();

	*x = isBlackAIx_2012180004[isRealPut];
	*y = isBlackAIy_2012180004[isRealPut];
	// �������� ������ �����ϴ� �κ�
	printf("BlackAttack!!! ( %d, %d )\n", isBlackAIx_2012180004[isRealPut], isBlackAIy_2012180004[isRealPut] );
	//------------------------------------------------------------------------------------------------------------------------------------------
	//isGame++;
	//if(isGame >= 21){
	//	printf(" �浹�� �¸��Ͽ����ϴ�.\n ");
	//	exit(0);
	//}
	//system("pause");
}

void BlackDefence_2012180004( int x, int y ){
	printf("BlackDefence!!! ( %d, %d )\n", x,y);

	if(isYourX != x && isYourY != y){
		isYourCount++;
	}else{
		isYourCount--;
	}
	if( isYourCount >=2){
		isAIScore =100;
	}
	isHintClear_2012180004();
	isBlackArr_2012180004[y][x] = White;
	isTempRy_2012180004=y, isTempRx_2012180004=x;
	isWhiteReverseStones_2012180004();
}

void isHintLoad_2012180004(){
	// None = 0, Black =1, White = 2, Hint = 3
	isTempRy_2012180004=0, isTempRx_2012180004=0;
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if( isBlackArr_2012180004[i][j] == None){
				isTempRy_2012180004= i, isTempRx_2012180004=j;
				isHintCheck_2012180004();

				if(istBlackAiCount_2012180004 >= isAiArrangement_2012180004)
					break;

				if( isBlackAiCheckTF_2012180004 == true){
					isBlackArr_2012180004[i][j] = Hint;
					isBlackAIx_2012180004[istBlackAiCount_2012180004] = isTempRx_2012180004;
					isBlackAIy_2012180004[istBlackAiCount_2012180004] = isTempRy_2012180004;
					++istBlackAiCount_2012180004;
					isBlackAiCheckTF_2012180004=false;
				}
			}
		}
	}
}

void isHintCheck_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] != None 
				&& isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] != Hint){
					// ���
					if( isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] == White){
						int tXt=isTempRx_2012180004+l, tYt=isTempRy_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackArr_2012180004[tYt][tXt]!=White || isBlackArr_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackArr_2012180004[tYt][tXt]==None || isBlackArr_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isTempRx_2012180004 || tYt!=isTempRy_2012180004){
								++isBlackAiCount_2012180004[istBlackAiCount_2012180004];
								tXt-=l;tYt-=k;
								isBlackAiCheckTF_2012180004 = true;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

void isHintClear_2012180004(){
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if(isBlackArr_2012180004[i][j] == Hint){
				isBlackArr_2012180004[i][j] = None;
			}
		}
	}
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isBlackAIx_2012180004[i] = 0, isBlackAIy_2012180004[i] = 0, isBlackAiCount_2012180004[i] = 0, istBlackAiCount_2012180004=0;
	}
	for(int i=0; i<isAiTempData_2012180004; ++i){
		isBlackmovetemp_2012180004[i] =0;
	}
}

void isBlackReverseStones_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] != None 
				&& isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] != Hint){
					// ����
					if( isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] == White){
						int tXt=isTempRx_2012180004+l, tYt=isTempRy_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackArr_2012180004[tYt][tXt]!=White || isBlackArr_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackArr_2012180004[tYt][tXt]==None || isBlackArr_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isTempRx_2012180004 || tYt!=isTempRy_2012180004){
								isBlackArr_2012180004[tYt][tXt]=Black;
								tXt-=l;tYt-=k;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

void isWhiteReverseStones_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] != None 
				&& isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] != Hint){
					// ���
					if( isBlackArr_2012180004[isTempRy_2012180004+k][isTempRx_2012180004+l] == Black){
						int tXt=isTempRx_2012180004+l, tYt=isTempRy_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackArr_2012180004[tYt][tXt]!=Black || isBlackArr_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackArr_2012180004[tYt][tXt]==None || isBlackArr_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isTempRx_2012180004 || tYt!=isTempRy_2012180004){
								isBlackArr_2012180004[tYt][tXt]=White;
								tXt-=l;tYt-=k;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

//-------------------------------------------------------------------------------------------------------------------------
void isBlackStonesChecker_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			if(isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] != None 
				&& isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] != Hint){
					if( isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] == White){
						int tXt=isBlackAiPutX_2012180004+l, tYt=isBlackAiPutY_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackAiNext_2012180004[tYt][tXt]!=White || isBlackAiNext_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackAiNext_2012180004[tYt][tXt]==None || isBlackAiNext_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isBlackAiPutX_2012180004 || tYt!=isBlackAiPutY_2012180004){
								isBlackAiNext_2012180004[tYt][tXt]=Black;
								tXt-=l;tYt-=k;
							}
						}
					}
			}
		} 
	} 
}

void isNextHintLoad_2012180004(){
	isTempRy_2012180004= 0, isTempRx_2012180004=0;
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if( isBlackAiNext_2012180004[i][j] == None){
				isBlackAiPutY_2012180004= i, isBlackAiPutX_2012180004=j;
				isNextHintCheck_2012180004();

				if(istBlackAiCountNext_2012180004 >= isAiArrangement_2012180004)
					break;

				if( isBlackAiNextCheck_2012180004 == 1){
					isBlackAiNext_2012180004[i][j] = Hint;
					isBlackAIxNext_2012180004[istBlackAiCountNext_2012180004] = isBlackAiPutX_2012180004;
					isBlackAIyNext_2012180004[istBlackAiCountNext_2012180004] = isBlackAiPutY_2012180004;
					++istBlackAiCountNext_2012180004;
					isBlackAiNextCheck_2012180004=0;
				}
			}
		}
	}
}

void isNextHintCheck_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			if(isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] != None 
				&& isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] != Hint){
					if( isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] == White){
						int tXt=isBlackAiPutX_2012180004+l, tYt=isBlackAiPutY_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackAiNext_2012180004[tYt][tXt]!=White || isBlackAiNext_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackAiNext_2012180004[tYt][tXt]==None || isBlackAiNext_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isBlackAiPutX_2012180004 || tYt!=isBlackAiPutY_2012180004){
								++isBlackAiCountNext_2012180004[istBlackAiCountNext_2012180004];
								tXt-=l;tYt-=k;
								isBlackAiNextCheck_2012180004=1;
							}
						}
					}
			}
		}
	}
}

void isNextHintClear_2012180004(){
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if(isBlackAiNext_2012180004[i][j] == Hint){
				isBlackAiNext_2012180004[i][j] = None;
			}
		}
	}
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isBlackAIxNext_2012180004[i] = 0, isBlackAIyNext_2012180004[i] = 0, isBlackAiCountNext_2012180004[i] = 0, istBlackAiCountNext_2012180004=0;
	}
	for(int i=0; i<isAiTempData_2012180004; ++i){
		isBlackmovetempNext_2012180004[i] =0;
	}
}
//-------------------------------------------------------------------------------------------------------------------------

void isAiPlus(){
for(int i=0; i<isAiArrangement_2012180004; ++i){
		// ����ġ ���
		if( isBlackAIx_2012180004[i] == 0 && isBlackAIy_2012180004[i] == 0 && isBlackAiCount_2012180004[i] == 0)
			break;
		if((isBlackAIy_2012180004[i] == 0 && isBlackAIx_2012180004[i] == 0) || (isBlackAIy_2012180004[i] == 0 && isBlackAIx_2012180004[i] ==7) || (isBlackAIy_2012180004[i] == 7 && isBlackAIx_2012180004[i] ==0) || (isBlackAIy_2012180004[i] == 7 && isBlackAIx_2012180004[i] ==7)){
			// ���� ��
			isBlackAiCount_2012180004[i]+=100;
		}else if(((isBlackAIy_2012180004[i] == 0 || isBlackAIy_2012180004[i] == 7) && (1<=isBlackAIx_2012180004[i] && isBlackAIx_2012180004[i]<=6))||((isBlackAIx_2012180004[i] == 0 || isBlackAIx_2012180004[i] == 7) && (1<=isBlackAIy_2012180004[i] && isBlackAIy_2012180004[i]<=6))){
			// �Ķ���
			if(isBlackAIy_2012180004[i]  == 1 && isBlackAIx_2012180004[i] == 0 || isBlackAIy_2012180004[i]  == 0 && isBlackAIx_2012180004[i] == 1 ){
				if(isBlackArr_2012180004[0][0] == Black){
					isBlackAiCount_2012180004[i]+=90;
				}else{
				isBlackAiCount_2012180004[i]+=60;
				}
			}else if(isBlackAIy_2012180004[i]  == 0 && isBlackAIx_2012180004[i] == 6 || isBlackAIy_2012180004[i]  == 1 && isBlackAIx_2012180004[i] == 7 ){
				if(isBlackArr_2012180004[0][7] == Black){
					isBlackAiCount_2012180004[i]+=90;
				}else{
				isBlackAiCount_2012180004[i]+=60;
				}
			}else if(isBlackAIy_2012180004[i]  == 6 && isBlackAIx_2012180004[i] == 0 || isBlackAIy_2012180004[i]  == 7 && isBlackAIx_2012180004[i] == 1 ){
				if(isBlackArr_2012180004[7][0] == Black){
					isBlackAiCount_2012180004[i]+=90;
				}else{
				isBlackAiCount_2012180004[i]+=60;
				}
			}else if(isBlackAIy_2012180004[i]  == 6 && isBlackAIx_2012180004[i] ==7 || isBlackAIy_2012180004[i]  == 7 && isBlackAIx_2012180004[i] == 6 ){
				if(isBlackArr_2012180004[7][7] == Black){
					isBlackAiCount_2012180004[i]+=90;
				}else{
				isBlackAiCount_2012180004[i]+=60;
				}
			}else{
				isBlackAiCount_2012180004[i]+=80;
			}
		}else if( (2<=isBlackAIy_2012180004[i] && isBlackAIy_2012180004[i]<= 5) && (2<=isBlackAIx_2012180004[i] && isBlackAIx_2012180004[i]<= 5) ){
			// �ʷϻ�
			if(isBlackAIy_2012180004[i]  == 2 && isBlackAIx_2012180004[i] == 2 ){
				isBlackAiCount_2012180004[i]+=70;
			}else if(isBlackAIy_2012180004[i]  == 2 && isBlackAIx_2012180004[i] == 5 ){
				isBlackAiCount_2012180004[i]+=70;
			}else if(isBlackAIy_2012180004[i]  == 5 && isBlackAIx_2012180004[i] == 2 ){
				isBlackAiCount_2012180004[i]+=70;
			}else if(isBlackAIy_2012180004[i]  == 5 && isBlackAIx_2012180004[i] == 5 ){
				isBlackAiCount_2012180004[i]+=70;
			}else{
				isBlackAiCount_2012180004[i]+=30;
			}
		}else if( (isBlackAIy_2012180004[i] == 1 && isBlackAIx_2012180004[i] == 1) || (isBlackAIy_2012180004[i] == 1 && isBlackAIx_2012180004[i] == 6) || (isBlackAIy_2012180004[i] == 6 && isBlackAIx_2012180004[i] == 1) || (isBlackAIy_2012180004[i] == 6 && isBlackAIx_2012180004[i] == 6) ){
			// ������
			isBlackAiCount_2012180004[i]+=1;
		}else{
			// �����
			if(isBlackAIy_2012180004[i]  == 1 && isBlackAIx_2012180004[i] == 2 || isBlackAIy_2012180004[i]  == 1 && isBlackAIx_2012180004[i] == 2 ){
				isBlackAiCount_2012180004[i]+=35;
			}else if(isBlackAIy_2012180004[i]  == 5 && isBlackAIx_2012180004[i] == 1 || isBlackAIy_2012180004[i]  == 2 && isBlackAIx_2012180004[i] == 6 ){
				isBlackAiCount_2012180004[i]+=35;
			}else if(isBlackAIy_2012180004[i]  == 1 && isBlackAIx_2012180004[i] == 5 || isBlackAIy_2012180004[i]  == 6 && isBlackAIx_2012180004[i] == 2 ){
				isBlackAiCount_2012180004[i]+=35;
			}else if(isBlackAIy_2012180004[i]  == 5 && isBlackAIx_2012180004[i] == 6 || isBlackAIy_2012180004[i]  == 6 && isBlackAIx_2012180004[i] == 5 ){
				isBlackAiCount_2012180004[i]+=35;
			}else{
				isBlackAiCount_2012180004[i]+=15;
			}
		}
	}
}

void isNextAiPlus(){
for(int i=0; i<isAiArrangement_2012180004; ++i){
		// ����ġ ���
		if( isBlackAIxNext_2012180004[i] == 0 && isBlackAIyNext_2012180004[i] == 0 && isBlackAiCountNext_2012180004[i] == 0)
			break;
		if((isBlackAIyNext_2012180004[i] == 0 && isBlackAIxNext_2012180004[i] == 0) || (isBlackAIyNext_2012180004[i] == 0 && isBlackAIxNext_2012180004[i] ==7) || (isBlackAIyNext_2012180004[i] == 7 && isBlackAIxNext_2012180004[i] ==0) || (isBlackAIyNext_2012180004[i] == 7 && isBlackAIxNext_2012180004[i] ==7)){
			// ���� ��
			isBlackAiCountNext_2012180004[i]+=100;
		}else if(((isBlackAIyNext_2012180004[i] == 0 || isBlackAIyNext_2012180004[i] == 7) && (1<=isBlackAIxNext_2012180004[i] && isBlackAIxNext_2012180004[i]<=6))||((isBlackAIxNext_2012180004[i] == 0 || isBlackAIxNext_2012180004[i] == 7) && (1<=isBlackAIyNext_2012180004[i] && isBlackAIyNext_2012180004[i]<=6))){
			// �Ķ���
			if(isBlackAIyNext_2012180004[i]  == 1 && isBlackAIxNext_2012180004[i] == 0 || isBlackAIyNext_2012180004[i]  == 0 && isBlackAIxNext_2012180004[i] == 1 ){
				if(isBlackArr_2012180004[0][0] == Black){
					isBlackAiCountNext_2012180004[i]+=90;
				}else{
				isBlackAiCountNext_2012180004[i]+=60;
				}
			}else if(isBlackAIyNext_2012180004[i]  == 0 && isBlackAIxNext_2012180004[i] == 6 || isBlackAIyNext_2012180004[i]  == 1 && isBlackAIxNext_2012180004[i] == 7 ){
				if(isBlackArr_2012180004[0][7] == Black){
					isBlackAiCountNext_2012180004[i]+=90;
				}else{
				isBlackAiCountNext_2012180004[i]+=60;
				}
			}else if(isBlackAIyNext_2012180004[i]  == 6 && isBlackAIxNext_2012180004[i] == 0 || isBlackAIyNext_2012180004[i]  == 7 && isBlackAIxNext_2012180004[i] == 1 ){
				if(isBlackArr_2012180004[7][0] == Black){
					isBlackAiCountNext_2012180004[i]+=90;
				}else{
				isBlackAiCountNext_2012180004[i]+=60;
				}
			}else if(isBlackAIyNext_2012180004[i]  == 6 && isBlackAIxNext_2012180004[i] ==7 || isBlackAIyNext_2012180004[i]  == 7 && isBlackAIxNext_2012180004[i] == 6 ){
				if(isBlackArr_2012180004[7][7] == Black){
					isBlackAiCountNext_2012180004[i]+=90;
				}else{
				isBlackAiCountNext_2012180004[i]+=60;
				}
			}else{
				isBlackAiCountNext_2012180004[i]+=80;
			}
		}else if( (2<=isBlackAIyNext_2012180004[i] && isBlackAIyNext_2012180004[i]<= 5) && (2<=isBlackAIxNext_2012180004[i] && isBlackAIxNext_2012180004[i]<= 5) ){
			// �ʷϻ�
			if(isBlackAIyNext_2012180004[i]  == 2 && isBlackAIxNext_2012180004[i] == 2 ){
				isBlackAiCountNext_2012180004[i]+=70;
			}else if(isBlackAIyNext_2012180004[i]  == 2 && isBlackAIxNext_2012180004[i] == 5 ){
				isBlackAiCountNext_2012180004[i]+=70;
			}else if(isBlackAIyNext_2012180004[i]  == 5 && isBlackAIxNext_2012180004[i] == 2 ){
				isBlackAiCountNext_2012180004[i]+=70;
			}else if(isBlackAIyNext_2012180004[i]  == 5 && isBlackAIxNext_2012180004[i] == 5 ){
				isBlackAiCountNext_2012180004[i]+=70;
			}else{
				isBlackAiCountNext_2012180004[i]+=30;
			}
		}else if( (isBlackAIyNext_2012180004[i] == 1 && isBlackAIxNext_2012180004[i] == 1) || (isBlackAIyNext_2012180004[i] == 1 && isBlackAIxNext_2012180004[i] == 6) || (isBlackAIyNext_2012180004[i] == 6 && isBlackAIxNext_2012180004[i] == 1) || (isBlackAIyNext_2012180004[i] == 6 && isBlackAIxNext_2012180004[i] == 6) ){
			// ������
			isBlackAiCountNext_2012180004[i]+=1;
		}else{
			// �����
			if(isBlackAIyNext_2012180004[i]  == 1 && isBlackAIxNext_2012180004[i] == 2 || isBlackAIyNext_2012180004[i]  == 1 && isBlackAIxNext_2012180004[i] == 2 ){
				isBlackAiCountNext_2012180004[i]+=35;
			}else if(isBlackAIyNext_2012180004[i]  == 5 && isBlackAIxNext_2012180004[i] == 1 || isBlackAIyNext_2012180004[i]  == 2 && isBlackAIxNext_2012180004[i] == 6 ){
				isBlackAiCountNext_2012180004[i]+=35;
			}else if(isBlackAIyNext_2012180004[i]  == 1 && isBlackAIxNext_2012180004[i] == 5 || isBlackAIyNext_2012180004[i]  == 6 && isBlackAIxNext_2012180004[i] == 2 ){
				isBlackAiCountNext_2012180004[i]+=35;
			}else if(isBlackAIyNext_2012180004[i]  == 5 && isBlackAIxNext_2012180004[i] == 6 || isBlackAIyNext_2012180004[i]  == 6 && isBlackAIxNext_2012180004[i] == 5 ){
				isBlackAiCountNext_2012180004[i]+=35;
			}else{
				isBlackAiCountNext_2012180004[i]+=15;
			}
		}
	}
}
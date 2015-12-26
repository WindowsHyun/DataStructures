#pragma once

#include "OdeloBattleSystem.h"

#define isOdelloData_2012180004 8 // 오델로 판
#define isAiArrangement_2012180004 20 // AI 배열 판
#define isAiTempData_2012180004 3 // AI 배열 판
// 오델로 판[y][x]
enum{ None, Black, White, Hint };
enum{ OneTurn, TwoTurn};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int isBlackArr_2012180004[8][8];
bool isBlackStart_2012180004 = false, isBlackAiCheckTF_2012180004 = false;
int isBlackAIx_2012180004[isAiArrangement_2012180004], isBlackAIy_2012180004[isAiArrangement_2012180004];
int isBlackAiCount_2012180004[isAiArrangement_2012180004]; // AI 관련한 배열
int istBlackAiCount_2012180004=0, isBlackmovetemp_2012180004[isAiTempData_2012180004]; // AI 관련한 배열
int isTempRy_2012180004, isTempRx_2012180004; // 힌트를 줄때돌의 위치를 넘겨준다.
// Next 관련한 부분 ↓
int isBlackAiNext_2012180004[isOdelloData_2012180004][isOdelloData_2012180004];
int isBlackAIxNext_2012180004[isAiArrangement_2012180004], isBlackAIyNext_2012180004[isAiArrangement_2012180004];
int isBlackAiCountNext_2012180004[isAiArrangement_2012180004];
int istBlackAiCountNext_2012180004=0, isBlackmovetempNext_2012180004[isAiTempData_2012180004];
int isBlackCheckStones_2012180004[isAiArrangement_2012180004];
int isBlackAiPutX_2012180004, isBlackAiPutY_2012180004, isBlackAiNextCheck_2012180004=0;
// AI 진행관련
int isYourX =0, isYourY = 0, isYourCount =0;
bool isGameLevelUP = false;
int isGame=0;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void isBlackReverseStones_2012180004(); // BlackAttack 할때
void isWhiteReverseStones_2012180004(); // BlackDefence 할때
void isHintLoad_2012180004(); // 힌트부분을 확인을 할때 사용한다.
void isHintCheck_2012180004(); // 힌트부분을 체킹하려고 할때 사용한다.
void isHintClear_2012180004(); //Hint를 초기화한다.

void isBlackStonesChecker_2012180004(); //AI 자신의 돌을 넘길때
void isWhiteStonesChecker_2012180004(); //AI 상대방 돌을 넘길때
void isNextHintClear_2012180004(); //Hint를 초기화한다.
void isNextHintLoad_2012180004(); // 힌트부분을 확인을 할때 사용한다.
void isNextHintCheck_2012180004(); // 힌트부분을 체킹하려고 할때 사용한다.

void isAiTotalPlus(int, int []); // 가중치 계산

void BlackAttack_2012180004( int *x, int *y ){
	if( isBlackStart_2012180004 == false){
		isBlackArr_2012180004[3][3] = Black;
		isBlackArr_2012180004[3][4] = White;
		isBlackArr_2012180004[4][3] = White;
		isBlackArr_2012180004[4][4] = Black;
		// Next AI 배열
		isBlackAiNext_2012180004[3][3] = Black;
		isBlackAiNext_2012180004[3][4] = White;
		isBlackAiNext_2012180004[4][3] = White;
		isBlackAiNext_2012180004[4][4] = Black;
		isBlackStart_2012180004 = true;
	}
	isHintClear_2012180004(); // 힌트를 초기화 한후
	isHintLoad_2012180004(); // 힌트를 재생성 해준다.
	isAiTotalPlus(OneTurn, isBlackAiCount_2012180004);

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
		// 가장 많이 뒤집는 경우부터 시작하여, 비교를 시작한다..!
		if( isBlackAIx_2012180004[0] == 0 && isBlackAIy_2012180004[0] == 0 && isBlackAiCount_2012180004[0] == 0){
			break; //더이상 돌릴게 없으므로 for문 빠져나온다.
		}
		isBlackAiPutX_2012180004 = isBlackAIx_2012180004[i], isBlackAiPutY_2012180004 = isBlackAIy_2012180004[i];
		isBlackStonesChecker_2012180004();
		isNextHintLoad_2012180004();
		isAiTotalPlus(TwoTurn, isBlackAiCountNext_2012180004);

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

		if( isBlackAiCount_2012180004[i] != 0 && isBlackAiCountNext_2012180004 != 0){
			isBlackCheckStones_2012180004[i] = isBlackAiCount_2012180004[i] - isBlackAiCountNext_2012180004[0];
		}
		//printf("%d - %d = %d\n", isBlackAiCount_2012180004[i], isBlackAiCountNext_2012180004[i],isBlackCheckStones_2012180004[i] );

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
			if( isBlackCheckStones_2012180004[i] <= isBlackCheckStones_2012180004[j] ){
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

	if(isGameLevelUP == true){
		for(int i=0; i<isAiArrangement_2012180004-1; ++i){
			for(int j=i+1; j<isAiArrangement_2012180004; ++j){
				if(isBlackAiCount_2012180004[i] <= isBlackAiCount_2012180004[j]){
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
	}

	printf("--------------------------------\n");
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		// 6,0
		printf("(%d, %d) = %d\n", isBlackAIx_2012180004[i], isBlackAIy_2012180004[i],isBlackAiCount_2012180004[i] );
	}
	printf("--------------------------------\n");

	if( isBlackAIx_2012180004[0] == 0 && isBlackAIy_2012180004[0] == 0 && isBlackAiCount_2012180004[0] == 0){
		for(int i=0; i<isAiArrangement_2012180004; ++i){
			if(isBlackAiCount_2012180004[i] !=0){
				// 내가 놓을수 있는 자리가 전부다 -1 이하일경우에는 그중 가장 최근껄 사용한다..!
				isBlackAIx_2012180004[0] = isBlackAIx_2012180004[i], isBlackAIy_2012180004[0] = isBlackAIy_2012180004[i];
				isBlackAiCount_2012180004[0] =  isBlackAiCount_2012180004[i];
				break;
			}
		}
	}
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isBlackCheckStones_2012180004[i] = 0; // 체크하는부분은 끝나면 초기화를 해줘야 한다..!
	}

	//------------------------------------------------------------------------------------------------------------------------------------------
	isBlackArr_2012180004[isBlackAIy_2012180004[0]][isBlackAIx_2012180004[0]] = Black;
	isTempRy_2012180004=isBlackAIy_2012180004[0], isTempRx_2012180004=isBlackAIx_2012180004[0];
	isBlackReverseStones_2012180004();

	// int isx=0, isy=0;
	//	printf("[%d / %d] BlackAttack!!! ( %d, %d )\n",isYourCount, isYourCount%2, isBlackAIx_2012180004[isRealPut], isBlackAIy_2012180004[isRealPut] );
	//	scanf("%d,%d", &isx, &isy);
	//*x = isx;
	//*y = isy;

	if(  isBlackAiCount_2012180004[0] != 0){
		*x = isBlackAIx_2012180004[0];
		*y = isBlackAIy_2012180004[0];
		// 검정색이 실제로 공격하는 부분
		printf("[%d / %d] BlackAttack!!! ( %d, %d )\n",isYourCount, isYourCount%2, isBlackAIx_2012180004[isRealPut], isBlackAIy_2012180004[isRealPut] );
	}else{
		//isBlackAIx_2012180004[i] == -1 , isBlackAIy_2012180004[i] == -1;
		printf("BlackAttack!!!\n자리가 없습니다..!\n");
	}
	//------------------------------------------------------------------------------------------------------------------------------------------
	//isGame++;
	//if(isGame >= 21){
	//}
}

void BlackDefence_2012180004( int x, int y ){
	printf("BlackDefence!!! ( %d, %d )\n", x,y);

	if(isYourX != x && isYourY != y){
		isYourCount++;
	}else{
		isYourCount--;
	}
	if( isYourCount >= 1){
		//if( isYourCount%2 == 0){
		isGameLevelUP =true;
	}else{
		isGameLevelUP = false;
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
					// 흰색
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
					// 검정
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
					// 흰색
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

void isAiTotalPlus(int whatPlay, int scoreData[]){
	//enum{ OneTurn, TwoTurn};
	int isRealX =0, isRealY =0;
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		if( whatPlay == OneTurn){
			isRealX =isBlackAIx_2012180004[i], isRealY = isBlackAIy_2012180004[i];
		}else{
			isRealX =isBlackAIxNext_2012180004[i], isRealY = isBlackAIyNext_2012180004[i];
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
				if(isBlackArr_2012180004[0][0] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 0 && isRealX == 6 || isRealY  == 1 && isRealX == 7 ){
				if(isBlackArr_2012180004[0][7] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 6 && isRealX == 0 || isRealY  == 7 && isRealX == 1 ){
				if(isBlackArr_2012180004[7][0] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 6 && isRealX ==7 || isRealY  == 7 && isRealX == 6 ){
				if(isBlackArr_2012180004[7][7] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else{

				/*if(isRealX == 2 && isRealY == 0 ||  isRealX == 0 && isRealY == 2){
				scoreData[i]+=70;
				}else if(isRealX == 5 && isRealY == 0 ||  isRealX == 7 && isRealY == 2){
				scoreData[i]+=70;
				}else if(isRealX == 0 && isRealY == 5 ||  isRealX == 2 && isRealY ==7){
				scoreData[i]+=70;
				}else if(isRealX == 7 && isRealY == 5 ||  isRealX == 5 && isRealY ==7){
				scoreData[i]+=70;
				}else{
				scoreData[i]+=80;
				}*/
				int isFakeData =0;
				int tempArr[8][8];
				for(int i=0; i<8; ++i){
					for(int j=0; j<8; ++j){
						if( isBlackArr_2012180004[i][j] == Black ){
							tempArr[i][j]  =Black;
						}else if ( isBlackArr_2012180004[i][j] == White){
							tempArr[i][j]  =White;
						}else{
							tempArr[i][j]  =None;
						}
					}
				}
				if(2<=isRealY && isRealY<=5){
					// 파란색 왼쪽 오른쪽
					printf("( %d, %d )\n", isRealX, isRealY);
					if( tempArr[isRealY-1][isRealX] == None && tempArr[isRealY+1][isRealX] == None ){
						printf("---------------------Bingo---------------------\n");
						scoreData[i]+=90;
					}else{
						if(isBlackArr_2012180004[isRealY-1][isRealX] == White){
							if(isBlackArr_2012180004[isRealY-2][isRealX] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						if(isBlackArr_2012180004[isRealY+1][isRealX] == White){
							if(isBlackArr_2012180004[isRealY+2][isRealX] == Black){
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
						printf("---------------------Bingo---------------------\n");
						scoreData[i]+=90;
					}else{
						if(isBlackArr_2012180004[isRealY][isRealX-1] == White){
							if(isBlackArr_2012180004[isRealY][isRealX-2] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						if(isBlackArr_2012180004[isRealY][isRealX+1] == White){
							if(isBlackArr_2012180004[isRealY][isRealX+2] == Black){
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
			/*if(isRealX == 6 && isRealY == 1 && isBlackArr_2012180004[7][0] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 1 && isRealY == 6 && isBlackArr_2012180004[0][7] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 1 && isRealY == 1 && isBlackArr_2012180004[7][7] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 6 && isRealY == 6 && isBlackArr_2012180004[0][0] == Black ){
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
				if(isRealY  == 6 && isRealX == 4  ){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=15;
				}
			}
		}
	}
}
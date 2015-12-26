#pragma once

#include "OdeloBattleSystem.h"

#define isOdelloData_2012180004 8 // 오델로 판
#define isAiArrangement_2012180004 20 // AI 배열 판
#define isAiTempData_2012180004 3 // AI 배열 판
// 오델로 판[y][x]
enum{ None, Black, White, Hint };
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int isWhiteArr_2012180004[8][8];
bool isWhiteStart_2012180004 = false, isWhiteAiCheckTF_2012180004 = false;
int isWhiteAIx_2012180004[isAiArrangement_2012180004], isWhiteAIy_2012180004[isAiArrangement_2012180004];
int isWhiteAiCount_2012180004[isAiArrangement_2012180004]; // AI 관련한 배열
int istWhiteAiCount_2012180004=0, isWhitemovetemp_2012180004[isAiTempData_2012180004]; // AI 관련한 배열
int isWhiteTempRy_2012180004, isWhiteTempRx_2012180004; // 힌트를 줄때돌의 위치를 넘겨준다.
// Next 관련한 부분 ↓
int isWhiteAiNext_2012180004[isOdelloData_2012180004][isOdelloData_2012180004];
int isWhiteAIxNext_2012180004[isAiArrangement_2012180004], isWhiteAIyNext_2012180004[isAiArrangement_2012180004];
int isWhiteAiCountNext_2012180004[isAiArrangement_2012180004];
int istWhiteAiCountNext_2012180004=0, isWhitemovetempNext_2012180004[isAiTempData_2012180004];
int isWhiteCheckStones_2012180004[isAiArrangement_2012180004];
int isWhiteAiPutX_2012180004, isWhiteAiPutY_2012180004, isWhiteAiNextCheck_2012180004=0;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void isWhiteBlackReverseStones_2012180004(); // WhiteAttack 할때
void isWhiteWhiteReverseStones_2012180004(); // WhiteDefence 할때
void isWhiteHintLoad_2012180004(); // 힌트부분을 확인을 할때 사용한다.
void isWhiteHintCheck_2012180004(); // 힌트부분을 체킹하려고 할때 사용한다.
void isWhiteHintClear_2012180004(); //Hint를 초기화한다.
void isWhiteAiPlus();

void isWhiteBlackStonesChecker_2012180004(); //AI 자신의 돌을 넘길때
void isWhiteWhiteStonesChecker_2012180004(); //AI 상대방 돌을 넘길때
void isWhiteNextHintClear_2012180004(); //Hint를 초기화한다.
void isWhiteNextHintLoad_2012180004(); // 힌트부분을 확인을 할때 사용한다.
void isWhiteNextHintCheck_2012180004(); // 힌트부분을 체킹하려고 할때 사용한다.
void isWhiteNextAiPlus();

void WhiteAttack_2012180004( int *x, int *y ){
	isWhiteHintClear_2012180004(); // 힌트를 초기화 한후
	isWhiteHintLoad_2012180004(); // 힌트를 재생성 해준다.
	isWhiteAiPlus();

	/*for(int i=0; i<isAiArrangement_2012180004; ++i){
	printf("(%d,%d) = %d\n", isWhiteAIx_2012180004[i], isWhiteAIy_2012180004[i], isWhiteAiCount_2012180004[i]);
	}*/

	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isWhiteAiCount_2012180004[i] < isWhiteAiCount_2012180004[j] ){
				isWhitemovetemp_2012180004[0]=isWhiteAiCount_2012180004[i];
				isWhitemovetemp_2012180004[1]=isWhiteAIx_2012180004[i];
				isWhitemovetemp_2012180004[2]=isWhiteAIy_2012180004[i];

				isWhiteAiCount_2012180004[i] = isWhiteAiCount_2012180004[j];
				isWhiteAIx_2012180004[i] = isWhiteAIx_2012180004[j];
				isWhiteAIy_2012180004[i] = isWhiteAIy_2012180004[j];

				isWhiteAiCount_2012180004[j] = isWhitemovetemp_2012180004[0];
				isWhiteAIx_2012180004[j] = isWhitemovetemp_2012180004[1];
				isWhiteAIy_2012180004[j] = isWhitemovetemp_2012180004[2];
			} 
		} 
	}


	int tempArr[isOdelloData_2012180004][isOdelloData_2012180004];
	isWhiteNextHintClear_2012180004();
	for( int i=0; i<isOdelloData_2012180004; ++i){
		for( int j=0; j<isOdelloData_2012180004; ++j){
			tempArr[i][j] = isWhiteAiNext_2012180004[i][j];
		}
	}

	for(int i=0; i<isAiArrangement_2012180004; ++i){
		// 가장 많이 뒤집는 경우부터 시작하여, 비교를 시작한다..!
		if( isWhiteAIx_2012180004[i] == 0 && isWhiteAIy_2012180004[i] == 0 && isWhiteAiCount_2012180004[i] == 0){
			printf("---------------------(%d, %d)---------------------\n",isWhiteAIx_2012180004[0], isWhiteAIy_2012180004[0]);
			break; //더이상 돌릴게 없으므로 for문 빠져나온다.
		}
		isWhiteAiPutX_2012180004 = isWhiteAIx_2012180004[i], isWhiteAiPutY_2012180004 = isWhiteAIy_2012180004[i];
		isWhiteBlackStonesChecker_2012180004();
		isWhiteNextHintLoad_2012180004();
		isWhiteNextAiPlus();

		for(int i=0; i<isAiArrangement_2012180004-1; ++i){
			for(int j=i+1; j<isAiArrangement_2012180004; ++j){
				if( isWhiteAiCountNext_2012180004[i] < isWhiteAiCountNext_2012180004[j] ){
					isWhitemovetempNext_2012180004[0]=isWhiteAiCountNext_2012180004[i];
					isWhitemovetempNext_2012180004[1]=isWhiteAIxNext_2012180004[i];
					isWhitemovetempNext_2012180004[2]=isWhiteAIyNext_2012180004[i];

					isWhiteAiCountNext_2012180004[i] = isWhiteAiCountNext_2012180004[j];
					isWhiteAIxNext_2012180004[i] = isWhiteAIxNext_2012180004[j];
					isWhiteAIyNext_2012180004[i] = isWhiteAIyNext_2012180004[j];

					isWhiteAiCountNext_2012180004[j] = isWhitemovetempNext_2012180004[0];
					isWhiteAIxNext_2012180004[j] = isWhitemovetempNext_2012180004[1];
					isWhiteAIyNext_2012180004[j] = isWhitemovetempNext_2012180004[2];
				} 
			} 
		}

		isWhiteCheckStones_2012180004[i] = isWhiteAiCount_2012180004[i] - isWhiteAiCountNext_2012180004[0];

		for( int i=0; i<isOdelloData_2012180004; ++i){
			for( int j=0; j<isOdelloData_2012180004; ++j){
				isWhiteAiNext_2012180004[i][j] = tempArr[i][j];
			}
		}
		if (i<isAiArrangement_2012180004){
			istWhiteAiCountNext_2012180004=0;
			for(int i=0; i<isAiArrangement_2012180004; ++i){
				isWhiteAIxNext_2012180004[i] = 0,isWhiteAIyNext_2012180004[i] = 0, isWhiteAiCountNext_2012180004[i] = 0;
			}
		}
	}

	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isWhiteCheckStones_2012180004[i] < isWhiteCheckStones_2012180004[j] ){
				//printf("\nChange\n");
				int tempData = isWhiteCheckStones_2012180004[i];
				isWhiteCheckStones_2012180004[i] = isWhiteCheckStones_2012180004[j];
				isWhiteCheckStones_2012180004[j] = tempData;

				isWhitemovetemp_2012180004[0]=isWhiteAiCount_2012180004[i];
				isWhitemovetemp_2012180004[1]=isWhiteAIx_2012180004[i];
				isWhitemovetemp_2012180004[2]=isWhiteAIy_2012180004[i];

				isWhiteAiCount_2012180004[i] = isWhiteAiCount_2012180004[j];
				isWhiteAIx_2012180004[i] = isWhiteAIx_2012180004[j];
				isWhiteAIy_2012180004[i] = isWhiteAIy_2012180004[j];

				isWhiteAiCount_2012180004[j] = isWhitemovetemp_2012180004[0];
				isWhiteAIx_2012180004[j] = isWhitemovetemp_2012180004[1];
				isWhiteAIy_2012180004[j] = isWhitemovetemp_2012180004[2];
			} 
		} 
	}

	if( isWhiteAIx_2012180004[0] == 0 && isWhiteAIy_2012180004[0] == 0 && isWhiteAiCount_2012180004[0] == 0){
		for(int i=0; i<isAiArrangement_2012180004; ++i){
			if(isWhiteAiCount_2012180004[i] !=0){
				// 내가 놓을수 있는 자리가 전부다 -1 이하일경우에는 그중 가장 최근껄 사용한다..!
				isWhiteAIx_2012180004[0] = isWhiteAIx_2012180004[i], isWhiteAIy_2012180004[0] = isWhiteAIy_2012180004[i];
				isWhiteAiCount_2012180004[0] =  isWhiteAiCount_2012180004[i];
				break;
			}
		}
	}
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isWhiteCheckStones_2012180004[i] = 0; // 체크하는부분은 끝나면 초기화를 해줘야 한다..!
	}

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------
	isWhiteArr_2012180004[isWhiteAIy_2012180004[0]][isWhiteAIx_2012180004[0]] = White;
	isWhiteTempRy_2012180004=isWhiteAIy_2012180004[0], isWhiteTempRx_2012180004=isWhiteAIx_2012180004[0];
	isWhiteBlackReverseStones_2012180004();

	*x = isWhiteAIx_2012180004[0];
	*y = isWhiteAIy_2012180004[0];

	printf("WhiteAttack!!! ( %d, %d )\n", isWhiteAIx_2012180004[0], isWhiteAIy_2012180004[0] );
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------
	//exit(0);
}

void WhiteDefence_2012180004( int x, int y ){
	if( isWhiteStart_2012180004 == false){
		isWhiteArr_2012180004[3][3] = Black;
		isWhiteArr_2012180004[3][4] = White;
		isWhiteArr_2012180004[4][3] = White;
		isWhiteArr_2012180004[4][4] = Black;
		//Next AI 배열
		isWhiteAiNext_2012180004[3][3] = Black;
		isWhiteAiNext_2012180004[3][4] = White;
		isWhiteAiNext_2012180004[4][3] = White;
		isWhiteAiNext_2012180004[4][4] = Black;
		isWhiteStart_2012180004 = true;
	}
	printf("WhiteDefence!!! ( %d, %d )\n",x,y);

	isWhiteHintClear_2012180004();
	isWhiteArr_2012180004[y][x] = Black;
	isWhiteTempRy_2012180004=y, isWhiteTempRx_2012180004=x;
	isWhiteWhiteReverseStones_2012180004();

	//for(int i=0; i<isOdelloData_2012180004; ++i){
	//	for( int j=0; j<isOdelloData_2012180004; ++j){
	//		printf("%2d",isWhiteArr_2012180004[i][j]);
	//	}
	//	printf("\n");
	//}

}

void isWhiteHintClear_2012180004(){
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if(isWhiteArr_2012180004[i][j] == Hint){
				isWhiteArr_2012180004[i][j] = None;
			}
		}
	}
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isWhiteAIx_2012180004[i] = 0, isWhiteAIy_2012180004[i] = 0, isWhiteAiCount_2012180004[i] = 0, istWhiteAiCount_2012180004=0;
	}
	for(int i=0; i<isAiTempData_2012180004; ++i){
		isWhitemovetemp_2012180004[i] =0;
	}
}

void isWhiteHintLoad_2012180004(){
	// None = 0, Black =1, White = 2, Hint = 3
	isWhiteTempRy_2012180004=0, isWhiteTempRx_2012180004=0;
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){

			if( isWhiteArr_2012180004[i][j] == None){
				isWhiteTempRy_2012180004= i, isWhiteTempRx_2012180004=j;
				isWhiteHintCheck_2012180004();

				if(istWhiteAiCount_2012180004 >= isAiArrangement_2012180004)
					break;

				if( isWhiteAiCheckTF_2012180004 == true){
					isWhiteArr_2012180004[i][j] = Hint;
					isWhiteAIx_2012180004[istWhiteAiCount_2012180004] = isWhiteTempRx_2012180004;
					isWhiteAIy_2012180004[istWhiteAiCount_2012180004] = isWhiteTempRy_2012180004;
					++istWhiteAiCount_2012180004;
					isWhiteAiCheckTF_2012180004=false;
				}
			}
		}
	}
}

void isWhiteHintCheck_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] != None 
				&& isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] != Hint){
					// 흰색
					if( isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] == Black){
						int tXt=isWhiteTempRx_2012180004+l, tYt=isWhiteTempRy_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteArr_2012180004[tYt][tXt]!=Black || isWhiteArr_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteArr_2012180004[tYt][tXt]==None || isWhiteArr_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isWhiteTempRx_2012180004 || tYt!=isWhiteTempRy_2012180004){
								++isWhiteAiCount_2012180004[istWhiteAiCount_2012180004];
								tXt-=l;tYt-=k;
								isWhiteAiCheckTF_2012180004 = true;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

void isWhiteBlackReverseStones_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] != None 
				&& isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] != Hint){
					// 흰색
					if( isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] == Black){
						int tXt=isWhiteTempRx_2012180004+l, tYt=isWhiteTempRy_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteArr_2012180004[tYt][tXt]!=Black || isWhiteArr_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteArr_2012180004[tYt][tXt]==None || isWhiteArr_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isWhiteTempRx_2012180004 || tYt!=isWhiteTempRy_2012180004){
								isWhiteArr_2012180004[tYt][tXt]=White;
								tXt-=l;tYt-=k;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

void isWhiteWhiteReverseStones_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] != None 
				&& isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] != Hint){
					// 검정
					if( isWhiteArr_2012180004[isWhiteTempRy_2012180004+k][isWhiteTempRx_2012180004+l] == White){
						int tXt=isWhiteTempRx_2012180004+l, tYt=isWhiteTempRy_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteArr_2012180004[tYt][tXt]!=White || isWhiteArr_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteArr_2012180004[tYt][tXt]==None || isWhiteArr_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isWhiteTempRx_2012180004 || tYt!=isWhiteTempRy_2012180004){
								isWhiteArr_2012180004[tYt][tXt]=Black;
								tXt-=l;tYt-=k;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

void isWhiteNextHintClear_2012180004(){
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if(isWhiteAiNext_2012180004[i][j] == Hint){
				isWhiteAiNext_2012180004[i][j] = None;
			}
		}
	}
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isWhiteAIxNext_2012180004[i] = 0, isWhiteAIyNext_2012180004[i] = 0, isWhiteAiCountNext_2012180004[i] = 0, istWhiteAiCountNext_2012180004=0;
	}
	for(int i=0; i<isAiTempData_2012180004; ++i){
		isWhitemovetempNext_2012180004[i] =0;
	}
}

void isWhiteBlackStonesChecker_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			if(isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] != None 
				&& isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] != Hint){
					if( isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] == Black){
						int tXt=isWhiteAiPutX_2012180004+l, tYt=isWhiteAiPutY_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteAiNext_2012180004[tYt][tXt]!=Black || isWhiteAiNext_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteAiNext_2012180004[tYt][tXt]==None || isWhiteAiNext_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isWhiteAiPutX_2012180004 || tYt!=isWhiteAiPutY_2012180004){
								isWhiteAiNext_2012180004[tYt][tXt]=White;
								tXt-=l;tYt-=k;
							}
						}
					}
			}
		} 
	} 
}

void isWhiteNextHintLoad_2012180004(){
	isWhiteTempRy_2012180004= 0, isWhiteTempRx_2012180004=0;
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if( isWhiteAiNext_2012180004[i][j] == None){
				isWhiteAiPutY_2012180004= i, isWhiteAiPutX_2012180004=j;
				isWhiteNextHintCheck_2012180004();

				if(istWhiteAiCountNext_2012180004 >= isAiArrangement_2012180004)
					break;

				if( isWhiteAiNextCheck_2012180004 == 1){
					isWhiteAiNext_2012180004[i][j] = Hint;
					isWhiteAIxNext_2012180004[istWhiteAiCountNext_2012180004] = isWhiteAiPutX_2012180004;
					isWhiteAIyNext_2012180004[istWhiteAiCountNext_2012180004] = isWhiteAiPutY_2012180004;
					++istWhiteAiCountNext_2012180004;
					isWhiteAiNextCheck_2012180004=0;
				}
			}
		}
	}
}

void isWhiteNextHintCheck_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){
			if(isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] != None 
				&& isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] != Hint){
					if( isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] == Black){
						int tXt=isWhiteAiPutX_2012180004+l, tYt=isWhiteAiPutY_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteAiNext_2012180004[tYt][tXt]!=Black || isWhiteAiNext_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteAiNext_2012180004[tYt][tXt]==None || isWhiteAiNext_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isWhiteAiPutX_2012180004 || tYt!=isWhiteAiPutY_2012180004){
								++isWhiteAiCountNext_2012180004[istWhiteAiCountNext_2012180004];
								tXt-=l;tYt-=k;
								isWhiteAiNextCheck_2012180004=1;
							}
						}
					}
			}
		}
	}
}

void isWhiteAiPlus(){
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		// 가중치 계산
		if( isWhiteAIx_2012180004[i] == 0 && isWhiteAIy_2012180004[i] == 0 && isWhiteAiCount_2012180004[i] == 0)
			break;
		if((isWhiteAIy_2012180004[i] == 0 && isWhiteAIx_2012180004[i] == 0) || (isWhiteAIy_2012180004[i] == 0 && isWhiteAIx_2012180004[i] ==7) || (isWhiteAIy_2012180004[i] == 7 && isWhiteAIx_2012180004[i] ==0) || (isWhiteAIy_2012180004[i] == 7 && isWhiteAIx_2012180004[i] ==7)){
			// 제일 끝
			isWhiteAiCount_2012180004[i]+=100;
		}else if(((isWhiteAIy_2012180004[i] == 0 || isWhiteAIy_2012180004[i] == 7) && (1<=isWhiteAIx_2012180004[i] && isWhiteAIx_2012180004[i]<=6))||((isWhiteAIx_2012180004[i] == 0 || isWhiteAIx_2012180004[i] == 7) && (1<=isWhiteAIy_2012180004[i] && isWhiteAIy_2012180004[i]<=6))){
			// 파란색
			if(isWhiteAIy_2012180004[i]  == 1 && isWhiteAIx_2012180004[i] == 0 || isWhiteAIy_2012180004[i]  == 0 && isWhiteAIx_2012180004[i] == 1 ){
				if(isWhiteArr_2012180004[0][0] == White){
					isWhiteAiCount_2012180004[i]+=90;
				}else{
				isWhiteAiCount_2012180004[i]+=60;
				}
			}else if(isWhiteAIy_2012180004[i]  == 0 && isWhiteAIx_2012180004[i] == 6 || isWhiteAIy_2012180004[i]  == 1 && isWhiteAIx_2012180004[i] == 7 ){
				if(isWhiteArr_2012180004[0][7] == White){
					isWhiteAiCount_2012180004[i]+=90;
				}else{
				isWhiteAiCount_2012180004[i]+=60;
				}
			}else if(isWhiteAIy_2012180004[i]  == 6 && isWhiteAIx_2012180004[i] == 0 || isWhiteAIy_2012180004[i]  == 7 && isWhiteAIx_2012180004[i] == 1 ){
				if(isWhiteArr_2012180004[7][0] == White){
					isWhiteAiCount_2012180004[i]+=90;
				}else{
				isWhiteAiCount_2012180004[i]+=60;
				}
			}else if(isWhiteAIy_2012180004[i]  == 6 && isWhiteAIx_2012180004[i] ==7 || isWhiteAIy_2012180004[i]  == 7 && isWhiteAIx_2012180004[i] == 6 ){
				if(isWhiteArr_2012180004[7][7] == White){
					isWhiteAiCount_2012180004[i]+=90;
				}else{
				isWhiteAiCount_2012180004[i]+=60;
				}
			}else{
				isWhiteAiCount_2012180004[i]+=80;
			}
		}else if( (2<=isWhiteAIy_2012180004[i] && isWhiteAIy_2012180004[i]<= 5) && (2<=isWhiteAIx_2012180004[i] && isWhiteAIx_2012180004[i]<= 5) ){
			// 초록색
			if(isWhiteAIy_2012180004[i]  == 2 && isWhiteAIx_2012180004[i] == 2 ){
				isWhiteAiCount_2012180004[i]+=70;
			}else if(isWhiteAIy_2012180004[i]  == 2 && isWhiteAIx_2012180004[i] == 5 ){
				isWhiteAiCount_2012180004[i]+=70;
			}else if(isWhiteAIy_2012180004[i]  == 5 && isWhiteAIx_2012180004[i] == 2 ){
				isWhiteAiCount_2012180004[i]+=70;
			}else if(isWhiteAIy_2012180004[i]  == 5 && isWhiteAIx_2012180004[i] == 5 ){
				isWhiteAiCount_2012180004[i]+=70;
			}else{
				isWhiteAiCount_2012180004[i]+=30;
			}
		}else if( (isWhiteAIy_2012180004[i] == 1 && isWhiteAIx_2012180004[i] == 1) || (isWhiteAIy_2012180004[i] == 1 && isWhiteAIx_2012180004[i] == 6) || (isWhiteAIy_2012180004[i] == 6 && isWhiteAIx_2012180004[i] == 1) || (isWhiteAIy_2012180004[i] == 6 && isWhiteAIx_2012180004[i] == 6) ){
			// 빨간색
			isWhiteAiCount_2012180004[i]+=1;
		}else{
			// 노란색
			if(isWhiteAIy_2012180004[i]  == 1 && isWhiteAIx_2012180004[i] == 2 || isWhiteAIy_2012180004[i]  == 1 && isWhiteAIx_2012180004[i] == 2 ){
				isWhiteAiCount_2012180004[i]+=35;
			}else if(isWhiteAIy_2012180004[i]  == 5 && isWhiteAIx_2012180004[i] == 1 || isWhiteAIy_2012180004[i]  == 2 && isWhiteAIx_2012180004[i] == 6 ){
				isWhiteAiCount_2012180004[i]+=35;
			}else if(isWhiteAIy_2012180004[i]  == 1 && isWhiteAIx_2012180004[i] == 5 || isWhiteAIy_2012180004[i]  == 6 && isWhiteAIx_2012180004[i] == 2 ){
				isWhiteAiCount_2012180004[i]+=35;
			}else if(isWhiteAIy_2012180004[i]  == 5 && isWhiteAIx_2012180004[i] == 6 || isWhiteAIy_2012180004[i]  == 6 && isWhiteAIx_2012180004[i] == 5 ){
				isWhiteAiCount_2012180004[i]+=35;
			}else{
				isWhiteAiCount_2012180004[i]+=15;
			}
		}
	}
}

void isWhiteNextAiPlus(){
for(int i=0; i<isAiArrangement_2012180004; ++i){
		// 가중치 계산
		if( isWhiteAIxNext_2012180004[i] == 0 && isWhiteAIyNext_2012180004[i] == 0 && isWhiteAiCountNext_2012180004[i] == 0)
			break;
		if((isWhiteAIyNext_2012180004[i] == 0 && isWhiteAIxNext_2012180004[i] == 0) || (isWhiteAIyNext_2012180004[i] == 0 && isWhiteAIxNext_2012180004[i] ==7) || (isWhiteAIyNext_2012180004[i] == 7 && isWhiteAIxNext_2012180004[i] ==0) || (isWhiteAIyNext_2012180004[i] == 7 && isWhiteAIxNext_2012180004[i] ==7)){
			// 제일 끝
			isWhiteAiCountNext_2012180004[i]+=100;
		}else if(((isWhiteAIyNext_2012180004[i] == 0 || isWhiteAIyNext_2012180004[i] == 7) && (1<=isWhiteAIxNext_2012180004[i] && isWhiteAIxNext_2012180004[i]<=6))||((isWhiteAIxNext_2012180004[i] == 0 || isWhiteAIxNext_2012180004[i] == 7) && (1<=isWhiteAIyNext_2012180004[i] && isWhiteAIyNext_2012180004[i]<=6))){
			// 파란색
			if(isWhiteAIyNext_2012180004[i]  == 1 && isWhiteAIxNext_2012180004[i] == 0 || isWhiteAIyNext_2012180004[i]  == 0 && isWhiteAIxNext_2012180004[i] == 1 ){
				if(isWhiteArr_2012180004[0][0] == White){
					isWhiteAiCountNext_2012180004[i]+=90;
				}else{
				isWhiteAiCountNext_2012180004[i]+=60;
				}
			}else if(isWhiteAIyNext_2012180004[i]  == 0 && isWhiteAIxNext_2012180004[i] == 6 || isWhiteAIyNext_2012180004[i]  == 1 && isWhiteAIxNext_2012180004[i] == 7 ){
				if(isWhiteArr_2012180004[0][7] == White){
					isWhiteAiCountNext_2012180004[i]+=90;
				}else{
				isWhiteAiCountNext_2012180004[i]+=60;
				}
			}else if(isWhiteAIyNext_2012180004[i]  == 6 && isWhiteAIxNext_2012180004[i] == 0 || isWhiteAIyNext_2012180004[i]  == 7 && isWhiteAIxNext_2012180004[i] == 1 ){
				if(isWhiteArr_2012180004[7][0] == White){
					isWhiteAiCountNext_2012180004[i]+=90;
				}else{
				isWhiteAiCountNext_2012180004[i]+=60;
				}
			}else if(isWhiteAIyNext_2012180004[i]  == 6 && isWhiteAIxNext_2012180004[i] ==7 || isWhiteAIyNext_2012180004[i]  == 7 && isWhiteAIxNext_2012180004[i] == 6 ){
				if(isWhiteArr_2012180004[7][7] == White){
					isWhiteAiCountNext_2012180004[i]+=90;
				}else{
				isWhiteAiCountNext_2012180004[i]+=60;
				}
			}else{
				isWhiteAiCountNext_2012180004[i]+=80;
			}
		}else if( (2<=isWhiteAIyNext_2012180004[i] && isWhiteAIyNext_2012180004[i]<= 5) && (2<=isWhiteAIxNext_2012180004[i] && isWhiteAIxNext_2012180004[i]<= 5) ){
			// 초록색
			if(isWhiteAIyNext_2012180004[i]  == 2 && isWhiteAIxNext_2012180004[i] == 2 ){
				isWhiteAiCountNext_2012180004[i]+=70;
			}else if(isWhiteAIyNext_2012180004[i]  == 2 && isWhiteAIxNext_2012180004[i] == 5 ){
				isWhiteAiCountNext_2012180004[i]+=70;
			}else if(isWhiteAIyNext_2012180004[i]  == 5 && isWhiteAIxNext_2012180004[i] == 2 ){
				isWhiteAiCountNext_2012180004[i]+=70;
			}else if(isWhiteAIyNext_2012180004[i]  == 5 && isWhiteAIxNext_2012180004[i] == 5 ){
				isWhiteAiCountNext_2012180004[i]+=70;
			}else{
				isWhiteAiCountNext_2012180004[i]+=30;
			}
		}else if( (isWhiteAIyNext_2012180004[i] == 1 && isWhiteAIxNext_2012180004[i] == 1) || (isWhiteAIyNext_2012180004[i] == 1 && isWhiteAIxNext_2012180004[i] == 6) || (isWhiteAIyNext_2012180004[i] == 6 && isWhiteAIxNext_2012180004[i] == 1) || (isWhiteAIyNext_2012180004[i] == 6 && isWhiteAIxNext_2012180004[i] == 6) ){
			// 빨간색
			isWhiteAiCountNext_2012180004[i]+=1;
		}else{
			// 노란색
			if(isWhiteAIyNext_2012180004[i]  == 1 && isWhiteAIxNext_2012180004[i] == 2 || isWhiteAIyNext_2012180004[i]  == 1 && isWhiteAIxNext_2012180004[i] == 2 ){
				isWhiteAiCountNext_2012180004[i]+=35;
			}else if(isWhiteAIyNext_2012180004[i]  == 5 && isWhiteAIxNext_2012180004[i] == 1 || isWhiteAIyNext_2012180004[i]  == 2 && isWhiteAIxNext_2012180004[i] == 6 ){
				isWhiteAiCountNext_2012180004[i]+=35;
			}else if(isWhiteAIyNext_2012180004[i]  == 1 && isWhiteAIxNext_2012180004[i] == 5 || isWhiteAIyNext_2012180004[i]  == 6 && isWhiteAIxNext_2012180004[i] == 2 ){
				isWhiteAiCountNext_2012180004[i]+=35;
			}else if(isWhiteAIyNext_2012180004[i]  == 5 && isWhiteAIxNext_2012180004[i] == 6 || isWhiteAIyNext_2012180004[i]  == 6 && isWhiteAIxNext_2012180004[i] == 5 ){
				isWhiteAiCountNext_2012180004[i]+=35;
			}else{
				isWhiteAiCountNext_2012180004[i]+=15;
			}
		}
	}
}
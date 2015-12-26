#pragma once

#include "OdeloBattleSystem.h"

#define isOdelloData_2012180004 8 // ������ ��
#define isAiArrangement_2012180004 20 // AI �迭 ��
#define isAiTempData_2012180004 3 // AI �迭 ��
// ������ ��[y][x]
enum{ None, Black, White, Hint };
enum{ OneTurn, TwoTurn};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int isWhiteArr_2012180004[8][8];
bool isWhiteStart_2012180004 = false, isWhiteAiCheckTF_2012180004 = false;
int isWhiteAIx_2012180004[isAiArrangement_2012180004], isWhiteAIy_2012180004[isAiArrangement_2012180004];
int isWhiteAiCount_2012180004[isAiArrangement_2012180004]; // AI ������ �迭
int istWhiteAiCount_2012180004=0, isWhitemovetemp_2012180004[isAiTempData_2012180004]; // AI ������ �迭
int isWhiteTempRy_2012180004, isWhiteTempRx_2012180004; // ��Ʈ�� �ٶ����� ��ġ�� �Ѱ��ش�.
// Next ������ �κ� ��
int isWhiteAiNext_2012180004[isOdelloData_2012180004][isOdelloData_2012180004];
int isWhiteAIxNext_2012180004[isAiArrangement_2012180004], isWhiteAIyNext_2012180004[isAiArrangement_2012180004];
int isWhiteAiCountNext_2012180004[isAiArrangement_2012180004];
int istWhiteAiCountNext_2012180004=0, isWhitemovetempNext_2012180004[isAiTempData_2012180004];
int isWhiteCheckStones_2012180004[isAiArrangement_2012180004];
int isWhiteTwoCheckStones_2012180004[isAiArrangement_2012180004];
int isWhiteAiPutX_2012180004, isWhiteAiPutY_2012180004, isWhiteAiNextCheck_2012180004=0;
// AI �÷��� ���úκ�
int isWhiteWhatPlayScore =0;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void isWhiteBlackReverseStones_2012180004(); // WhiteAttack �Ҷ�
void isWhiteWhiteReverseStones_2012180004(); // WhiteDefence �Ҷ�
void isWhiteHintLoad_2012180004(); // ��Ʈ�κ��� Ȯ���� �Ҷ� ����Ѵ�.
void isWhiteHintCheck_2012180004(); // ��Ʈ�κ��� üŷ�Ϸ��� �Ҷ� ����Ѵ�.
void isWhiteHintClear_2012180004(); //Hint�� �ʱ�ȭ�Ѵ�.


void isWhiteBlackStonesChecker_2012180004(); //AI �ڽ��� ���� �ѱ涧
void isWhiteWhiteStonesChecker_2012180004(); //AI ���� ���� �ѱ涧
void isWhiteNextHintClear_2012180004(); //Hint�� �ʱ�ȭ�Ѵ�.
void isWhiteNextHintLoad_2012180004(); // ��Ʈ�κ��� Ȯ���� �Ҷ� ����Ѵ�.
void isWhiteNextHintCheck_2012180004(); // ��Ʈ�κ��� üŷ�Ϸ��� �Ҷ� ����Ѵ�.

void isWhiteAiTotalPlus(int, int []); // ����ġ ���

void WhiteAttack_2012180004( int *x, int *y ){
	isWhiteHintClear_2012180004(); // ��Ʈ�� �ʱ�ȭ ����
	isWhiteHintLoad_2012180004(); // ��Ʈ�� ����� ���ش�.
	isWhiteAiTotalPlus(OneTurn,isWhiteAiCount_2012180004);

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
		// ���� ���� ������ ������ �����Ͽ�, �񱳸� �����Ѵ�..!
		if( isWhiteAIx_2012180004[i] == 0 && isWhiteAIy_2012180004[i] == 0 && isWhiteAiCount_2012180004[i] == 0)
			break;
		isWhiteAiPutX_2012180004 = isWhiteAIx_2012180004[i], isWhiteAiPutY_2012180004 = isWhiteAIy_2012180004[i];
		isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004][isWhiteAiPutX_2012180004] = White;
		isWhiteBlackStonesChecker_2012180004();
		// �� �������� �ѹ� ������
		isWhiteNextHintClear_2012180004();
		isWhiteNextHintLoad_2012180004();
		isWhiteAiTotalPlus(TwoTurn, isWhiteAiCountNext_2012180004);
		// �� ������ �������� �ϴ°��� �ֻ�����
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

		int tempB=0, tempW=0;
		for(int i=0; i<isOdelloData_2012180004; ++i){
			for(int j=0; j<isOdelloData_2012180004; ++j){
				if( isWhiteArr_2012180004[i][j] == Black){
					++tempB;
				}else if ( isWhiteArr_2012180004[i][j] == White){
					++tempW;
				}
			}
		}
		//printf("Black : %d, White : %d\n", tempB, tempW);
		isWhiteAiNext_2012180004[isWhiteAIyNext_2012180004[0]][isWhiteAIxNext_2012180004[0]] = Black;
		isWhiteAiPutX_2012180004 = isWhiteAIxNext_2012180004[0], isWhiteAiPutY_2012180004 = isWhiteAIyNext_2012180004[0];
		isWhiteWhiteStonesChecker_2012180004();
		// �� �ֻ��� ���� ���� ����ġ �������� �ѱ�� �ϴ� �κ�
		int NtempNB=0, NtempNW=0;
		for(int i=0; i<isOdelloData_2012180004; ++i){
			for(int j=0; j<isOdelloData_2012180004; ++j){
				if( isWhiteAiNext_2012180004[i][j] == Black){
					++NtempNB;
				}else if ( isWhiteAiNext_2012180004[i][j] == White){
					++NtempNW;
				}
			}
		}

		/*printf("NBlack : %d, NWhite : %d\n", NtempNB, NtempNW);
		printf("Nblack-Black = %d\n", NtempNB-tempB);
		printf("NWhite-NWhite = %d\n", NtempNW-tempW);*/
		int isResult_2012180004=0, isWhiteResult_2012180004 = NtempNB-tempB;
		if( (NtempNW-tempW) < 0){
			//����
			isResult_2012180004 = (NtempNB-tempB)+(NtempNW-tempW);
			//printf("Result : %d\n", isResult_2012180004);
		}else{
			isResult_2012180004 = (NtempNB-tempB)-(NtempNW-tempW);
			//printf("Result : %d\n", isResult_2012180004);
		}

		//printf("(%d, %d) = %d : %d : %d --\n\n", isWhiteAIx_2012180004[i], isWhiteAIy_2012180004[i], isWhiteAiCount_2012180004[i], isResult_2012180004, isWhiteResult_2012180004);

		isWhiteCheckStones_2012180004[i] = isResult_2012180004;
		isWhiteTwoCheckStones_2012180004[i] = isWhiteResult_2012180004;
		//system("pause");

		for( int i=0; i<isOdelloData_2012180004; ++i){
			for( int j=0; j<isOdelloData_2012180004; ++j){
				isWhiteAiNext_2012180004[i][j] = tempArr[i][j];
			}
		}

	} // for(int i=0; i<isAiArrangement_2012180004; ++i){

	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isWhiteCheckStones_2012180004[i] < isWhiteCheckStones_2012180004[j] ){
				int tempData = isWhiteCheckStones_2012180004[i];
				int tempTwoData = isWhiteTwoCheckStones_2012180004[i];
				isWhiteCheckStones_2012180004[i] = isWhiteCheckStones_2012180004[j];
				isWhiteTwoCheckStones_2012180004[i] = isWhiteTwoCheckStones_2012180004[j];
				isWhiteCheckStones_2012180004[j] = tempData;
				isWhiteTwoCheckStones_2012180004[j] = tempTwoData;


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

	/*for(int i=0; i<isAiArrangement_2012180004; ++i){
	printf("(%d, %d) = %d : %d : %d\n", isWhiteAIx_2012180004[i], isWhiteAIy_2012180004[i],isWhiteAiCount_2012180004[i], isWhiteCheckStones_2012180004[i], isWhiteTwoCheckStones_2012180004[i]  );
	}
	system("pause");*/


	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isWhiteAiCount_2012180004[i] != 0){
				if( isWhiteTwoCheckStones_2012180004[i] < isWhiteTwoCheckStones_2012180004[j] ){
					int tempData = isWhiteTwoCheckStones_2012180004[i];
					int tempTwoData = isWhiteCheckStones_2012180004[i];
					isWhiteTwoCheckStones_2012180004[i] = isWhiteTwoCheckStones_2012180004[j];
					isWhiteCheckStones_2012180004[i] = isWhiteCheckStones_2012180004[j];
					isWhiteTwoCheckStones_2012180004[j] = tempData;
					isWhiteCheckStones_2012180004[j] = tempTwoData;

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
	}

	int isRBlack_2012180004=0, isRWhite_2012180004=0;
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if( isWhiteArr_2012180004[i][j] == Black){
				++isRBlack_2012180004;
			}else if ( isWhiteArr_2012180004[i][j] == White){
				++isRWhite_2012180004;
			}
		}
	}

	bool isEdge = false;
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		// 2������ �д´� �ص� �𼭸��� �߿��ϴϱ�~!!!
		if( isWhiteAIx_2012180004[i] == 0 && isWhiteAIy_2012180004[i] == 0 && isWhiteAiCount_2012180004[i] != 0){
			isEdge = true;
		}else if( isWhiteAIx_2012180004[i] == 0 && isWhiteAIy_2012180004[i] == 7 && isWhiteAiCount_2012180004[i] != 0){
			isEdge = true;										  
		}else if( isWhiteAIx_2012180004[i] == 7 && isWhiteAIy_2012180004[i] == 0 && isWhiteAiCount_2012180004[i] != 0){
			isEdge = true;							  
		}else if( isWhiteAIx_2012180004[i] == 7 && isWhiteAIy_2012180004[i] == 7 && isWhiteAiCount_2012180004[i] != 0){
			isEdge = true;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------------
	int isEdgeMyCount =0; // �ڽ��� ���� �𼭸��� 3���̻�ÿ� ����ġ�� �����Ѵ�.
	if( isWhiteArr_2012180004[0][0] == Black){
		++isEdgeMyCount;
	}else if( isWhiteArr_2012180004[0][7] == Black){
		++isEdgeMyCount;							  
	}else if( isWhiteArr_2012180004[7][0] == Black){
		++isEdgeMyCount;						  
	}else if( isWhiteArr_2012180004[7][7] == Black){
		++isEdgeMyCount;
	}
	if( isEdgeMyCount>= 3){
		isEdge=true;
	}
	//------------------------------------------------------------------------------------------------------------------------------------------
	int isEdgeYourCount =0; // ����  ���� �𼭸��� 2���̻�ÿ� ����ġ�� �����Ѵ�.
	if( isWhiteArr_2012180004[0][0] == White){
		++isEdgeYourCount;
	}else if( isWhiteArr_2012180004[0][7] == White){
		++isEdgeYourCount;							  
	}else if( isWhiteArr_2012180004[7][0] == White){
		++isEdgeYourCount;						  
	}else if( isWhiteArr_2012180004[7][7] == White){
		++isEdgeYourCount;
	}
	if( isEdgeYourCount>= 2){
		isEdge=true;
	}
	//------------------------------------------------------------------------------------------------------------------------------------------

	if(isWhiteWhatPlayScore >= 10 && isRBlack_2012180004 >= isRWhite_2012180004 || isEdge == true ){
		printf("AiTotalPlus Attack!!!\n");
		for(int i=0; i<isAiArrangement_2012180004-1; ++i){
			for(int j=i+1; j<isAiArrangement_2012180004; ++j){
				if( isWhiteAiCount_2012180004[i] < isWhiteAiCount_2012180004[j] ){
					int tempData = isWhiteTwoCheckStones_2012180004[i];
					int tempTwoData = isWhiteCheckStones_2012180004[i];
					isWhiteTwoCheckStones_2012180004[i] = isWhiteTwoCheckStones_2012180004[j];
					isWhiteCheckStones_2012180004[i] = isWhiteCheckStones_2012180004[j];
					isWhiteTwoCheckStones_2012180004[j] = tempData;
					isWhiteCheckStones_2012180004[j] = tempTwoData;

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
	}



	/*for(int i=0; i<isAiArrangement_2012180004; ++i){
	printf("(%d, %d) = %d : %d : %d\n", isWhiteAIx_2012180004[i], isWhiteAIy_2012180004[i],isWhiteAiCount_2012180004[i], isWhiteCheckStones_2012180004[i], isWhiteTwoCheckStones_2012180004[i]  );
	}
	system("pause");*/

	if(  isWhiteAIx_2012180004[0] == 0 && isWhiteAIy_2012180004[0] == 0 &&  isWhiteAiCount_2012180004[0] == 0){
		for(int i=0; i<isAiArrangement_2012180004; ++i){
			if(isWhiteAiCount_2012180004[i] !=0){
				// ������ �����Ͽ�����, ������ ���� �������
				isWhiteAIx_2012180004[0] = isWhiteAIx_2012180004[i], isWhiteAIy_2012180004[0] = isWhiteAIy_2012180004[i];
				isWhiteAiCount_2012180004[0] =  isWhiteAiCount_2012180004[i];
				break;
			}
		}
	}

	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isWhiteCheckStones_2012180004[i] = 0; // üũ�ϴºκ��� ������ �ʱ�ȭ�� ����� �Ѵ�..!
		isWhiteTwoCheckStones_2012180004[i] = 0;
	}

	//------------------------------------------------------------------------------------------------------------------------------------------
	if(  isWhiteAiCount_2012180004[0] != 0){

		isWhiteArr_2012180004[isWhiteAIy_2012180004[0]][isWhiteAIx_2012180004[0]] = White;
		isWhiteTempRy_2012180004=isWhiteAIy_2012180004[0], isWhiteTempRx_2012180004=isWhiteAIx_2012180004[0];
		isWhiteBlackReverseStones_2012180004();

		isWhiteAiPutX_2012180004 = isWhiteAIx_2012180004[0], isWhiteAiPutY_2012180004 = isWhiteAIy_2012180004[0];
		isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004][isWhiteAiPutX_2012180004] = White;
		isWhiteBlackStonesChecker_2012180004();

		*x = isWhiteAIx_2012180004[0];
		*y = isWhiteAIy_2012180004[0];
		// ����� ������ �����ϴ� �κ�
		printf("[%d]WhiteAttack!!! ( %d, %d )\n",isWhiteWhatPlayScore, isWhiteAIx_2012180004[0], isWhiteAIy_2012180004[0] );
	}else{
		printf("WhiteAttack!!!\n�ڸ��� �����ϴ�..!\n");
	}
	++isWhiteWhatPlayScore;
	//------------------------------------------------------------------------------------------------------------------------------------------
}

void WhiteDefence_2012180004( int x, int y ){
	if( isWhiteStart_2012180004 == false){
		isWhiteArr_2012180004[3][3] = Black;
		isWhiteArr_2012180004[3][4] = White;
		isWhiteArr_2012180004[4][3] = White;
		isWhiteArr_2012180004[4][4] = Black;
		//Next AI �迭
		isWhiteAiNext_2012180004[3][3] = Black;
		isWhiteAiNext_2012180004[3][4] = White;
		isWhiteAiNext_2012180004[4][3] = White;
		isWhiteAiNext_2012180004[4][4] = Black;
		isWhiteStart_2012180004 = true;
	}
	printf("[%d]BlackDefence!!! ( %d, %d )\n", isWhiteWhatPlayScore, x,y);

	isWhiteHintClear_2012180004();
	isWhiteArr_2012180004[y][x] = Black;
	isWhiteTempRy_2012180004=y, isWhiteTempRx_2012180004=x;
	isWhiteWhiteReverseStones_2012180004();

	isWhiteAiNext_2012180004[y][x] = Black;
	isWhiteAiPutX_2012180004 =x, isWhiteAiPutY_2012180004 = y;
	isWhiteWhiteStonesChecker_2012180004();
	++isWhiteWhatPlayScore;


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
					// ���
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
					// ���
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
					// ����
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
					// ����
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
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

void isWhiteWhiteStonesChecker_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] != None 
				&& isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] != Hint){
					// ���
					if( isWhiteAiNext_2012180004[isWhiteAiPutY_2012180004+k][isWhiteAiPutX_2012180004+l] == White){
						int tXt=isWhiteAiPutX_2012180004+l, tYt=isWhiteAiPutY_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteAiNext_2012180004[tYt][tXt]!=White || isWhiteAiNext_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isWhiteAiNext_2012180004[tYt][tXt]==None || isWhiteAiNext_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isWhiteAiPutX_2012180004 || tYt!=isWhiteAiPutY_2012180004){
								isWhiteAiNext_2012180004[tYt][tXt]=Black;
								tXt-=l;tYt-=k;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
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


void isWhiteAiTotalPlus(int whatPlay, int scoreData[]){
	//enum{ OneTurn, TwoTurn};
	int isRealX =0, isRealY =0;
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		if( whatPlay == OneTurn){
			isRealX =isWhiteAIx_2012180004[i], isRealY = isWhiteAIy_2012180004[i];
		}else{
			isRealX =isWhiteAIxNext_2012180004[i], isRealY = isWhiteAIyNext_2012180004[i];
		}
		// ����ġ ���
		if( isRealX == 0 && isRealY == 0 && scoreData[i] == 0)
			continue;
		if((isRealY == 0 && isRealX == 0) || (isRealY == 0 && isRealX ==7) || (isRealY == 7 && isRealX ==0) || (isRealY == 7 && isRealX ==7)){
			// ���� ��
			scoreData[i]+=100;
		}else if(((isRealY == 0 || isRealY == 7) && (1<=isRealX && isRealX<=6))||((isRealX == 0 || isRealX == 7) && (1<=isRealY && isRealY<=6))){
			// �Ķ���
			if(isRealY  == 1 && isRealX == 0 || isRealY  == 0 && isRealX == 1 ){
				if(isWhiteArr_2012180004[0][0] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 0 && isRealX == 6 || isRealY  == 1 && isRealX == 7 ){
				if(isWhiteArr_2012180004[0][7] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 6 && isRealX == 0 || isRealY  == 7 && isRealX == 1 ){
				if(isWhiteArr_2012180004[7][0] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else if(isRealY  == 6 && isRealX ==7 || isRealY  == 7 && isRealX == 6 ){
				if(isWhiteArr_2012180004[7][7] == Black){
					scoreData[i]+=90;
				}else{
					scoreData[i]+=1;
				}
			}else{
				int isFakeData =0;
				int tempArr[8][8];
				for(int i=0; i<8; ++i){
					for(int j=0; j<8; ++j){
						if( isWhiteArr_2012180004[i][j] == Black ){
							tempArr[i][j]  =Black;
						}else if ( isWhiteArr_2012180004[i][j] == White){
							tempArr[i][j]  =White;
						}else{
							tempArr[i][j]  =None;
						}
					}
				}
				if(2<=isRealY && isRealY<=5){
					// �Ķ��� ���� ������
					//printf("( %d, %d )\n", isRealX, isRealY);
					if( tempArr[isRealY-1][isRealX] == None && tempArr[isRealY+1][isRealX] == None ){
						//printf("---------------------Bingo---------------------\n");
						scoreData[i]+=90;
					}else{
						if(isWhiteArr_2012180004[isRealY-1][isRealX] == White){
							if(isWhiteArr_2012180004[isRealY-2][isRealX] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						if(isWhiteArr_2012180004[isRealY+1][isRealX] == White){
							if(isWhiteArr_2012180004[isRealY+2][isRealX] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						scoreData[i]+=isFakeData;
					}

				}else if(2<=isRealX && isRealX<=5){
					// �Ķ��� ���� �Ʒ���
					if( tempArr[isRealY][isRealX-1] == None && tempArr[isRealY][isRealX+1] == None ){
						//printf("---------------------Bingo---------------------\n");
						scoreData[i]+=90;
					}else{
						if(isWhiteArr_2012180004[isRealY][isRealX-1] == White){
							if(isWhiteArr_2012180004[isRealY][isRealX-2] == Black){
								isFakeData=80;
							}else{
								isFakeData=1;
							}
						}
						if(isWhiteArr_2012180004[isRealY][isRealX+1] == White){
							if(isWhiteArr_2012180004[isRealY][isRealX+2] == Black){
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
			// �ʷϻ�
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
			// ������
			/*if(isRealX == 6 && isRealY == 1 && isWhiteArr_2012180004[7][0] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 1 && isRealY == 6 && isWhiteArr_2012180004[0][7] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 1 && isRealY == 1 && isWhiteArr_2012180004[7][7] == Black ){
			scoreData[i]+=90;
			}else if(isRealX == 6 && isRealY == 6 && isWhiteArr_2012180004[0][0] == Black ){
			scoreData[i]+=90;
			}else{
			scoreData[i]+=1;
			}*/
			scoreData[i]+=1;
		}else{
			// �����
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
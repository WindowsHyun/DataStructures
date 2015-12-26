#pragma once

#include "OdeloBattleSystem.h"

#define isOdelloData_2012180004 8 // ������ ��
#define isAiArrangement_2012180004 20 // AI �迭 ��
#define isAiTempData_2012180004 3 // AI �迭 ��
// ������ ��[y][x]
enum{ None, Black, White, Hint };
enum{ OneTurn, TwoTurn};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int isBlackArr_2012180004[isOdelloData_2012180004][isOdelloData_2012180004];
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
int isBlackTwoCheckStones_2012180004[isAiArrangement_2012180004];
int isBlackAiPutX_2012180004, isBlackAiPutY_2012180004, isBlackAiNextCheck_2012180004=0;
// AI �÷��� ���úκ�
int isWhatPlayScore =0;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void isBlackReverseStones_2012180004(); // BlackAttack �Ҷ�
void isWhiteReverseStones_2012180004(); // BlackDefence �Ҷ�
void isHintLoad_2012180004(); // ��Ʈ�κ��� Ȯ���� �Ҷ� ����Ѵ�.
void isHintCheck_2012180004(); // ��Ʈ�κ��� üŷ�Ϸ��� �Ҷ� ����Ѵ�.
void isHintClear_2012180004(); //Hint�� �ʱ�ȭ�Ѵ�.

void isBlackStonesChecker_2012180004(); //���� ���� ���� �켱 �������� ������ġ
void isWhiteStonesChecker_2012180004(); //���� ���� ���� ����� ���� ��ġ
void isNextHintClear_2012180004(); //Hint�� �ʱ�ȭ�Ѵ�.
void isNextHintLoad_2012180004(); // ��Ʈ�κ��� Ȯ���� �Ҷ� ����Ѵ�.
void isNextHintCheck_2012180004(); // ��Ʈ�κ��� üŷ�Ϸ��� �Ҷ� ����Ѵ�.

void isAiTotalPlus(int, int []); // ����ġ ���

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
	}
	isHintClear_2012180004(); // ��Ʈ�� �ʱ�ȭ ����
	isHintLoad_2012180004(); // ��Ʈ�� ����� ���ش�.
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
		// ���� ���� ������ ������ �����Ͽ�, �񱳸� �����Ѵ�..!
		if( isBlackAIx_2012180004[i] == 0 && isBlackAIy_2012180004[i] == 0 && isBlackAiCount_2012180004[i] == 0)
			break;

		isBlackAiPutX_2012180004 = isBlackAIx_2012180004[i], isBlackAiPutY_2012180004 = isBlackAIy_2012180004[i];
		isBlackAiNext_2012180004[isBlackAiPutY_2012180004][isBlackAiPutX_2012180004] = Black;
		isBlackStonesChecker_2012180004();
		// �� �������� �ѹ� ������
		isNextHintClear_2012180004();
		isNextHintLoad_2012180004();
		isAiTotalPlus(TwoTurn, isBlackAiCountNext_2012180004);
		// �� ������ �������� �ϴ°��� �ֻ�����
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

		int tempB=0, tempW=0;
		for(int i=0; i<isOdelloData_2012180004; ++i){
			for(int j=0; j<isOdelloData_2012180004; ++j){
				if( isBlackArr_2012180004[i][j] == Black){
					++tempB;
				}else if ( isBlackArr_2012180004[i][j] == White){
					++tempW;
				}
			}
		}
		//printf("Black : %d, White : %d\n", tempB, tempW);
		isBlackAiNext_2012180004[isBlackAIyNext_2012180004[0]][isBlackAIxNext_2012180004[0]] = White;
		isBlackAiPutX_2012180004 = isBlackAIxNext_2012180004[0], isBlackAiPutY_2012180004 = isBlackAIyNext_2012180004[0];
		isWhiteStonesChecker_2012180004();
		// �� �ֻ��� ���� ���� ����ġ �������� �ѱ�� �ϴ� �κ�
		int NtempNB=0, NtempNW=0;
		for(int i=0; i<isOdelloData_2012180004; ++i){
			for(int j=0; j<isOdelloData_2012180004; ++j){
				if( isBlackAiNext_2012180004[i][j] == Black){
					++NtempNB;
				}else if ( isBlackAiNext_2012180004[i][j] == White){
					++NtempNW;
				}
			}
		}

		/*printf("NBlack : %d, NWhite : %d\n", NtempNB, NtempNW);
		printf("Nblack-Black = %d\n", NtempNB-tempB);
		printf("NWhite-NWhite = %d\n", NtempNW-tempW);*/
		int isResult_2012180004=0, isBlackResult_2012180004 = NtempNB-tempB;
		if( (NtempNW-tempW) < 0){
			//����
			isResult_2012180004 = (NtempNB-tempB)+(NtempNW-tempW);
			//printf("Result : %d\n", isResult_2012180004);
		}else{
			isResult_2012180004 = (NtempNB-tempB)-(NtempNW-tempW);
			//printf("Result : %d\n", isResult_2012180004);
		}

		//printf("(%d, %d) = %d : %d : %d --\n\n", isBlackAIx_2012180004[i], isBlackAIy_2012180004[i], isBlackAiCount_2012180004[i], isResult_2012180004, isBlackResult_2012180004);

		isBlackCheckStones_2012180004[i] = isResult_2012180004;
		isBlackTwoCheckStones_2012180004[i] = isBlackResult_2012180004;
		//system("pause");

		for( int i=0; i<isOdelloData_2012180004; ++i){
			for( int j=0; j<isOdelloData_2012180004; ++j){
				isBlackAiNext_2012180004[i][j] = tempArr[i][j];
			}
		}

	} // for(int i=0; i<isAiArrangement_2012180004; ++i){

	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isBlackCheckStones_2012180004[i] < isBlackCheckStones_2012180004[j] ){
				int tempData = isBlackCheckStones_2012180004[i];
				int tempTwoData = isBlackTwoCheckStones_2012180004[i];
				isBlackCheckStones_2012180004[i] = isBlackCheckStones_2012180004[j];
				isBlackTwoCheckStones_2012180004[i] = isBlackTwoCheckStones_2012180004[j];
				isBlackCheckStones_2012180004[j] = tempData;
				isBlackTwoCheckStones_2012180004[j] = tempTwoData;


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

	/*for(int i=0; i<isAiArrangement_2012180004; ++i){
	printf("(%d, %d) = %d : %d : %d\n", isBlackAIx_2012180004[i], isBlackAIy_2012180004[i],isBlackAiCount_2012180004[i], isBlackCheckStones_2012180004[i], isBlackTwoCheckStones_2012180004[i]  );
	}
	system("pause");*/


	for(int i=0; i<isAiArrangement_2012180004-1; ++i){
		for(int j=i+1; j<isAiArrangement_2012180004; ++j){
			if( isBlackAiCount_2012180004[i] != 0){
				if( isBlackTwoCheckStones_2012180004[i] < isBlackTwoCheckStones_2012180004[j] ){
					int tempData = isBlackTwoCheckStones_2012180004[i];
					int tempTwoData = isBlackCheckStones_2012180004[i];
					isBlackTwoCheckStones_2012180004[i] = isBlackTwoCheckStones_2012180004[j];
					isBlackCheckStones_2012180004[i] = isBlackCheckStones_2012180004[j];
					isBlackTwoCheckStones_2012180004[j] = tempData;
					isBlackCheckStones_2012180004[j] = tempTwoData;

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

	int isRBlack_2012180004=0, isRWhite_2012180004=0;
	for(int i=0; i<isOdelloData_2012180004; ++i){
		for(int j=0; j<isOdelloData_2012180004; ++j){
			if( isBlackArr_2012180004[i][j] == Black){
				++isRBlack_2012180004;
			}else if ( isBlackArr_2012180004[i][j] == White){
				++isRWhite_2012180004;
			}
		}
	}

	bool isEdge = false;
	for(int i=0; i<isAiArrangement_2012180004; ++i){
		// 2������ �д´� �ص� �𼭸��� �߿��ϴϱ�~!!!
		if( isBlackAIx_2012180004[i] == 0 && isBlackAIy_2012180004[i] == 0 && isBlackAiCount_2012180004[i] != 0){
			isEdge = true;
		}else if( isBlackAIx_2012180004[i] == 0 && isBlackAIy_2012180004[i] == 7 && isBlackAiCount_2012180004[i] != 0){
			isEdge = true;										  
		}else if( isBlackAIx_2012180004[i] == 7 && isBlackAIy_2012180004[i] == 0 && isBlackAiCount_2012180004[i] != 0){
			isEdge = true;							  
		}else if( isBlackAIx_2012180004[i] == 7 && isBlackAIy_2012180004[i] == 7 && isBlackAiCount_2012180004[i] != 0){
			isEdge = true;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------------
	int isEdgeMyCount =0; // �ڽ��� ���� �𼭸��� 3���̻�ÿ� ����ġ�� �����Ѵ�.
	if( isBlackArr_2012180004[0][0] == Black){
		++isEdgeMyCount;
	}else if( isBlackArr_2012180004[0][7] == Black){
		++isEdgeMyCount;							  
	}else if( isBlackArr_2012180004[7][0] == Black){
		++isEdgeMyCount;						  
	}else if( isBlackArr_2012180004[7][7] == Black){
		++isEdgeMyCount;
	}
	if( isEdgeMyCount>= 3){
		isEdge=true;
	}
	//------------------------------------------------------------------------------------------------------------------------------------------
	int isEdgeYourCount =0; // ����  ���� �𼭸��� 2���̻�ÿ� ����ġ�� �����Ѵ�.
	if( isBlackArr_2012180004[0][0] == White){
		++isEdgeYourCount;
	}else if( isBlackArr_2012180004[0][7] == White){
		++isEdgeYourCount;							  
	}else if( isBlackArr_2012180004[7][0] == White){
		++isEdgeYourCount;						  
	}else if( isBlackArr_2012180004[7][7] == White){
		++isEdgeYourCount;
	}
	if( isEdgeYourCount>= 2){
		isEdge=true;
	}
	//------------------------------------------------------------------------------------------------------------------------------------------

	if(isWhatPlayScore >= 10 && isRBlack_2012180004 <= isRWhite_2012180004 || isEdge == true ){
		printf("AiTotalPlus Attack!!!\n");
		for(int i=0; i<isAiArrangement_2012180004-1; ++i){
			for(int j=i+1; j<isAiArrangement_2012180004; ++j){
				if( isBlackAiCount_2012180004[i] < isBlackAiCount_2012180004[j] ){
					int tempData = isBlackTwoCheckStones_2012180004[i];
					int tempTwoData = isBlackCheckStones_2012180004[i];
					isBlackTwoCheckStones_2012180004[i] = isBlackTwoCheckStones_2012180004[j];
					isBlackCheckStones_2012180004[i] = isBlackCheckStones_2012180004[j];
					isBlackTwoCheckStones_2012180004[j] = tempData;
					isBlackCheckStones_2012180004[j] = tempTwoData;

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

	/*for(int i=0; i<isAiArrangement_2012180004; ++i){
	printf("(%d, %d) = %d : %d : %d\n", isBlackAIx_2012180004[i], isBlackAIy_2012180004[i],isBlackAiCount_2012180004[i], isBlackCheckStones_2012180004[i], isBlackTwoCheckStones_2012180004[i]  );
	}
	system("pause");*/

	if(  isBlackAIx_2012180004[0] == 0 && isBlackAIy_2012180004[0] == 0 &&  isBlackAiCount_2012180004[0] == 0){
		for(int i=0; i<isAiArrangement_2012180004; ++i){
			if(isBlackAiCount_2012180004[i] !=0){
				// ������ �����Ͽ�����, ������ ���� �������
				isBlackAIx_2012180004[0] = isBlackAIx_2012180004[i], isBlackAIy_2012180004[0] = isBlackAIy_2012180004[i];
				isBlackAiCount_2012180004[0] =  isBlackAiCount_2012180004[i];
				break;
			}
		}
	}

	for(int i=0; i<isAiArrangement_2012180004; ++i){
		isBlackCheckStones_2012180004[i] = 0; // üũ�ϴºκ��� ������ �ʱ�ȭ�� ����� �Ѵ�..!
		isBlackTwoCheckStones_2012180004[i] = 0;
	}

	//------------------------------------------------------------------------------------------------------------------------------------------
	if(  isBlackAiCount_2012180004[0] != 0){

		isBlackArr_2012180004[isBlackAIy_2012180004[0]][isBlackAIx_2012180004[0]] = Black;
		isTempRy_2012180004=isBlackAIy_2012180004[0], isTempRx_2012180004=isBlackAIx_2012180004[0];
		isBlackReverseStones_2012180004();

		isBlackAiPutX_2012180004 = isBlackAIx_2012180004[0], isBlackAiPutY_2012180004 = isBlackAIy_2012180004[0];
		isBlackAiNext_2012180004[isBlackAiPutY_2012180004][isBlackAiPutX_2012180004] = Black;
		isBlackStonesChecker_2012180004();

		*x = isBlackAIx_2012180004[0];
		*y = isBlackAIy_2012180004[0];
		// �������� ������ �����ϴ� �κ�
		printf("[%d]BlackAttack!!! ( %d, %d )\n",isWhatPlayScore, isBlackAIx_2012180004[0], isBlackAIy_2012180004[0] );
	}else{
		printf("BlackAttack!!!\n�ڸ��� �����ϴ�..!\n");
	}
	++isWhatPlayScore;
	//------------------------------------------------------------------------------------------------------------------------------------------
}

void BlackDefence_2012180004( int x, int y ){
	printf("[%d]BlackDefence!!! ( %d, %d )\n", isWhatPlayScore, x,y);

	isHintClear_2012180004();
	isBlackArr_2012180004[y][x] = White;
	isTempRy_2012180004=y, isTempRx_2012180004=x;
	isWhiteReverseStones_2012180004();

	isBlackAiNext_2012180004[y][x] = White;
	isBlackAiPutX_2012180004 =x, isBlackAiPutY_2012180004 = y;
	isWhiteStonesChecker_2012180004();
	++isWhatPlayScore;
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
					// ����
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
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
}

void isWhiteStonesChecker_2012180004(){
	for(int k=-1; k<=1; ++k){
		for(int l=-1;l<=1; ++l){

			if(isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] != None 
				&& isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] != Hint){
					// ���
					if( isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] == Black){
						int tXt=isBlackAiPutX_2012180004+l, tYt=isBlackAiPutY_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackAiNext_2012180004[tYt][tXt]!=Black || isBlackAiNext_2012180004[tYt][tXt]==Hint)
								break;
							tYt+=k;
							tXt+=l;
						}

						if((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackAiNext_2012180004[tYt][tXt]==None || isBlackAiNext_2012180004[tYt][tXt]==Hint)
								continue;

							tXt-=l; tYt-=k;
							while(tXt!=isBlackAiPutX_2012180004 || tYt!=isBlackAiPutY_2012180004){
								isBlackAiNext_2012180004[tYt][tXt]=White;
								tXt-=l;tYt-=k;
							}
						}
					}
			} // if(arr[tempX-1+k][tempY-1+l] != None){
		} // for(l=-1;l<=1; ++l){
	} // for(k=-1; k<=1; ++k){
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
					if( isBlackAiNext_2012180004[isBlackAiPutY_2012180004+k][isBlackAiPutX_2012180004+l] == Black){
						int tXt=isBlackAiPutX_2012180004+l, tYt=isBlackAiPutY_2012180004+k;
						while((tXt>=0&&tYt>=0)&&(tXt<=7&&tYt<=7)){
							if(isBlackAiNext_2012180004[tYt][tXt]!=Black || isBlackAiNext_2012180004[tYt][tXt]==Hint)
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
		// ����ġ ���
		if( isRealX == 0 && isRealY == 0 && scoreData[i] == 0)
			continue;
		if((isRealY == 0 && isRealX == 0) || (isRealY == 0 && isRealX ==7) || (isRealY == 7 && isRealX ==0) || (isRealY == 7 && isRealX ==7)){
			// ���� ��
			scoreData[i]+=100;
		}else if(((isRealY == 0 || isRealY == 7) && (1<=isRealX && isRealX<=6))||((isRealX == 0 || isRealX == 7) && (1<=isRealY && isRealY<=6))){
			// �Ķ���
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
					// �Ķ��� ���� ������
					//printf("( %d, %d )\n", isRealX, isRealY);
					if( tempArr[isRealY-1][isRealX] == None && tempArr[isRealY+1][isRealX] == None ){
						//printf("---------------------Bingo---------------------\n");
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
					// �Ķ��� ���� �Ʒ���
					if( tempArr[isRealY][isRealX-1] == None && tempArr[isRealY][isRealX+1] == None ){
						//printf("---------------------Bingo---------------------\n");
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
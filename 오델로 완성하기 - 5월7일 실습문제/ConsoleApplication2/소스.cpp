#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


/*
1. 오델로의 규칙에 따라 돌을 뒤집어라.
└ 이미 구현 되어 있으므로 패스 for문2개와 while 문을 이용하면 구현이 가능하다.

2. 오델로판의 현재 상태를 저장하여 파일로 만드는 기능을 구현하라.
└ 배열 8*8로 저장을 하여 있으므로 배열을 한줄씩 읽어서 한줄씩 저장을 해버린다.
 └ fopen을 이용하여 저장하되 파싱을 할수있게 하나하나 마다의 동일한 값을 넣어준다 ex) 0,0,1,2,0,2,1
  └ 배열의 한줄씩 마다 저장을 하는 방법도 있지만, 좀더 편하게 배열전체를 한줄로 만들어 저장을 하게 한다.

3. 저장 파일을 읽어들려 오델로를 계속 둘 수 있는 기능을 구현하라.
└ 불러오기시 한줄씩 읽어가면서 배열에 집어넣는다. 파싱을 이용해서 한줄씩 읽어들여가면서 파싱을 해야한다.
 └ 한줄씩 읽기를 하려 하였으나 fscanf 를 이용하여 한줄이 아닌 하나의 위치당 하나씩 읽어들인다. ex) 0, 를 읽어서 데이터에는 0을 쓰게 한다.

= 대화상자를 사용할수 없는 상황이므로, 파일이 실행되는 위치에다가 저장을 하거나, 그외 다른 위치에 따로 데이터를 저장할수 있게 한다.
= fopen을 이용하여 경로를 정해주지 않으면 해당 실행되는 위치에 저장, 불러오기가 가능하다.
= 저장시에 기존 저장된 데이터를 확인하고 덮어씌우던가 지워야하는데 unlink라는 함수를 사용하여 해당 파일을 삭제후 저장을 하게 만든다.

4. 오델로에서 몇 수를 물렀다가 전부 원래대로 또 일부를 원래대로 두게 하는 기능을 스택 또는 큐를 이용하여 구현하라.
└ 스택이나 큐를 아직 배우지 않았으므로, 목요일날 배운 이후 해결을 해본다
 └ 스택은 먼저 들어오는사람이 가장 아래로 쌓이는것이고, 큐는 계속 옆으로 쌓이는데 먼저들어온사람이 제일 오른쪽으로 쌓이는것이다.
  └ 스택은 한수 물리기 등의 기능을 사용할때 편하고 ( 스택을 2개를 만들어서 ), 큐도 가능은 하지만 스택이 오히려 편한거 같은 느낌이 든다..!
*/

enum{ None, Black, White, Hint };

#define LEFT   75      // 좌측방향키
#define RIGHT  77      // 우측방향키
#define UP     72      // 위쪽방향키
#define DOWN   80      // 아래방향키
#define ENTER   13      // Enter키
#define SPACE   32      // Space키

void isShowOdelloMap();
void isDrawBWstones(int);
void isWidthCheck(int);
void isHeightCheck(int);
void isAddStones();
void isTempBWStones();
int isTempReverseStones();
void isReverseStones();
void isClearTempBW();
// 불러오기 저장을 위한 부분
void isSaveData();
void isLoadData();

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
			printf("Play User : Black");
		}else{
			printf("Play User : White");
		}
		/*
		printf("Coordinates ( %d , %d )\n", tempX, tempY);
		printf("Real Coordinates ( %d , %d )", tempX-1, tempY-1 );
		printf("Key : %d", isGetInPutKey );
		*/
		isGetInPutKey = getch();

		switch( isGetInPutKey ){

		case 's':
		case 'S':
			isSaveData();
			break;

		case 'l':
		case 'L':
			isLoadData();
			break;

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

void isSaveData(){
	int data=0;
	unlink("Save.dat");
	//unlink("Team.dat");

	for(int i=0; i <8; ++i){
		for( int j=0; j<8; ++j){
			if( arr[i][j] == None){
				FILE * pFile;
				char buffer[] = { '0' , ',' };
				pFile = fopen ( "Save.dat" , "a+" );
				fwrite (buffer , 1 , sizeof(buffer) , pFile );
				fclose (pFile);
			}else if( arr[i][j] == Hint){
				FILE * pFile;
				char buffer[] = { '0' , ',' };
				pFile = fopen ( "Save.dat" , "a+" );
				fwrite (buffer , 1 , sizeof(buffer) , pFile );
				fclose (pFile);
			}else if( arr[i][j] == Black){
				FILE * pFile;
				char buffer[] = { '1' , ',' };
				pFile = fopen ( "Save.dat" , "a+" );
				fwrite (buffer , 1 , sizeof(buffer) , pFile );
				fclose (pFile);
			}else if( arr[i][j] == White){
				FILE * pFile;
				char buffer[] = { '2' , ',' };
				pFile = fopen ( "Save.dat" , "a+" );
				fwrite (buffer , 1 , sizeof(buffer) , pFile );
				fclose (pFile);
			}
			printf("(%d, %d)\n", i,j);
		}
	}
	//Sleep(100000);

	if(isPlayUser == Black){
		FILE * pFile;
		char buffer[] = { '1' , ',' };
		pFile = fopen ( "Save.dat" , "a+" );
		fwrite (buffer , 1 , sizeof(buffer) , pFile );
		fclose (pFile);
	}else{
		FILE * pFile;
		char buffer[] = { '2' , ',' };
		pFile = fopen ( "Save.dat" , "a+" );
		fwrite (buffer , 1 , sizeof(buffer) , pFile );
		fclose (pFile);
	}

	printf("Save.dat..!");
}

void isLoadData(){

	for(int i=0; i <8; ++i){
		for(int j=0; j<8; ++j){
			arr[i][j] =  None;
		}
	}

	FILE *fp;//파일을 읽기 위한 포인터 선언
	int aa[1000];//정수형 배열 선언
	int idx=0;//배열 인덱스로 사용할 변수
	int isi=0, isj=0;
	if((fp = fopen("Save.dat","r")) == NULL) {//파일 오픈시 널이면 에러메시지 처리
		printf("No Save Data..!\n");
	}
	while( fscanf(fp, "%d,",&aa[idx]) != EOF) {//파일의 끝이 아닐 경우 계속적으로 반복,인덱스를 하나씩 증가해서 넣어준 것이 핵심, fscanf or scanf 사용시 &(주소)를 붙여줘야 함.

		if( aa[idx] == 0){
			arr[isi][isj] = None;
		}else if( aa[idx] == 1){
			arr[isi][isj] = Black;
		}else if( aa[idx] == 2){
			arr[isi][isj] = White;
		}

		printf("(%d, %d)%d\n",isi,isj,aa[idx]);//입력된 값을 파일 형식대로 출력해봄. 입력이 잘 되었으면 파일 내용을 그대로 출력해줌.
		isj++;
		if(isj==8){
			isj=0;
			isi++;
		}
		if(isi==8){
			isi=0, isj=0;
			idx+=1;//4개씩 배열에 입력되므로 익덱스를 4만큼 증가
			fscanf(fp, "%d,",&aa[idx]);
			if(aa[idx] == 1){
				isPlayUser = Black;
			}else{
				isPlayUser =White;
			}
			break;
		}
		idx+=1;//4개씩 배열에 입력되므로 익덱스를 4만큼 증가
	}
	fclose(fp);//파일을 닫아줌.

	//Sleep(100000);

	printf("Load.dat..!");
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
	for(int i=0; i<8; ++i){
		isHeightCheck(i);
	}
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

	isWidthCheck(line);

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

void isWidthCheck(int line){
	int isStonesCheck[8] = {0}, isStonesCount[8]= {0}, isCheckNum=0;
	// Black, White 돌로 체크를 하게할까?
	for(int i=0; i<8; ++i){
		if(arr[line][i] ==Black && isStonesCount[isCheckNum] == 0){ // 검정이고 체크한적이 없으면 검정색을 올린다
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if(arr[line][i] ==White && isStonesCount[isCheckNum] == 0){ // 흰색이고 체크한적이 없으면 흰색으로 올린다.
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else{
			if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[line][i] ==Black){ //검정이고 올린적이 있고 그다음도 검정이면 숫자를 올린다.
				isStonesCount[isCheckNum] +=1;
			}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[line][i] ==White){ // 흰색이고 올린적이 있고 그다음도 흰색이면 숫자를 올린다.
				isStonesCount[isCheckNum] +=1;
			}
		}

		if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[line][i] ==White){ // 검정인데 숫자는 올라가있고 다음이 흰색이면 초기화후 흰색으로
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[line][i] ==Black){ // 흰색인데 숫자는 올라가있고 다음이 검정이면 초기화후 검정으로
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if( isStonesCount[isCheckNum] != 0 && (arr[line][i] ==None || arr[line][i] ==Hint) ){ // 연속체크를 하다가 빈자리가 나올경우 값을 올린다.
			isCheckNum+=1;
		}
	}

	for(int i=0; i<8-1; ++i){
		for(int j=i+1; j<8; ++j){
			int isMoveTemp[3] ={0};
			if( isStonesCount[i] < isStonesCount[j] ){
				isMoveTemp[0]=isStonesCount[i];
				isMoveTemp[1]=isStonesCheck[i];

				isStonesCount[i] = isStonesCount[j];
				isStonesCheck[i] = isStonesCheck[j];

				isStonesCount[j] = isMoveTemp[0];
				isStonesCheck[j] = isMoveTemp[1];
			} 
		} 
	}
	if(isStonesCount[0] != isStonesCount[1] && isStonesCount[0] != 1){
		if(isStonesCheck[0] == Black){
			printf("검정색돌이 %d번 연속으로 놓아져 있습니다..!",isStonesCount[0]);
		}else{
			printf("흰색돌이 %d번 연속으로 놓아져 있습니다..!",isStonesCount[0]);
		}
	}
}

void isHeightCheck(int line){
	int isStonesCheck[8] = {0}, isStonesCount[8]= {0}, isCheckNum=0;
	// Black, White 돌로 체크를 하게할까?
	for(int i=0; i<8; ++i){
		if(arr[i][line] ==Black && isStonesCount[isCheckNum] == 0){ // 검정이고 체크한적이 없으면 검정색을 올린다
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if(arr[i][line] ==White && isStonesCount[isCheckNum] == 0){ // 흰색이고 체크한적이 없으면 흰색으로 올린다.
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else{
			if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[i][line] ==Black){ //검정이고 올린적이 있고 그다음도 검정이면 숫자를 올린다.
				isStonesCount[isCheckNum] +=1;
			}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[i][line] ==White){ // 흰색이고 올린적이 있고 그다음도 흰색이면 숫자를 올린다.
				isStonesCount[isCheckNum] +=1;
			}
		}

		if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[i][line] ==White){ // 검정인데 숫자는 올라가있고 다음이 흰색이면 초기화후 흰색으로
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[i][line] ==Black){ // 흰색인데 숫자는 올라가있고 다음이 검정이면 초기화후 검정으로
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if( isStonesCount[isCheckNum] != 0 && (arr[i][line] ==None || arr[i][line] ==Hint) ){ // 연속체크를 하다가 빈자리가 나올경우 값을 올린다.
			isCheckNum+=1;
		}
	}

	for(int i=0; i<8-1; ++i){
		for(int j=i+1; j<8; ++j){
			int isMoveTemp[3] ={0};
			if( isStonesCount[i] < isStonesCount[j] ){
				isMoveTemp[0]=isStonesCount[i];
				isMoveTemp[1]=isStonesCheck[i];

				isStonesCount[i] = isStonesCount[j];
				isStonesCheck[i] = isStonesCheck[j];

				isStonesCount[j] = isMoveTemp[0];
				isStonesCheck[j] = isMoveTemp[1];
			} 
		} 
	}
	if(isStonesCount[0] != isStonesCount[1] && isStonesCount[0] != 1){
		if(isStonesCheck[0] == Black){
			printf("세로 %d : 검정색돌이 %d번 연속으로 놓아져 있습니다..!\n",line+1,isStonesCount[0]);
		}else{
			printf("세로 %d : 흰색돌이 %d번 연속으로 놓아져 있습니다..!\n",line+1,isStonesCount[0]);
		}
	}
}
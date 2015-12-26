#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

/*
1. 오델로의 규칙에 따라 돌을 뒤집어라.
└ 이미 구현 되어 있으므로 패스 for문2개와 while 문을 이용하면 구현이 가능하다.
└ Hint를 줄경우 돌을 확인하기 위해 해당 돌의 갯수만큼 올라가서 해당 돌이 내가 놓은 돌과 다른 돌일경우에는, True를 반환해 Hint를 찍어주는것을 이용한다.
└ 해당 True를 반환하는것을 거기서 끝내지 말고, 다시 이동한만큼 -(마이너스)를 이용하여 다시 되돌아 오면서 해당 돌의 값들을 자신의 돌로 바꾸는 방식을 이용한다.

2. 오델로판의 현재 상태를 저장하여 파일로 만드는 기능을 구현하라.
└ 배열값을 그대로 저장하고, 불러오기 기능을 하면 편하고 빠르게 저장및 불러오기가 가능하지만, 무르기와 같은 기능을 추가해야 하므로, 배열값을 저장하는것은 의미가 없다.
└ 배열값을 저장하지 않고, 스택에 저장된 데이터 들을 ( x, y , t ) 값을 저장하면 불러올시에도 해당 스택을 그대로 불러오면 되돌리기등이 가능하게 된다.
└ x, y = 돌이 놓여진 위치 / t = 돌의 색상(현제 돌의팀)

3. 저장 파일을 읽어들려 오델로를 계속 둘 수 있는 기능을 구현하라.
└ 불러오기시 저장된 값이 x, y, t 로 저장이 되어 있으므로 3개씩 끊어서 파싱을 해온다.
└ 3개씩 파싱을 한후에 해당 파싱한 데이터를 스택에 저장을 하면서, 배열에 그려준다. ( 스택에 저장된것을 바로 표시하게 하면 편할수 있지만, 코드를 다시 짜야하므로 따로따로 해준다. )
└ 파싱을 할시 fscanf 를 이용하여 %d, %d, %d 단위로 저장을 하여, 해당 값을 배열에 그려 주면서 스택에 넣어준다.
└ 불러올시 뒤집어진 돌에 대해서의 기록은 저장되어있지 않기때문에, 4번에서의 마지막 말처럼 사용자가 직접 놓은것처럼 자동으로 스택을 읽어서 놓는다.

= 대화상자를 사용할수 없는 상황이므로, 파일이 실행되는 위치에다가 저장을 하거나, 그외 다른 위치에 따로 데이터를 저장할수 있게 한다.
= fopen을 이용하여 경로를 정해주지 않으면 해당 실행되는 위치에 저장, 불러오기가 가능하다.
= 저장시에 기존 저장된 데이터를 확인하고 덮어씌우던가 지워야하는데 unlink라는 함수를 사용하여 해당 파일을 삭제후 저장을 하게 만든다.

4. 오델로에서 몇 수를 물렀다가 전부 원래대로 또 일부를 원래대로 두게 하는 기능을 스택 또는 큐를 이용하여 구현하라.
└ 스택에 저장하는 방식을 배열로 하면 편할수 있지만, 배열의 경우 미리 크기를 정해놓아야 하므로, 그이상의 데이터를 넣을수 없기에, 연결리스트를 사용한다.
└ 연결리스트를 사용하여 데이터를 추가시 기본적으로 head의 next 부분의 추가를 하지만, 스택처럼 쌓이게 만들때 이중환영연결리스트가 아닌이상 tail에서 head까지 확인이 불가능하니
└ 등록시에 tail의 이전의 next 부분에 추가하면, head ~ tail 까지 계속 쌓이게 만들수가 있다.
└ 무르기와, 무른것을 취소하기위해서는 이중 스택을 만들어서 무르기를 할경우, 해당 무르기가 된 값을 다른 스택에 등록을 해둔다.
└ 무르기를 한후에 돌이 새로 놓아질경우 다른 스택에 무른것에 있는 데이터를 초기화 한다. ( 초기화를 안할시 새로 놓은것이 무시되고 이전 데이터로 되돌아갈수있기 때문에 )
└ 스택에는 놓아진 돌만을 추가를 하기때문에, 되돌리기를 할경우에 뒤집어진 돌에는 신경을 쓰지 못한다... 해당 부분을 해결 하기 위하여
└ 조금 무식한 방법이지만 해당 배열을 비운후 스택에 쌓여진 돌을 실제로 User가 Enter를 치면서 놓는것처럼 처음부터 현제 스택까지를 계속 놓아준다.
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
void isHintData(); //힌트 주는 부분
int isTempReverseStones();
void isReverseStones();
void isClearTempBW();
// 불러오기 저장을 위한 부분
void isSaveData(); // 스택을 저장
void isLoadData(); // 스택을 불러온다
void isDataAdd(int, int, int); // 스택에 놓아진 돌들을 저장해주는 부분
void isBackUpDataAdd(int, int, int); // 되돌리기등을 한후의 그 되돌리기의 되돌리기를 다시 되돌리기를 할때 저장하는 부분
void isShowData(); // 스택이 제대로 저장이 되어있는지 확인한기 위한부분
void isCtrlZ(); // 되돌리기
void isCtrlShiftZ(); // 되돌린것을 다시 되돌리기
void isReLoadData(); // 스택에 저장된 값으로 돌을 놓아주는 부분

typedef struct isData { //구조체 선언
	int isX;
	int isY;
	int isTeam;
	struct isData* next;
}isData;

typedef struct isDataBUP { //구조체 선언
	int isX;
	int isY;
	int isTeam;
	struct isDataBUP* next;
}isDataBUP;

isData *head;
isData *tail;
isDataBUP *bhead;
isDataBUP *btail;

void init(void){
	head=(isData*)malloc(sizeof(isData));
	head->next=tail;
	bhead=(isDataBUP*)malloc(sizeof(isDataBUP));
	bhead->next=btail;
}

void isOldDatainit(void){
	bhead=(isDataBUP*)malloc(sizeof(isDataBUP));
	bhead->next=btail;
}

int isGetInPutKey, isSetBlockTF=0;
int arr[8][8], isSeroCheck[8], isSero[8];

int tempX=1, tempY=1;
int isPlayUser = Black, temp;
int isBlackNum =0, isWhiteNum = 0;
int isTempRx, isTempRy;
int isReLoadAddStone=0;
int isinsertname=0;

int main(){
	init();
	for(int i=0; i <8; ++i){
		for(int j=0; j<8; ++j){
			arr[i][j] =  None;
		}
	}

	arr[4][3] = Black; //검은색 돌
	isDataAdd(4,3,White);
	arr[3][4] = Black;
	isDataAdd(3,4,White);
	arr[3][3] = White; //흰색 돌
	isDataAdd(3,3,Black);
	arr[4][4] = White;
	isDataAdd(4,4,Black);

	while(1){
		system("cls");
		isHintData();
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

		case 'z':
		case 'Z':
			isCtrlZ();
			break;

		case 'x':
		case 'X':
			isCtrlShiftZ();
			break;

		case 'a':
		case 'A':
			isShowData();
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

void isReLoadData(){
	int isDrawStones = 0;
	for(int i=0; i <8; ++i){
		for(int j=0; j<8; ++j){
			arr[i][j] =  None;
		}
	}
	arr[4][3] = Black; //검은색 돌
	arr[3][4] = Black;
	arr[3][3] = White; //흰색 돌
	arr[4][4] = White;
	// └ 기본 적으로 저장된 데이터 들을 우선적으로 놓는다
	isData *z;
	z=head->next;
	while (z != tail){

		if( z->isTeam == Black){
			isDrawStones = 2;
		}else{
			isDrawStones = 1;
		}

		tempY = z->isX+1, tempX= z->isY+1;
		isPlayUser = isDrawStones;

		isClearTempBW(); // 힌트부분을 초기화 해준다
		isReLoadAddStone=1; 
		// AddStones 을 할시 기본적으로 되돌리기의 되돌리기인 isDataBup 는 초기화를 하게된다.
		// 그부분을 방지하기위해 전역변수로 초기화를 하지 못하게 방지하는 부분의 IF문을 추가하였다.
		isAddStones();
		isReLoadAddStone=0;
		isHintData(); // 힌트를 다시 생성해준다.

		z=z->next;
	}

	if(isDrawStones == 2){
		isPlayUser = 1;
	}else{
		isPlayUser = 2;
	}
	// 저장시 돌의 색상의 반대를 저장하게 해놓아서 다시 원래되로 되돌린다.
}

void isCtrlZ(){
	isData *t;
	isData *p;
	isData *n;

	if( isBlackNum == 2 &&  isWhiteNum == 2){
		printf("\n\nNoData..!");
	}else{
		if(head->next == tail){
			printf("\n\nNoData..!");
		}else{
			p=head;
			t=p->next;
			n=t->next;
			while (n != tail){
				p=p->next;
				t=p->next; //가장 마지막 좌표
				n=t->next;
			}

			isBackUpDataAdd(t->isX, t->isY, t->isTeam);

			p->next=n;
			free(t);
			isReLoadData();
			isClearTempBW();
			isHintData();
		}
	}
}

void isCtrlShiftZ(){
	int isDrawStones = 0;
	isDataBUP *p;
	isDataBUP *t;
	isDataBUP *n;
	if(bhead->next == btail){
		printf("\n\nNoData..!");
	}else{

		p=bhead;
		t=p->next;
		n=t->next;

		while (n != btail){
			p=p->next;
			t=p->next; //가장 마지막 좌표
			n=t->next;
		}

		isDataAdd(t->isX,t->isY,t->isTeam);

		p->next=n;
		free(t);

		isReLoadData();
		isClearTempBW();
		isHintData();

	}
}

void isShowData(){
	int isCount=0;
	isData *t;
	t=head->next;
	printf("\n");
	while (t != tail){
		printf("%d = isX : %d, isY : %d, isTeam : %d\n",isCount, t->isX,t->isY, t->isTeam);
		isCount++;
		t=t->next;
	}
	printf("----------------------------\n\n");
	Sleep(3000);
}

void isBackUpDataAdd(int isDataX,int isDataY,int isDataTeam){
	isDataBUP *t;
	isDataBUP *p;
	isDataBUP *n;
	p=bhead;
	t=p->next;

	while (t != btail){
		p=p->next;
		t=p->next;
	}

	n=(isDataBUP*)malloc(sizeof(isDataBUP));
	n->isX= isDataX;
	n->isY=isDataY;
	n->isTeam= isDataTeam;
	n->next=p->next;
	p->next=n;

}

void isDataAdd(int isDataX,int isDataY,int isDataTeam){
	isData *t;
	isData *p;
	isData *n;
	p=head;
	t=p->next;

	while (t != tail){
		p=p->next;
		t=p->next;
	}

	n=(isData*)malloc(sizeof(isData));
	n->isX= isDataX;
	n->isY=isDataY;
	n->isTeam= isDataTeam;
	n->next=p->next;
	p->next=n;

}

void isSaveData(){
	isData *t;
	t=head->next;
	unlink("Save.dat");
	//unlink("Team.dat");

	printf("\n");
	while (t != tail){

		FILE * pFile;
		char buffer[] = {(char)(t->isX + '0') , ',' , (char)(t->isY+'0'), ',', (char)(t->isTeam+'0'), ','  };
		pFile = fopen ( "Save.dat" , "a+" );
		fwrite (buffer , 1 , sizeof(buffer) , pFile );
		fclose (pFile);

		printf("isX : %d, isY : %d, isTeam : %d\n", t->isX,t->isY, t->isTeam);
		//Sleep(100);
		t=t->next;
	}
	printf("Save.dat..!");
}

void isLoadData(){
	int isDrawStones = 0;
	for(int i=0; i <8; ++i){
		for(int j=0; j<8; ++j){
			arr[i][j] =  None;
		}
	}
	init(); //초기화
	printf("\n");
	FILE *fp;
	int isSaveStack[1000];
	int idx=0;
	if((fp = fopen("Save.dat","r")) == NULL) {
		printf("No Save Data..!\n");
	}
	while( fscanf(fp, "%d,%d,%d,", &isSaveStack[idx], &isSaveStack[idx+1], &isSaveStack[idx+2]) != EOF) {

		if( isSaveStack[idx+2] == Black){
			isDrawStones = 2;
		}else{
			isDrawStones = 1;
		}

		isDataAdd(isSaveStack[idx], isSaveStack[idx+1], isSaveStack[idx+2]);

		printf("isX : %d, isY : %d, isTeam : %d\n",isSaveStack[idx], isSaveStack[idx+1], isSaveStack[idx+2]);
		idx+=3;
	}
	fclose(fp);
	isReLoadData();
	isClearTempBW();
	isHintData();
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
				if(isReLoadAddStone == 0){
					isDataAdd(tempY-1,tempX-1,White);
					isOldDatainit();
				}
				isSetBlockTF = 0;
				isPlayUser = White;
			} // if(isSetBlockTF == 1){
		}
	}else{
		if(arr[tempY-1][tempX-1] == None || arr[tempY-1][tempX-1] == Hint ){
			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = White;
				if(isReLoadAddStone == 0){
					isDataAdd(tempY-1,tempX-1,Black);
					isOldDatainit();
				}
				isSetBlockTF = 0;
				isPlayUser = Black;
			} // if(isSetBlockTF == 1){
		}
	} 

}

void isReAddStones(){
	if(isPlayUser == Black){
		if(arr[tempY-1][tempX-1] == None || arr[tempY-1][tempX-1] == Hint ){
			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = Black;
				isSetBlockTF = 0;
				isPlayUser = White;
			} // if(isSetBlockTF == 1){
		}
	}else{
		if(arr[tempY-1][tempX-1] == None || arr[tempY-1][tempX-1] == Hint ){
			isReverseStones();
			if(isSetBlockTF == 1){
				arr[tempY-1][tempX-1] = White;
				isSetBlockTF = 0;
				isPlayUser = Black;
			} // if(isSetBlockTF == 1){
		}
	} 

}

void isHintData(){
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
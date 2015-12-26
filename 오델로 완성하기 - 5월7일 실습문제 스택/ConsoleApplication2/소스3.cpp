#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

enum{ None, Black, White, Hint };

#define LEFT   75      // ��������Ű
#define RIGHT  77      // ��������Ű
#define UP     72      // ���ʹ���Ű
#define DOWN   80      // �Ʒ�����Ű
#define ENTER   13      // EnterŰ
#define SPACE   32      // SpaceŰ

void isShowOdelloMap();
void isDrawBWstones(int);
void isWidthCheck(int);
void isHeightCheck(int);
void isAddStones();
void isHintData();
int isTempReverseStones();
void isReverseStones();
void isClearTempBW();

void isSaveData();
void isLoadData();
void isDataAdd(int, int, int);
void isBackUpDataAdd(int, int, int);
void isShowData();
void isCtrlZ();
void isCtrlShiftZ();
void isReLoadData();

typedef struct isData { //����ü ����
	int isX;
	int isY;
	int isTeam;
	struct isData* next;
}isData;

typedef struct isDataBUP { //����ü ����
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
int isShiftZControl =0;

int main(){
	init();
	for(int i=0; i <8; ++i){
		for(int j=0; j<8; ++j){
			arr[i][j] =  None;
		}
	}

	arr[4][3] = Black; //������ ��
	isDataAdd(4,3,White);
	arr[3][4] = Black;
	isDataAdd(3,4,White);
	arr[3][3] = White; //��� ��
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
	isData *z;
	z=head->next;
	while (z != tail){
		if( z->isTeam == Black){
			isDrawStones = 2;
		}else{
			isDrawStones = 1;
		}

		arr[z->isX][z->isY] = isDrawStones;
		isPlayUser = z->isTeam;
		z=z->next;
	}
}

void isCtrlZ(){
	isData *t;
	isData *p;
	isData *n;

	if(head->next == tail){
		printf("\n\nNoData..!");
	}else{
		p=head;
		t=p->next;
		n=t->next;
		while (n != tail){
			p=p->next;
			t=p->next; //���� ������ ��ǥ
			n=t->next;
		}

		arr[t->isX][t->isY] =None;
		isPlayUser = t->isTeam;

		isBackUpDataAdd(t->isX, t->isY, t->isTeam);

		p->next=n;
		free(t);
		isReLoadData();
		isClearTempBW();
		isHintData();
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
			t=p->next; //���� ������ ��ǥ
			n=t->next;
		}

		if( t->isTeam == Black){
			isDrawStones = 2;
		}else{
			isDrawStones = 1;
		}

		tempY = t->isX+1, tempX= t->isY+1;

		isDataAdd(t->isX,t->isY,t->isTeam);

		p->next=n;
		free(t);
		isClearTempBW();
		isShiftZControl=1;
		isAddStones();
		isShiftZControl=0;
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

	printf("\n");
	while (t != tail){

		FILE * pFile;
		char buffer[] = {(char)(t->isX + '0') , ',' , (char)(t->isY+'0'), ',', (char)(t->isTeam+'0'), ','  };
		pFile = fopen ( "Save.dat" , "a+" );
		fwrite (buffer , 1 , sizeof(buffer) , pFile );
		fclose (pFile);

		printf("isX : %d, isY : %d, isTeam : %d\n", t->isX,t->isY, t->isTeam);
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
	init();
	printf("\n");
	FILE *fp;
	int aa[1000];
	int idx=0;
	if((fp = fopen("Save.dat","r")) == NULL) {
		printf("No Save Data..!\n");
	}
	while( fscanf(fp, "%d,%d,%d,",&aa[idx],&aa[idx+1],&aa[idx+2]) != EOF) {

		if( aa[idx+2] == Black){
			isDrawStones = 2;
		}else{
			isDrawStones = 1;
		}

		arr[aa[idx]][aa[idx+1]] = isDrawStones;
		isDataAdd(aa[idx], aa[idx+1], aa[idx+2]);

		printf("isX : %d, isY : %d, isTeam : %d\n",aa[idx], aa[idx+1], aa[idx+2]);
		idx+=3;
	}
	fclose(fp);
	printf("Load.dat..!");
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
					printf("��");
				if( isPlayUser == White)
					printf("��");
			}else{
				printf("  ");
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
				isDataAdd(tempY-1,tempX-1,White);
				if(isShiftZControl == 0){
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
				isDataAdd(tempY-1,tempX-1,Black);
				if(isShiftZControl == 0){
					isOldDatainit();
				}
				isShiftZControl = 0;
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
					//�������ϰ�� itPlayUser
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

void isWidthCheck(int line){
	int isStonesCheck[8] = {0}, isStonesCount[8]= {0}, isCheckNum=0;
	// Black, White ���� üũ�� �ϰ��ұ�?
	for(int i=0; i<8; ++i){
		if(arr[line][i] ==Black && isStonesCount[isCheckNum] == 0){ // �����̰� üũ������ ������ �������� �ø���
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if(arr[line][i] ==White && isStonesCount[isCheckNum] == 0){ // ����̰� üũ������ ������ ������� �ø���.
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else{
			if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[line][i] ==Black){ //�����̰� �ø����� �ְ� �״����� �����̸� ���ڸ� �ø���.
				isStonesCount[isCheckNum] +=1;
			}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[line][i] ==White){ // ����̰� �ø����� �ְ� �״����� ����̸� ���ڸ� �ø���.
				isStonesCount[isCheckNum] +=1;
			}
		}

		if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[line][i] ==White){ // �����ε� ���ڴ� �ö��ְ� ������ ����̸� �ʱ�ȭ�� �������
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[line][i] ==Black){ // ����ε� ���ڴ� �ö��ְ� ������ �����̸� �ʱ�ȭ�� ��������
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if( isStonesCount[isCheckNum] != 0 && (arr[line][i] ==None || arr[line][i] ==Hint) ){ // ����üũ�� �ϴٰ� ���ڸ��� ���ð�� ���� �ø���.
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
			printf("���������� %d�� �������� ������ �ֽ��ϴ�..!",isStonesCount[0]);
		}else{
			printf("������� %d�� �������� ������ �ֽ��ϴ�..!",isStonesCount[0]);
		}
	}
}

void isHeightCheck(int line){
	int isStonesCheck[8] = {0}, isStonesCount[8]= {0}, isCheckNum=0;
	// Black, White ���� üũ�� �ϰ��ұ�?
	for(int i=0; i<8; ++i){
		if(arr[i][line] ==Black && isStonesCount[isCheckNum] == 0){ // �����̰� üũ������ ������ �������� �ø���
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if(arr[i][line] ==White && isStonesCount[isCheckNum] == 0){ // ����̰� üũ������ ������ ������� �ø���.
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else{
			if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[i][line] ==Black){ //�����̰� �ø����� �ְ� �״����� �����̸� ���ڸ� �ø���.
				isStonesCount[isCheckNum] +=1;
			}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[i][line] ==White){ // ����̰� �ø����� �ְ� �״����� ����̸� ���ڸ� �ø���.
				isStonesCount[isCheckNum] +=1;
			}
		}

		if(isStonesCheck[isCheckNum] == Black && isStonesCount[isCheckNum] != 0 && arr[i][line] ==White){ // �����ε� ���ڴ� �ö��ְ� ������ ����̸� �ʱ�ȭ�� �������
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = White;
			isStonesCount[isCheckNum] +=1;
		}else if(isStonesCheck[isCheckNum] == White && isStonesCount[isCheckNum] != 0 && arr[i][line] ==Black){ // ����ε� ���ڴ� �ö��ְ� ������ �����̸� �ʱ�ȭ�� ��������
			isCheckNum+=1;
			isStonesCheck[isCheckNum] = Black;
			isStonesCount[isCheckNum] +=1;
		}else if( isStonesCount[isCheckNum] != 0 && (arr[i][line] ==None || arr[i][line] ==Hint) ){ // ����üũ�� �ϴٰ� ���ڸ��� ���ð�� ���� �ø���.
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
			printf("���� %d : ���������� %d�� �������� ������ �ֽ��ϴ�..!\n",line+1,isStonesCount[0]);
		}else{
			printf("���� %d : ������� %d�� �������� ������ �ֽ��ϴ�..!\n",line+1,isStonesCount[0]);
		}
	}
}
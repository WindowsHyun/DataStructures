#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


/*
1. �������� ��Ģ�� ���� ���� �������.
�� �̹� ���� �Ǿ� �����Ƿ� �н� for��2���� while ���� �̿��ϸ� ������ �����ϴ�.

2. ���������� ���� ���¸� �����Ͽ� ���Ϸ� ����� ����� �����϶�.
�� �迭 8*8�� ������ �Ͽ� �����Ƿ� �迭�� ���پ� �о ���پ� ������ �ع�����.
 �� fopen�� �̿��Ͽ� �����ϵ� �Ľ��� �Ҽ��ְ� �ϳ��ϳ� ������ ������ ���� �־��ش� ex) 0,0,1,2,0,2,1
  �� �迭�� ���پ� ���� ������ �ϴ� ����� ������, ���� ���ϰ� �迭��ü�� ���ٷ� ����� ������ �ϰ� �Ѵ�.

3. ���� ������ �о��� �����θ� ��� �� �� �ִ� ����� �����϶�.
�� �ҷ������ ���پ� �о�鼭 �迭�� ����ִ´�. �Ľ��� �̿��ؼ� ���پ� �о�鿩���鼭 �Ľ��� �ؾ��Ѵ�.
 �� ���پ� �б⸦ �Ϸ� �Ͽ����� fscanf �� �̿��Ͽ� ������ �ƴ� �ϳ��� ��ġ�� �ϳ��� �о���δ�. ex) 0, �� �о �����Ϳ��� 0�� ���� �Ѵ�.

= ��ȭ���ڸ� ����Ҽ� ���� ��Ȳ�̹Ƿ�, ������ ����Ǵ� ��ġ���ٰ� ������ �ϰų�, �׿� �ٸ� ��ġ�� ���� �����͸� �����Ҽ� �ְ� �Ѵ�.
= fopen�� �̿��Ͽ� ��θ� �������� ������ �ش� ����Ǵ� ��ġ�� ����, �ҷ����Ⱑ �����ϴ�.
= ����ÿ� ���� ����� �����͸� Ȯ���ϰ� �������� �������ϴµ� unlink��� �Լ��� ����Ͽ� �ش� ������ ������ ������ �ϰ� �����.

4. �����ο��� �� ���� �����ٰ� ���� ������� �� �Ϻθ� ������� �ΰ� �ϴ� ����� ���� �Ǵ� ť�� �̿��Ͽ� �����϶�.
�� �����̳� ť�� ���� ����� �ʾ����Ƿ�, ����ϳ� ��� ���� �ذ��� �غ���
 �� ������ ���� �����»���� ���� �Ʒ��� ���̴°��̰�, ť�� ��� ������ ���̴µ� �������»���� ���� ���������� ���̴°��̴�.
  �� ������ �Ѽ� ������ ���� ����� ����Ҷ� ���ϰ� ( ������ 2���� ���� ), ť�� ������ ������ ������ ������ ���Ѱ� ���� ������ ���..!
*/

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
void isTempBWStones();
int isTempReverseStones();
void isReverseStones();
void isClearTempBW();
// �ҷ����� ������ ���� �κ�
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

	arr[4][3] = Black; //������ ��
	arr[3][4] = Black;
	arr[3][3] = White; //��� ��
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

	FILE *fp;//������ �б� ���� ������ ����
	int aa[1000];//������ �迭 ����
	int idx=0;//�迭 �ε����� ����� ����
	int isi=0, isj=0;
	if((fp = fopen("Save.dat","r")) == NULL) {//���� ���½� ���̸� �����޽��� ó��
		printf("No Save Data..!\n");
	}
	while( fscanf(fp, "%d,",&aa[idx]) != EOF) {//������ ���� �ƴ� ��� ��������� �ݺ�,�ε����� �ϳ��� �����ؼ� �־��� ���� �ٽ�, fscanf or scanf ���� &(�ּ�)�� �ٿ���� ��.

		if( aa[idx] == 0){
			arr[isi][isj] = None;
		}else if( aa[idx] == 1){
			arr[isi][isj] = Black;
		}else if( aa[idx] == 2){
			arr[isi][isj] = White;
		}

		printf("(%d, %d)%d\n",isi,isj,aa[idx]);//�Էµ� ���� ���� ���Ĵ�� ����غ�. �Է��� �� �Ǿ����� ���� ������ �״�� �������.
		isj++;
		if(isj==8){
			isj=0;
			isi++;
		}
		if(isi==8){
			isi=0, isj=0;
			idx+=1;//4���� �迭�� �ԷµǹǷ� �͵����� 4��ŭ ����
			fscanf(fp, "%d,",&aa[idx]);
			if(aa[idx] == 1){
				isPlayUser = Black;
			}else{
				isPlayUser =White;
			}
			break;
		}
		idx+=1;//4���� �迭�� �ԷµǹǷ� �͵����� 4��ŭ ����
	}
	fclose(fp);//������ �ݾ���.

	//Sleep(100000);

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
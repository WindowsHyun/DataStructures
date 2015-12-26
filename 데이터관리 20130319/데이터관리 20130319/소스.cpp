#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>

int isDeleteNum=0, isTotalData=0, num, isSearchNum, isZeroNum=0;
int tempHP, tempUnitNum=0, tempindex;

// ����̷�
// ȣ��絧��
// ���Ӿ�Ű���ĵ�����
// �ѹ��� �о��

struct isData { //����ü ����
	char* isName;
	int isX;
	int isY;
	char* isType;
	int isHP;
	int isNumber;
};




struct isData data[100];

void isAddData();
void isDataSearch(int);
void isInsertData(int);
void isPrintAll();
void isDataDelete(int);
void isFindMinHealth();


int main(){
	if(isTotalData == 0 ){
		isAddData();
	}
	while(1){
		printf("1. Search\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. PrintAll\n");
		printf("5. FindMinHealth\n\n");
		printf("Input Num : ");
		scanf("%d", &num);
		system("cls");
		if(num == 1){
			printf("Menu : Search\n\n");
			isZeroNum=0;
			printf("input num : ");
			scanf("%d",&isSearchNum);
			isDataSearch(isSearchNum);
		}else if( num ==2){
			printf("Menu : Insert\n\n");
			int tempNumber;
			isZeroNum=0;
			printf("input Number : ");
			scanf("%d",&tempNumber);
			isInsertData(tempNumber);
		}else if(num ==3){
			printf("Menu : Delete\n\n");
			isZeroNum=0;
			printf("input num : ");
			scanf("%d",&isDeleteNum);
			isDataDelete(isDeleteNum);
		}else if(num ==4){
			printf("Menu : PrintAll\n\n");
			isZeroNum=0;
			isPrintAll();
		}else if(num==5){
			system("cls");
			printf("Menu : FindMinHelath\n\n");
			isZeroNum=0;
			tempHP =data[0].isHP;
			isFindMinHealth();
		}else{
			printf("��ȣ ������ �ʰ��Ͽ����ϴ�..!\n\n");
		}

	}
}

void isAddData(){
	srand((unsigned int)time(NULL));
	for (int i=0; i<5; ++i){
		data[i].isName = "SCV";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Terran";
		data[i].isHP = rand()%255+1;
		data[i].isNumber =  rand()%255+1;
	}
	for (int i=5; i<10; ++i){
		data[i].isName = "Zergling";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Zerg";
		data[i].isHP = rand()%255+1;
		data[i].isNumber =  rand()%500+1;
	}
	for (int i=10; i<15; ++i){
		data[i].isName = "Prove";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Protoss";
		data[i].isHP = rand()%255+1;
		data[i].isNumber =  rand()%1000+1;
	}
	for (int i=15; i<20; ++i){
		data[i].isName = "Drone";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Zerg";
		data[i].isHP = rand()%255+1;
		data[i].isNumber =  rand()%5000+1;
	}

	isTotalData=20;
}

void isDataSearch(int istheSearchNum){
	if(data[isZeroNum].isNumber == istheSearchNum){ // �ڷḦ ã�����
		printf("X : %d, Y: %d\n",data[isZeroNum].isX ,data[isZeroNum].isY );
		printf("----------\n\n");
	}else if(isZeroNum == isTotalData-1){ // �ڷḦ ��ã�� ���
		printf("�˻���� ��ġ�Ǵ� �׸��� �����ϴ�..!\n");
		printf("----------\n\n");
	}else if(data[isZeroNum].isNumber != istheSearchNum){ // �ڷᰡ ������ �ƴҰ�쿡�� �˻��� ��� �Ѵ�.
		++isZeroNum;
		isDataSearch(istheSearchNum);
	}
}

void isInsertData(int istheInsertNum){
	if(data[isZeroNum].isNumber == istheInsertNum){ // �ڷᰡ �������
		printf("�ߺ��� ��ȣ�� �̹� �ֽ��ϴ�..!\n");
		printf("----------\n\n");
	}else if(isZeroNum == isTotalData-1){ // �ڷḦ ��ã�� ���
		char* tempName=(char*)calloc(10,sizeof(char));
		char* tempType=(char*)calloc(10,sizeof(char));
		int tempX= rand()%1000+1, tempY = rand()%1000+1;
		data[isTotalData].isNumber = istheInsertNum;
		printf("input name : ");
		scanf("%s",tempName);
		data[isTotalData].isName = tempName;

		printf("input X : ");
		scanf("%d",&tempX);
		data[isTotalData].isX = tempX;

		printf("input Y : ");
		scanf("%d",&tempY);
		data[isTotalData].isY = tempY;

		printf("input Type : ");
		scanf("%s",tempType);
		data[isTotalData].isType = tempType;
		data[isTotalData].isHP = rand()%255+1;
		isTotalData = isTotalData+1;
		printf("�ڷ� ��� �Ϸ�..!\n");
		printf("----------\n\n");
	}else if(data[isZeroNum].isNumber != istheInsertNum){ // �ڷᰡ ������ �ƴҰ�쿡�� �˻��� ��� �Ѵ�.
		++isZeroNum;
		isInsertData(istheInsertNum);
	}
}

void isDataDelete(int isDeleteNum){
	if(data[isZeroNum].isNumber == isDeleteNum){ // �ڷᰡ �������
		data[isZeroNum].isName = data[isTotalData-1].isName;
		data[isZeroNum].isX = data[isTotalData-1].isX;
		data[isZeroNum].isY = data[isTotalData-1].isY;
		data[isZeroNum].isType = data[isTotalData-1].isType;
		data[isZeroNum].isHP =data[isTotalData-1].isHP;
		data[isZeroNum].isNumber = data[isTotalData-1].isNumber;
		isTotalData = isTotalData -1;
		printf("�����Ϸ�..!\n");
		printf("----------\n\n");
	}else if(isZeroNum == isTotalData-1){ // �ڷḦ ��ã�� ���
		printf("������ �ڷᰡ �����ϴ�..!\n");
		printf("----------\n\n");
	}else if(data[isZeroNum].isNumber != isDeleteNum){ // �ڷᰡ ������ �ƴҰ�쿡�� �˻��� ��� �Ѵ�.
		++isZeroNum;
		isDataDelete(isDeleteNum);
	}
}


void isPrintAll(){
	if(isZeroNum != isTotalData-1){ // �ڷḦ ã�����
		printf("Unit Number : %d\n",data[isZeroNum].isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", data[isZeroNum].isName,data[isZeroNum].isX, data[isZeroNum].isY, data[isZeroNum].isType, data[isZeroNum].isHP);
		++isZeroNum;
		isPrintAll();
	}else{
		printf("----------------------------\n\n");
	}
}

void isFindMinHealth(){
	if( tempHP >= data[isZeroNum].isHP){
		tempHP = data[isZeroNum].isHP;
		tempindex = isZeroNum;
	}
	if(isZeroNum == isTotalData-1){ // �ڷḦ ��ã�� ���
		printf("Unit Number : %d\n",data[tempindex].isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", data[tempindex].isName,data[tempindex].isX, data[tempindex].isY, data[tempindex].isType, data[tempindex].isHP);
		printf("----------------------------\n\n");
	}else{
		++isZeroNum;
		isFindMinHealth();
	}
}
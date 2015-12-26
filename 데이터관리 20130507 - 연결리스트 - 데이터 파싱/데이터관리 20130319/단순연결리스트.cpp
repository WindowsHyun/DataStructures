#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int isDeleteNum=0, num, isSearchNum, isZeroNum=0;
int tempHP, tempUnitNum=0, tempindex;

// 재미이론
// 호모루덴스
// 게임아키텍쳐디자인
// 한번씩 읽어보기

typedef struct isData { //구조체 선언
	char* isName;
	int isX;
	int isY;
	char* isType;
	int isHP;
	int isNumber;
	struct isData* next;
}isData;

isData *head;
isData *tail;

void init(void){
	head=(isData*)malloc(sizeof(isData));
	tail=(isData*)malloc(sizeof(isData));
	head->next=tail;
	tail->next=tail;
}

void isAddData();
void isPrintAll();
void isDataSearch(int);
void isInsertData(int);
void isDataDelete(int);
void isFindMinHealth();

int main(){
	init();
	isAddData();
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
			isData *t;
			t=head->next;
			tempHP =t->isHP;
			isFindMinHealth();
		}else{
			printf("번호 범위를 초과하였습니다..!\n\n");
		}

	}
}

void isAddData(){
	srand((unsigned int)time(NULL));
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "SCV";
		t->isX= rand()%1000+1;
		t->isY= rand()%1000+1;
		t->isType = "Terran";
		t->isHP = rand()%255+1;
		t->isNumber = rand()%255+1;
		t->next=head->next;
		head->next=t;
	}
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "Zergling";
		t->isX= rand()%1000+1;
		t->isY= rand()%1000+1;
		t->isType = "Zerg";
		t->isHP = rand()%255+1;
		t->isNumber = rand()%500+1;
		t->next=head->next;
		head->next=t;
	}
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "Prove";
		t->isX= rand()%1000+1;
		t->isY= rand()%1000+1;
		t->isType = "Protoss";
		t->isHP = rand()%255+1;
		t->isNumber = rand()%1000+1;
		t->next=head->next;
		head->next=t;
	}
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "Drone";
		t->isX= rand()%1000+1;
		t->isY= rand()%1000+1;
		t->isType = "Zerg";
		t->isHP = rand()%255+1;
		t->isNumber = rand()%5000+1;
		t->next=head->next;
		head->next=t;
	}
}

void isDataSearch(int istheSearchNum){
	isData *t;
	t=head->next;
	while (t != tail){
		if(t->isNumber == istheSearchNum){
			printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", t->isName,t->isX, t->isY, t->isType, t->isHP);
			printf("----------------------------\n\n");
			break;
		}
		t=t->next;
	}
	if( t == tail){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
}

void isInsertData(int istheInsertNum){
	char* tempName=(char*)calloc(10,sizeof(char));
	char* tempType=(char*)calloc(10,sizeof(char));
	isData *t;
	t=head->next;
	while (t != tail){
		if(t->isNumber == istheInsertNum){
			printf("Use Number..!\n");
			printf("----------------------------\n\n");
			break;
		}
		t=t->next;
	}
	if( t == tail){
		isData *newdata;
		newdata=(isData*)malloc(sizeof(isData));
		int tempX= rand()%1000+1, tempY = rand()%1000+1;
		newdata->isNumber = istheInsertNum;
		printf("input name : ");
		scanf("%s",tempName);
		newdata->isName = tempName;

		printf("input X : ");
		scanf("%d",&tempX);
		newdata->isX = tempX;

		printf("input Y : ");
		scanf("%d",&tempY);
		newdata->isY = tempY;

		printf("input Type : ");
		scanf("%s",tempType);
		newdata->isType = tempType;
		newdata->isHP = rand()%255+1;

		newdata->next=head->next; //설명이 필요함..!
		head->next=newdata; // 설명이 필요함..!
	}
}

void isDataDelete(int isDeleteNum){
	isData *p;
	isData *t;
	isData *s;
	p=head->next;
	s=head;
	while (p != tail){
		if(p->isNumber == isDeleteNum){
			t=p;
			p=p->next;
			s->next=p;
			free(t);
			printf("Data Delete..!\n");
			printf("----------------------------\n\n");
			break;
		}
		s=s->next;
		p=s->next;
	}
	if( p == tail){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
}


void isPrintAll(){
	isData *t;
	t=head->next;
	if (head->next == tail){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
	while (t != tail){
		printf("Unit Number : %d\n",t->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", t->isName,t->isX, t->isY, t->isType, t->isHP);
		t=t->next;
	}
	printf("----------------------------\n\n");
}

void isFindMinHealth(){
	isData *t;
	isData *p;
	t=head->next;
	while (t != tail){
		if( tempHP >= t->isHP ){
			tempHP = t->isHP;
			p=t;
		}

		t=t->next;
	}
	if( t == tail ){
		printf("Unit Number : %d\n",p->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", p->isName,p->isX, p->isY, p->isType, p->isHP);
		printf("----------------------------\n\n");
	}
}
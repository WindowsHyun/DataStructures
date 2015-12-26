#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int isDeleteNum=0, num, isSearchNum, isZeroNum=0, isTempTheEnd=0, isInsertNum=0, isTestNum=0,isTestNum2=0;
double isShortDistance=0;
double isStartTimet =0, isEndTimet =0;
double isStartTime =0, isEndTime =0;
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

void init(void){
	head=(isData*)malloc(sizeof(isData));
	head->next=head;
}

void isAddData();
void isPrintAll();
void isDataSearch(int);
void isInsertData(int);
void isDataDelete(int);
void isFindMinHealth();
void isFindTarget(int);

int main(){
	init();
	isStartTimet = GetTickCount();
	for(int i=0; i<1299999; ++i){
	//for(int i=0; i<500000; ++i){
	isAddData();
	}
	isEndTimet = GetTickCount();
	while(1){
		printf("Time : %f초\n", (isEndTimet-isStartTimet)/1000);
		printf("1. Search\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. PrintAll\n");
		printf("5. FindMinHealth\n");
		printf("6. FindTarget\n\n");
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
			isTestNum=0,isTestNum2=0;
			isData *t;
			t=head->next;
			tempHP =t->isHP;
			isStartTime = GetTickCount();
			isFindMinHealth();
		}else if(num==6){
			printf("Menu : FindTarget\n\n");
		//	for(int i=1; i<1200000; ++i){
			isTempTheEnd=0;
			isTestNum=0,isTestNum2=0;
			printf("input num : ");
			scanf("%d",&isSearchNum);
			isStartTime = GetTickCount();
			isFindTarget(isSearchNum);
			//}
		}else{
			printf("번호 범위를 초과하였습니다..!\n\n");
		}

	}
}

void isAddData(){
	//srand((unsigned int)time(NULL));
	srand(isInsertNum);
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "SCV";
		t->isX= rand()%3000000+1;
		t->isY= rand()%3000000+1;
		t->isType = "Terran";
		t->isHP = rand()%3000000+1;
		t->isNumber = isInsertNum;
		t->next=head->next;
		head->next=t;
		isInsertNum+=1;
	}
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "Zergling";
		t->isX= rand()%3000000+1;
		t->isY= rand()%3000000+1;
		t->isType = "Zerg";
		t->isHP = rand()%3000000+1;
		t->isNumber = isInsertNum;
		t->next=head->next;
		head->next=t;
		isInsertNum+=1;
	}
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "Prove";
		t->isX= rand()%3000000+1;
		t->isY= rand()%3000000+1;
		t->isType = "Protoss";
		t->isHP = rand()%3000000+1;
		t->isNumber = isInsertNum;
		t->next=head->next;
		head->next=t;
		isInsertNum+=1;
	}
	for (int i=0; i<5; ++i){
		isData *t;
		t=(isData*)malloc(sizeof(isData));
		t->isName= "Drone";
		t->isX= rand()%3000000+1;
		t->isY= rand()%3000000+1;
		t->isType = "Zerg";
		t->isHP = rand()%3000000+1;
		t->isNumber = isInsertNum;
		t->next=head->next;
		head->next=t;
		isInsertNum+=1;
	}
}

void isDataSearch(int istheSearchNum){
	isData *t;
	isData *theEnd;
	t=head->next;
	theEnd=head;
	while (t != theEnd){
		if(t->isNumber == istheSearchNum){
			printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", t->isName,t->isX, t->isY, t->isType, t->isHP);
			printf("----------------------------\n\n");
			break;
		}
		t=t->next;
	}
	if( t == theEnd){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
}

void isInsertData(int istheInsertNum){
	char* tempName=(char*)calloc(10,sizeof(char));
	char* tempType=(char*)calloc(10,sizeof(char));
	isData *t;
	isData *theEnd;
	t=head->next;
	theEnd=head;
	while (t != theEnd){
		if(t->isNumber == istheInsertNum){
			printf("Use Number..!\n");
			printf("----------------------------\n\n");
			break;
		}
		t=t->next;
	}
	if( t == theEnd){
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
	isData *theEnd;
	isData *s;
	p=head->next;
	s=head;
	theEnd=head;
	while (p != theEnd){
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
	if( p == theEnd){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
}

void isPrintAll(){
	isData *t;
	isData *theEnd;
	t=head->next;
	theEnd=head;
	if (head->next == theEnd){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
	while (t != theEnd){
		printf("Unit Number : %d\n",t->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", t->isName,t->isX, t->isY, t->isType, t->isHP);
		t=t->next;
	}
	printf("----------------------------\n\n");
}

void isFindMinHealth(){
	isData *t;
	isData *p;
	isData *theEnd;
	t=head->next;
	theEnd=head;
	while (t != theEnd){
		if( tempHP >= t->isHP ){
			tempHP = t->isHP;
			p=t;
		isTestNum2++;
				}
				isTestNum+=1;
		t=t->next;
	}
	if( t == theEnd ){
		isEndTime = GetTickCount();
		printf("Unit Number : %d\n",p->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", p->isName,p->isX, p->isY, p->isType, p->isHP);
		printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
		printf("Time : %f초\n", (isEndTime-isStartTime)/1000);
		printf("----------------------------\n\n");
	}
}

void isFindTarget(int isSearchNum){
	isData *t;
	isData *theEnd;
	t=head->next;
	theEnd=head;
	while (t != theEnd){
		if(t->isNumber == isSearchNum){
			isData *temp;
			temp=head->next;
			if(t->isY == temp->isY && t->isX == temp->isX){
				temp=temp->next;
			}
			isShortDistance = (abs(t->isY-temp->isY)*abs(t->isY-temp->isY))+(abs(t->isX-temp->isX)*abs(t->isX-temp->isX));

			isData *search;
			isData *isShortSearched;
			search =head->next;
			isShortSearched=head;
			while (search != theEnd){
				// 구해야지
				if(t == search){
					search=search->next;
				}

				if(isShortDistance >= (abs(t->isY-search->isY)*abs(t->isY-search->isY))+(abs(t->isX-search->isX)*abs(t->isX-search->isX))){
					isShortDistance = (abs(t->isY-search->isY)*abs(t->isY-search->isY))+(abs(t->isX-search->isX)*abs(t->isX-search->isX));
					isShortSearched = search;
					isTestNum2++;
				}
				isTestNum+=1;
				search=search->next;
			}

			if(search == head){
				isEndTime = GetTickCount();
				printf("1. Search\n");
				printf("Number : %d\n", t->isNumber);
				printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", t->isName,t->isX, t->isY, t->isType, t->isHP);
				printf("2. Result\n");
				printf("Number : %d\n", isShortSearched->isNumber);
			printf("Name : %s, X : %d Y : %d, Type : %s, HP : %d\n", isShortSearched->isName,isShortSearched->isX, isShortSearched->isY, isShortSearched->isType, isShortSearched->isHP);
			printf("3. Distance\n");
			printf("└ %f\n",sqrt(isShortDistance));
			printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
			printf("Time : %f초\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
			isTempTheEnd=1;
			}
		}
		t=t->next;
	}
	if( t == theEnd && isTempTheEnd ==0){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
}
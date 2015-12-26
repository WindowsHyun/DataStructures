#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int isDeleteNum=0, num, isSearchNum, isZeroNum=0, isTempTheEnd=0;
double isShortDistance=0;
double isStartTimet =0, isEndTimet =0;
double isStartTime=0, isEndTime=0;
int isTestNum=0,isTestNum2=0;
int tempHP, tempUnitNum=0, tempindex, isInsertNum=0;
int isPrintAllpn=0;
// ����̷�
// ȣ��絧��
// ���Ӿ�Ű���ĵ�����
// �ѹ��� �о��

typedef struct isData { //����ü ����
	char* isName;
	int isX;
	int isY;
	char* isType;
	int isHP;
	int isNumber;
	int isAttack;
	int isDefence;
	struct isData* next;
	struct isData* prev; // ����
}isData;

isData *head, * tail;


void init(void){
	head=(isData*)malloc(sizeof(isData));
	tail=(isData*)malloc(sizeof(isData));
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
}

void isAddData();
void isPrintAll();
void isDataSearch(int);
void isInsertData(int);
void isDataDelete(int);
void isFindMinHealth();
void isFindTarget(int);
void isSortByName();
void isSwap(isData, isData, isData, isData);

int main(){
	init();
	isStartTimet = GetTickCount();
	isAddData();
	isEndTimet = GetTickCount();

	while(1){
		printf("Time : %f��\n", (isEndTimet-isStartTimet)/1000);
		printf("1. Search\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. PrintAll\n");
		printf("5. FindMinHealth\n");
		printf("6. FindTarget\n");
		printf("7. SortByName\n\n");
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
			printf("1. Next PrintAll\n");
			printf("2. Prev PrintAll\n\n");
			printf("input num : ");
			scanf("%d", &isPrintAllpn);
			if( isPrintAllpn == 1 || isPrintAllpn == 2){
				isPrintAll();
			}else{
				printf("Not Input..!\n\n");
			}
		}else if(num==5){
			system("cls");
			printf("Menu : FindMinHelath\n\n");
			isZeroNum=0;
			isData *t;
			t=head->next;
			tempHP =t->isHP;
			isTestNum=0,isTestNum2=0;
			isStartTime = GetTickCount();
			isFindMinHealth();
		}else if(num==6){
			printf("Menu : FindTarget\n\n");
			isTempTheEnd=0;
			printf("input num : ");
			scanf("%d",&isSearchNum);
			isTestNum=0,isTestNum2=0;
			isStartTime = GetTickCount();
			isFindTarget(isSearchNum);
		}else if(num==7){
			printf("Menu : SortByName\n\n");
			isTempTheEnd=0;
			isTestNum=0,isTestNum2=0;
			isStartTime = GetTickCount();
			isSortByName();
		}else{
			printf("��ȣ ������ �ʰ��Ͽ����ϴ�..!\n\n");
		}

	}
}

void isSwap(isData *p1, isData *start, isData *p2, isData *end){
	isData *temp, *temp2;
	/*if(p2 == start){
	printf("1��------------------\n");
	temp=end->next;
	p1->next = end;
	end->next = start;
	start->next =temp; 
	}else if(end->next == tail){
	printf("2��------------------\n");
	temp=end->next;
	end->next=start->next;
	end->next->prev=end;
	start->next=temp;
	start->next->prev=start;
	p2->next=start;
	p1->next=end;

	}else if(p1 == head){
	printf("3��------------------\n");
	temp=end->next;
	end->next=start->next;
	start->next=temp;
	p2->next=start;
	p1->next=end;


	}else{*/


	if(p2 == start){
		//printf("1��\n");
		temp=end->next;
		p1->next = end;
		end->prev=p1;

		end->next = start;
		start->prev=end;

		start->next =temp; 
		start->next->prev=start;
	}else{
		//printf("2��\n");
		temp=end->next;

		end->next=start->next;
		end->next->prev=end;

		start->next=temp;
		start->next->prev=start;

		p1->next=end;
		end->prev=p1;

		p2->next=start;
		start->prev=p2;

	}
}

void isSortByName(){
	isData *start, *end, *write, *p1, *p2;
	int comp,count=0;
isReStart:
	//printf("�ʱ�ȭ\n");
	start = head->next;
	end=start->next;

	while(1){
		if(start->next == tail){
			break;
		}else{
			while(1){
				if( end == tail ){
					end=start->next->next;
					break;
				}else{
					//printf("%s <-> %s\n", start->isName, end->isName);
					//Sleep(1000);
					comp=strcmp(start->isName, end->isName);
					if(comp==1) {
						//printf("%s -> %s\n\n", start->isName, end->isName);
						p1=start->prev, p2=end->prev;
						isSwap(start->prev,start,end->prev,end);
						start=p1->next;
						end=p2->next;
						/*write=head->next;
						while(write !=tail){
						printf("%s\n",write->isName);
						Sleep(1000);
						write=write->next;
						}
						printf("-----------------------\n");
						Sleep(1000);
						write=tail->prev;
						while(write !=head){
						printf("%s\n",write->isName);
						Sleep(1000);
						write=write->prev;
						}
						printf("-----------------------\n\n");
						Sleep(1000);*/
					}
					end=end->next;
				}
			}
			start = start->next;
		}
	}
	++count;
	if(count ==1){
		goto isReStart;
	}
	isEndTime = GetTickCount();
	printf("Time : %f��\n", (isEndTime-isStartTime)/1000);
	printf("----------------------------\n\n");
}

void isAddData(){
	srand((unsigned int)time(NULL));
	int hp, attack, defence, isx, isy;
	FILE *fp;
	if((fp = fopen("StarDic.txt","r")) == NULL) {
		printf("No Save Data..!\n");
	}

	char* type=(char*)calloc(10,sizeof(char));
	char* name=(char*)calloc(10,sizeof(char));

	//isData** temp = (isData**)malloc(sizeof(isData*)*20000000); 2õ�� ������ ��ŭ ����� �����.

	while( fscanf(fp, "%s %s %d %d %d %d %d ", type, name, &hp, &attack, &defence, &isx, &isy ) != EOF) {
		isData *t;
		t=(isData*)malloc(sizeof(isData));

		char* temptype=(char*)calloc(10,sizeof(char));
		char* tempname=(char*)calloc(10,sizeof(char));
		strcpy(temptype, type);
		strcpy(tempname, name);

		t->isName=tempname;
		t->isX= isx;
		t->isY= isy;
		t->isType = temptype;
		t->isAttack = attack;
		t->isDefence = defence;
		t->isHP = hp;
		t->isNumber = isInsertNum;

		if(isInsertNum == 0){
			t->next = tail;
			t->prev = head;
			head->next=t;
			tail->prev =t;

		}else{
			t->next = tail;
			t->prev = tail->prev;
			tail->prev->next = t;
			tail->prev = t;
		}
		isInsertNum+=1;

		if(isInsertNum >= 1000000){
			break;
		}
	}
	fclose(fp);

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

		newdata->next = tail;
		newdata->prev = tail->prev;
		tail->prev->next = newdata;
		tail->prev = newdata;

	}
}

void isDataDelete(int isDeleteNum){
	isData *p;
	isData *t;
	p=head->next;
	while (p != tail){
		if(p->isNumber == isDeleteNum){
			t=p;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(t);

			printf("Data Delete..!\n");
			printf("----------------------------\n\n");
			break;
		}
		p=p->next;
	}
	if( p == tail){
		printf("Not Data..!\n");
		printf("----------------------------\n\n");
	}
}

void isPrintAll(){
	if( isPrintAllpn == 1){
		isData *t;
		t=head->next;
		if (head->next == tail){
			printf("Not Data..!\n");
			printf("----------------------------\n\n");
		}
		while (t != tail){
			printf("Unit Number : %d\n",t->isNumber);
			printf("type : %s, name : %s, hp: %d, attack : %d, defence : %d, isx : %d, isy : %d\n", t->isType, t->isName, t->isHP, t->isAttack, t->isDefence, t->isX, t->isY);
			t=t->next;
		}
		printf("----------------------------\n\n");

	}else{
		isData *t;
		t=tail->prev;
		if (head->next == head){
			printf("Not Data..!\n");
			printf("----------------------------\n\n");
		}
		while (t != head){
			printf("Unit Number : %d\n",t->isNumber);
			printf("type : %s, name : %s, hp: %d, attack : %d, defence : %d, isx : %d, isy : %d\n", t->isType, t->isName, t->isHP, t->isAttack, t->isDefence, t->isX, t->isY);
			t=t->prev;
		}
		printf("----------------------------\n\n");

	}
}

void isFindMinHealth(){
	isData *t;
	isData *p;
	isData *theEnd;
	t=head->next;
	theEnd=tail;
	while (t != theEnd){
		if( tempHP >= t->isHP ){
			tempHP = t->isHP;
			p=t;
			isTestNum2++;
		}
		isTestNum++;
		t=t->next;
	}
	if( t == theEnd ){
		isEndTime = GetTickCount();
		printf("Unit Number : %d\n",p->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", p->isName,p->isX, p->isY, p->isType, p->isAttack, p->isDefence, p->isHP);
		printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
		printf("Time : %f��\n", (isEndTime-isStartTime)/1000);
		printf("----------------------------\n\n");
	}
}

void isFindTarget(int isSearchNum){
	isData *t;
	isData *theEnd;
	t=head->next;
	theEnd=tail;
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
				// ���ؾ���
				if(t == search){
					search=search->next;
				}

				if(isShortDistance >= (abs(t->isY-search->isY)*abs(t->isY-search->isY))+(abs(t->isX-search->isX)*abs(t->isX-search->isX))){
					isShortDistance = (abs(t->isY-search->isY)*abs(t->isY-search->isY))+(abs(t->isX-search->isX)*abs(t->isX-search->isX));
					isShortSearched = search;
					isTestNum2++;
				}
				isTestNum++;
				search=search->next;
			}

			if(search == tail){
				isEndTime = GetTickCount();
				printf("1. Search\n");
				printf("Number : %d\n", t->isNumber);
				printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", t->isName,t->isX, t->isY, t->isType, t->isAttack, t->isDefence, t->isHP);
				printf("2. Result\n");
				printf("Number : %d\n", isShortSearched->isNumber);
				printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", isShortSearched->isName,isShortSearched->isX, isShortSearched->isY, isShortSearched->isType, isShortSearched->isAttack, isShortSearched->isDefence, isShortSearched->isHP);
				printf("3. Distance\n");
				printf("�� %f\n",sqrt(isShortDistance));
				printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
				printf("Time : %f��\n", (isEndTime-isStartTime)/1000);
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

/*
isData *i, *j, *temp;
isData *test;
test=head->next;
char tempName[16];
char tempNewName[16];
for( i = head; i->next != head ; i = i->next ){
for( j = i->next ; j != head ; j = j->next ){
if( i != head){
strcpy(tempName,i->isName);
strcmp(tempName,i->isName);

strcpy(tempNewName,j->isName);
strcmp(tempNewName,j->isName);

if(tempName[0] < tempNewName[0]){
printf("%s -> %s\n", i->isName, j->isName);
temp =i;
i=j;
i->next = j->next;
j=temp;
j->next=temp->next;
test=head->next;
while(test != head){
printf("%s\n",test->isName);
test=test->next;
}
printf("\n");
}

}
}		
}*/

/*isData *main;
isData *next;
isData *temp;
main = head->next;
next = main->next;
while(next != head){
strcpy(tempName,main->isName);
strcmp(tempName,main->isName);

strcpy(tempNewName,next->isName);
strcmp(tempNewName,next->isName);

if(tempName[0] < tempNewName[0]){
isSwap(&main, &next);
}
main=main->next;
next=main->next;
}*/

/*
void isSortByName(){
isData* p1, *p2, *p3, *start, *end, *write;
int comp,count=0;
isReStart:
printf("�ʱ�ȭ\n");
p1=head;
start = head->next;

p2=head->next;
end=p2->next;


while(1){
if(start->next == tail){
break;
}else{
while(1){
if( end == tail ){
p2=start->next;
end=p2->next;
break;
}else{
printf("%s <-> %s\n", start->isName, end->isName);
Sleep(1000);
comp=strcmp(start->isName, end->isName);
if(comp==1) {
printf("%s -> %s\n\n", start->isName, end->isName);

isSwap(p1,start,p2,end);
start=p1->next;
p2=start->next;
end=p2->next;

write=head->next;
while(write !=tail){
printf("%s\n",write->isName);
Sleep(1000);
write=write->next;
}
printf("-----------------------\n");
Sleep(1000);
write=tail->prev;
while(write !=head){
printf("%s\n",write->isName);
Sleep(1000);
write=write->prev;
}
printf("-----------------------\n\n");
Sleep(1000);
}
p2=p2->next;
end=end->next;
}
}
p1=p1->next;
start = start->next;
}
}
++count;
if(count ==1){
goto isReStart;
}
isEndTime = GetTickCount();
printf("Time : %f��\n", (isEndTime-isStartTime)/1000);
printf("----------------------------\n\n");
}
*/
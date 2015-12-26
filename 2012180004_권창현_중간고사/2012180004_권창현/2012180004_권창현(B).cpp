#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <String.h>

int isGetX, isGetY, isGetZ, isDistanceData=0;
int isNum=0, isDataww=0,isNAge=0;
int isNewData[12];

typedef struct isData{
	char* isName;
	int isAge;
	char* isID;
	char* isSex;
	int isX;
	int isY;
	int isZ;
	struct isData* next;
}isData;


isData *isSearchPos;
isData *isPreSearchPos;
isData *isNextSearchPos;

isData *isDeletePos;
isData *isDeletePrevPos;
isData *isPrevPos;
isData *isMainData;
isData *isNextData;
isData *head;

void init(void){
	head = (isData*)malloc(sizeof(isData));
	head->next=head;

}

void isAddData();
void isPrintAll();
void DeleteByPos_R(int, int, int);
void SortByID();
void DeleteByAge_List(int);

void main(){
	init();
	isAddData();
	while(1){

		printf("1. PrintAll\n");
		printf("2. DeleteByPos\n");
		printf("3. SortByID\n");
		printf("4. DeleteByAge_List\n\n");
		printf("Input Num : ");
		scanf("%d",&isNum );

		if(isNum == 1){
			system("cls");
			printf("Menu : PrintAll\n\n");
			isPrintAll();
		}else if(isNum == 2){
			system("cls");
			printf("Menu : DeleteByPos\n\n");
			printf("X : ");
			scanf("%d",&isGetX);
			printf("Y : ");
			scanf("%d",&isGetY);
			printf("Z : ");
			scanf("%d",&isGetZ);
			isDeletePrevPos=head;
			isDeletePos=isDeletePrevPos->next;
			isPrevPos=head;
			isDistanceData = (abs(isGetX-isDeletePos->isX)*abs(isGetX-isDeletePos->isX))+(abs(isGetY-isDeletePos->isY)*abs(isGetY-isDeletePos->isY))+(abs(isGetZ-isDeletePos->isZ)*abs(isGetZ-isDeletePos->isZ));
			DeleteByPos_R(isGetX,isGetY,isGetZ);
		}else if (isNum ==3){
			system("cls");
			printf("Menu : SortByID\n\n");
			SortByID();
		}else if(isNum ==4){
			system("cls");
			printf("Menu : DeleteByAge_List\n\n");
			printf("Input Age : ");
			scanf("%d",&isNAge);
			isPreSearchPos=head;
			isSearchPos=head->next;
			DeleteByAge_List(isNAge);
		}else{
			printf("Re Input..!\n");
			printf("-------------------------------\n\n");
		}
	}
}

void DeleteByAge_List(int isNAge){
	if(isSearchPos == head){

	}else{

		if(isSearchPos->isAge == isNAge){
			isNextSearchPos = isSearchPos->next;

			isPreSearchPos->next=isNextSearchPos->next;

			free(isSearchPos);
		}

		isPreSearchPos=isPreSearchPos->next;
		isSearchPos=isPreSearchPos->next;
		DeleteByAge_List(isNAge);
	}
}

void SortByID(){
	isData *ms;
	isData *nns;
	isData *swap;
	isData *ns;
	swap=head;
	ms=head->next;
	ns=ms->next;
	nns=ns->next;

	char tempName[12];
	char tempNewName[12];

	while(ms != head){
		strcpy(tempName,ms->isID);
		strcmp(tempName,ms->isID);

		strcpy(tempNewName,ns->isID);
		strcmp(tempNewName,ns->isID);

		if(tempNewName[0] <= tempName[0]){

			swap = ms->next;
				ms->next=nns;
				ns->next=swap;

		}
		ms=ms->next;
		ns=ms->next;
		nns=ns->next;
	}
}

void DeleteByPos_R(int isDGetX, int isDGetY, int isDGetZ){
	if(isDeletePos == head){
		printf("Delete Data : %s\n",isMainData->isName);
		if( isMainData->next == head){
			isPrevPos->next=head;
			free(isMainData);
		}else{
			isPrevPos->next=isNextData->next;
			free(isMainData);
		}
		printf("-------------------------------\n\n");
	}else{
		if(isDistanceData >= (abs(isDGetX-isDeletePos->isX)*abs(isDGetX-isDeletePos->isX))+(abs(isDGetY-isDeletePos->isY)*abs(isDGetY-isDeletePos->isY))+(abs(isDGetZ-isDeletePos->isZ)*abs(isDGetZ-isDeletePos->isZ))){
			isDistanceData = (abs(isDGetX-isDeletePos->isX)*abs(isDGetX-isDeletePos->isX))+(abs(isDGetY-isDeletePos->isY)*abs(isDGetY-isDeletePos->isY))+(abs(isDGetZ-isDeletePos->isZ)*abs(isDGetZ-isDeletePos->isZ));
			isPrevPos = isDeletePrevPos;
			isMainData=isDeletePrevPos->next;
			isNextData=isMainData->next;
		}

		isDeletePrevPos=isDeletePrevPos->next;
		isDeletePos=isDeletePrevPos->next;
		DeleteByPos_R(isGetX,isGetY,isGetZ);
	}
}

void isPrintAll(){
	isData *t;
	t=head->next;
	while(t != head){
		printf("Name : %s, Age : %d, ID : %s, Sex : %s, Position : (%d, %d, %d)\n",t->isName, t->isAge, t->isID, t->isSex, t->isX, t->isY, t->isZ);
		t=t->next;
	}
	if(t == head){
		printf("-------------------------------\n\n");
	}
}

void isAddData(){
	isData *t;
	t = (isData*)malloc(sizeof(isData));
	t->isName = "Lee JY";
	t->isAge = 16;
	t->isID = "jylee";
	t->isSex = "male";
	t->isX = 4;
	t->isY = 9;
	t->isZ = 30;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Yoon JH";
	t->isAge = 55;
	t->isID = "wulong";
	t->isSex = "male";
	t->isX = 7;
	t->isY = 13;
	t->isZ = 0;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Song IH";
	t->isAge = 18;
	t->isID = "ihsong";
	t->isSex = "female";
	t->isX = 1;
	t->isY = 36;
	t->isZ = 29;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Chang JW";
	t->isAge = 24;
	t->isID = "duribaba";
	t->isSex = "male";
	t->isX = 41;
	t->isY = 94;
	t->isZ = 0;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Lee HG";
	t->isAge = 44;
	t->isID = "hgl";
	t->isSex = "male";
	t->isX = 7;
	t->isY = 13;
	t->isZ = 28;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Lee YH";
	t->isAge = 42;
	t->isID = "louis";
	t->isSex = "male";
	t->isX = 5;
	t->isY = 19;
	t->isZ = 32;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Kim JK";
	t->isAge = 73;
	t->isID = "doublepar";
	t->isSex = "male";
	t->isX = 16;
	t->isY = 27;
	t->isZ = 18;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Oh HS";
	t->isAge = 37;
	t->isID = "ken";
	t->isSex = "male";
	t->isX = 42;
	t->isY = 62;
	t->isZ = 28;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Lim CJ";
	t->isAge = 29;
	t->isID = "scjlim";
	t->isSex = "male";
	t->isX = 52;
	t->isY = 48;
	t->isZ = 12;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Kim YS";
	t->isAge = 52;
	t->isID = "yskim";
	t->isSex = "male";
	t->isX = 7;
	t->isY = 13;
	t->isZ = 33;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Lee DH";
	t->isAge = 46;
	t->isID = "dustin";
	t->isSex = "male";
	t->isX = 5;
	t->isY = 7;
	t->isZ = 23;
	t->next=head->next;
	head->next=t;

	t = (isData*)malloc(sizeof(isData));
	t->isName = "Jung NH";
	t->isAge = 42;
	t->isID = "nhjung";
	t->isSex = "male";
	t->isX = 3;
	t->isY = 56;
	t->isZ = 21;
	t->next=head->next;
	head->next=t;

}
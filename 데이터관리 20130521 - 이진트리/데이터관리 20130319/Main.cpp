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
int isPrintAllpn=0, isSearrchEnd=0;
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
	int isAttack;
	int isDefence;
	struct isData* left;
	struct isData* right;

}Tree;

Tree* root = NULL; 
Tree* find = NULL;


void isAddData();
Tree* insertNode(Tree*, char , int , int , char , int , int , int , int );
void isPrintAll(Tree*);
void isSortByName(Tree*);
Tree* isDataSearch(Tree*, int);
Tree* isDataNumSearch(Tree*, int);
void isInsertData(int);
void isDataDelete(Tree*, int);
void isFindMinHealth(Tree*);
void isFindTarget(Tree*, Tree*, int);


int main(){
	isStartTimet = GetTickCount();
	isAddData();
	isEndTimet = GetTickCount();

	while(1){
		printf("Time : %f초\n", (isEndTimet-isStartTimet)/1000);
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
			isStartTime = GetTickCount();
			isTestNum=0;
			find = isDataSearch(root,isSearchNum);
			if(find == NULL){
				printf("NoData..!");
			}
			isEndTime = GetTickCount();
			printf("\n\nTime : %f초\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
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
			isStartTime = GetTickCount();
			isDataDelete(root,isDeleteNum);
			isEndTime = GetTickCount();
			printf("\n\nTime : %f초\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
		}else if(num ==4){
			printf("Menu : PrintAll\n\n");
			isStartTime = GetTickCount();
			isPrintAll(root);
			isEndTime = GetTickCount();
			printf("\n\nTime : %f초\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
		}else if(num==5){
			system("cls");
			printf("Menu : FindMinHelath\n\n");
			isZeroNum=0;
			tempHP = root->isHP;
			isTestNum=0,isTestNum2=0;
			isStartTime = GetTickCount();
			isFindMinHealth(root);
			isEndTime = GetTickCount();
			printf("Time : %f초\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
		}else if(num==6){
			printf("Menu : FindTarget\n\n");
			isTempTheEnd=0;
			printf("input num : ");
			scanf("%d",&isSearchNum);
			isTestNum=0,isTestNum2=0;

			Tree* isSearchData;
			isSearrchEnd=0;
			isSearchData = isDataNumSearch(root , isSearchNum);
			if( isSearrchEnd == 0 ){
				printf("NoData..!\n");
			}else{
				isStartTime = GetTickCount();
				isFindTarget(isSearchData, root,isSearchNum);
				isEndTime = GetTickCount();
				printf("Time : %f초\n", (isEndTime-isStartTime)/1000);
				printf("----------------------------\n\n");
			}
		}else if(num==7){
			printf("Menu : SortByName\n\n");
			isTempTheEnd=0;
			isTestNum=0,isTestNum2=0;
			isStartTime = GetTickCount();
			isSortByName(root);
			isEndTime = GetTickCount();
			printf("\n\nTime : %f초\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
		}else{
			printf("번호 범위를 초과하였습니다..!\n\n");
		}

	}
}

void isSortByName(Tree* p){
	if(p){
		isPrintAll(p->left);
		printf("Name : %s, X : %d, Y : %d, Type : %s, Attack : %d, Defence : %d, HP : %d, Number : %d\n", p->isName,p->isX, p->isY, p->isType, p->isAttack, p->isDefence, p->isHP, p->isNumber);
		isPrintAll(p->right);
	}
}

Tree* insertNode(Tree* p, char* tmpname, int isx, int isy, char* tmptype, int attack, int defence, int hp, int isInsertNum){
	Tree* newTree;

	char* temptype=(char*)calloc(10,sizeof(char));
	char* tempname=(char*)calloc(10,sizeof(char));
	strcpy(temptype, tmptype);
	strcpy(tempname, tmpname);


	if( p == NULL )
	{
		newTree = (Tree*)malloc(sizeof(Tree));

		//printf("Number : %x\n", tempname);

		newTree->isName=tempname;
		newTree->isX= isx;
		newTree->isY= isy;
		newTree->isType = temptype;
		newTree->isAttack = attack;
		newTree->isDefence = defence;
		newTree->isHP = hp;
		newTree->isNumber = isInsertNum;
		newTree->left = NULL;
		newTree->right = NULL;

		return newTree; 
	}

	else if( strcmp(tempname , p->isName) <= -1 ) 
	{
		p -> left = insertNode(p->left, tempname, isx, isy, temptype, attack, defence, hp, isInsertNum); 

	}

	else if(  strcmp(tempname , p->isName) >= 1 )
	{
		p -> right = insertNode(p->right, tempname, isx, isy, temptype, attack, defence, hp, isInsertNum); 

	}

	else 
		printf("Alreday Data..!\n");

	return p; 
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

	//isData** temp = (isData**)malloc(sizeof(isData*)*20000000); 2천만 데이터 만큼 사이즈를 만든다.

	while( fscanf(fp, "%s %s %d %d %d %d %d ", type, name, &hp, &attack, &defence, &isx, &isy ) != EOF) {

		char* temptype=(char*)calloc(10,sizeof(char));
		char* tempname=(char*)calloc(10,sizeof(char));
		strcpy(temptype, type);
		strcpy(tempname, name);
		if(isInsertNum == 0 ){
			root = insertNode(root, tempname,  isx,  isy,  temptype,  attack,  defence,  hp,  isInsertNum);
			++isInsertNum;
		}else{
			insertNode(root, tempname,  isx,  isy,  temptype,  attack,  defence,  hp,  isInsertNum);
			++isInsertNum;
		}
		if(isInsertNum >= 1000 ){
			break;
		}

	}
	fclose(fp);

}

Tree* isDataSearch(Tree* p, int istheSearchNum){
	if(p){
		isDataSearch(p->left, istheSearchNum);
		if( p->isNumber == istheSearchNum){
			printf("Name : %s, X : %d, Y : %d, Type : %s, Attack : %d, Defence : %d, HP : %d, Number : %d\n", p->isName,p->isX, p->isY, p->isType, p->isAttack, p->isDefence, p->isHP, p->isNumber);
			return p;
		}
		isDataSearch(p->right, istheSearchNum);
		isTestNum++;
	}
	if(isTestNum == isInsertNum){
		if(p->isNumber != isInsertNum){
			return NULL;
		}
	}
}

Tree* isDataNumSearch(Tree* p , int istheSearchNum){
	if(p){
		if( isSearrchEnd == 0 ){
			isDataNumSearch(p->left, istheSearchNum);
		}
		if( p->isNumber == istheSearchNum){
			//printf("Name : %s, X : %d, Y : %d, Type : %s, Attack : %d, Defence : %d, HP : %d, Number : %d\n", p->isName,p->isX, p->isY, p->isType, p->isAttack, p->isDefence, p->isHP, p->isNumber);
			isSearrchEnd=1;
			find = p;
			return find;
		}
		if( isSearrchEnd == 0 ){
			isDataNumSearch(p->right, istheSearchNum);
		}
	}
	//if( isSearrchEnd == 0 ){
	//p = NULL;
	//return p;
	//}
}

void isInsertData(int istheInsertNum){
	char* tempName=(char*)calloc(10,sizeof(char));
	char* tempType=(char*)calloc(10,sizeof(char));

	int tempX= rand()%1000+1, tempY = rand()%1000+1;

	printf("input name : ");
	scanf("%s",tempName);

	printf("input X : ");
	scanf("%d",&tempX);

	printf("input Y : ");
	scanf("%d",&tempY);

	printf("input Type : ");
	scanf("%s",tempType);

	insertNode(root, tempName,  tempX,  tempY,  tempType,  rand()%10000, rand()%10000,  rand()%255+1,  isInsertNum);
	isInsertNum++;
}

void isDataDelete(Tree* p, int isDeleteNum){
	Tree* isSearchData;
	Tree* parent;
	Tree* child; 
	Tree* succ_parent; 
	Tree* succ; 

	isSearrchEnd=0;
	isSearchData = isDataNumSearch(root , isDeleteNum);
	if( isSearrchEnd == 0 ){
		printf("NoData..!\n");
		return ; 
	}

	while( p != NULL && p->isName != find->isName ) 
	{
		parent = p; 

		if(strcmp(p->isName , find->isName) >= 1)
			p = p->left;
		else
			p = p->right; 
	}

	if(p->left == NULL && p->right == NULL){  
		if( parent != NULL){ 
			if(parent ->left == p ) 
				parent->left = NULL; 

			else 
				parent->right = NULL;
		}

		else 
			p = NULL;
	}

	else if(p->left == NULL || p->right == NULL){ 
		if(p->left != NULL)
			child = p->left; 


		else 
			child = p->right;


		if(parent == NULL)
			p = child;

		else
		{
			if(p == parent->left) 
				parent->left = child;

			else
				parent->right = child; 
		}

	}

	else 
	{
		succ_parent = p; 
		succ = p->left;  

		while(succ->right != NULL){
			succ_parent = succ; 

			succ = succ->right; 
		}

		if(succ_parent->left == succ) 
			succ_parent->left = succ->left;

		else
			succ_parent->right = succ->left;

		p->isAttack = succ->isAttack;
		p->isDefence = succ->isDefence;
		p->isHP = succ->isHP;
		p->isName = succ->isName;
		p->isType = succ->isType;
		p->isX = succ->isX;
		p->isY = succ->isY;
		p->isNumber = succ->isNumber;
		p = succ; 

	}

	free(p);

}

void isPrintAll(Tree* p){
	if(p){
		isPrintAll(p->left);
		printf("Name : %s, X : %d, Y : %d, Type : %s, Attack : %d, Defence : %d, HP : %d, Number : %d\n", p->isName,p->isX, p->isY, p->isType, p->isAttack, p->isDefence, p->isHP, p->isNumber);
		isPrintAll(p->right);
	}
}

void isFindMinHealth(Tree* p){

	if(p != NULL){
		isFindMinHealth(p->left);
		if( tempHP >= p->isHP ){
			tempHP = p->isHP;
			find = p;
			isTestNum2++;
		}
		isFindMinHealth(p->right);
		isTestNum++;
	}
	if(isTestNum == isInsertNum){
		printf("Unit Number : %d\n",find->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", find->isName,find->isX, find->isY, find->isType, find->isAttack, find->isDefence, find->isHP);
		printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
	}
}

void isFindTarget(Tree* p, Tree* t, int isSearchNum){
	if(t != NULL){
		isFindTarget(p, t->left, isSearchNum);
		if(p->isNumber != t->isNumber){
			isShortDistance = (abs(t->isY-p->isY)*abs(t->isY-p->isY))+(abs(t->isX-p->isX)*abs(t->isX-p->isX));

			if(isShortDistance >= (abs(t->isY-p->isY)*abs(t->isY-p->isY))+(abs(t->isX-p->isX)*abs(t->isX-p->isX))){
				isShortDistance = (abs(t->isY-p->isY)*abs(t->isY-p->isY))+(abs(t->isX-p->isX)*abs(t->isX-p->isX));
				find = t;
				isTestNum2++;
			}
		}
		isFindTarget(p,t->right, isSearchNum);
		isTestNum++;
	}

	if(isTestNum == isInsertNum){
		printf("\n");
		printf("1. Search\n");
		printf("Number : %d\n", p->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", p->isName,p->isX, p->isY, p->isType, p->isAttack, p->isDefence, p->isHP);
		printf("2. Result\n");
		printf("Number : %d\n", find->isNumber);
		printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", find->isName,find->isX, find->isY, find->isType, find->isAttack, find->isDefence, find->isHP);
		printf("3. Distance\n");
		printf("└ %f\n",sqrt(isShortDistance));
	}
}
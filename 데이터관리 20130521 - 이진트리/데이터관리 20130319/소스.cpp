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

Tree* root = NULL;  // root 만들어 초기값 NULL로 정의.
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
void isFindTarget(int);


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
			isDataDelete(root,isDeleteNum);
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
		}else if(num==6){
			/*printf("Menu : FindTarget\n\n");
			isTempTheEnd=0;
			printf("input num : ");
			scanf("%d",&isSearchNum);
			isTestNum=0,isTestNum2=0;
			isStartTime = GetTickCount();
			isFindTarget(isSearchNum);*/
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


	if( p == NULL )  // 단말일때.. 삽입-> 첫번째 이거나 단말일때..
	{
		newTree = (Tree*)malloc(sizeof(Tree));

		printf("Number : %s\n", tempname);

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

		return newTree;  // newTree 값 반환.
	}

	else if( strcmp(tempname , p->isName) <= -1 ) // 현재 키값(tempname)가 작을때  go left  즉, p->left 가 널일때 까지 반복됨,
	{
		p -> left = insertNode(p->left, tempname, isx, isy, temptype, attack, defence, hp, isInsertNum);  // 재귀함수.

	}

	else if(  strcmp(tempname , p->isName) >= 1 ) // 현재 키값이 클때 go right
	{
		p -> right = insertNode(p->right, tempname, isx, isy, temptype, attack, defence, hp, isInsertNum);  // 재귀함수.

	}

	else // 키값과 실제 키값이 같을 때
		printf("이미 같은 키가 있습니다. \n");

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
		if(isInsertNum >= 10 ){
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
	}
}

Tree* isDataNumSearch(Tree* p , int istheSearchNum){
	if(p){
		if( isSearrchEnd == 0 ){
			isDataNumSearch(p->left, istheSearchNum);
		}
		if( p->isNumber == istheSearchNum){
			printf("Name : %s, X : %d, Y : %d, Type : %s, Attack : %d, Defence : %d, HP : %d, Number : %d\n", p->isName,p->isX, p->isY, p->isType, p->isAttack, p->isDefence, p->isHP, p->isNumber);
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
	Tree* isSearchData; // 부모 포인터를 기억해 놓는것이다.. 나중에 연결성 주기 위하여
	Tree* parent; // 부모 포인터를 기억해 놓는것이다.. 나중에 연결성 주기 위하여
	Tree* child; // p의 자식으로 기억 해둘 곳 선언..
	Tree* succ_parent; // 또다른 부모를 기억해둘려고 선언( 후계자의 부모)
	Tree* succ; // 후계자 선언.

	isSearrchEnd=0;
	isSearchData = isDataNumSearch(root , isDeleteNum);
	if( isSearrchEnd == 0 ){
		printf("NoData..!\n");
		return ; // 함수를 종료 하겠다.
	}

	while( p != NULL && p->isName != find->isName ) // p 값이 널이 아니거나, 키값과 같지 않을 동안 이동시킨다.
	{
		parent = p; // p를 부모에 기록 해둔다.

		if(strcmp(p->isName , find->isName) >= 1) // p를 왼쪽으로 이동시킴.
			p = p->left;
		else  // 아니라면 오른쪽으로 이동시킴.
			p = p->right; 
	}

	// 삭제할 조건 3가지

	// 1. 단말 노드인 경우
	// 2. 자식노드가 1개인 경우 => 자식을 부모로 대체
	// 3. 자식노드가 2개인 경우 => 후계자를 선택

	if(p->left == NULL && p->right == NULL){  // 단말 노드 인경우.
		if( parent != NULL){ // 부모가 널이 아닌경우
			if(parent ->left == p ) // 부모의 왼쪽이라면..
				parent->left = NULL; // left 를 널로 바꾼다.

			else // 오른쪽이라면..
				parent->right = NULL;
		}

		else // 하나라는 얘기..(아예 비어있다..)
			p = NULL;
	}

	else if(p->left == NULL || p->right == NULL){  // 자식노드가 1개인 경우.. -> 자식을 부모로 대체. 
		if(p->left != NULL) // 자식이 왼쪽에 있는 경우
			child = p->left; // p의 left를 자식에 기록 해둠


		else  // 자식이 오른쪽인 경우
			child = p->right;


		if(parent == NULL) // 부모가 NULL 인경우.
			p = child;  // p(루트)는 자식이 되면 됨.

		else // 부모가 널이 아닌경우.. 
		{
			if(p == parent->left) // p가 부모의 왼쪽 자식이 라면..
				parent->left = child; // child는 parent의 레프트가 됨

			else // 오른쪽 자식이라면..
				parent->right = child; 
		}

	}

	else // 자식노드가 2개인 경우.. 후계자 선정 해줘야함.
	{
		succ_parent = p;  // p와 같이 해줌.
		succ = p->left;  // left 를 후계자로 선언 한다면... 후계자의 right가 NULL 일 때까지 찾아가야함.. 

		while(succ->right != NULL){ // 후계자의 오른쪽이 널이 아닌동안 반복
			succ_parent = succ; //  succ 의 오른쪽이 있다면 succ parent 를 succ 자리로 가면서 따라 가 줘야함.

			succ = succ->right; // succ 는 오른쪽으로 옮겨 줘야함.   
		}

		if(succ_parent->left == succ) // 반복문 수행없는 경우, 즉 succ_p 의 자식이 succ 인 경우..  반복문 안돌기 때문에 왼쪽이 자식이 됨. ( 왼쪽만 자식을 가져서..)
			succ_parent->left = succ->left;

		else
			succ_parent->right = succ->left;

		p->isAttack = succ->isAttack;// succ의 키 값을 p의 키 값에 넣어줌.
		p->isDefence = succ->isDefence;// succ의 키 값을 p의 키 값에 넣어줌.
		p->isHP = succ->isHP;// succ의 키 값을 p의 키 값에 넣어줌.
		p->isName = succ->isName;// succ의 키 값을 p의 키 값에 넣어줌.
		p->isType = succ->isType;// succ의 키 값을 p의 키 값에 넣어줌.
		p->isX = succ->isX;// succ의 키 값을 p의 키 값에 넣어줌.
		p->isY = succ->isY;// succ의 키 값을 p의 키 값에 넣어줌.
		p->isNumber = succ->isNumber;// succ의 키 값을 p의 키 값에 넣어줌.
		p = succ; // succ의 주소를 p 에 넣어줌

	}

	free(p); // 현재 p는 해제 하겠다.. 

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
	}else{

		if(find != NULL){
			printf("Unit Number : %d\n",find->isNumber);
			printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", find->isName,find->isX, find->isY, find->isType, find->isAttack, find->isDefence, find->isHP);
			printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
			printf("Time : %f초\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
		}
	}
}
//
//void isFindTarget(int isSearchNum){
//	isData *t;
//	isData *theEnd;
//	t=head->next;
//	theEnd=tail;
//	while (t != theEnd){
//		if(t->isNumber == isSearchNum){
//			isData *temp;
//			temp=head->next;
//			if(t->isY == temp->isY && t->isX == temp->isX){
//				temp=temp->next;
//			}
//			isShortDistance = (abs(t->isY-temp->isY)*abs(t->isY-temp->isY))+(abs(t->isX-temp->isX)*abs(t->isX-temp->isX));
//
//			isData *search;
//			isData *isShortSearched;
//			search =head->next;
//			isShortSearched=head;
//			while (search != theEnd){
//				// 구해야지
//				if(t == search){
//					search=search->next;
//				}
//
//				if(isShortDistance >= (abs(t->isY-search->isY)*abs(t->isY-search->isY))+(abs(t->isX-search->isX)*abs(t->isX-search->isX))){
//					isShortDistance = (abs(t->isY-search->isY)*abs(t->isY-search->isY))+(abs(t->isX-search->isX)*abs(t->isX-search->isX));
//					isShortSearched = search;
//					isTestNum2++;
//				}
//				isTestNum++;
//				search=search->next;
//			}
//
//			if(search == tail){
//				isEndTime = GetTickCount();
//				printf("1. Search\n");
//				printf("Number : %d\n", t->isNumber);
//				printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", t->isName,t->isX, t->isY, t->isType, t->isAttack, t->isDefence, t->isHP);
//				printf("2. Result\n");
//				printf("Number : %d\n", isShortSearched->isNumber);
//				printf("Name : %s, X : %d Y : %d, Type : %s, Attack : %d, Deffence : %d, HP : %d\n", isShortSearched->isName,isShortSearched->isX, isShortSearched->isY, isShortSearched->isType, isShortSearched->isAttack, isShortSearched->isDefence, isShortSearched->isHP);
//				printf("3. Distance\n");
//				printf("└ %f\n",sqrt(isShortDistance));
//				printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
//				printf("Time : %f초\n", (isEndTime-isStartTime)/1000);
//				printf("----------------------------\n\n");
//				isTempTheEnd=1;
//			}
//		}
//		t=t->next;
//	}
//	if( t == theEnd && isTempTheEnd ==0){
//		printf("Not Data..!\n");
//		printf("----------------------------\n\n");
//	}
//}
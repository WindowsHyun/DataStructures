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
	struct isData* left;
	struct isData* right;

}Tree;

Tree* root = NULL;  // root ����� �ʱⰪ NULL�� ����.
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
			isStartTime = GetTickCount();
			find = isDataSearch(root,isSearchNum);
			if(find == NULL){
				printf("NoData..!");
			}
			isEndTime = GetTickCount();
			printf("\n\nTime : %f��\n", (isEndTime-isStartTime)/1000);
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
			printf("\n\nTime : %f��\n", (isEndTime-isStartTime)/1000);
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
			printf("\n\nTime : %f��\n", (isEndTime-isStartTime)/1000);
			printf("----------------------------\n\n");
		}else{
			printf("��ȣ ������ �ʰ��Ͽ����ϴ�..!\n\n");
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


	if( p == NULL )  // �ܸ��϶�.. ����-> ù��° �̰ų� �ܸ��϶�..
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

		return newTree;  // newTree �� ��ȯ.
	}

	else if( strcmp(tempname , p->isName) <= -1 ) // ���� Ű��(tempname)�� ������  go left  ��, p->left �� ���϶� ���� �ݺ���,
	{
		p -> left = insertNode(p->left, tempname, isx, isy, temptype, attack, defence, hp, isInsertNum);  // ����Լ�.

	}

	else if(  strcmp(tempname , p->isName) >= 1 ) // ���� Ű���� Ŭ�� go right
	{
		p -> right = insertNode(p->right, tempname, isx, isy, temptype, attack, defence, hp, isInsertNum);  // ����Լ�.

	}

	else // Ű���� ���� Ű���� ���� ��
		printf("�̹� ���� Ű�� �ֽ��ϴ�. \n");

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

	//isData** temp = (isData**)malloc(sizeof(isData*)*20000000); 2õ�� ������ ��ŭ ����� �����.

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
	Tree* isSearchData; // �θ� �����͸� ����� ���°��̴�.. ���߿� ���Ἲ �ֱ� ���Ͽ�
	Tree* parent; // �θ� �����͸� ����� ���°��̴�.. ���߿� ���Ἲ �ֱ� ���Ͽ�
	Tree* child; // p�� �ڽ����� ��� �ص� �� ����..
	Tree* succ_parent; // �Ǵٸ� �θ� ����صѷ��� ����( �İ����� �θ�)
	Tree* succ; // �İ��� ����.

	isSearrchEnd=0;
	isSearchData = isDataNumSearch(root , isDeleteNum);
	if( isSearrchEnd == 0 ){
		printf("NoData..!\n");
		return ; // �Լ��� ���� �ϰڴ�.
	}

	while( p != NULL && p->isName != find->isName ) // p ���� ���� �ƴϰų�, Ű���� ���� ���� ���� �̵���Ų��.
	{
		parent = p; // p�� �θ� ��� �صд�.

		if(strcmp(p->isName , find->isName) >= 1) // p�� �������� �̵���Ŵ.
			p = p->left;
		else  // �ƴ϶�� ���������� �̵���Ŵ.
			p = p->right; 
	}

	// ������ ���� 3����

	// 1. �ܸ� ����� ���
	// 2. �ڽĳ�尡 1���� ��� => �ڽ��� �θ�� ��ü
	// 3. �ڽĳ�尡 2���� ��� => �İ��ڸ� ����

	if(p->left == NULL && p->right == NULL){  // �ܸ� ��� �ΰ��.
		if( parent != NULL){ // �θ� ���� �ƴѰ��
			if(parent ->left == p ) // �θ��� �����̶��..
				parent->left = NULL; // left �� �η� �ٲ۴�.

			else // �������̶��..
				parent->right = NULL;
		}

		else // �ϳ���� ���..(�ƿ� ����ִ�..)
			p = NULL;
	}

	else if(p->left == NULL || p->right == NULL){  // �ڽĳ�尡 1���� ���.. -> �ڽ��� �θ�� ��ü. 
		if(p->left != NULL) // �ڽ��� ���ʿ� �ִ� ���
			child = p->left; // p�� left�� �ڽĿ� ��� �ص�


		else  // �ڽ��� �������� ���
			child = p->right;


		if(parent == NULL) // �θ� NULL �ΰ��.
			p = child;  // p(��Ʈ)�� �ڽ��� �Ǹ� ��.

		else // �θ� ���� �ƴѰ��.. 
		{
			if(p == parent->left) // p�� �θ��� ���� �ڽ��� ���..
				parent->left = child; // child�� parent�� ����Ʈ�� ��

			else // ������ �ڽ��̶��..
				parent->right = child; 
		}

	}

	else // �ڽĳ�尡 2���� ���.. �İ��� ���� �������.
	{
		succ_parent = p;  // p�� ���� ����.
		succ = p->left;  // left �� �İ��ڷ� ���� �Ѵٸ�... �İ����� right�� NULL �� ������ ã�ư�����.. 

		while(succ->right != NULL){ // �İ����� �������� ���� �ƴѵ��� �ݺ�
			succ_parent = succ; //  succ �� �������� �ִٸ� succ parent �� succ �ڸ��� ���鼭 ���� �� �����.

			succ = succ->right; // succ �� ���������� �Ű� �����.   
		}

		if(succ_parent->left == succ) // �ݺ��� ������� ���, �� succ_p �� �ڽ��� succ �� ���..  �ݺ��� �ȵ��� ������ ������ �ڽ��� ��. ( ���ʸ� �ڽ��� ������..)
			succ_parent->left = succ->left;

		else
			succ_parent->right = succ->left;

		p->isAttack = succ->isAttack;// succ�� Ű ���� p�� Ű ���� �־���.
		p->isDefence = succ->isDefence;// succ�� Ű ���� p�� Ű ���� �־���.
		p->isHP = succ->isHP;// succ�� Ű ���� p�� Ű ���� �־���.
		p->isName = succ->isName;// succ�� Ű ���� p�� Ű ���� �־���.
		p->isType = succ->isType;// succ�� Ű ���� p�� Ű ���� �־���.
		p->isX = succ->isX;// succ�� Ű ���� p�� Ű ���� �־���.
		p->isY = succ->isY;// succ�� Ű ���� p�� Ű ���� �־���.
		p->isNumber = succ->isNumber;// succ�� Ű ���� p�� Ű ���� �־���.
		p = succ; // succ�� �ּҸ� p �� �־���

	}

	free(p); // ���� p�� ���� �ϰڴ�.. 

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
			printf("Time : %f��\n", (isEndTime-isStartTime)/1000);
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
//				// ���ؾ���
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
//				printf("�� %f\n",sqrt(isShortDistance));
//				printf("AllSearchData : %d\nChangeData : %d\n",isTestNum,isTestNum2);
//				printf("Time : %f��\n", (isEndTime-isStartTime)/1000);
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
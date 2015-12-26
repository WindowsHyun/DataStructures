// 이진 탐색 트리         

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	char key; // 핵심이되는 데이타 값 => key
	struct treeNode* left;
	struct treeNode* right;
}Tree;

// 삽입 함수
Tree* insertNode(Tree* p, char d);

// 삭제 함수
void deleteNode(Tree* p, char d);

// 출력 함수
void displayinoder(Tree* p);

// 탐색 함수
Tree* searchNode(Tree* p, char d);

// 메뉴 
void menu()
{
	printf("\n*-------------------------*");
	printf("\n\t1: 트리출력");
	printf("\n\t2: 문자삽입");
	printf("\n\t3: 문자삭제");
	printf("\n\t4: 문자검색");
	printf("\n\t5: 종료");
	printf("\n*-------------------------*");
	printf("\n메뉴입력>> ");
}

int main()
{	
	Tree* root = NULL;  // root 만들어 초기값 NULL로 정의.
	Tree* find = NULL;

	char choice, key;

	// 값을 넣어 준다. ( 이부분은 StarDic.txt 에서 노드로 읽어온 부분을 반복문을 이용해서 삽입하면 됨 )
	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');
	

	while(1)
	{
		menu();
		choice = getchar();
		getchar();
        fflush(stdin);
		switch(choice)
		{
			case '1':	
				printf("\t[이진트리 출력] ");
				displayinoder(root);
				printf("\n");
				break;
				
			case '2':
				printf("삽입할 문자를 입력하세요 :");
				key = getchar(); 
				getchar();
				insertNode(root, key);
				break;
			
			case '3':
				printf("삭제할 문자를 입력하세요 :");
				key = getchar();
				getchar();
				deleteNode(root, key);
				break;

			case '4':
				printf("찾을 문자를 입력하세요:");
				key = getchar();
				getchar();
				find = searchNode(root, key);
				
				if(find != NULL)
					printf("\n 입력하신 %c 를 찾았습니다. !! \n", find->key);

				else
					printf("\n 찾는 문자가 없습니다. \n");


			default :
				printf("없는 메뉴입니다. 다시 선택하세요 \n");
				break;
		}
	}


	return 0;
}

// 삽입
Tree* insertNode(Tree* p, char d)
{
	Tree* newTree;

	if( p == NULL )  // 단말일때.. 삽입-> 첫번째 이거나 단말일때..
	{
		newTree = (Tree*)malloc(sizeof(Tree));

		newTree->key = d;
		newTree->left = NULL;
		newTree->right = NULL;
			

		return newTree;  // newTree 값 반환.
	}

	else if( d < p->key ) // 현재 키값(d)가 작을때  go left  즉, p->left 가 널일때 까지 반복됨,
	{
		p -> left = insertNode(p->left, d);  // 재귀 함수.

	}
	
	else if( d > p->key ) // 현재 키값이 클때 go right
	{
		p -> right = insertNode(p->right, d);  // 재귀함수.
	
	}

	else // 키값과 실제 키값이 같을 때
		printf("이미 같은 키가 있습니다. \n");
	

	return p; 
}


// 삭제
void deleteNode(Tree* p, char d)
{
	Tree* parent; // 부모 포인터를 기억해 놓는것이다.. 나중에 연결성 주기 위하여
	Tree* child; // p의 자식으로 기억 해둘 곳 선언..
	Tree* succ_parent; // 또다른 부모를 기억해둘려고 선언( 후계자의 부모)
	Tree* succ; // 후계자 선언.

	while( p != NULL && p->key != d ) // p 값이 널이 아니거나, 키값과 같지 않을 동안 이동시킨다.
	{
		parent = p; // p를 부모에 기록 해둔다.
		
		
		if(p->key > d) // p를 왼쪽으로 이동시킴.
			p = p->left;
		

		else  // 아니라면 오른쪽으로 이동시킴.
			p = p->right; 

	}

	if(p==NULL)  // 찾는 값이 없는 경우.
	{
		printf("삭제할 키가 없습니다. \n");
		
		return ; // 함수를 종료 하겠다.
	}

	
	// 삭제할 조건 3가지

	// 1. 단말 노드인 경우
	// 2. 자식노드가 1개인 경우 => 자식을 부모로 대체
	// 3. 자식노드가 2개인 경우 => 후계자를 선택

	if(p->left == NULL && p->right == NULL)  // 단말 노드 인경우.
	{
		if( parent != NULL) // 부모가 널이 아닌경우
		{
			if(parent ->left == p ) // 부모의 왼쪽이라면..
				parent->left = NULL; // left 를 널로 바꾼다.
		
			else // 오른쪽이라면..
				parent->right = NULL;
		}

		else // 하나라는 얘기..(아예 비어있다..)
			p = NULL;
	}

	else if(p->left == NULL || p->right == NULL)  // 자식노드가 1개인 경우.. -> 자식을 부모로 대체. 
	{

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
		
		while(succ->right != NULL) // 후계자의 오른쪽이 널이 아닌동안 반복
		{
			succ_parent = succ; //  succ 의 오른쪽이 있다면 succ parent 를 succ 자리로 가면서 따라 가 줘야함.
			
			succ = succ->right; // succ 는 오른쪽으로 옮겨 줘야함.   
		}

		if(succ_parent->left == succ) // 반복문 수행없는 경우, 즉 succ_p 의 자식이 succ 인 경우..  반복문 안돌기 때문에 왼쪽이 자식이 됨. ( 왼쪽만 자식을 가져서..)
			succ_parent->left = succ->left;
		
		else
			succ_parent->right = succ->left;
		
		p->key = succ->key;// succ의 키 값을 p의 키 값에 넣어줌.
		p = succ; // succ의 주소를 p 에 넣어줌

	}

	free(p); // 현재 p는 해제 하겠다.. 

}	

// 출력   => 중위표현
void displayinoder(Tree* p)
{
	if(p)
	{
		displayinoder(p->left);
		printf("%c_", p->key);
		displayinoder(p->right);
	}
}

// 탐색
Tree* searchNode(Tree* p, char d)
{
	Tree* temp;
	temp = p;

	while (temp != NULL)
	{
		if(d < temp->key)
			temp = temp->left;

		else if(d > temp->key)
			temp = temp->right;

		else{
			return temp;
            break;
        }
        
	}
	printf("\n 찾는 키가 없습니다 !!");
	return temp;
}

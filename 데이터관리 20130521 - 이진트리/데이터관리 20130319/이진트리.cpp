// ���� Ž�� Ʈ��         

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	char key; // �ٽ��̵Ǵ� ����Ÿ �� => key
	struct treeNode* left;
	struct treeNode* right;
}Tree;

// ���� �Լ�
Tree* insertNode(Tree* p, char d);

// ���� �Լ�
void deleteNode(Tree* p, char d);

// ��� �Լ�
void displayinoder(Tree* p);

// Ž�� �Լ�
Tree* searchNode(Tree* p, char d);

// �޴� 
void menu()
{
	printf("\n*-------------------------*");
	printf("\n\t1: Ʈ�����");
	printf("\n\t2: ���ڻ���");
	printf("\n\t3: ���ڻ���");
	printf("\n\t4: ���ڰ˻�");
	printf("\n\t5: ����");
	printf("\n*-------------------------*");
	printf("\n�޴��Է�>> ");
}

int main()
{	
	Tree* root = NULL;  // root ����� �ʱⰪ NULL�� ����.
	Tree* find = NULL;

	char choice, key;

	// ���� �־� �ش�. ( �̺κ��� StarDic.txt ���� ���� �о�� �κ��� �ݺ����� �̿��ؼ� �����ϸ� �� )
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
				printf("\t[����Ʈ�� ���] ");
				displayinoder(root);
				printf("\n");
				break;
				
			case '2':
				printf("������ ���ڸ� �Է��ϼ��� :");
				key = getchar(); 
				getchar();
				insertNode(root, key);
				break;
			
			case '3':
				printf("������ ���ڸ� �Է��ϼ��� :");
				key = getchar();
				getchar();
				deleteNode(root, key);
				break;

			case '4':
				printf("ã�� ���ڸ� �Է��ϼ���:");
				key = getchar();
				getchar();
				find = searchNode(root, key);
				
				if(find != NULL)
					printf("\n �Է��Ͻ� %c �� ã�ҽ��ϴ�. !! \n", find->key);

				else
					printf("\n ã�� ���ڰ� �����ϴ�. \n");


			default :
				printf("���� �޴��Դϴ�. �ٽ� �����ϼ��� \n");
				break;
		}
	}


	return 0;
}

// ����
Tree* insertNode(Tree* p, char d)
{
	Tree* newTree;

	if( p == NULL )  // �ܸ��϶�.. ����-> ù��° �̰ų� �ܸ��϶�..
	{
		newTree = (Tree*)malloc(sizeof(Tree));

		newTree->key = d;
		newTree->left = NULL;
		newTree->right = NULL;
			

		return newTree;  // newTree �� ��ȯ.
	}

	else if( d < p->key ) // ���� Ű��(d)�� ������  go left  ��, p->left �� ���϶� ���� �ݺ���,
	{
		p -> left = insertNode(p->left, d);  // ��� �Լ�.

	}
	
	else if( d > p->key ) // ���� Ű���� Ŭ�� go right
	{
		p -> right = insertNode(p->right, d);  // ����Լ�.
	
	}

	else // Ű���� ���� Ű���� ���� ��
		printf("�̹� ���� Ű�� �ֽ��ϴ�. \n");
	

	return p; 
}


// ����
void deleteNode(Tree* p, char d)
{
	Tree* parent; // �θ� �����͸� ����� ���°��̴�.. ���߿� ���Ἲ �ֱ� ���Ͽ�
	Tree* child; // p�� �ڽ����� ��� �ص� �� ����..
	Tree* succ_parent; // �Ǵٸ� �θ� ����صѷ��� ����( �İ����� �θ�)
	Tree* succ; // �İ��� ����.

	while( p != NULL && p->key != d ) // p ���� ���� �ƴϰų�, Ű���� ���� ���� ���� �̵���Ų��.
	{
		parent = p; // p�� �θ� ��� �صд�.
		
		
		if(p->key > d) // p�� �������� �̵���Ŵ.
			p = p->left;
		

		else  // �ƴ϶�� ���������� �̵���Ŵ.
			p = p->right; 

	}

	if(p==NULL)  // ã�� ���� ���� ���.
	{
		printf("������ Ű�� �����ϴ�. \n");
		
		return ; // �Լ��� ���� �ϰڴ�.
	}

	
	// ������ ���� 3����

	// 1. �ܸ� ����� ���
	// 2. �ڽĳ�尡 1���� ��� => �ڽ��� �θ�� ��ü
	// 3. �ڽĳ�尡 2���� ��� => �İ��ڸ� ����

	if(p->left == NULL && p->right == NULL)  // �ܸ� ��� �ΰ��.
	{
		if( parent != NULL) // �θ� ���� �ƴѰ��
		{
			if(parent ->left == p ) // �θ��� �����̶��..
				parent->left = NULL; // left �� �η� �ٲ۴�.
		
			else // �������̶��..
				parent->right = NULL;
		}

		else // �ϳ���� ���..(�ƿ� ����ִ�..)
			p = NULL;
	}

	else if(p->left == NULL || p->right == NULL)  // �ڽĳ�尡 1���� ���.. -> �ڽ��� �θ�� ��ü. 
	{

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
		
		while(succ->right != NULL) // �İ����� �������� ���� �ƴѵ��� �ݺ�
		{
			succ_parent = succ; //  succ �� �������� �ִٸ� succ parent �� succ �ڸ��� ���鼭 ���� �� �����.
			
			succ = succ->right; // succ �� ���������� �Ű� �����.   
		}

		if(succ_parent->left == succ) // �ݺ��� ������� ���, �� succ_p �� �ڽ��� succ �� ���..  �ݺ��� �ȵ��� ������ ������ �ڽ��� ��. ( ���ʸ� �ڽ��� ������..)
			succ_parent->left = succ->left;
		
		else
			succ_parent->right = succ->left;
		
		p->key = succ->key;// succ�� Ű ���� p�� Ű ���� �־���.
		p = succ; // succ�� �ּҸ� p �� �־���

	}

	free(p); // ���� p�� ���� �ϰڴ�.. 

}	

// ���   => ����ǥ��
void displayinoder(Tree* p)
{
	if(p)
	{
		displayinoder(p->left);
		printf("%c_", p->key);
		displayinoder(p->right);
	}
}

// Ž��
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
	printf("\n ã�� Ű�� �����ϴ� !!");
	return temp;
}

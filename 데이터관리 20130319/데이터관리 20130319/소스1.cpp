//�ܼ� ���Ḯ��Ʈ ����� (due date : next)
#include <stdio.h>
#include <stdlib.h>

int  isNum;



typedef struct Node{

	int data;
	struct Node* link;

}Node;

Node *head;
Node *tail;

void init(void){
	head=(Node*)malloc(sizeof(Node));
	tail=(Node*)malloc(sizeof(Node));
	head->link=tail;
	tail->link=tail;
}


void createList(Node **head)

{

	/*

	����ڰ� ���ϴ� ��� �� ��ŭ �ܼ����Ḯ��Ʈ�� ����� �Լ�

	main�Լ����� ȣ���ϸ� ����Ʈ ����������� �����͸� �������ڷ� ���

	��带 ����Ʈ�� �����Ҷ� appendNode �Լ��� ȣ���Ͽ� ���

	*/



	//appendNode();



}



void appendNode(Node **,int)

{

	/*

	malloc �Լ��� ���ο� ��� ����

	����Ʈ�� ���� ������ ��忬��

	*/

}





//Node* searchNode(Node **,int){
//
//	//�Լ��� �ι�° �������ڸ� ����Ʈ���� ã�� �׵������� ���� �����͸� �����ϰ� ã�� �����͸� ����Ű�� �����͸� ù��° �������ڿ� �����ϴ� �Լ� 
//
//
//}



void insertNode (Node *head){

	/*�Լ��� �ι�° �������ڸ� searchNode�Լ��� �̿��Ͽ� ã�� �� ������ ���ο� ��带 appendNode �Լ��� �̿��Ͽ� ����Ʈ�� ����



	������ ������ �Է�			<- �ΰ���  ���Ե�����, ���������� ����������

	searchNode()�� �̿��Ͽ� ������ ��ġ�� Ȯ��

	searchNode�Լ����� ���� �����͸� ����Ͽ� �� ������ ������ ���ο� ��� ����

	*/

}


void deleteNode(Node **){			

	//searchNode �Լ����� ���� �����͸� ����Ͽ� �� ������ ������ ���ο�  ��� ����

	//�ǵ� ,�߰� ���� �����Ҽ� �־�� �Ѵ�. 

	/*searchNode�Լ��� �̿��Ͽ� ���ϴ� ���� ã�� �����ϴ� �Լ�.



	������ ������ �Է�				

	searchNode()

	searchNode()�Լ����� ���ϵǴ� �����ϰ��� �ϴ� ����� prev�����͸� �����ϴ� ��� ������ ���� ������ ��带 free ��Ŵ

	*/

}



int main(void)

{
	init();
	while(1)

	{

		printf("1. List All\n");
		printf("2. Search Node\n");
		printf("3. insert Node\n");
		printf("4. Delete Node\n");
		printf("5. EXIT\n\n");
		printf("Input Num : ");
		scanf("%d", &isNum);
		system("cls");
		if(isNum == 1){
			printf("Menu : List All\n\n");

		}else if( isNum ==2){
			printf("Menu : Search Node\n\n");

		}else if(isNum ==3){
			printf("Menu : insert Node\n\n");

		}else if(isNum ==4){
			printf("Menu : Delete Node\n\n");

		}else if(isNum==5){
			system("exit");
			printf("Fuck!\n");
			return 0;
		}else{
			printf("��ȣ ������ �ʰ��Ͽ����ϴ�..!\n\n");
		}

	}

}
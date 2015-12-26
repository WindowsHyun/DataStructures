//단순 연결리스트 만들기 (due date : next)
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

	사용자가 원하는 노드 수 만큼 단순연결리스트를 만드는 함수

	main함수에서 호출하며 리스트 헤드포인터의 포인터를 전달인자로 사용

	노드를 리스트에 연결할때 appendNode 함수를 호출하여 사용

	*/



	//appendNode();



}



void appendNode(Node **,int)

{

	/*

	malloc 함수로 새로운 노드 생성

	리스트에 새로 생선된 노드연결

	*/

}





//Node* searchNode(Node **,int){
//
//	//함수의 두번째 전달인자를 리스트에서 찾아 그데이터의 이전 포인터를 리턴하고 찾은 데이터를 가리키는 포인터를 첫번째 전달인자에 저장하는 함수 
//
//
//}



void insertNode (Node *head){

	/*함수의 두번째 전달인자를 searchNode함수를 이용하여 찾고 그 다음에 새로운 노드를 appendNode 함수를 이용하여 리스트에 연결



	삽입할 데이터 입력			<- 두개값  삽입데이터, 누구다음에 넣을것인지

	searchNode()를 이용하여 삽입할 위치를 확인

	searchNode함수에서 얻은 포인터를 사용하여 이 포인터 다음에 새로운 노드 연결

	*/

}


void deleteNode(Node **){			

	//searchNode 함수에서 얻은 포인터를 사용하여 이 포인터 다음에 새로운  노드 연결

	//맨뒤 ,중간 앞을 제거할수 있어야 한다. 

	/*searchNode함수를 이용하여 원하는 원소 찾고 삭제하는 함수.



	삭제할 데이터 입력				

	searchNode()

	searchNode()함수에서 리턴되는 삭제하고자 하는 노드의 prev포인터를 삭제하는 노드 다음에 연결 삭제한 노드를 free 시킴

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
			printf("번호 범위를 초과하였습니다..!\n\n");
		}

	}

}
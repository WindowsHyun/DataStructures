#include <stdio.h>
#include <Windows.h>

/*
����� �迭�� ���� �̾߱�
 ����
 �Ѹ� �Ʒ��� �����ϼ� �ֵ���





*/ 

#define OBJ 'C'
#define OBJ2 'c'
#define BREADTH 80

int main()
{
	int i,j = 0;
	int a=0;
	while( j < BREADTH){
		system("cls");

		for(i=0; i<j; i++){
			printf(" ");
		}
		if(j%2==0){
			printf("%c", OBJ);
		}else{
			printf("%c", OBJ2);
		}

		for(i=0; i<BREADTH-j-1; ++i){
			printf(".");
		}

		/*for(a=BREADTH; a-j-1>0; --a){
		printf(".");
		}*/

		j++;
		Sleep(100);
	}
	return 0;
}
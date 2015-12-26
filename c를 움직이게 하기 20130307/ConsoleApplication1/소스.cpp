#include <stdio.h>
#include <Windows.h>

#define OBJ 'C'
#define OBJ2 'c'
#define BREADTH 20

int main(){
	int i,j =0;
	
	while(j<BREADTH){
		system("cls");

		for(i=0; i<j; ++i){
			printf(" ");
		}

		printf("%c",OBJ);

		for(j=0; j>BREADTH; ++j){
			printf(".");

		}

		Sleep(100);

		j++;
		return 0;


	}

}
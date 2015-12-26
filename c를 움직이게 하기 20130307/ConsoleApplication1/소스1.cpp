#include <stdio.h>
#include <Windows.h>

int i=0,j=0;
void PrintStar(int);
void PrintNumber(int);
void PrintRestart(int );

int main(){
	int isnum;

	printf("Line : ");
	scanf("%d",&isnum);

	//PrintStar(isnum);
	//PrintNumber(isnum);
	PrintRestart(isnum);
}


void PrintRestart(int num){
	if(i>num) return;

	for(j=0; j<i; ++j){
		printf("¡Ú");
		Sleep(100);
	}
	printf("\n");
	i++;
	PrintRestart(num);

}

void PrintStar(int num){
	int i,j;
	for(i=0; i<=num; ++i){
		for(j=0; j<i; ++j){
			printf("¡Ú");
			Sleep(100);
		}
		printf("\n");
	}

}

void PrintNumber(int num){
	int i,j;

	for(i=0; i<=num; ++i){
		for(j=0; j<i; ++j){
			printf("%d",j+1);
			Sleep(100);
		}
		printf("\n");
	}

}
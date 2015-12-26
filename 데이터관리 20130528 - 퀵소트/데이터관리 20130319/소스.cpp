#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#define MAX 20

typedef struct Data{
	int num; 
	int hp;
	int attack;
	int defence;
	char name[20];
	int xpos;
	int ypos;
	char trib[20];
};

int num=0;
Data unit[20] = {{0,13,71,99,"P7655432", 42,89,"P"},
{1,564,132,876,"Z22312323", 75,53,"Z"},
{2,8,786,234,"T312323", 65,564,"T"},
{3,456,7564,1555,"Z42323123", 645,234,"Z"}, 
{4,456,457,2342,"P522333", 234,465,"P"},
{5,345,645,245,"T12672323", 565,324,"T"},
{6,1320,1253,1516,"P22323123", 236,456,"P"},
{7,1300,1923,1556,"P32323123", 223,425,"P"},
{8,1322,123,156,"Z42323993", 756,23,"Z"},
{9,1230,1323,234,"T2723793", 345,45,"T"},
{10,230,223,156,"P62323123", 123,52,"P"},
{11,2230,743,645,"P72323123", 8,145,"P"},
{12,765,223,156,"P82323123", 77,145,"P"},
{13,2330,453,423,"P92323123", 99,1415,"P"},
{14,54,223,156,"T12323123", 345,34,"T"},
{15,64,223,65,"Z552233123", 454,145,"Z"},
{16,867,342,4,"Z7882323123", 675,532,"Z"},
{17,455,223,123,"P99923123", 875,867,"P"},
{18,453,343,156,"T5233123", 2345,564,"T"},
{19,655,223,156,"Z7772373123", 443,543,"Z"}};

void isDataSwap(Data *x, Data *y);
void isQuickSort(Data a[], int left, int right);

void printAll(Data a[]){
	for(int i = 0; i<MAX; ++i){
		printf("Number :%d, Type :%s , Name : %s, HP : %d , Attack : %d, Defence : %d, X : %d, Y : %d \n", a[i].num, a[i].trib, a[i].name, a[i].hp, a[i].attack, a[i].defence, a[i].xpos, a[i].ypos);
	}
}

int main(){

	while(1){
		printf("1. Search\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. PrintAll\n");
		printf("5. FindMinHealth\n");
		printf("6. FindTarget\n");
		printf("7. QuickSort\n\n");
		printf("Input Num : ");
		scanf("%d", &num);
		if(num == 4){
			system("cls");
			printf("Menu : PrintAll\n\n");
			printAll(unit);
		}else if(num == 7){
			system("cls");
			printf("Menu : QuickSort\n\n");
			isQuickSort(unit,0,MAX-1);

		}else{
			printf("번호 범위를 초과하였습니다..!\n\n");
		}
	}

}

void isDataSwap(Data *x, Data *y){
	Data temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


void isQuickSort(Data a[], int left, int right){
	int i,j;
	Data pivot;

	if(left<right){
		pivot = a[left];
		i = left+1;
		j = right;

		while(i<=j){
			while((i<= right) && (strcmp(a[i].name, pivot.name) == -1))
				i++;
			while((j>= left) && (strcmp(a[j].name, pivot.name) == 1))
				j--;

			if(i<j){
				isDataSwap(&a[i], &a[j]);
			}
		}

		isDataSwap(&a[left], &a[j]);
		isQuickSort(a, left, j-1);
		isQuickSort(a, j+1, right);
	}
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

int isDeleteNum=0, isTotalData, num, isSearchNum;

struct isData { //구조체 선언
	char* isName;
	int isX;
	int isY;
	char* isType;
	int isHP;
	int isNumber;
};

struct isData data[100];

void isAddData();
void isDataSearch();
void isInsertData();
void isPrintAll();
void isDataDelete();

int main(){

}

void isAddData(){
	char* tempName=(char*)calloc(10,sizeof(char));
	char* tempType=(char*)calloc(10,sizeof(char));
	for (int i=0; i<5; ++i){
		data[i].isName = "SCV";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Terran";
		data[i].isHP = rand()%255+1;
		data[i].isNumber = i;
	}
	for (int i=5; i<10; ++i){
		data[i].isName = "Zergling";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Zerg";
		data[i].isHP = rand()%255+1;
		data[i].isNumber = i;
	}
	for (int i=10; i<15; ++i){
		data[i].isName = "Prove";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Protoss";
		data[i].isHP = rand()%255+1;
		data[i].isNumber = i;
	}
	for (int i=15; i<20; ++i){
		data[i].isName = "Drone";
		data[i].isX = rand()%1000+1;
		data[i].isY = rand()%1000+1;
		data[i].isType = "Zerg";
		data[i].isHP = rand()%255+1;
		data[i].isNumber = i;
	}
	isTotalData=20;
}


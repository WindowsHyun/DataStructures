#include<stdio.h>
#include<stdlib.h>

typedef struct isData{
	char *name;
	struct isData* next;

}isData;

isData *head;

void init(void){
	head = (isData*)malloc(sizeof(isData));
	head->next=head;
}

void initAdd(){
	isData *t;

	t=(isData*)malloc(sizeof(isData));
	t->name = "a";
	t->next=head->next;
	head->next=t;

	t=(isData*)malloc(sizeof(isData));
	t->name = "b";
	t->next=head->next;
	head->next=t;

}

void printAll(){
	isData *t;
	t=head->next;
	while(t != head){
		printf("%s", t->name);
		t=t->next;
	}

}

int main()
{
	init();
	initAdd();
	//printf("%d", 'Z');
	printAll();
}
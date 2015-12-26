#include <stdio.h>
#include <malloc.h>

typedef struct data_{
	int a;
	struct data_ *link;
}data;

typedef struct data_head{
	data *link;
}head;

void create_linked_list(head *h)
{
	h->link = NULL;
}

void add_data(head *h, int num)
{
	data* temp;
	data* p = h->link;

	temp = (data*)malloc(sizeof(data));
	
	temp->a = num;
	temp->link = NULL;	

	if(h->link == NULL){
		h->link = temp;
		return;
	}

	while(!(p->link == NULL))
		p = p->link;
	
	p->link = temp;
}

void print_data(head *h)
{
	data* p = h->link;
	
	while(!(p == NULL)){
		printf("%d ", p->a);
		p = p->link;
	}
}

void buble_sort(head *h)
{
	data* p = h->link;
	int temp;
	int count = 0;
	
	do
	{
		if(p->link == NULL){
			p = h->link;
			count = 0;
		}
		if(p->a < p->link->a){
			temp = p->a;
			p->a = p->link->a;
			p->link->a = temp;
			count++;
		}
		p = p->link;
	}while(!(p->link == NULL) || !(count == 0));

}

int main()
{
	head h;

	create_linked_list(&h);

	add_data(&h, 10);
	add_data(&h, 3);
	add_data(&h, 2);
	add_data(&h, 9);
	print_data(&h);
	
	printf("\n");

	buble_sort(&h);
	print_data(&h);

}
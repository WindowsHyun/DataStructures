//******************************************************************
//이중 연결 리스트
//******************************************************************
#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node * next; // 다음
	struct node * prev; // 이전
}Node;
//******************************************************************
Node * head, * tail;
//******************************************************************
//util
//******************************************************************
Node * CreateNode(int x)
{
	Node * newnode = (Node *)malloc(sizeof(Node));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//******************************************************************
void init()
{
	head = CreateNode(0);
	tail = CreateNode(0);
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
}
//******************************************************************
void push_back(int x)
{
	Node * newnode = CreateNode(x);
	newnode->next = tail;
	newnode->prev = tail->prev;
	tail->prev->next = newnode;
	tail->prev = newnode;
}
//******************************************************************
//2)push_front
//******************************************************************
void push_front(int x)
{
	Node * newnode = CreateNode(x);
	//링크 연결
	newnode->prev = head;
	newnode->next = head->next;
	head->next->prev = newnode;
	head->prev = newnode;
}
//******************************************************************
//3)order_insert
//******************************************************************
void order_insert(int key, int x)
{

	Node * p;

	if(head->next == tail)
	{
		puts("없네유~");
	}
	else
	{
		p = head->next;
		while(p != tail)
		{
			if(p->data == key)
			{
				Node * newnode = CreateNode(x);
				newnode->next = p->next;
				newnode->prev = p;
				p->next->prev = newnode;
				p->next = newnode;
				return;
			}
			else
			{
				p = p->next;
			}
		}
		push_back(x);
	}
}
//******************************************************************
//삭제
//******************************************************************
//1)pop_back
//******************************************************************
void pop_back()
{
	if(head->next == tail)
	{
		puts("비었음요!!");
	}
	else
	{
		Node * p = tail->prev;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}
//******************************************************************
//2)pop_front
//******************************************************************
void pop_front()
{
	if(head->next == tail)
	{
		puts("비었음요!!!");
	}
	else
	{
		Node * p = head->next;
		head->next = p->next;
		p->next->prev = head;
		free(p);
	}
}
//******************************************************************
//3)erase
//******************************************************************
void erase(int key)
{
	Node * p;
	if(head->next == tail)
	{
		puts("없어유!!!");
	}
	else
	{
		p = head->next;
		while(p != tail)
		{
			if(p->data == key)
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				free(p);
				return;
			}
			else
			{
				p = p->next;
			}
		}
	}
}
//******************************************************************
//print
//******************************************************************
void print()
{
	Node * p = head->next;
	while(p != tail)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	puts("");
}
void main()
{
	init();
	push_back(10);
	push_back(20);
	push_back(30);
	print();
	erase(10);
	print();
	erase(20);
	print();
	erase(30);
	print();
}
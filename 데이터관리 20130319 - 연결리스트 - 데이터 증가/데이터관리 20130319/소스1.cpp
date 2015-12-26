//************************************************
//   ������ ���Ḯ��Ʈ ���� �÷Ƚ��ϴ�.
//   �⺻���� ��������±��� �߽��ϴٸ�..
//   �������� �׳� �ܿ�ø鼭 ������ ������ �󸶵���
//   ���� �����ϸ��� ���ϴ�. ȭ���� ����
//************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _node{
 char name[20];
 char tel[20];
 struct _node *next;
}node;
node *head;
node *tail;
void init(void)
{
 head=(node*)malloc(sizeof(node));
 tail=(node*)malloc(sizeof(node));
 head->next=tail;
 tail->next=tail;
}
void insertAfter(char *name, char *tel)
{
 node *t;
 t=(node*)malloc(sizeof(node));
 strcpy(t->name, name);
 strcpy(t->tel, tel);
 t->next=head->next;
 head->next=t;
 printf("-------->Data Inserted\n");
}
void printfAll(void)
{
 node *t;
 t=head->next;
 if (head->next == tail)
 {
  printf("������ �����ϴ�.\n\n");
 }

 while (t != tail)
 {
  printf("name : %s  Tel: %s\n", t->name, t->tel);
  t=t->next;
 }

}
void deleteall(void)
{
 node *p;
 node *s;
 p=head->next;
 if (head->next == tail)
 {
  printf("������ ���� �����ϴ�.\n\n");
 }
 
 while (p != tail)
 {
  s=p;
  p=p->next;
  free(s);
 }
 head->next=tail;
 printf("��� ���� �Ͽ����ϴ�.\n\n");

}
void findnode(char *name)
{
 node *t;
 t=head->next;
 while (t != tail && strcmp(t->name, name) != 0)
 {
  t=t->next;
 }
 if (t == tail)
 {
  printf("ã���ô� ������ �����ϴ�.\n\n");
 }
 else
 {
  printf("name : %s // Tel: %s\n\n", t->name, t->tel);
 }
}
void finddelete(char *name)
{
 node *p;
 node *s;
 node *t;
 p=head->next;
 s=head;
 while (p != tail && strcmp(p->name, name) != 0)
 {
  s=s->next;
  p=s->next;
 }
 
 if (p == tail)
 {
  printf("������ ������ �����ϴ�.\n\n");
 }
 else
 {
  t=p;
  p=p->next;
  s->next=p;
  free(t);
  printf("--------->Data deleted\n\n");
 }
}
void save_node(char *s)       //���Ϸ� ����!!
{
 FILE *fp;
 node *t;
 if ((fp=fopen(s, "wb")) == NULL)
 {
  printf(" Error \n");
  return;
 }
 t=head->next;
 while (t != tail)
 {
  fwrite(t, sizeof(node)-4, 1, fp);
  t=t->next;
 }
 fclose(fp);
}
void load_node(char *t)       //���� ������ ���Ḯ��Ʈ��!!
{
 FILE *fp;
 node *p;
 node *s;
 if ((fp=fopen(t, "rb")) == NULL) 
 {
  printf(" Error \n");
  return;
 }
 p=head->next;
 while (p != tail)
 {
  s=p;
  p=p->next;
  free(s);
 }
 head->next=tail;
 while (1)
 {
  p=(node*)malloc(sizeof(node));
  if (!fread(p, sizeof(node)-4, 1, fp))
  {
   free(p);
   break;
  }
  p->next=head->next;
  head->next=p;
 }
 fclose(fp);
}
int main(void)
{
 char name[20]={0,};
 char tel[20]={0,};
 int select=0;
 char *file = "phonebook.txt";
 init();
 load_node(file);        // ���۽� ���� ���� ����!!!!
 while (1)
 {
  printf("\n\n-----------Menu-----------\n");
  printf("                1. Insert\n");
  printf("                2. Delete\n");
  printf("                3. Search\n");
  printf("                4. Print All\n");
  printf("                5. Exit\n");
  printf("Choose the item: ");
  scanf("%d", &select);
  
  switch(select) 
  {
   case 1:
   {
    printf("[INSERT]\n");
    printf("Input Name :");
    scanf("%s", name);
    printf("Iput Tel Number: ");
    scanf("%s", tel);
    insertAfter(name, tel);
    break;
   }
   case 2:
   {
    printf("[Delete]\n");
    printf("Input Name :");
    scanf("%s", name);
    finddelete(name);
    break;
   }
   case 3:
   {
    printf("[Search]\n");
    printf("Input Name :");
    scanf("%s", name);
    findnode(name);
    break;
   }
   case 4:
   {
    printf("[Print All]\n");
    printfAll();
    break;
   }
   case 5:
   {
    save_node(file);     // ����� ���Ϸ� ����!!
    deleteall();
    exit(0);
   }
  default:
   {
    printf("�߸� �����̽��ϴ�.\n");
    break;
   }
  }
  getch();
  system("cls");
 }
 deleteall();
 free(head);
 free(tail);
 return 0;
}
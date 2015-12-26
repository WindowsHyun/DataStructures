#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
// ��ȭ��ȣ ����ü�� Book ���� ������
typedef struct Phone Book;
// ��ȭ��ȣ ����ü�� ������ pBook
typedef struct Phone *pBook;
// ��ȭ��ȣ ����ü �̸�, ��ȭ��ȣ, ���� ����ü ������ next 
struct Phone { 
    char name[20]; 
    char phone[20]; 
    pBook next; 
}; 
// ���Ḯ��Ʈ ����ü�� List�� ������
typedef struct phoneList List;
// ���Ḯ��Ʈ ����ü�� ������ pList
typedef struct phoneList *pList;
// ���Ḯ��Ʈ ����ü : head�� tail�� ������ �ִ�.
struct phoneList {
    pBook head;
    pBook tail;
};  
// ����带 ����� �����͸� NULL�� �ʱ�ȭ ��Ų��.
pBook makeNode();
// ��ȭ��ȣ�� �ߺ��˻縦 ���� �ʰ�, �̸�, ��ȣ�� �Է¹޾� �����Ѵ�.
// ������ �Է¹��� ������� �Ǿ��ִ�.
void insertNode(pList); 
// �̸��� �Է¹޾� �̸��� ���� ��带 �����Ѵ�.
// ���� �̸��� ���� ��� ���� �߰��� ��常 �����Ѵ�.
void deleteNode(pList); 
// �̸����� ã�� ��ȭ��ȣ�� �����ش�.
void searchNode(pList); 
// �̸������� ��ȭ��ȣ�θ� �����ش�.
void showByNames(pList); 
// ��ȣ������ ��ȭ��ȣ�θ� �����ش�.
void showByPhoneNumber(pList); 
// �Էµ� ������ ��ȭ��ȣ�θ� �����ش�.
void showAll(pList); 
// ��� ������ �����Ѵ�.
void quitNode(pList); 
int main() { 
    // ��ȭ��ȣ�� ����Ʈ list
    pList list;
    // �޴������� ���� ����, 7�� �Է��ϸ� �����Ѵ�.
    int menu=1; 

    // ����Ʈ�� �ʱ�ȭ�Ѵ�. ���� ��带 �Ѱ� ���� head�� tail�� �� ��带 ����Ű�� �Ѵ�.
    // �̷��� �ؼ� �׻� ������ ����Ű�⸦ ���ϴ� ��� ���� ���� ��带 ������ ã�ƴٴϸ�
    // � ��ġ������� ���԰� ������ �� �� �ִ�.
    // �� ���� �����͸� ����ؾ��ϴ� ���ŷ����� ���� ���� �ִ�.
    // head�� ����Ʈ�� �����ϴ� ���(�׻� ���̳��)�� ����Ų��.
    // tail�� ����Ʈ�� �� ������ ��带 ����Ų��. ó������ ���̳�带 ����Ű�ٰ�,
    // ������ ��尡 ���ԵǸ� ���� ���߿� ���Ե� ��带 ����Ű�� �ȴ�.
    // tail �� �̿��ؼ� �츮�� ���� ���ԵǴ� ��带 ���� �ڿ� �ٷ� ������ �� �ִ�.
    list=(pList)malloc(sizeof(List));
    list->head=makeNode();
    list->tail=list->head;

    // �޴��� �����ְ� ������ �Է� �޴´�.
    while(menu!=7) { 
        puts("*************"); 
        puts("* 1. �Է�: "); 
        puts("* 2. ����: "); 
        puts("* 3. �˻�: "); 
        puts("* 4. �̸��� ��ü���: "); 
        puts("* 5. ��ȭ��ȣ�� ��ü���: "); 
        puts("* 6. ��ü���:"); 
        puts("* 7. ������"); 
        puts("*************"); 
        printf("����="); 
        scanf("%d", &menu); 
        fflush(stdin); 
        switch(menu) { 
            case 1: 
                // ����
                insertNode(list); 
                break; 
            case 2: 
                // ����
                deleteNode(list); 
                break; 
            case 3: 
                // �˻�
                searchNode(list); 
                break; 
            case 4: 
                // �̸���
                showByNames(list); 
                break; 
            case 5: 
                // ��ȭ��ȣ��
                showByPhoneNumber(list); 
                break; 
            case 6: 
                // ��ü���
                showAll(list); 
                break; 
            case 7: 
                // ����
                quitNode(list); 
                break; 
        } 
    }
    // ���������� list�� free��Ų��.
    free(list);

    return 0;
} 
// ����带 �����.
pBook makeNode() { 
    pBook p;

    p=(pBook)malloc(sizeof(Book));
    strcpy(p->name,"");
    strcpy(p->phone,"");
    p->next=NULL;
    return p;
}
// ��带 �����Ѵ�.
pBook copyNode(pBook q) { 
    pBook p;

    p=(pBook)malloc(sizeof(Book));
    strcpy(p->name,q->name);
    strcpy(p->phone,q->phone);
    p->next=NULL;
    return p;
}
// �̸��� ��ȣ�� �Է¹޾� ����带 �����Ѵ�.
void insertNode(pList list) {
    pBook t=list->head; 
    pBook newnode = makeNode(); 
    printf("�̸��� �Է��ϼ��� : "); 
    gets(newnode->name); 
    fflush(stdin); 
    printf("��ȣ�� �Է��ϼ��� : "); 
    gets(newnode->phone); 
    fflush(stdin); 
    list->tail->next=newnode;
    list->tail=newnode;
} 
// �̸��� �Է¹޾� �� ��带 ã�Ƽ� �����Ѵ�.
void deleteNode(pList list) {
    pBook t = list->head;
    pBook temp; 
    char str[20]={0,}; 
    printf("�̸��� �Է��ϼ��� : "); 
    gets(str); 
    fflush(stdin); 
    while(t->next) {
        // ���⼭ t->next->name�� str�� ���� �Ϳ���
        // ������ ����Ű�� ����� ��ĭ ���� �����͸� ������
        // ã�´ٴ� �ǹ̸� �� �� �ִ�.
        if(strcmp(t->next->name,str)==0) {
            temp = t->next; 
            // �츮�� ã�� ��尡 temp��� �̴�. �̳�尡 ������ ����� tail�� ������ �־�� �Ѵ�.
            if(list->tail==temp) list->tail=t;
            // t->next�� t->next->next�� �ٲپ� �ش�.
            // �̷��� ���ָ� temp�� ����Ʈ �󿡼� ������� �ȴ�.
            t->next=t->next->next; 
            // temp�� free�����ش�.
            free(temp);
            return;
        } 
        t=t->next;
    }
} 
// �̸����� ��ȭ��ȣ�� ã�´�.
void searchNode(pList list) {
    pBook t = list->head;
    char str[20]={0,}; 
    printf("�̸��� �Է��ϼ��� : "); 
    gets(str); 
    fflush(stdin); 
    while(t->next) {
        if(strcmp(t->next->name,str)==0) {
            printf("�̸�: \t%s\t��ȣ:\t%s\n", t->next->name, t->next->phone); 

            return;
        } 
        t=t->next;
    }
} 
// �̸������� �����ϱ� 
void showByNames(pList list) {
    pBook t = list->head;
    pBook temp;
    pBook root=makeNode();
    pBook s=root;
    int comp;
 
    // ��ȭ��ȣ����Ʈ�� ó������ ������ ���鼭
    // ���ο� ����Ʈ root�� �̸������� ������ �Ѵ�.
    while(t->next) {
        // ���� ���� ��带 �����Ѵ�.
        temp=copyNode(t->next);
        // ���ο� ����Ʈ root�� ó������ �����Ͽ�
        s=root;
        // temp�� �̸��� root���� �����ϴ� ����� �̸��� ���Ѵ�.
        while(s->next) {
            comp=strcmp(s->next->name, temp->name);
            // temp�� �̸��� root���� �����ϴ� ���� ����� �̸����� �۴ٸ�
            if(comp>=0) {
                // s->next �տ� temp�� ���� �־�� �Ѵ�.
                // ���� temp->next�� s->next�� �Ǿ�� �Ѵ�.
                temp->next=s->next;
                break;
            }
            // ���� temp�� �̸��� �������� �̸����� ũ�ٸ� ���� ���� ����.
            else s=s->next;
        }
        // s->next�տ� temp�� ���� �־�� �ϹǷ�
        // s->next�� temp�� �־� �ָ� �ȴ�.
        s->next=temp;
        // ���� ��ȭ��ȣ�ο��� �����ִ� ��带 ó������ ���ؼ� t�� ���� ���� ���� �̵���Ų��.
        t=t->next;
    }
    // ���� ������� root����Ʈ�� ��� ����� �ش�.
    t=root;
    while(t->next) {
        printf("�̸�: \t%s\t��ȣ:\t%s\n", t->next->name, t->next->phone); 

        t = t->next; 
    }
    // ���� ������� root����Ʈ�� ��� ������ �ش�. 
    t=root;
    while(t->next) {
        temp = t->next;
        t=t->next; 
        free(temp); 
    } 
    free(root);
} 
// ��ȣ�� ��µ� �̸��� ��°� ����.
// ���� ���� �� �̸���� ��ȣ�� ����ϴ� �͸� �ٸ���.
void showByPhoneNumber(pList list) {
    pBook t = list->head;
    pBook temp;
    pBook root=makeNode();
    pBook s=root;
    int comp;
 
    while(t->next) {
        temp=copyNode(t->next);
        s=root;
        while(s->next) {
            comp=strcmp(s->next->phone, temp->phone);
            if(comp>=0) {
                temp->next=s->next;
                break;
            }
            else s=s->next;
        }
        s->next=temp;
        t=t->next;
    }
    t=root;
    while(t->next) {
        printf("�̸�: \t%s\t��ȣ:\t%s\n", t->next->name, t->next->phone); 

        t = t->next; 
    } 
    t=root;
    while(t->next) {
        temp = t->next;
        t=t->next; 
        free(temp); 
    } 
    free(root);
} 
// ��ü ��ȣ�� ����Ѵ�.
void showAll(pList list) {
    pBook t = list->head; 
    while(t->next) {
        printf("�̸�: \t%s\t��ȣ:\t%s\n", t->next->name, t->next->phone); 
        t = t->next; 
    } 
} 
// ����Ʈ�� ��� ��带 �����Ѵ�.
void quitNode(pList list) { 
    pBook t=list->head;
    pBook temp;
  
    while(t->next) {
        temp = t->next;
        t=t->next; 
        free(temp); 
    } 
    free(list->head);
}
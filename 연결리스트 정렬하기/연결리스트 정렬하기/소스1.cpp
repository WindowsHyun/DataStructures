#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
// 전화번호 구조체를 Book 으로 재정의
typedef struct Phone Book;
// 전화번호 구조체의 포인터 pBook
typedef struct Phone *pBook;
// 전화번호 구조체 이름, 전화번호, 다음 구조체 포인터 next 
struct Phone { 
    char name[20]; 
    char phone[20]; 
    pBook next; 
}; 
// 연결리스트 구조체를 List로 재정의
typedef struct phoneList List;
// 연결리스트 구조체의 포인터 pList
typedef struct phoneList *pList;
// 연결리스트 구조체 : head와 tail을 가지고 있다.
struct phoneList {
    pBook head;
    pBook tail;
};  
// 새노드를 만들고 포인터를 NULL로 초기화 시킨다.
pBook makeNode();
// 전화번호를 중복검사를 하지 않고, 이름, 번호를 입력받아 삽입한다.
// 노드들은 입력받은 순서대로 되어있다.
void insertNode(pList); 
// 이름을 입력받아 이름을 가진 노드를 삭제한다.
// 같은 이름이 있을 경우 먼저 발견한 노드만 삭제한다.
void deleteNode(pList); 
// 이름으로 찾은 전화번호를 보여준다.
void searchNode(pList); 
// 이름순으로 전화번호부를 보여준다.
void showByNames(pList); 
// 번호순으로 전화번호부를 보여준다.
void showByPhoneNumber(pList); 
// 입력된 순으로 전화번호부를 보여준다.
void showAll(pList); 
// 모든 노드들을 삭제한다.
void quitNode(pList); 
int main() { 
    // 전화번호부 리스트 list
    pList list;
    // 메뉴선택을 위한 변수, 7을 입력하면 종료한다.
    int menu=1; 

    // 리스트를 초기화한다. 더미 노드를 한개 만들어서 head와 tail이 이 노드를 가리키게 한다.
    // 이렇게 해서 항상 실제로 가리키기를 원하는 노드 보다 앞의 노드를 가지고 찾아다니면
    // 어떤 위치에서든디 삽입과 삭제를 할 수 있다.
    // 또 이중 포이터를 사용해야하는 번거러움을 피할 수가 있다.
    // head는 리스트의 시작하는 노드(항상 더미노드)를 가리킨다.
    // tail은 리스트의 맨 마지막 노드를 가리킨다. 처음에는 더미노드를 가리키다가,
    // 실제로 노드가 삽입되면 가장 나중에 삽입된 노드를 가리키게 된다.
    // tail 을 이용해서 우리는 새로 삽입되는 노드를 가장 뒤에 바로 삽일할 수 있다.
    list=(pList)malloc(sizeof(List));
    list->head=makeNode();
    list->tail=list->head;

    // 메뉴를 보여주고 선택을 입력 받는다.
    while(menu!=7) { 
        puts("*************"); 
        puts("* 1. 입력: "); 
        puts("* 2. 삭제: "); 
        puts("* 3. 검색: "); 
        puts("* 4. 이름순 전체출력: "); 
        puts("* 5. 전화번호순 전체출력: "); 
        puts("* 6. 전체출력:"); 
        puts("* 7. 끝내기"); 
        puts("*************"); 
        printf("선택="); 
        scanf("%d", &menu); 
        fflush(stdin); 
        switch(menu) { 
            case 1: 
                // 삽입
                insertNode(list); 
                break; 
            case 2: 
                // 삭제
                deleteNode(list); 
                break; 
            case 3: 
                // 검색
                searchNode(list); 
                break; 
            case 4: 
                // 이름순
                showByNames(list); 
                break; 
            case 5: 
                // 전화번호순
                showByPhoneNumber(list); 
                break; 
            case 6: 
                // 전체출력
                showAll(list); 
                break; 
            case 7: 
                // 종료
                quitNode(list); 
                break; 
        } 
    }
    // 마지막으로 list를 free시킨다.
    free(list);

    return 0;
} 
// 새노드를 만든다.
pBook makeNode() { 
    pBook p;

    p=(pBook)malloc(sizeof(Book));
    strcpy(p->name,"");
    strcpy(p->phone,"");
    p->next=NULL;
    return p;
}
// 노드를 복사한다.
pBook copyNode(pBook q) { 
    pBook p;

    p=(pBook)malloc(sizeof(Book));
    strcpy(p->name,q->name);
    strcpy(p->phone,q->phone);
    p->next=NULL;
    return p;
}
// 이름과 번호를 입력받아 새노드를 삽입한다.
void insertNode(pList list) {
    pBook t=list->head; 
    pBook newnode = makeNode(); 
    printf("이름을 입력하세요 : "); 
    gets(newnode->name); 
    fflush(stdin); 
    printf("번호를 입력하세요 : "); 
    gets(newnode->phone); 
    fflush(stdin); 
    list->tail->next=newnode;
    list->tail=newnode;
} 
// 이름을 입력받아 그 노드를 찾아서 삭제한다.
void deleteNode(pList list) {
    pBook t = list->head;
    pBook temp; 
    char str[20]={0,}; 
    printf("이름을 입력하세요 : "); 
    gets(str); 
    fflush(stdin); 
    while(t->next) {
        // 여기서 t->next->name과 str을 비교한 것에서
        // 실제로 가리키는 노드의 한칸 앞의 포인터를 가지고
        // 찾는다는 의미를 알 수 있다.
        if(strcmp(t->next->name,str)==0) {
            temp = t->next; 
            // 우리가 찾은 노드가 temp노드 이다. 이노드가 마지막 노드라면 tail을 수정해 주어야 한다.
            if(list->tail==temp) list->tail=t;
            // t->next를 t->next->next로 바꾸어 준다.
            // 이렇게 해주면 temp는 리스트 상에서 사라지게 된다.
            t->next=t->next->next; 
            // temp를 free시켜준다.
            free(temp);
            return;
        } 
        t=t->next;
    }
} 
// 이름으로 전화번호를 찾는다.
void searchNode(pList list) {
    pBook t = list->head;
    char str[20]={0,}; 
    printf("이름을 입력하세요 : "); 
    gets(str); 
    fflush(stdin); 
    while(t->next) {
        if(strcmp(t->next->name,str)==0) {
            printf("이름: \t%s\t번호:\t%s\n", t->next->name, t->next->phone); 

            return;
        } 
        t=t->next;
    }
} 
// 이름순으로 정렬하기 
void showByNames(pList list) {
    pBook t = list->head;
    pBook temp;
    pBook root=makeNode();
    pBook s=root;
    int comp;
 
    // 전화번호리스트를 처음부터 끝까지 가면서
    // 새로운 리스트 root에 이름순으로 삽입을 한다.
    while(t->next) {
        // 먼저 현재 노드를 복사한다.
        temp=copyNode(t->next);
        // 새로운 리스트 root의 처음부터 시작하여
        s=root;
        // temp의 이름과 root에서 시작하는 노드의 이름을 비교한다.
        while(s->next) {
            comp=strcmp(s->next->name, temp->name);
            // temp의 이름이 root에서 시자하는 현재 노드의 이름보다 작다면
            if(comp>=0) {
                // s->next 앞에 temp를 끼워 넣어야 한다.
                // 따라서 temp->next는 s->next가 되어야 한다.
                temp->next=s->next;
                break;
            }
            // 만약 temp의 이름이 현재노드의 이름보다 크다면 다음 노드로 간다.
            else s=s->next;
        }
        // s->next앞에 temp를 끼워 넣어야 하므로
        // s->next에 temp를 넣어 주면 된다.
        s->next=temp;
        // 원래 전화번호부에서 남아있는 노드를 처리히기 위해서 t의 값을 다음 노드로 이동시킨다.
        t=t->next;
    }
    // 새로 만들어진 root리스트를 모두 출력해 준다.
    t=root;
    while(t->next) {
        printf("이름: \t%s\t번호:\t%s\n", t->next->name, t->next->phone); 

        t = t->next; 
    }
    // 새로 만들어진 root리스트를 모두 삭제해 준다. 
    t=root;
    while(t->next) {
        temp = t->next;
        t=t->next; 
        free(temp); 
    } 
    free(root);
} 
// 번호순 출력도 이름순 출력과 같다.
// 단지 비교할 때 이름대신 번호를 사용하는 것만 다른다.
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
        printf("이름: \t%s\t번호:\t%s\n", t->next->name, t->next->phone); 

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
// 전체 번호를 출력한다.
void showAll(pList list) {
    pBook t = list->head; 
    while(t->next) {
        printf("이름: \t%s\t번호:\t%s\n", t->next->name, t->next->phone); 
        t = t->next; 
    } 
} 
// 리스트의 모든 노드를 삭제한다.
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
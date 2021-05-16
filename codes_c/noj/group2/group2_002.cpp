#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode { //双向循环链表

char data;

struct LinkNode *prior;

struct LinkNode *next;

int freq;

} DuLNode, *DuLinkedList;

void createLinkedList(DuLinkedList &L, int n) { //创建双向循环链表

int i; DuLinkedList p,q;

L = (DuLinkedList)malloc(sizeof(DuLNode));
q = L;
L->next = L->prior = L; L->freq = 0;

for(i=n; i>0; i--) {

p = (DuLinkedList)malloc(sizeof(DuLNode));

if(i!=1)scanf("%c ",&(p->data));
if(i==1)scanf("%c",&(p->data));

p->freq = 0; p->prior = L->prior; p->next = L;

L->prior->next = p;L->prior = p;



}

}

void printList(DuLinkedList L) { //打印双向循环链表

DuLinkedList p = L->next;

while(p != L) {

if(p->next!=L)
{
    printf("%c ", p->data); p = p->next;
}
else{
    printf("%c",p->data);p=p->next;
}
}

}

void locate(DuLinkedList &L, char x) { //查找位置，并变换位置

DuLinkedList q , p = L->next;

while(p != L && p->data != x) p = p->next;

if(p == L) return ;

p->freq += 1; q = p->prior;

while(q->freq < p->freq && q != L) {

p->prior = q->prior; q->next = p->next; q->prior->next = p; p->next->prior = q;

q->prior = p; p->next = q; q = p->prior;

}

}

int main() {

DuLinkedList L; int n;
int searchNum;
char tempC;
scanf("%d%d", &n,&searchNum);
char c = getchar(); //目的：消除上一次的回车符

createLinkedList(L,n);
getchar();

while(searchNum--)
{
    if(searchNum!=0)scanf("%c ",&tempC);
    else scanf("%c",&tempC);
  //  printf("get %c\n",tempC);
    locate(L,tempC);
}

printList(L); 
return 0;
}
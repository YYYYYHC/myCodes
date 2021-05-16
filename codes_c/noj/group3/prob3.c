#include<stdio.h>
#include<stdlib.h>

int MAXNUM;

typedef int DataType;

typedef struct Node
{
    DataType info;
    struct Node * link;
}Node,*PNode;


typedef struct SeqQueue
{
    PNode rear,front;
    int PreLength;
    int MaxLength;
}SeqQueue,*PSeqQueue;

PSeqQueue creatEmptyQueue_seq(int MaxLength)
{
    PSeqQueue paqu = (struct SeqQueue*)malloc(sizeof(SeqQueue));
    if(paqu!=NULL)
    {
        paqu->rear=NULL;
        paqu->front=NULL;
        paqu->MaxLength = MaxLength;
        paqu->PreLength = 0;
    }
    else
        printf("Out of Space!\n");
    return paqu;
}

int isEmptyQueue_seq(PSeqQueue paqu)
{
    return(paqu->front == NULL);
}

void enQueue_seq(PSeqQueue paqu,DataType x)
{
    if(paqu->PreLength == paqu->MaxLength)
        printf("Full Queue!\n");
    else{
        paqu->PreLength++;
        PNode newNode = (Node*)malloc(sizeof(Node));
        newNode->info = x;
        newNode->link=NULL;
        if(paqu->front==NULL)
        {
            paqu->front = newNode;
            paqu->rear = newNode;
        }
        else{
            paqu->rear->link = newNode;
            paqu->rear = newNode;
        }
       
    }
}

void deQueue_seq(PSeqQueue paqu)
{
    if(isEmptyQueue_seq(paqu))
        printf("empty queue dequeue!\n");
    else{
        PNode p = paqu->front;
        paqu->front = paqu->front->link;
        free(p);
    }
}

int isFullQUeue_seq(PSeqQueue paqu)
{
    return (paqu->MaxLength==paqu->PreLength);
}

DataType frontQueue_seq(PSeqQueue paqu)
{
    if(isEmptyQueue_seq(paqu))
        printf("empty queue front!\n");
    else{
        return paqu->front->info;
    }
    return 0;
}

int main()
{
    scanf("%d",&MAXNUM);
    PSeqQueue p=creatEmptyQueue_seq(MAXNUM);
    int t;
    char yn[3];
    char tc;
    getchar();
    while(1)
    {
        tc = getchar();
        if(tc=='\n') break;
        else if(tc!=' ') 
        {
            t = tc-'0'; 
            enQueue_seq(p,t);
        }
    }
    scanf("%s",yn);
    int outNum;
    scanf("%d",&outNum);
    while(frontQueue_seq(p)!=outNum) deQueue_seq(p);
    deQueue_seq(p);
    int first = frontQueue_seq(p);
    while(!isEmptyQueue_seq(p))
    {
        printf("%d ",frontQueue_seq(p));
        deQueue_seq(p);
    }
    printf("\n%d",first);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 100

typedef int DataType;

typedef struct SeqQueue
{
    DataType q[MAXNUM];
    int front,rear;
}SeqQueue,*PSeqQueue;

PSeqQueue creatEmptyQueue_seq()
{
    PSeqQueue paqu = (struct SeqQueue*)malloc(sizeof(SeqQueue));
    if(paqu!=NULL)
    {
        paqu->front=0;
        paqu->rear=0;
    }
    else
        printf("Out of Space!\n");
    return paqu;
}

int isEmptyQueue_seq(PSeqQueue paqu)
{
    return(paqu->front == paqu->rear);
}

void enQueue_seq(PSeqQueue paqu,DataType x)
{
    if((paqu->rear+1)%MAXNUM == paqu->front)
        printf("Full Queue!\n");
    else{
        paqu->q[paqu->rear] = x;
        paqu->rear = (paqu->rear+1)%MAXNUM;
    }
}

void deQueue_seq(PSeqQueue paqu)
{
    if(isEmptyQueue_seq(paqu))
        printf("empty queue dequeue!\n");
    else{
        paqu->front = (paqu->front+1)%MAXNUM;
    }
}

DataType frontQueue_seq(PSeqQueue paqu)
{
    if(isEmptyQueue_seq(paqu))
        printf("empty queue front!\n");
    else{
        return paqu->q[paqu->front];
    }
    return 0;
}
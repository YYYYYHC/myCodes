#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct SeqQueue{
    DataType *base;
    int front,rear;
    int maxLength;
}SeqQueue,*PSeqQueue;

PSeqQueue createEmptyQueue_seq(int MAXNUM)
{
    PSeqQueue plau= (struct SeqQueue*)malloc(sizeof(struct SeqQueue));
    if(plau!=NULL)
    {
        plau->base = (DataType*)malloc(sizeof(DataType)*MAXNUM);
        plau->front = 0;
        plau->rear = 0;
        plau->maxLength = MAXNUM;
    }
    else{
        printf("Out of Space! Return NULL!\n");
    }
    return plau;
}

int isEmptyQueue_seq(PSeqQueue plau)
{
    return(plau->front==plau->rear);
}

void enQueue_seq(PSeqQueue plau, DataType x)
{
    if((plau->rear+1)%plau->maxLength == plau->front){
        plau->base[plau->rear] = x;
    }
    else{
        plau->base[plau->rear] = x;
        plau->rear = (plau->rear+1)%plau->maxLength;
    }
}

DataType deQueue_seq(PSeqQueue plau)
{
    if(isEmptyQueue_seq(plau))
        printf("Empty deQueue! Return 0!\n");
    else{
        DataType temp = plau->base[plau->front];
        plau->front = (plau->front+1)%plau->maxLength;
        return temp;
    }
    return 0;
}

DataType front_seq(PSeqQueue plau)
{
    if(isEmptyQueue_seq(plau))
        printf("empty fornt!return 0!\n");
    else{
        return plau->base[plau->front]; 
    }
    return 0;
}



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




int sumQueue_seq(PSeqQueue plau)
{
    int res=0;
    if(isEmptyQueue_seq(plau))
    {
        return 0;
    }
    else{
        for(int i=0;i<plau->maxLength;i++)
        {
            res+=plau->base[i];
        }
    }
    
    return res;
}

void outQueue_seq(PSeqQueue plau)
{
    for(int i=plau->front;i!=plau->rear;i=(i+1)%plau->maxLength)
    {
        printf("%d ",plau->base[i]);
    }
    printf("%d",plau->base[plau->rear]);
    printf("\n");
}

int main()
{
    int max,k;
    scanf("%d%d",&max,&k);
    PSeqQueue p=createEmptyQueue_seq(k);
    int t;
    for(int i=0;i<k-1;i++)
        enQueue_seq(p,0);
    enQueue_seq(p,1);
    // outQueue_seq(p);
    while(sumQueue_seq(p)<=max)
    {
        t = sumQueue_seq(p);
        deQueue_seq(p);
        p->rear=(p->rear+1)%p->maxLength;
        enQueue_seq(p,t);
        // outQueue_seq(p);
    }
    outQueue_seq(p);
}
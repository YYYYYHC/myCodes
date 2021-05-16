#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct QNode{
    DataType info;
    struct QNode * link;
}Node,*PNode;

typedef struct LinkQueue
{
    PNode front,rear;
}LinkQueue,*PLinkQueue;

PLinkQueue creatEmptyQueue_link()
{
    PLinkQueue plqu;
    plqu = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
    if(plqu!=NULL)
    {
        plqu->front = NULL;
        plqu->rear = NULL;
    }   
    else
        printf("Out of Space!\n");
    return plqu;
}

int isEmptyQueue_link(PLinkQueue plqu)
{
    return(plqu->front==NULL);
}

void enQueue_link(PLinkQueue plqu,DataType x)
{
    PNode p=(Node*)malloc(sizeof(Node));
    if(p!=NULL)
    {
        p->info = x;
        p->link = NULL;
        if(plqu->front == NULL){
            plqu->front = p;
            plqu->rear = p;
        }
        else{
            plqu->rear->link = p;
            plqu->rear = p;
        }
    }
    else
        printf("Out of Space!\n");
}
void deQueue_link(PLinkQueue plqu)
{
    PNode p;
    if(plqu->front == NULL)
        printf("Empty Queue!\n");
    else{
        p = plqu->front;
        plqu->front = plqu->front->link;
        free(p);
    }
}

DataType frontQueue_link(PLinkQueue plqu)
{
    return plqu->front->info;
}
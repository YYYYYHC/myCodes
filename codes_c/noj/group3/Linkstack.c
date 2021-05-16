#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

struct  Node
{
    DataType info;
    struct Node * link;
};

typedef struct Linkstack
{
    struct Node *top;
}LinkStack,*PLinkStack;

PLinkStack createEmptyStack_link()
{
    PLinkStack plstack;
    plstack = (struct Linkstack*)malloc(sizeof(struct Linkstack));
    if(plstack == NULL)
        printf("OUt of Space!\n");
    else
        plstack->top = NULL;
    return plstack;
}

int isEmptyStack_link(PLinkStack plstack)
{
    return (plstack->top == NULL);
}

void push_link(PLinkStack plstack,DataType x)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL)
        printf("Out of Space!\n");
    else{
        p->info = x;
        p->link = plstack->top;
        plstack->top = p;
    }
}

DataType pop_link(PLinkStack plstack)
{
    struct Node *p;
    DataType elem;
    if(isEmptyStack_link(plstack))
        printf("Empty stack pop\n");
    else{
        p = plstack->top;
        elem = p->info;
        plstack->top = plstack->top->link;
        free(p);
    }

    return elem;
}

DataType top_link(PLinkStack plstack)
{
    if(isEmptyStack_link(plstack))
        printf("Empty Stack!\n");
    else{
        return plstack->top->info;
    }
    return 0;
}
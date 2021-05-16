#include<stdio.h>
#include<stdlib.h>

#define INCREMENT 8
#define INITSIZE 100
typedef struct  SqStack
{
    int *base;
    int *top;
    int stackSize;
}SqStack,*PSqStack;

int InitStack(PSqStack s)
{
    s->base = (int*) malloc(sizeof(int)*INITSIZE);
    if(s->base == NULL)
        printf("Out of Space!\n");
    else{
        s->top = s->base;
        s->stackSize = INITSIZE;
    }
    return 1;
}

int isEmptyStack_sq(PSqStack s)
{
    return(s->top == s->base);
}

void push_sq(PSqStack s, int x)
{
    if(s->top - s->base >= s->stackSize){
        s->base = (int*)realloc(s->base,(s->stackSize+(INCREMENT))*sizeof(int));
    }
    if(s->base == NULL)
        printf("During the process of pushing the element, the space room is not enough!\n");
    else{
        s->top = s->base + s->stackSize;
        s->stackSize+=INCREMENT;
    }
    s->top++ ;
    *s->top = x;
}

int pop_sq(PSqStack s)
{
    if(isEmptyStack_sq(s))
        {
            printf("Underflow!\n");
            return -1;
        }
    else{
        int temp;
        temp = *s->top;
        s->top --;
        return temp;
    }
}

int top_sq(PSqStack s)
{
    if(isEmptyStack_sq(s))
    {
        printf("no element in the stack!\n");
        return -1;
    }
    else{
        return *s->top;
    }
}
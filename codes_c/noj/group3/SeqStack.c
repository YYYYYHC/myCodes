#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 100

typedef struct SeqStack
{
    int s[MAXNUM];
    int top;
}SeqStack,*PSeqStack;

PSeqStack createEmptyStack_seq()
{
    PSeqStack pastack;

    pastack = (PSeqStack)malloc(sizeof(SeqStack));
    if(pastack==NULL)
        printf("Out space!!\n");
    else 
        pastack->top = -1;

    return pastack;
}

int isEmptyStack_seq(PSeqStack pastack)
{
    return (pastack->top == -1);
}

void push_seq(PSeqStack pastack, int x)
{
    if(pastack->top >= MAXNUM-1)
        printf("overflow\n");
    else{
        pastack->top = pastack->top + 1;
        pastack->s[pastack->top] = x;
    }
}

int pop_seq(PSeqStack pastack)
{
    int temp;
    if(isEmptyStack_seq(pastack))
        printf("Underflow!\n");
    else{
        temp = pastack->s[pastack->top];
        pastack->top = pastack->top -1;
    }
    return temp;
}

int top_seq(PSeqStack pastack)
{
    if(isEmptyStack_seq(pastack))
        printf("Empty Stack!\n");
    else
        return pastack->s[pastack->top];
}
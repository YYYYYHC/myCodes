#include "SqStack.c"

int main()
{
    PSqStack PtestSq;
    InitStack(PtestSq);
    printf("isEmptyNum=%d\n",isEmptyStack_sq(PtestSq));
    push_sq(PtestSq,1);
    printf("isEmptyNum=%d\n",isEmptyStack_sq(PtestSq));
    printf("top of stack is %d\n",top_sq(PtestSq));
    printf("pop the stack and get %d \n",pop_sq(PtestSq));
    printf("isEmptyNum=%d\n",isEmptyStack_sq(PtestSq));

    return 0;
}
#include "LinkStack.c"

int main()
{
    PLinkStack PtestLk;
    printf("isEmptyNum=%d\n",isEmptyStack_link(PtestLk));
    push_link(PtestLk,1);
    printf("isEmptyNum=%d\n",isEmptyStack_link(PtestLk));
    printf("top of stack is %d\n",top_link(PtestLk));
    printf("pop the stack and get %d \n",pop_link(PtestLk));
    printf("isEmptyNum=%d\n",isEmptyStack_link(PtestLk));
    return 0;
}
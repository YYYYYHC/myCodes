#include "Linkstack.c"
#include<string.h>

int main()
{
    PLinkStack s = createEmptyStack_link();
    char x[1000];
    scanf("%s",x);
    for(int i=0; i<strlen(x);i++)
    {
        if(x[i]=='('||x[i]=='['||x[i]=='{')
            push_link(s,x[i]);
        else if(x[i]==')'||x[i]==']'||x[i]=='}'){
            if(top_link(s)=='('&&x[i]==')'||top_link(s)=='['&&x[i]==']'||top_link(s)=='{'&&x[i]=='}'){
                pop_link(s);
            }
            else{
                printf("no\n");
                return 0;
            }
        }
    }
    printf("yes\n");
    return 0;
}
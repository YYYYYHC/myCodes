#include<string.h>

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
        return '!';
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
//< = > nan  -1 0 1 100
int priMartix[7][7] ={
{1,1,-1,-1,-1,1,1},
{1,1,-1,-1,-1,1,1},
{1,1,1,1,-1,1,1},
{1,1,1,1,-1,1,1},
{-1,-1,-1,-1,-1,0,100},
{1,1,1,1,100,1,1},
{-1,-1,-1,-1,-1,100,-1},
};

int findPriority(char c1, char c2)
{
    int x1,x2;
    if(c1=='+')x1=0;
    else if(c1=='-')x1=1;
    else if(c1=='*')x1=2;
    else if(c1=='/')x1=3;
    else if(c1=='(')x1=4;
    else if(c1==')')x1=5;
    else if(c1=='#')x1=6;
    
    if(c2=='+')x2=0;
    else if(c2=='-')x2=1;
    else if(c2=='*')x2=2;
    else if(c2=='/')x2=3;
    else if(c2=='(')x2=4;
    else if(c2==')')x2=5;
    else if(c2=='#')x2=6;
    
    return priMartix[x1][x2];
}

int main()
{  
    char ans[100];
    int ansTag = 0;
    char x[100];
    int i=0;
    scanf("%s",x);
    x[strlen(x)]='#';
    PLinkStack OPTR = createEmptyStack_link();
    PLinkStack OPND = createEmptyStack_link();
    PLinkStack ANS = createEmptyStack_link();

    push_link(OPTR,'#');
    while(top_link(OPTR)!='#'||x[i]!='#')
    {
        if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'||x[i]=='('||x[i]==')'||x[i]=='#'){
            if(isEmptyStack_link(OPTR)){
                push_link(OPTR,x[i]);
                i++;
            }
            else{
                int temp = findPriority(top_link(OPTR),x[i]);
                if(temp==-1){
                    push_link(OPTR,x[i]);
                    i++;
                }
                else if(temp==0){
                    pop_link(OPTR);
                    i++;
                }
                else if(temp==1){
                    char x=pop_link(OPND);
                    char y=pop_link(OPND);
                    if(y!='!')push_link(ANS,y);
                    if(x!='!')push_link(ANS,x);
                    push_link(ANS,pop_link(OPTR));
                }
                else{
                    printf("Error occur!\n");
                }
            }
        }
        else{
            push_link(OPND,x[i]);
            i++;
        }
    }

    while(!isEmptyStack_link(ANS))
    {
        ans[ansTag]=pop_link(ANS);
        ansTag++;
    }

    for(int i=ansTag-1;i>=0;i--)
    {
        printf("%c",ans[i]);
    }
    printf("\n");
    return 0;
}
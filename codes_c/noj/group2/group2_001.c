#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node * next;
}Node,*NodeList;

NodeList InitLinkList(int length)
{
    Node *init = (Node*)malloc(sizeof(Node));
    Node *p,*a;
    p =init;
    for(int i=0;i<length;i++)
    {
        a = (Node*)malloc(sizeof(Node));
        scanf("%d",&a->data);
        p->next = a;
        p = a;
    }
    p->next = NULL;
    return init;
}

void OutputLinkList(Node *Head)
{
    Node *temp = Head->next;
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* Merge(Node* A,Node* B)
{
    A=A->next;
    B=B->next;

    printf("*");
    Node* tempA =A;
    Node* tempB =B;
    Node* Head =(Node*)malloc(sizeof(Node));

    printf("**");
    if(A->data>B->data)
    {
        Head = A;
        tempA = A->next;
    }
    else
    {
        Head =B;
        tempB = B->next;
    }
    Head->next = NULL;

    Node* tempH = Head;
    printf(" %d ",tempH->data);
    int tA = tempA ? 1 : 0;
    int tB = tempB ? 1 : 0;
    while(tB||tA)
    {
        if( (tB!=0&&tA==0) || tempA->data <= tempB->data)
        {
            Node *temp1 = tempH;
            tempH = tempB;
            tempH->next = temp1;
            Head = tempH;
            if(tempB->next)tempB = tempB->next;
            else tB=0;
        }
        else if((tA!=0&&tB==0) || tempB->data < tempA->data)
        {
            Node* temp2 = tempH;
            tempH = tempA;
            tempH->next = temp2;
            Head = tempH;
            if(tempA->next)tempA = tempA->next;
            else tA=0;
        }
    }
    return Head; 
}

int main()
{
    int m,n;
    int aA[100],aB[100];
    int i;
    scanf("%d",&m);
    Node* A = InitLinkList(m);
    scanf("%d",&n);
    Node* B = InitLinkList(n);

    printf("doingC\n");
    Node* C = (Node*)malloc(sizeof(Node)); 
    C = Merge(A,B);

    printf("jobsDone\n");
    // OutputLinkList(C);  
    
    // OutputLinkList(A);
    // OutputLinkList(B);
    // free(C);
    free(A);
    free(B);
    
    return 0;
}
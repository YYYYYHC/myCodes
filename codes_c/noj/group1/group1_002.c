#include <stdio.h>
#include<stdlib.h>

typedef struct LinkList
{
    int data;
    struct LinkList * next;
}Link;


int main()
{
    int elenum=0;
    int theArray[100]={0};
    Link *p = (Link*)malloc(sizeof(Link));
    Link *temp = p;

    scanf("%d",&elenum);
    
    for(int i=0;i<elenum;i++)
    {
        scanf("%d",&theArray[i]);
        Link *a =(Link*)malloc(sizeof(Link));
        a->data = theArray[i];
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    
    //数组逆序
    int temp2;
    for(int i=0;i<=(elenum-1)/2;i++)
    {
        temp2 = theArray[i];
        theArray[i] = theArray[elenum-1-i];
        theArray[elenum-1-i] = temp2;
    }

    //单链表逆序
    Link *temp_pre = p;
    Link *temp_now = p->next;
    Link *temp_next = p->next->next;
    
    while(temp_now)
    {
        
        temp_now -> next = temp_pre;
        temp_pre = temp_now;
        temp_now = temp_next;
        if(!temp_now) break;
        temp_next = temp_now->next;
        
    }
    p->next = temp_pre;

    //输出
    Link *temp1 = p;
    for(int i=0;i<elenum;i++)
    {
        temp1 = temp1->next;
        printf("%d ",temp1->data);
        
        
    }
    printf("\n");

    for(int i=0;i<elenum;i++)
    {
        printf("%d ",theArray[i]);
    }


    return 0;
}
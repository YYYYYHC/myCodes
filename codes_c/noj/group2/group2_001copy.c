#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node
{
 datatype data;
 struct node *next;
}listnode,*linklist;
 
linklist creatlist(int a[],int n)//创建单链表
{
 int i;
 linklist head=(linklist)malloc(sizeof(listnode));
 linklist p,q;
 q=head;
  for(i=0;i<n;i++)
 {
        p=(linklist)malloc(sizeof(listnode));
        p->data=a[i];
  q->next=p;
  q=p;
 }
 q->next=NULL;
 return head;
}
void printlist(linklist head)//输出单链表
{
    int i,c[100];
 linklist p;
 for(p=head->next,i=0;p;p=p->next,i++)
    c[i]=p->data;
    for(i=i-1;i>=0;i--)
    printf("%d ",c[i]);
 
}
linklist listadd(linklist la,linklist lb)//两链表合并
{
 linklist pb,pa,p,q;
 linklist head=(linklist)malloc(sizeof(listnode));
 q=head;
 for(pa=la->next,pb=lb->next;pa&&pb;)
 {
  if(pa->data>=pb->data)
  {
   p=(linklist)malloc(sizeof(listnode));
   p->data=pb->data;
   q->next=p;
   q=p;
   pb=pb->next;
  }
  else if(pa->data<pb->data)
  {
   p=(linklist)malloc(sizeof(listnode));
   p->data=pa->data;
   q->next=p;
   q=p;
   pa=pa->next;
  }
 
  if(pa==NULL&&pb!=NULL)
  {
   while(pb!=NULL)
   {
    p=(linklist)malloc(sizeof(listnode));
       p->data=pb->data;
       q->next=p;
       q=p;
       pb=pb->next;
   }
  }
  if(pa!=NULL&&pb==NULL)
  {
   while(pa!=NULL)
   {
    p=(linklist)malloc(sizeof(listnode));
       p->data=pa->data;
       q->next=p;
       q=p;
    pa=pa->next;
   }
  }
 }
 q->next=NULL;
 return head;
}
 
int main()
{
 int n,m,i;
 int a[100],b[100];
 scanf("%d %d",&n,&m);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 for(i=0;i<m;i++)
 scanf("%d",&b[i]);
 linklist la=creatlist(a,n);
 linklist lb=creatlist(b,m);
 linklist lc=listadd(la,lb);
 printlist(lc);
 return 0;
}


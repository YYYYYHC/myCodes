#include <stdio.h>
#include <stdlib.h>

int main()
{
 int a,b,n=1,p,q;
 double sum=0,t=0;
 scanf("%d %d",&a,&b);
 for(n=1;;n++){
    t=t+1.0/n;
    sum=sum+1.0/t;

    if(sum>a)break;
 }
 p=n;
 t=0;
 for(n++;;n++){
    t=t+1.0/n;
    sum=sum+1.0/t;
    if(sum>=b)break;
 }
 q=n-1;
 if(p==q)printf("%d",q);
 else printf("%d %d",p,q);
return 0;
}
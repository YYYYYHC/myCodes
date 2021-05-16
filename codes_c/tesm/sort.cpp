#include<algorithm>
using namespace std;
int main()
{
    int a[200],n,i;
    scanf("%d\n",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=1;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
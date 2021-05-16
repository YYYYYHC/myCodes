#include<iostream>

using namespace std;
int q,n;
int a;
int ans[101];

int main()
{
    cin>>q;
    int temp=0;
    for(int i=0;i<q;i++)
    {
        cin>>n;
        temp=0;
        for(int j=0;j<n;j++)
        {
            cin>>a;temp+=a;
        }
        if((temp/n)*n>=temp) ans[i]=temp/n;
        else ans[i]=temp/n+1;
    }
    for(int k=0;k<q;k++) cout<<ans[k]<<endl;
    return 0;
}
#include<iostream>
#include<math.h>

using namespace std;
int n;
int binary[10000][10000];

void tobinary(int num,int hang)
{
        for(int j=0;j<n;j++)
        {binary[hang][j]=num%2;
        num/=2;}
}


int main()
{
    cin>>n;
    for(int i=0;i<pow(2,n);i++)
    tobinary(i,i);
    for(int ii=0;ii<pow(2,n);ii++)
       { for(int jj=0;jj<n;jj++)
        cout<<binary[ii][n-jj-1];
        cout<<endl;}
    return 0;
}
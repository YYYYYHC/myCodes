#include<iostream>
#include<stdio.h>

using namespace std;
char A[2000],B[2000];
int dp[2000][2000];
int lena,lenb;

void myInit()
{
    scanf("%s",A);
    lena=strlen(A);
    scanf("%s",B);
    lenb=strlen(B);
    for(int i=1;i<=lena;i++) dp[0][i+1]=A[i-1];
    for(int j=1;j<=lenb;j++) dp[j+1][0]=B[j-1];
}

void pointOut()
{
    cout<<endl;
    for(int i=0;i<=lenb+1;i++)
        {for(int j=0;j<=lena+1;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;}   
}

int  myMax(int a,int b)
{
    return a>b?a:b;
}

void DP()
{
    for(int i=2;i<=lenb+1;i++)
    {
        for(int j=2;j<=lena+1;j++)
        {
            if(A[j-2]==B[i-2]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=myMax(dp[i-1][j],dp[i][j-1]);
          //  pointOut();
        }
    }
}

int main()
{
    myInit();
   // pointOut();
    DP();
    cout<<dp[lenb+1][lena+1]<<endl;
    return 0;
}
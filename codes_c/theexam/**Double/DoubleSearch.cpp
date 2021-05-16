#include<iostream>

using namespace std;

int n,m;
int InputNum[10001];
int SearchNum[50001];

bool DFS(int startNum,int endNum,int searchnum)
{
    if(startNum>endNum) return 0;
    else
    {
        int midNum=startNum+(endNum-startNum)/2; //防止整数溢出
        if(InputNum[midNum]==SearchNum[searchnum]||InputNum[startNum]==SearchNum[searchnum]||InputNum[endNum]==SearchNum[searchnum])
            return 1;
        else if(InputNum[midNum]>SearchNum[searchnum]) 
           return DFS(startNum,midNum-1,searchnum); //一定要有return
        else 
           return DFS(midNum+1,endNum,searchnum);
    }
}

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++) cin>>InputNum[i];
    cin>>m;
    for(i=0;i<m;i++) cin>>SearchNum[i];
    for(i=0;i<m;i++)
    {
        if(DFS(0,n-1,i)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
      //  cout<<"1"<<endl;
    }
    return 0;
}

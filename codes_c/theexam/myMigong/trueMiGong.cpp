#include<iostream>
#include<cstdio>
#include<cstring>
int a[1000][1000],book[1000][1000];
int p,q,m,n;
int flag=0;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//右//左//下//上//
using namespace std;
void dfs(int x,int y)//当前x,当前y,已经走过的步数
{
    int tx,ty;
    if(x==p&&y==q)
    {
        flag=1;
        return;
    }
    for(int k=0;k<4;k++)
    {
        tx=x+dir[k][0];
        ty=y+dir[k][1];
        if(tx>=m||ty>=n||ty<0||tx<0||a[tx][ty]==1)
        {
            continue;
        }
        if(book[tx][ty]==0)
        {
            book[tx][ty]=1;
            dfs(tx,ty);
            if(flag==1)return;
            book[tx][ty]=0;
        }
    }
}
int main()
{
    int i,j,startx,starty;
    //int m,n;//总共有几行几列
    cin>>m>>n;
    cin>>startx>>starty>>p>>q;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];
   book[startx][starty]=1;
   dfs(startx,starty);
   if(flag==0)cout<<"No"<<endl;
   else cout<<"Yes"<<endl;
   return 0;
 
}


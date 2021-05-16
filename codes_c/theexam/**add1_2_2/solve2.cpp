#include<iostream>
#include<queue>

using namespace std;
int m,n;
int step[100001],used[100001];

queue<int> q1;

int moveto(int num,int dir)
{
    if(dir==0) return num+1;
    if(dir==1) return num*2;
    if(dir==2) return num*num;
    return -1;
}

void BFS()
{
    int u,v,i;
    while(!q1.empty())
    {
        u=q1.front();
        q1.pop();
        for(i=0;i<3;i++){
            v=moveto(u,i);
        if(v==n) {cout<<step[u]+1<<endl;return ;}
           // cout<<"v="<<v<<endl;
        if(v<n && used[v]==0) 
        {
            step[v]=step[u]+1;
            used[v]=1;
            q1.push(v);}
        }
    }
}

int main()
{
    cin>>m>>n;
    q1.push(m);
    used[m]=1;
    BFS();
    return 0;
}
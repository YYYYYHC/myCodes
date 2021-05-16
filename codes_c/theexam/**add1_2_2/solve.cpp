#include<iostream>
#include<queue>

using namespace std;
int m,n;
int step[10001],used[10001];
queue<int > q1;

void myInit()
{
    cin>>m>>n;
    used[m]=1;
    q1.push(m);
}

int  moveto(int num,int dir)
{
    if(dir==0) return num+1;
    if(dir ==1 ) return num*2;
    if(dir ==2) return num*num;
    return-1;
}

void BFS()
{
    int u,v,i;
    while(!q1.empty())
    {
        u=q1.front();
        q1.pop();
        for(i=0;i<3;i++)
        {
            v=moveto(u,i);
            if(v==n){cout<<step[u]+1<<endl;return;}
            else if(used[v]==0 && v<n) 
            {
                used[v]=1;
                q1.push(v);
                step[v]=step[u]+1;
            }
        }
    }
}

int main()
{
    myInit();
    BFS();

    return 0;
}
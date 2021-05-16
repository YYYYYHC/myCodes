#include<iostream>

using namespace std;
int m,n,flag=0;
int theMpa[21][21],used[21][21];
int in[2],out[2];
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

void myInit()
{
    cin>>m>>n;
    cin>>in[0]>>in[1];
    cin>>out[0]>>out[1];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>theMpa[i][j];
    used[in[0]][in[1]]=1;
}


void DFS(int x,int y)
{  
    int tx=x,ty=y;
    if(x==out[0]&&y==out[1]) {flag=1;return ;}
    for(int i=0;i<4;i++)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(x+dir[i][0]<0||x+dir[i][0]>=m||y+dir[i][1]<0||y+dir[i][1]>=n||theMpa[x+dir[i][0]][y+dir[i][1]]==1)
            continue;
        if(used[x+dir[i][0]][y+dir[i][1]]==0){
            used[tx][ty]=1;
            DFS(tx,ty);
            if(flag==1) {return ;}
            used[tx][ty]=0;
        }
    }

}

int main()
{
    myInit();
  //  cout<<theMpa[1][0]<<endl;
    if(theMpa[in[0]][in[1]]==1) cout<<"No"<<endl;
 else{
    // cout<<"1"<<endl; 
      DFS(in[0],in[1]);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;}
    return 0;
}
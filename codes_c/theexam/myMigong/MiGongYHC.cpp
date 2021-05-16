#include<iostream>

using namespace std;
int m,n;
int flag=0;
int theMap[21][21];
int store[21][21];
int inPoint[2],outPoint[2];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void myInit()
{
    cin>>m>>n;
    cin>>inPoint[0]>>inPoint[1];
    cin>>outPoint[0]>>outPoint[1];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>theMap[i][j];
    store[inPoint[0]][inPoint[1]]=1;
}

void PointOut()
{
    cout<<endl;
    for(int i=0;i<m;i++)
       { for(int j=0;j<n;j++)
            cout<<(theMap[i][j] || store[i][j])<<" ";
    cout<<endl;}

}

void DFS(int x,int y)
{
    int tx=x,ty=y;
    store[x][y]=1;
    if(x==outPoint[0]&&y==outPoint[1]) 
    {flag=1;return ;}
    else{
        for(int i=0;i<4;i++)
        {
            if(theMap[tx+dir[i][0]][ty+dir[i][1]]==0 && tx+dir[i][0]>=0&&tx+dir[i][0]<m&&ty+dir[i][1]>=0&&ty+dir[i][1]<n&&store[tx+dir[i][0]][ty+dir[i][1]]==0){
                
              //  PointOut();
                tx=x+dir[i][0];//!!!!!!!!!!!注意
                ty=y+dir[i][1];
                store[tx][ty]=1;
               // cout<<endl<<"tx="<<tx<<" ty="<<ty<<" i="<<i<<endl;
                DFS(tx,ty);

                if(flag==1) {return ;}
                store[tx][ty]=0;
            }
          //  cout<<"good"<<endl;
        }
        return;


    }

}

int main()
{
    myInit();
    if(theMap[inPoint[0]][inPoint[1]]==1||theMap[outPoint[0]][outPoint[1]]==1) cout<<"No"<<endl;
    else{DFS(inPoint[0],inPoint[1]);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;}
}
#include<iostream>
#include<queue>

using namespace std;
int startPoint[2],endPoint[2];
int theMap[13][13];
char tempMap[13][13];
int road='.';
int wall='X';
int used[13][13];
int step[13][13];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue < int > qx;
queue < int > qy;

void printMap()
{
    for(int i=0;i<12;i++)
        {for(int j=0;j<12;j++)
        cout<<used[i][j];
         cout<<endl;}
    cout<<endl;
}

int myMin(int a, int b)
{
    return a<b?a:b;
}

void BFS()
{
    int ux,uy,vx,vy,i;
    while(!qx.empty()&&!qy.empty())
    {
        ux=qx.front();
        qx.pop();
        uy=qy.front();
        qy.pop();
        if(ux==endPoint[0]&&uy==endPoint[1])
        {
            cout<<step[ux][uy]<<endl;
            return;
        }
            for(i=0;i<4;i++)
            {
                vx=ux+dir[i][0];
                vy=uy+dir[i][1];
                if(vx==endPoint[0]&&uy==endPoint[1])
                {
                    cout<<step[ux][uy]+1<<endl;
                    return;
                }
                if(vx<0||vy<0||vx>11||vy>11||theMap[vx][vy]==wall) continue;
                if(used[vx][vy]==0)
                {
                    used[vx][vy]=1;
                    step[vx][vy]=step[ux][uy]+1;
                    qx.push(vx);
                    qy.push(vy);
                   // printMap();
                    //cout<<step[vx][vy]<<" ";
                }
            }
    }
    cout<<"error"<<endl;
}

void myInit()
{
    int i;
    cin>>startPoint[0]>>startPoint[1]>>endPoint[0]>>endPoint[1];
    startPoint[0]--;
    startPoint[1]--;
    endPoint[0]--;
    endPoint[1]--;
    qx.push(startPoint[0]);
    qy.push(startPoint[1]);
    for( i=0;i<12;i++)
        scanf("%s",tempMap[i]);
    for( i=0;i<12;i++)
        for(int j=0;j<12;j++)
            theMap[i][j]=int(tempMap[i][j]);
}


int main()
{
    myInit();
    BFS();
    return 0;
}
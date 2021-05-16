#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
 
int m,n;
int flag=0;
int in1,in2;
int out1,out2;
int maze[25][25];
int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
 
void DSF(int x,int y)
{
	if(x==out1 && y==out2)
	{
		flag=1;
		return;
	}

	for(int i=0;i<n;i++)
	{
		int nx=x+direction[i][0];
		int ny=y+direction[i][1];
		if(maze[nx][ny]==0)
			{
				maze[nx][ny]=1;  
				DSF(nx,ny);
				if(flag==1) return ;
			}
	}
}
 
int main()
{
	cin>>m>>n;
	cin>>in1>>in2;
	cin>>out1>>out2;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>maze[i][j];
	maze[in1][in2]=1; 
    DSF(in1,in2);
	if(flag==1)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}


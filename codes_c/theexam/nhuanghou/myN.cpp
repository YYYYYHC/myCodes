#include<iostream>

using namespace std;
int map[8][8]={0};
int res[8][2];
int flag=0;


void place(int px,int py)
{
    for(int i=0;i<8;i++) 
    {   
        map[px][i]=1;
        map[i][py]=1;
    }
}

void ddbug()
{
     for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
}
void paint()
{
    int toPaint[8][8]={0};
    cout<<"haha";
    for(int i=0;i<8;i++)
    {
        toPaint[res[i][0]][res[i][1]]=1;
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            cout<<toPaint[i][j]<<" ";
        cout<<endl;
    }
}

void Solver(int rest ) 
{
    flag=0;
    if(rest==0)  paint();
    for(int i=0;i<8;i++)
        if(map[i][0]==0)
            for(int j=0;j<8;j++)
                if(map[0][j]==0)
                {
                   
                    flag=1;
                    place(i,j);
                    ddbug();
                    res[8-rest][0]=i;
                    res[8-rest][1]=j;
                    Solver(rest-1);
                }
    if(!flag) return; 

}


int main()
{
    Solver(8);
    return 0;
}
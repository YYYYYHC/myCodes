#include<iostream>
#include<queue>

using namespace std;
int t;
long int theCol[4][100];
long int r[100],g[100],b[100],w[100];
int judge[4]={0};
queue<int> q1;
int solveAns[100];

int toJudge(int theNum)
{
    if(theNum%2==0) return 1;
    else return 0;
}

void solve(int indexNum)
{
    judge[0]=toJudge(theCol[0][indexNum]);
    judge[1]=toJudge(theCol[1][indexNum]);
    judge[2]=toJudge(theCol[2][indexNum]);
    judge[3]=toJudge(theCol[3][indexNum]);
    if(judge[0]+judge[1]+judge[2]+judge[3]==1) 
    {
        solveAns[indexNum]=1;
        return;
    }
    else
    {
        while(theCol[0][indexNum]>=0&&theCol[1][indexNum]>=0&&theCol[2][indexNum]>=0&&theCol[3][indexNum]>=0)
        {
            for(int j=0;j<4;j++) 
            {
                judge[j]=~judge[j];
                if(j!=3) theCol[j][indexNum]--;   
            }
            if(judge[0]+judge[1]+judge[2]+judge[3]==1||judge[0]+judge[1]+judge[2]==0) 
            {
                solveAns[indexNum]=1;
                return;
            }
        }
        solveAns[indexNum]=0;
        return;
    }
}

int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%ld%ld%ld%ld",&theCol[0][i],&theCol[1][i],&theCol[2][i],&theCol[3][i]);
        solve(i);
    }
    for(int i=0;i<t;i++) printf("%d\n",solveAns[i]);
    return 0;
}
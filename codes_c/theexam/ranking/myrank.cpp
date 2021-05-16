#include<iostream>

using namespace std;
int num;
char abc[26];
char t_abc[26];
int flag=0;
void exchange(int pos1, int pos2)
{
    char ctemp=abc[pos1];
    abc[pos1]=abc[pos2];
    abc[pos2]=ctemp;
}

void OutPut()
{
    for(int i=0;i<num;i++) cout<<abc[i];
    cout<<endl;
}

void DFS(int startNum, int endNum)
{
    if(startNum==endNum+1)  //排好了再输出！！！
    {
        OutPut(); 
        return;
    }
    for(int i=startNum;i<=endNum;i++)
    {
        exchange(i,startNum);
        DFS(startNum+1,endNum);
        exchange(i,startNum);
    }
}

int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        abc[i] = 'a'+i;
        t_abc[i] = abc[i];
    }
    DFS(0,num-1);
    return 0;
}
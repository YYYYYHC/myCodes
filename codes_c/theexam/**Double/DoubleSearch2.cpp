#include<iostream>

using namespace std;
int n,m;
int theNum[10001],searchNum[50001];

void myInit()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>theNum[i];
    cin>>m;
    for(int j=0;j<m;j++) cin>>searchNum[j];
}

bool mySearch(int startPoint,int endPoint,int num)
{
    if(startPoint>endPoint) return 0;
    int midPoint=startPoint + (endPoint-startPoint)/2;
    if(theNum[midPoint]==num) return 1;
    else if(theNum[midPoint]>num) return mySearch(startPoint,midPoint-1,num);
    else return mySearch(midPoint+1,endPoint,num);

}

int main()
{
    myInit();
    for(int i=0;i<m;i++) 
    {
        if(mySearch(0,n-1,searchNum[i])) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
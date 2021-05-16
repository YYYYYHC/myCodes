#include<iostream>

using namespace std;

int n;
int InputNum[10000];

void FastSort(int startPoint,int endPoint)
{
    if(startPoint>=endPoint) return; //终止条件
    int target=InputNum[startPoint];
    int i=startPoint,j=endPoint;
    while(i<j)
    {
        while(i<j && InputNum[j]>=target)  //时刻保证i<j
        {
            j--;
        }
        if(i<j) InputNum[i]=InputNum[j];  //同样保证i<j（可以不要）
        while(i<j && InputNum[i]<=target)
        {
            i++;
        }
        if(i<j) InputNum[j]=InputNum[i];
    }
    InputNum[i]=target;  //不能忘记
    FastSort(startPoint,i-1);//这样出去得快
    FastSort(i+1,endPoint);

}

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++) cin>>InputNum[i];
    FastSort(0,n-1);
    for(i=0;i<n;i++) cout<<InputNum[i]<<endl;
    return 0;
}
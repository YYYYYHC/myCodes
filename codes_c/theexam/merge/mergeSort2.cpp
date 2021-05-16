#include<iostream>

using namespace std;
int n;
int Tosort[10000];
int Temp[10000];

void Merge(int startPoint,int midPoint,int endPoint)
{
    int i=startPoint,j=midPoint+1,k=i;//实际上左半边有midPoint 右边没有
    while(i!=midPoint+1 && j!=endPoint+1) //左边到midpoint为止 右边到endpoint
    {
        if(Tosort[i]<Tosort[j]) Temp[k++]=Tosort[i++];
        else Temp[k++]=Tosort[j++]; 
    }
    while(i!=midPoint+1)//同上
    {
        Temp[k++]=Tosort[i++];
    }
    while(j!=endPoint+1)
    {
        Temp[k++]=Tosort[j++];
    }
    for(i=startPoint;i<=endPoint;i++)
        Tosort[i]=Temp[i]; //排好的要更新
    return;

}

void MergeSort(int startPoint,int endPoint)
{
    int midPoint = startPoint + (endPoint-startPoint)/2;
    if(startPoint<endPoint)
    {
        MergeSort(startPoint,midPoint);
        MergeSort(midPoint+1,endPoint);
        Merge(startPoint,midPoint,endPoint);
    }
    return;
}

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++) cin>>Tosort[i];
    MergeSort(0,n-1);
    for(i=0;i<n;i++) cout<<Tosort[i]<<" ";
    return 0;
}
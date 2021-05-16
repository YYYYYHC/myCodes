#include<iostream>

using namespace std;

int n;
int ToSort[10001];
int Sorted[10001];

void Merge(int startNum,int midNum,int endNum)
{
    int i=startNum,j=midNum+1,k=startNum; //细节加一
    while(i!=midNum+1 && j!=endNum+1) //一定要有判断
    {
        if(ToSort[i]<ToSort[j])
            Sorted[k++] = ToSort[i++]; //++
        else 
            Sorted[k++] = ToSort[j++];
    }
    while(i!=midNum+1) //补上
        Sorted[k++] = ToSort[i++];
    while(j!=endNum+1) //补上
        Sorted[k++] =ToSort[j++];
    for(i=startNum;i<=endNum;i++)
        ToSort[i]=Sorted[i]; //更新
}

void MergeSort(int startNum,int endNum)
{
    if(startNum<endNum)
    {
        int midNum=startNum+(endNum-startNum)/2;
        MergeSort(startNum,midNum);
        MergeSort(midNum+1,endNum); //不能重复排
        Merge(startNum,midNum,endNum); //三元 好写
    }
    return;

}

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++) cin>>ToSort[i];
    MergeSort(0,n-1);
    for(i=0;i<n;i++) cout<<ToSort[i]<<endl;

    return 0;
}
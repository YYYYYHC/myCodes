#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
int A[3];

void myInit()
{
    A[0]=2;
    A[1]=1;
    A[2]=3;
}

int main()
{
    myInit();
    sort(A,A+2);
    cout<<A[0]<<A[1]<<A[2];
    return 0;
}
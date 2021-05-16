#include<stdio.h>
#include<stdlib.h>
 
typedef struct{//定义带有队头队尾的结构体
    int *Data;
    int front;
    int rear;
    int K;
} Queue;
 
Queue* creat(int k){//不确定k的值所以动态申请队列
    Queue *Q;
    Q = (Queue*)malloc(sizeof(Queue));
    Q->K = k + 1;
    Q->Data = (int*)malloc(sizeof(int)*Q->K);//多申请一个空间用来判断是否满了
    Q->front = Q->rear = 0;
    return Q;
}
 
void plus(Queue *Q, int item)//在队尾加一个  
{
    if((Q->rear+1)%Q->K == Q->front){
        return;
    }
    else{
        Q->rear = (Q->rear+1)%Q->K;//依然选择先移动rear再输入数据
        Q->Data[Q->rear] = item;
    }
 
}
 
int del(Queue *Q)
{//在队头删一个
    if(Q->rear == Q->front){
        printf("kong\n");
        return NULL;
    }
    else{
        Q->front = (Q->front+1)%Q->K;
        return Q->Data[Q->front];
    }
}
 
void Fibonacci(int k,int max)
{//斐波那契数列的循环数列
    Queue *q;
    int i, item, t = 1,j = 0;//第一个t为1，直接初始化
    q = creat(k);
    for(i = 0; i<k; i++)//先用0和1填满数列
        if(i == k-1)
            plus(q,1);//k为1，之前的全部为零 这样第k+1个也是1
        else
            plus(q,0);
    while(t <= max){
        j++;
        del(q); 
        plus(q,t);//把新的t加入到循环队列中
        t = 0;//每次都把t置零，因为t是要把之前的k个加和
        for(i = 0; i<k; i++){
            item = del(q);//每次弹出队头元素后之后要再压进去
            t = t+item;
            plus(q,item);
        }
    }
    for(i = 0; i<k; i++){//把最后的k循环数列输出
        item = del(q);
        printf("%d ", item);
        plus(q,item);
    }
}
 
int main()
{
	int max,k;
	scanf("%d %d",&max,&k);
	Fibonacci(k,max);
	return 0;
}


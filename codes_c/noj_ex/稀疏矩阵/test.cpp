#include<stdio.h>
#include<iostream>
using namespace std;
#define Maxsize 100

typedef struct Data{
    int row,col,num;
    struct Data *right,*down;
}Data,*Dlink;//三元组数据

typedef struct List{
    int mu,nu,tu;
    Dlink rhead[Maxsize],chead[Maxsize];
}List;//十字链表

void Create(List& M,int i,int j)//创建十字链表，将行列数赋值，非零元素个数为0
{
    M.mu=i;
    M.nu=j;
    M.tu=0;
    for(int k=0;k<i;k++){
        M.rhead[k]=NULL;
    }
    for(int k=0;k<j;k++){
        M.chead[k]=NULL;
    }//将十字链表的头指针置空
}

void Insert_new(List& M,int i,int j,int num)//往十字链表中插入一个三元组数据
{
        M.tu++;//非零元个数加1
        Dlink p=new Data;//创建一个三元组
        p->row=i;
        p->col=j;
        p->num=num;//将三元组赋值
        //以下进行插入
        if(M.rhead[i]==NULL||M.rhead[i]->col>j){//如果该行还没有三元组或即将插入的三元组的列号为该行中最小
            p->right=M.rhead[i];
            M.rhead[i]=p;
        }
        else{//否则按列号大小插入
            Dlink q;
            for(q=M.rhead[i];q->right&&q->right->col<j;q=q->right);
            p->right=q->right;
            q->right=p;
        }
        //以下进行列插入
        if(M.chead[j]==NULL||M.chead[j]->row>i){//如果该列还没有三元组或即将插入的三元组的行号为该列中最小
            p->down=M.chead[j];
            M.chead[j]=p;
        }
        else{//否则按行号大小插入
            Dlink q;
            for(q=M.chead[j];q->down&&q->down->row<i;q=q->down);
            p->down=q->down;
            q->down=p;
        }
}

void Input(List& M,int n1)//输入第一个矩阵的所有三元组
{
    int i,j,num;
    for(int k=0;k<n1;k++){
        cin>>i>>j>>num;
        Insert_new(M,i,j,num);
    }
}

void Sum(List& M,int n2)
{
    int i,j,num;//第二矩阵的三元组
    bool flag=false;//判断有没有和第一矩阵相同位置的元素，有则true，没有则false
    for(int k=0;k<n2;k++,flag=false){
        cin>>i>>j>>num;
        Dlink q;
        if(M.chead[j]==NULL||M.rhead[i]==NULL);
        else{
            for(q=M.rhead[i];q->col<=j;q=q->right){
                if(q->col==j){q->num+=num;flag=true;}//true就相加
                if(q->right==NULL)break;
            }
        }
        if(!flag){
            Insert_new(M,i,j,num);//false就插入一个新的三元组
        }
    }
}

void Print(List M)//输出函数
{
    Dlink p;
    for(int k=0;k<M.mu;k++)
        for(p=M.rhead[k];p;p=p->right){
            cout<<p->row<<" "<<p->col<<" "<<p->num<<endl;
        }
}

int main()
{
    int i,j,n1,n2;
    cin>>i>>j>>n1>>n2;
    List M;
    Create(M,i,j);//创建一个十字链表
    Input(M,n1);//输入第一个矩阵的三元组
    Sum(M,n2);//输入第二个矩阵的三元组并与第一矩阵求和
    Print(M);
    return 0;
}
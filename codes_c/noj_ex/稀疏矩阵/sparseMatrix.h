#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define MAXNUM 100

typedef int Datatype;

typedef struct CrNode{
    Datatype row,col,value;
    struct CrNode *right, *down;
}CrNode,*PcrNode;

typedef struct CrList{
    int tn;
    int row,col;
    PcrNode rHead[MAXNUM];
    PcrNode dHead[MAXNUM];
}CrList,*PCrList;

PCrList createCrList(int row,int col)
{
    PCrList M=new CrList;
    M->row=row;
    M->col=col;
    M->tn=0;
    for(int i=0;i<row;i++)
        M->rHead[i]=NULL;
    for(int j=0;j<col;j++)
        M->dHead[j]=NULL;
    return M;
}

void insertCrList(PCrList& M, int row,int col, Datatype value)
{
    PcrNode newNode=new CrNode;
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    if(M->rHead[row]==NULL||M->rHead[row]->col>col){
        // std::cout<<"爷出来了"<<std::endl;
        newNode->right = M->rHead[row];
        M->rHead[row] = newNode;
        M->tn++;
        // std::cout<<"爷出来了"<<std::endl;
    }
    else{
        PcrNode q = new CrNode;
        for(q=M->rHead[row];q->right&&q->right->col<col;q=q->right);
        
        //出循环有三个情况——qright为空 qright的列标等于newNode的col qright的列标大于newNode的col
        if(q->right==NULL&&q==M->rHead[row]){
            // std::cout<<"xixi"<<std::endl;
            if(q->col<col){
                newNode->right = NULL;
                q->right=newNode;
                M->tn++;
            }
            else if(q->col==col){
                // std::cout<<"q="<<q->value<<std::endl;
                // std::cout<<q->value<<std::endl;
                q->value+=value;
                // std::cout<<"q="<<q->value<<std::endl;
                // std::cout<<q->value<<std::endl;
            }
            else{
                newNode->right = M->rHead[row];
                M->rHead[row] = newNode;
                M->tn++;
            }
        }
        else if(q->right==NULL||q->right->col>col){
            newNode->right = q->right;
            q->right=newNode;
            M->tn++;
            // std::cout<<"haha"<<std::endl;
        }
        else{
            // std::cout<<"??"<<std::endl;
            q->right->value+=value;
        } 
    }

    if(M->dHead[col]==NULL||M->dHead[col]->row>row){
        // std::cout<<"爷出来了"<<std::endl;
        newNode->down = M->dHead[col];
        // std::cout<<"爷出来了"<<std::endl;
        // if(!(newNode->down!=NULL))
        //     std::cout<<"爷出来了"<<std::endl;
        M->dHead[col] = newNode;
        // std::cout<<"爷出来了"<<std::endl;
    }
    else{
        PcrNode q = new CrNode;
        for(q=M->dHead[col];q->down&&q->down->row<row;q=q->down);
        //出循环有三个情况——qright为空 qright的列标等于newNode的col qright的列标大于newNode的col
        // if(q->down==NULL) std::cout<<"NULL yes"<<std::endl;
        // if(q==M->dHead[col]) std::cout<<"Q yes"<<std::endl;
        if(q->down==NULL&&q==M->dHead[col]){
            // std::cout<<"xixi"<<std::endl;
            if(q->row<row){
                newNode->down = NULL;
                q->down=newNode;
                // M->tn++;
            }
            else if(q->row==row){
                // std::cout<<q->value<<std::endl;
                // q->value+=value;
                // std::cout<<q->value<<std::endl;
            }
            else{
                newNode->down = M->dHead[col];
                M->dHead[col] = newNode;
                // M->tn++;
            }
        }
        else if(q->down==NULL||q->down->row>row){
            newNode->down = q->down;
            q->down=newNode;
        }
        else{
            // std::cout<<"!!"<<std::endl;
            // q->down->value+=value;
        } 
    }
}
void printCrList(PCrList M)
{
    PcrNode p = new CrNode;
    for(int k=0;k<M->row;k++)
        {
            for(p=M->rHead[k];p!=NULL;p=p->right)
            {
                std::cout<<p->row<<" "<<p->col<<" "<<p->value<<std::endl;
            }
        }
    printf("\n");
}
void inputCrList(PCrList&M, int num){
    int row,col,value;
    while(num--)
    {
        std::cin>>row>>col>>value;
        insertCrList(M,row,col,value);
    }
}
void test()
{
    PCrList M = createCrList(3,3);
    // std::cout<<"1"<<std::endl;
    insertCrList(M,1,1,2);
    printCrList(M);
    insertCrList(M,0,1,2);
    printCrList(M);
    insertCrList(M,0,1,-1);
    printCrList(M);
}




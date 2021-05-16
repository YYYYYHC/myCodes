#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct
{
    int raw,col;
    int val;
} Triple;
typedef struct
{
    Triple *data;
    int m,n,len;
} TSMatrix;

void CreateTSMatrix(TSMatrix *p,int k)
{
    p->data = (Triple*)malloc(sizeof(Triple)*k);
    p->len = k;
}

void AddTwoTSMatrix(TSMatrix *A,TSMatrix *B,TSMatrix *C)
{
    int i=0,j=0,sum,C_len=0;
    while(i<A->len && j<B->len){
        if(A->data[i].raw==B->data[j].raw && A->data[i].col==B->data[j].col){
            sum = A->data[i].val + B->data[j].val;
            if(sum!=0){
                C->data[C_len].raw = A->data[i].raw;
                C->data[C_len].col = A->data[i].col;
                C->data[C_len].val = sum;
                C_len++;
            }
            i++;
            j++;
        }
        else if(A->data[i].raw < B->data[j].raw){
            C->data[C_len].raw = A->data[i].raw;
            C->data[C_len].col = A->data[i].col;
            C->data[C_len].val = A->data[i].val;
            C_len++;
            i++;
        }
        else if(A->data[i].raw > B->data[j].raw){
            C->data[C_len].raw = B->data[j].raw;
            C->data[C_len].col = B->data[j].col;
            C->data[C_len].val = B->data[j].val;
            C_len++;
            j++;
        }
        else if(A->data[i].col < B->data[j].col){
            C->data[C_len].raw = A->data[i].raw;
            C->data[C_len].col = A->data[i].col;
            C->data[C_len].val = A->data[i].val;
            C_len++;
            i++;
        }
        else{
            C->data[C_len].raw = B->data[j].raw;
            C->data[C_len].col = B->data[j].col;
            C->data[C_len].val = B->data[j].val;
            C_len++;
            j++;
        }
    }
    while(i<A->len){
        C->data[C_len].raw = A->data[i].raw;
        C->data[C_len].col = A->data[i].col;
        C->data[C_len].val = A->data[i].val;
        C_len++;
        i++;
    }
    while(j < B->len){
        C->data[C_len].raw = B->data[j].raw;
        C->data[C_len].col = B->data[j].col;
        C->data[C_len].val = B->data[j].val;
        C_len++;
        j++;
    }
    C->len = C_len;
}

int main()
{
    int t1,t2;
    int m,n;
    cin>>m>>n;
    cin>>t1>>t2;
    TSMatrix *pa,*pb,*pc;
    pa = (TSMatrix*)malloc(sizeof(TSMatrix));
    pb = (TSMatrix*)malloc(sizeof(TSMatrix));
    pc = (TSMatrix*)malloc(sizeof(TSMatrix));
    CreateTSMatrix(pa,t1);
    CreateTSMatrix(pb,t2);
    CreateTSMatrix(pc,t1+t2);
    for(int i=0; i<t1; i++)
        cin>>pa->data[i].raw>>pa->data[i].col>>pa->data[i].val;
    for(int j=0; j<t2; j++)
        cin>>pb->data[j].raw>>pb->data[j].col>>pb->data[j].val;
    AddTwoTSMatrix(pa,pb,pc);
    for(int i=0; i<pc->len-1; i++)
        cout<<pc->data[i].raw<<' '<<pc->data[i].col<<' '<<pc->data[i].val<<endl;
    cout<<pc->data[pc->len-1].raw<<' '<<pc->data[pc->len-1].col<<' '<<pc->data[pc->len-1].val;
    return 0;
}
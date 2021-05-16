#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node{
    char elem;
    Node *nex, *pre;
    Node(int elem = 0, Node *nex = 0, Node *pre = 0):elem(elem), nex(nex), pre(pre){}
};
typedef Node *LinkList;

struct BigDec{
    LinkList Head;
    //int dot;  dot=1
    BigDec(int n = 500){
        int i = n;
        LinkList L,s;
        L = this->Head = new Node();
        L->nex = L->pre = L; //设计成环，防止溢出出错
        while(i--){
            s = new Node(0, L->nex, L);
            L->nex->pre = s;
            L->nex = s;
        }
    }

    BigDec operator * (const long long rsh){
        LinkList pa= this->Head->pre;
        long long s = 0;
        while(pa != this->Head){
            long long x = rsh*(pa->elem);
            pa->elem = (x+s)%10; //将个位放到本地
            s = (x+s)/10; //将十位放到进位
            pa = pa->pre;
        }
        this->Head->elem += s;
        return *this;
    }

    BigDec operator / (const long long rsh){
        LinkList pa = this->Head->nex;
        long long s = this->Head->elem;
        if(s<rsh) {this->Head->elem = 0;s = (s%rsh)*10;} //小于除数直接退位
        else {this->Head->elem = s/rsh; s = (s%rsh)*10;}
        while(pa != this->Head){
            s += pa->elem;
            if(s < rsh ){ pa->elem = 0;s = (s%rsh)*10;pa = pa->nex;}
            else {pa->elem = s/rsh;s = (s%rsh)*10; pa = pa->nex;}
        }
        return *this;
    }


    BigDec operator + (const BigDec &rsh){
        LinkList pa,pb;
        pa = this->Head->pre;
        pb = rsh.Head->pre;
        int s = 0;
        while(pa!=this->Head){
            int x = (pa->elem + pb->elem);
            pa->elem = (x+s)%10;
            s = (x+s)/10;
            pa = pa->pre;pb = pb->pre;
        }
        return *this;
    }

};

typedef BigDec *LBigDec;

void BigDec_pri(BigDec &BDec, int n){//打印
    LinkList p = BDec.Head->nex;
    printf("%d.", BDec.Head->elem); 
    while(n--){
        printf("%d", p->elem);
        p = p->nex;
    }
    printf("\n");
}

int main(){
    int N;
    scanf("%d", &N);
    BigDec *a = new BigDec(N+10);
    BigDec *b = new BigDec(N+10); //b记录结果
    a->Head->nex->elem = 5;
    *b+*a;
    long long x, y;
    for(int i = 1; i<=N*10; i++){
        x = (long long)(2*i-1)*(2*i-1); 
        y = (long long)(2*i)*(2*i+1)*4; 
        (*a)*x;
        (*a)/y;
        //BigDec_pri(*a);
        (*b)+(*a);
    }
    (*b)*(long long)6;
    BigDec_pri(*b,N);

}


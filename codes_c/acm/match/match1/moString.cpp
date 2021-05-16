#include<iostream>
#include<string>

using namespace std;
int t;
string Str;
string ans[1000];

int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>Str;
        ans[i].push_back(Str[0]);
        // cout<<"length"<<Str.length();
        for(int p=1;p<Str.length()/2;p++)
        {
            
            ans[i].push_back(Str[2*p-1]);
            //  cout<<"yes"<<ans[i][p]<< ' ';
        }
        ans[i].push_back( Str[Str.length()-1]);
    }
    for(int j=0;j<t;j++) 
            cout<<ans[j]<<endl;
    return 0;
}
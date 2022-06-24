#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==1&&b==0&&c==0)
    {
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0 ;
    }
    if(c==0&&a!=b)
    {
        cout<<"YES"<<endl;
        cout<<min(a,b)+1<<endl;
    }
    else if(a>b+c)
    {
        cout<<"YES"<<endl;
        cout<<(b+c)*2+1<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
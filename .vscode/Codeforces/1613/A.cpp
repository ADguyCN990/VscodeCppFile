#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,c;
ll b,d;

void solve()
{
    cin>>a>>b>>c>>d;
    ll tmp=min(b,d);
    b=b-tmp;
    d=d-tmp;
    if(b>=7)
        {cout<<">"<<endl;return;}
    else if(d>=7)
        {cout<<"<"<<endl;return;}
    ll x=stoll(a),y=stoll(c);
    for(int i=1;i<=b;i++) x*=10;
    for(int i=1;i<=d;i++) y*=10;
    if(x>y)
        cout<<">"<<endl;
    else if(x==y)
        cout<<"="<<endl;
    else
        cout<<"<"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
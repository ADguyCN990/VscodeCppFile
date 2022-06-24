#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll d,k;
//ASHISH 先手
void solve()
{
    cin>>d>>k;
    ll x=0;
    ll y=0;
    while(1)
    {
        if(x<=y&&(x+k)*(x+k)+y*y<=d*d)
        {
            x+=k;
        }
        else if(x>y&&x*x+(y+k)*(y+k)<=d*d)
        {
            y+=k;
        }
        else 
            break;
    }
    if(x==y)
        cout<<"Utkarsh"<<endl;
    else
        cout<<"Ashish"<<endl;
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
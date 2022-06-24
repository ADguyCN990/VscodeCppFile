#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f

void solve()
{
    ll a,b,x;
    cin>>a>>b>>x;
    if(x==a||x==b) 
    {
        cout<<"YES"<<endl;
        return;
    }
    if(a<b) swap(a,b);
    while(b)
    {
        if(x>a)
            break;
        if(x>=b&&(a-x)%b==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        a=a%b;
        swap(a,b);
    }
    cout<<"NO"<<endl;
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
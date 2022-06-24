#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f

void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==1&&m==1)
    {
        cout<<0<<endl;
    }
    else if(n==1||m==1)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<2<<endl;
    }
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
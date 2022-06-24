#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int a[MAXN];
void solve()
{
    ll sum=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum==m)
        cout<<"YES"<<endl;
    else
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
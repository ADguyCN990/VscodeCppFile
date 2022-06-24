#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int f[MAXN],a[MAXN],rk[MAXN];
int n;
int dis[MAXN],cnt;




void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i];//父亲
    for(int i=1;i<=n;i++)
        cin>>a[i];//顺序
    int rt=0;
    for(int i=1;i<=n;i++)
    {
        if(i==f[i])
        {
            rt=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        rk[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(rk[a[i]]<rk[f[a[i]]])
        {
            cout<<-1<<endl;
            return;
        }
        dis[a[i]]=rk[a[i]]-rk[f[a[i]]];
    }
    dis[rt]=0;
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
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
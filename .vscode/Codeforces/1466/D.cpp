#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,k,cnt,ans;
ll a[MAXN];
int outdgr[MAXN];//统计每个点的出度数
ll value[MAXN];//可以增加的贡献
void init()
{
    k=n-1;cnt=0;ans=0;
    for(int i=1;i<=n;i++) {outdgr[i]=0;value[i]=0;}
}
bool cmp(ll a,ll b){return a>b;}
void solve()
{
    cin>>n;
    init();
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        outdgr[u]++;outdgr[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        outdgr[i]--;
        int j=i;
        while(outdgr[j]>0)
        {
            value[++cnt]=a[i];
            outdgr[j]--;
        }
    }
    sort(value+1,value+cnt+1,cmp);
    for(int i=1;i<n;i++) 
    {       
        cout<<ans<<" ";
        ans+=value[i];
    }
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
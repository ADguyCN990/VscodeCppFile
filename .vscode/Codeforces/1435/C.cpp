#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 600005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int b[10];
int n; 
int a[MAXN];
pii p[MAXN];
int vis[100005];
int cnt=0;
void solve()
{
    for(int i=1;i<=6;i++)
        cin>>b[i];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(b+1,b+7);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            p[++cnt]={a[i]-b[j],i};
        }
    }
    sort(p+1,p+1+cnt);
    int l=1,r=1,num=0;
    int ans=INF;
    while(r<=cnt)
    {
        if(!vis[p[r].second])
            num++;
        vis[p[r].second]++;
        while(num==n&&vis[p[l].second])
        {
            ans=min(ans,p[r].first-p[l].first);
            vis[p[l].second]--;
            if(!vis[p[l].second])
                num--;
            l++;
        }
        r++;
        if(ans==0)
            break;
    }
    
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}
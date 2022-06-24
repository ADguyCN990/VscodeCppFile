#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n,m;
ll a[MAXN];
bool cmp(ll a,ll b) {return a>b;}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    priority_queue <int> q;
    q.push(0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int now=q.top();
        q.pop();
        if(a[i]>now)
        {
            q.push(now);
            q.push(m-a[i]);
            ans++;
        }
        else
        {
            q.push(now-a[i]);
        }
    }
    cout<<ans<<endl;
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
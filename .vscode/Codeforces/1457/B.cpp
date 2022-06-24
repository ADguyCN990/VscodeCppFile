#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,k;ll a[MAXN];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0x3f3f3f3f;
    for(int o=1;o<=100;o++)
    {
        int now=o;//将所有方块涂成now
        int tmp=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
 
            if(a[i]==now&&cnt==0) continue;
            cnt++;
            if(cnt==k)
            {
                cnt=0;
                tmp++;
            }
        }
        if(cnt>0) tmp++;
        ans=min(ans,tmp);
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
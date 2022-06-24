#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
ll n;ll a[MAXN];ll q;
ll cnt[MAXN];
ll ans[MAXN][MAXN];
void solve()
{
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        cnt[a[i]]++;
        ans[0][i]=a[i];
    }
    int flag=0;
    for(int k=1;;k++)
    {
        flag=0;
        mx=k;
        for(int i=1;i<=n;i++)
        {
            if(ans[k-1][i]!=cnt[ans[k-1][i]])
            {
                flag=1;             
            }
            ans[k][i]=cnt[ans[k-1][i]];
        }
        if(flag==0) break;
        for(int i=1;i<=MAXN;i++) 
        {
            cnt[i]=0;
        }
        for(int i=1;i<=n;i++) cnt[ans[k][i]]++;
       
    }
    cin>>q;
    while(q--)
    {
        int id;int k;
        cin>>id>>k;
        if(k>mx) k=mx;
        cout<<ans[k][id]<<endl;

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
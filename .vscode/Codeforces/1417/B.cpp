#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,k;
int a[MAXN];
int vis[MAXN];
map <int,int> mp1;
map <int,int> mp2;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    mp1.clear();
    mp2.clear();
    for(int i=1;i<=n;i++)
    {
        if(mp1[k-a[i]]==0)
        {
            mp1[a[i]]++;
            vis[i]=1;
        }
        else
        {
            if(mp1[k-a[i]]<=mp2[k-a[i]])
            {
                mp1[a[i]]++;
                vis[i]=1;
            }
            else
            {
                mp2[a[i]]++;
                vis[i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<vis[i]<<" ";
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
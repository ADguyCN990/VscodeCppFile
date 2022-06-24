#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int mx,mn;
int a[MAXN],n;
void solve()
{
    cin>>n;
    mx=-1,mn=INF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    if(mn==mx)
    {
        cout<<"-1"<<endl;
        return;
    }
    a[0]=INF,a[n+1]=INF;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==mx&&(a[i]>a[i-1]||a[i]>a[i+1]))
        {
            cout<<i<<endl;
            return;
        }
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
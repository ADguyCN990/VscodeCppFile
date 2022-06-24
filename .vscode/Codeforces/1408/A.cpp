#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int a[MAXN],b[MAXN],c[MAXN],n;
int p[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    p[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        p[i]=a[i];
        if(p[i]==p[i-1]||(i==n&&p[i]==p[1]))
            p[i]=b[i];
        if(p[i]==p[i-1]||(i==n&&p[i]==p[1]))
            p[i]=c[i];
    }
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
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
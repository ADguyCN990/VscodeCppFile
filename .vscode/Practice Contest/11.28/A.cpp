#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n;
int d[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        d[u]++,d[v]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]>=4)
        {
            cout<<0<<endl;
            return;
        }
        else if(d[i]<=2)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}
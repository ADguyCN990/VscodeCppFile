#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int ans[MAXN][MAXN];
int n,m;
set <pair<int,vector<int>>> s;
void solve()
{
    s.clear();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>b[i][j];
    for(int i=1;i<=n;i++)
    {
        int now=a[i][1];
        int to=0;
        vector <int> v;
        for(int j=1;j<=m;j++)
            v.emplace_back(a[i][j]);
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(b[j][k]==now)
                {
                    to=k;
                    break;
                }
            }
            if(to)
                break;
        }
        s.insert({to,v});
    }
    for(auto x:s)
    {
        for(auto i:x.second)
        {
            cout<<i<<" ";
        }
        cout<<endl;
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
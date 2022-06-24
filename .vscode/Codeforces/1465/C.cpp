#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
int f[MAXN];
ll n,m;
//n*n的棋盘上有m个棋子，m个棋子移动到朱对角线上，只能横穿
//通过并查集判断有几个环

int findx(int x)
{
    if(x==f[x]) return x;
    return f[x]=findx(f[x]);
}

void solve()
{
    cin>>n>>m;
    int ans=m;//最少需要的步数
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            ans--;//不用移动
            continue;
        }
        if(findx(x)==findx(y))//判环
        {
            ans++;
        }
        else if(findx(x)!=findx(y))//维护并查集
        {
            int fx=findx(x);
            int fy=findx(y);
            f[fy]=fx;
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
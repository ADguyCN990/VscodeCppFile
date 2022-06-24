#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
int pos[MAXN]; //现在每个数选到了哪个位置
int a[MAXN]; 
bool vis[MAXN]; //大于当前最大值的被标记为flase，等找到更大值是标记为true
vector <int> v[MAXN]; //每个数依次出现的位置
void solve()
{
    n = read();
    for (int i = 0; i <= n; i ++) pos[i] = 0, v[i].clear(), vis[i] = true;
    for (int i = 1; i <= n; i ++) a[i] = read(), v[a[i]].pb(i);
    vector <int> ans;
    int mx = -1; // 当前能选到的连续的最大值
    for (int i = 1; i <= n; i ++)
    {
        pos[a[i]] ++; 
        if (a[i] > mx)  vis[a[i]] = false;
        while (vis[mx + 1] == false) //之前就出现这个数了，等着更小的数将他连接
            vis[++ mx] = true;
        
        if (pos[mx + 1] == v[mx + 1].size()) //之前已经选满了
        {
            ans.pb(mx + 1);
            mx = -1;
        }

    }
    int len = ans.size();
    printf("%d\n", len);
    for (int x : ans) printf("%d ", x);
    puts("");
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MAXN 1005
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
map <string, int> mp;
map <ll, int> hashmap;
int idx = 0;
int a[MAXN][MAXN];
int n, m;
vector <int> key;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        string s;
        cin >> s;
        mp[s] = ++ idx;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    while (1)
    {
        string x;
        cin >> x;
        int len = x.size();
        if (x[len - 1] != ';') continue;
        string tmp = "";
        for (int i = 0; i < len; i ++)
        {
            if (x[i] == ',' || x[i] == ';')
            {
                key.pb(mp[tmp]);
                tmp = "";
            }
            else
                tmp += x[i];
        }
        break;
    }
    for (int i = 1; i <= n; i ++)
    {
        ll val = 0;
        for (int x : key)
        {
            val = val * 131 + a[i][x];
        }
        hashmap[val] ++;
    }
    cout << hashmap.size() << endl;
    for (auto it : hashmap) cout << it.second << " ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
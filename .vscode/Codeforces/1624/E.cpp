#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 200005
typedef pair<int,pair<int,int>> pii;
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
int n, len;
unordered_map <string, pii> two;// id l r
unordered_map <string, pii> three;// id l r 
string s;
vector <pii> ans;
int dp[MAXN];

bool dfs(int now) //now表示正在匹配第几位上的数，从0开始
{
    if (now == len - 1) //只剩一个数，不可能匹配成功，可行性剪枝
        return false;
    if (now == len) 
        return true;
    if (dp[now] != -1)  //冗余性剪枝
        return dp[now];
    bool ok = false;
    string x;
    if(now < len - 2)   //先搜索长度为3再搜索长度为2的子串，优化搜索顺序
        x = s.substr(now,3);
    if (three.count(x))
    {
        if (dfs(now + 3))
            ok = true;
        if (ok)
        {
            dp[now] = 1;
            ans.pb(three[x]);
            return true;
        }
    }
    x = s.substr(now, 2);
    if (two.count(x))
    {
        if (dfs(now+2))
            ok = true;
        if (ok)
        {
            dp[now] = 1;
            ans.pb(two[x]);
            return true;
        }
    }
    return dp[now] = 0;
}

void solve()
{
    cin >> n >> len;
    ans.clear();
    two.clear();
    three.clear();
    for (int i = 1; i <= n; i ++)
    {
        cin >> s;
        for (int j = 0; j < len - 1; j ++)
        {
            string tmp = s.substr(j, 2);
            two[tmp] = {i, {j + 1, j + 2}};
        }
        for (int j = 0; j < len - 2; j ++)
        {
            string tmp = s.substr(j, 3);
            three[tmp] = {i, {j + 1, j + 3}};
        }
    }
    cin >> s;
    memset(dp, -1, sizeof dp);
    bool flag = dfs(0);
    if (!flag)
    {
        puts("-1");
        return;
    }
    printf("%d\n", ans.size());
    reverse(ans.begin(),ans.end());
    for (auto x : ans)
    {
        printf("%d %d %d\n", x.second.first, x.second.second, x.first);
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}
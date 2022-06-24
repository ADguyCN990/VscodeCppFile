#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
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
char s[MAXN];
int pre[MAXN];
int sum[MAXN + 10005];
vector <int> ans;
void solve()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i ++)
    {
        int u = s[i] - '0';
        pre[i] = pre[i - 1] + u;
        sum[n - i + 1] = pre[i];
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     printf("%d ", sum[i]);
    // }
    // puts("");
    for (int i = 1;; i ++)
    {
        int u = sum[i] % 10;
        ans.pb(u);
        sum[i + 1] += sum[i] / 10;
        if (sum[i + 1] == 0) break;
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d", x);
}

int main()
{
    solve();
    return 0;
}
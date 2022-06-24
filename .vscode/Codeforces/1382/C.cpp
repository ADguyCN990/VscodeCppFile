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
char a[MAXN], b[MAXN];
void solve()
{
    n = read();
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    vector <int> ans;
    for (int i = 1; i < n; i ++)
    {
        if (a[i] != a[i + 1])
        {
            ans.pb(i);
        }
    }
    int now = a[n] - '0';
    for (int i = n; i >= 1; i --)
    {
        if (now == b[i] - '0') continue;
        now = now ^ 1;
        ans.pb(i);
    }
    printf("%d ", ans.size());
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
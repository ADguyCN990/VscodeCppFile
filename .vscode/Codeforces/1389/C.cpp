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
char s[MAXN];

int find(char s[], int a, int b)
{
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        int u = s[i] - '0';
        if (u == a)
        {
            cnt ++;
            swap(a, b);
        }
    }
    if (cnt % 2 == 1 && a != b) cnt --;
    return cnt;
}

void solve()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int ans = n;
    for (int i = 0; i < 10; i ++)
    {
        for (int j = 0; j < 10; j ++)
        {
            int tmp = find(s, i, j);
            ans = min(ans, n - tmp);
        }
    }
    printf("%d\n", ans);
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
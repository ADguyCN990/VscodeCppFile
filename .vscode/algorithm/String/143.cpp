#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
char p[MAXN];
int n;
int ne[MAXN];
void solve()
{
    for (int i = 1; i <= n; i ++) ne[i] = 0;
    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    for (int len = 2; len <= n; len ++)
    {
        int k = len - ne[len];
        if (len % k == 0 && ne[len])
        {
            printf("%d %d\n", len, len/k);
        }
    }
}

int main()
{
    int cnt = 0;
    while (1)
    {
        ++ cnt;
        n = read();
        if (!n) break;
        scanf("%s", p + 1);
        printf("Test case #%d\n", cnt);
        solve();
        puts("");
    }
    return 0;
}
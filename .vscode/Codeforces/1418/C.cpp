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
int a[MAXN];
int ans = 0;
bool isdata, getdata = false;
void solve()
{
    n = read();
    ans = 0;
    for (int i = 1; i <= n; i ++) a[i] = read();
    a[n + 1] = 0;
    int pos = 2;
    if (a[1] == 1) ans ++;
    while (pos <= n)
    {
        if (a[pos] == 0) 
        {
            pos ++;
            continue;
        }
        int j = pos, cnt = 0;
        while (a[j] == 1)
        {
            cnt ++;
            j ++;
        }
        pos = j;
        ans += cnt / 3;
    }
    printf("%d\n", ans);
}

int main()
{
    int T;
    T=read();
    for (int i = 1; i <= T; i ++)
    {
        solve();
    }

    return 0;
}
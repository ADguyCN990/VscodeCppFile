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
void solve()
{
    n = read();
    int cnt = 0;
    for (int i = 1; i <= n; i ++) a[i] = read();
    reverse(a + 1, a + 1 + n);
    int num;
    for (int i = 2; i <= n; i ++)
    {
        num = i - 1;
        if (a[i] != a[1]) 
        {
            cnt ++;
            if (i == 2) continue;
            i = num * 2;
        }
    }
    printf("%d\n", cnt);
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
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
int x, a, b;
char s[MAXN];
void solve()
{
    x = read(), a = read(), b = read();
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int now = x;
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == '0') now += b;
        else if (s[i] == '1')
        {
            if (now >= a) 
            {
                now -= a;
                ans ++;
            }
            else
                now += b;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}
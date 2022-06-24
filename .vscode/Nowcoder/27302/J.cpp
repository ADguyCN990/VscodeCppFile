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
int cnt0, cnt1;
char s[MAXN];
int a, b, c, n;

int work1() //消相同的比消不同的赚
{
    int ans = 0;
    ans += cnt1 / 2 * a;
    ans += cnt0 / 2 * a;
    cnt1 %= 2;
    if (cnt1 == 1)
    {
        if (a + c < b)
            ans += a + c;
        else
            ans += b;
    }
    return ans;
}

int work2() //消不同的比消相同的赚
{
    int ans = 0;
    int mn = min(cnt0, cnt1);
    ans += mn * b;
    int left = max(cnt0, cnt1) - mn;
    left /= 2;
    if (b + c < a)
    {
        ans += (b + c) * left;
    }
    else
    {
        ans += a * left;
    }
    return ans;
}

void solve()
{
    // a: 00 11
    // b: 10
    scanf("%s", s + 1);
    n = strlen(s + 1);
    b = read(), a = read(), c = read();
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == '1') cnt1 ++;
        else cnt0 ++;
    }
   // printf("cnt0: %d, cnt1: %d\n", cnt0, cnt1);
    int ans;
    if (a < b) ans = work1();
    else ans = work2();
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}
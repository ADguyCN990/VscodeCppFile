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
ll n, k;
char s[MAXN];
int cnt[30];
int two, one;
pii pre(int cnt[])
{
    int two = 0;
    int one = 0;
    for (int i = 1; i <= 26; i ++)
    {
        two += cnt[i] / 2;
        one += cnt[i] % 2;
    }
    return {two, one};
}

bool check (int mid,int cnt[])
{
    int left = 0;
    int need = 0;
    if (mid & 1) 
        need = k;
    mid = k * (mid / 2);
    if (two >= mid && (one + (two - mid) * 2) >= need) return true;
    else return false;
}

void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= 26; i ++) cnt[i] = 0;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
    {
        cnt[s[i] - 'a' + 1] ++;
    }
    pii result = pre(cnt);
    two = result.first, one = result.second;
    //printf("one: %d two: %d\n", one, two);
    int l = 1;
    int r = n / k;
    int ans;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid,cnt))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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
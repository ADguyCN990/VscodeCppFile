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
int small[MAXN], big[MAXN], num[MAXN], symbol[MAXN];
int n, l, r;
char s[MAXN];

bool check(int l, int r)
{
    int cnt1 = small[r] - small[l - 1];
    int cnt2 = big[r] - big[l - 1];
    int cnt3 = num[r] - num[l - 1];
    int cnt4 = symbol[r] - symbol[l - 1];
    int cnt = 0;
    if (cnt1 > 0) cnt ++;
    if (cnt2 > 0) cnt ++;
    if (cnt3 > 0) cnt ++;
    if (cnt4 > 0) cnt ++;
    //printf("!!!check   start: %d end: %d cnt: %d\n", l, r, cnt);
    return cnt >= 3;
}

void solve()
{
    n = read(), l = read(), r = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
    {
        small[i] = small[i - 1];
        big[i] = big[i - 1];
        num[i] = num[i - 1];
        symbol[i] = symbol[i - 1];
        if (s[i] >= 'a' && s[i] <= 'z') small[i] ++;
        else if (s[i] >= 'A' && s[i] <= 'Z') big[i] ++;
        else if (s[i] >= '0' && s[i] <= '9') num[i] ++;
        else symbol[i] ++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++) //枚举左端点
    {
        //对右端点进行二分
        int le = i + l - 1, ri = min(n, i + r - 1);
        //printf("le : %d ri : %d\n", le, ri);
        if (le > n) break;
        int tmp = -1;
        while (le <= ri)
        {
            int mid = le + ri >> 1;
            if (check(i, mid))
            {
                tmp = mid;
                ri = mid - 1;
            }
            else 
                le = mid + 1;
        }
        if (tmp == -1) continue;
        //printf("start: %d end: %d\n", i, tmp);
        ans += min(n, i + r - 1) - tmp + 1;
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}
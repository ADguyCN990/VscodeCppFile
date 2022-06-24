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
int cnt[5];
//R石头 S剪刀 P布
struct node
{
    int cnt;
    char id;
    friend bool operator < (node a, node b)
    {
        return a.cnt > b.cnt;
    }
}a[MAXN];
int n;
char s[MAXN];
void solve()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == 'R') cnt[1] ++;
        else if (s[i] == 'S') cnt[2] ++;
        else if (s[i] == 'P') cnt[3] ++;
    }
    a[1] = {cnt[1], 'R'}, a[2] = {cnt[2], 'S'}, a[3] = {cnt[3], 'P'};
    sort(a + 1, a + 1 + 3);
    char c = a[1].id;
    if (c == 'R') c = 'P';
    else if (c == 'S') c = 'R';
    else c = 'S';
    for (int i = 1; i <= n; i ++) printf("%c", c);
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
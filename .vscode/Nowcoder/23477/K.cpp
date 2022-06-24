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
char s[MAXN];
int cnt[15];
int n;
void solve()
{
    n = read();
    scanf("%s", s + 1);
    int tmp = 0;
    for (int i = 1; i <= n; i ++)
    {
        int u = s[i] - '0';
        cnt[u] ++;
        if (u != 5) tmp ++;
    }
    cnt[5] = 0;
    cnt[5] = tmp;
    for (int i = 1; i <= 5; i ++) printf("%d ", cnt[i]);
}

int main()
{
    

    return 0;
}
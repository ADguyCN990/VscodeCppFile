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
int n;
char s[MAXN];
char tmp[10];
void solve()
{
    n = read();
    tmp[0] = 'N', tmp[1] = 'E', tmp[2] = 'U', tmp[3] = 'Q'; 
    scanf("%s", s + 1);
    int cnt = 0, id = 0;
    for (int i = 1; i <= n; i ++)
    {
        if(s[i] == tmp[id]) id ++;
        if (id == 4) id = 0, cnt ++;
    }
    printf("%d\n", n - 4 * cnt);
}

int main()
{
    solve();
    return 0;
}
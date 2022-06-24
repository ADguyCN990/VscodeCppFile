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
int n, m;
char s[MAXN], p[MAXN]; 
int stk[MAXN], tt;
int len[MAXN]; //已经匹配的长度   
int ne[MAXN];                                              
void solve()
{
    scanf("%s", s + 1);
    m = strlen(s + 1);
    scanf("%s", p + 1);
    n = strlen(p + 1);
    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i ++)
    {
        stk[++ tt] = i;
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        len[i] = j;
        if (j == n) //全部都匹配上了
        {
            tt -= n; //弹出栈顶的n个元素
            j = len[stk[tt]];
        }
    }
    for (int i = 1; i <= tt; i ++) printf("%c", s[stk[i]]);
}

int main()
{
    solve();
    return 0;
}
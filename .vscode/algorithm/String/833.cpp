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
char s[MAXN], p[MAXN];
int n, m;
int ne[MAXN];
void solve()
{
    n = read();//模式串长度
    scanf("%s", p + 1);
    m = read(); 
    scanf("%s", s + 1);
    for (int i = 2, j = 0; i <= n; i ++) //与自身匹配
    {
        while (j && p[i] != p[j + 1]) j = ne[j]; //i与j+1匹配
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i ++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j]; //i与j+1匹配
        if (s[i] == p[j + 1]) j ++;
        if (j == n) //匹配完了n个字符，说明匹配上了
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

}

int main()
{
    solve();
    return 0;
}
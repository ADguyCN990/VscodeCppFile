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
char p[MAXN];
int ne[MAXN];
int m, n;
string ans = "0123456789ABCDEF";

string work(int n, int k) //把n转化成k进制下的字符串
{
    string res;
    while (n)
    {
        int num = n % k;
        res = res + ans[num];
        n /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}

void getnext()
{
    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
}

void solve()
{
    m = read();
    scanf("%s", p + 1);
    n = strlen(p + 1);
    getnext();
    for (int i = 2; i <= 16; i ++)
    {
        string s = " ";
        for (int j = 1; j <= m; j ++) s += work(j, i);
        //cout << s <<endl;
        int len = s.length();
        for (int k = 1, j = 0; k <= len; k ++)
        {
            while (j && s[k] != p[j + 1]) j = ne[j];
            if (s[k] == p[j + 1]) j ++;
            if (j == n)
            {
                puts("yes");
                return;
            }
        }
    }
    puts("no");
}

int main()
{
    solve();
    return 0;
}
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
int n;
char a[MAXN], b[MAXN];
int mp[25][25];
void solve()
{
    n = read();
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    memset(mp, 0, sizeof mp);
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] > b[i])
        {
            puts("-1");
            return;
        }
        if (a[i] < b[i])
        {
            mp[a[i] - 'a'][b[i] - 'a'] = 1;
        }
    }
    //类似于弗洛伊德的
    int ans = 0;
    for (int i = 0; i < 20; i ++)
    {
        for (int j = i + 1; j < 20; j ++)
        {
            if (mp[i][j])
            {
                ans ++;
                for (int k = j + 1; k < 20; k ++)
                {
                    if (mp[i][k])
                        mp[j][k] = 1; //i未竟的事业就由j来完成吧（这么像傻卵二次元）
                }
                break;
            }
        }
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
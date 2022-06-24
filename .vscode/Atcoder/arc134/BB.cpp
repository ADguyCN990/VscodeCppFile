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
vector <int> pos[MAXN];
int n;
char s[MAXN];
void solve()
{
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
        pos[(int)(s[i] - 'a')].pb(i);
    int q = n;
    //q表示最后一位能取到的位置
    for (int p = 1; p < q; p ++)
    {
        for (int i = 0; i < 26; i ++)
        {
            char c = 'a' + i;
            if (c >= s[p]) break;
            while (pos[i].size() && pos[i].back() > q)
                pos[i].pop_back();
            if (pos[i].size() && pos[i].back() > p)
            {
                int now = p;
                int to = pos[i].back();
                pos[i].pop_back();
                swap(s[now], s[to]);
                q = to - 1;
            }
        }
    }
    puts(s + 1);
}

int main()
{
    solve();
    return 0;
}
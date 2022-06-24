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
char s[MAXN];
vector <int> pos[30];
void solve()
{
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
    {
        int u = s[i] - 'a';
        pos[u].pb(i);
    }
    int p = 1, q = n; 
    for (int p = 1; p < q; p ++)
    {
        for (int i = 0; i < 26; i ++)
        {
            char c = 'a' + i;
            if (c < s[p]) 
            {
                while(pos[i].size() && pos[i].back() > q) 
                    pos[i].pop_back();
                if (!pos[i].empty() && p <= pos[i].back())
                {
                    int now = p;
                    int to = pos[i].back();
                    //printf("now: %d to: %d %c %c\n", now, to, s[now], s[to]);
                    swap(s[now], s[to]);
                    pos[i].pop_back();
                    q = to - 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) printf("%c", s[i]);
}

int main()
{
    solve();
    return 0;
}
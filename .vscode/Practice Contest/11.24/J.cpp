#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
int vis[MAXN];
int dis[MAXN];
int digit[4];

void fill(int x)
{
    for (int i = 0; i < 4; i++)
    {
        digit[i] = x % 10;
        x /= 10;
    }
}

int get()
{
    int x = 0;
    for (int i = 3; i >= 0; i--)
    {
        x = x * 10 + digit[i];
    }
    return x;
}

void pre()
{
    queue<int> q;
    q.emplace(0);
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    vis[0] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        fill(x);
        for (int i = 0; i < 4; ++i)
        {
            for (int j = i; j < 4; ++j)
            {
                //从i到j加
                for (int k = i; k <= j; ++k)
                {
                    digit[k]++;
                    if (digit[k] >= 10)
                        digit[k] -= 10;
                }
                int nxt = get();
                if (!vis[nxt])
                {
                    vis[nxt] = 1;
                    q.push(nxt);
                    dis[nxt] = dis[x] + 1;
                }

                //从i到j减
                for (int k = i; k <= j; ++k)
                {
                    digit[k] -= 2;
                    if (digit[k] < 0)
                        digit[k] += 10;
                }
                nxt = get();
                if (!vis[nxt])
                {
                    vis[nxt] = 1;
                    q.push(nxt);
                    dis[nxt] = dis[x] + 1;
                }

                //还原
                for (int k = i; k <= j; ++k)
                {
                    digit[k]++;
                    if (digit[k] >= 10)
                        digit[k] -= 10;
                }
            }
        }
    }
}

void solve()
{
    string a,b;
    cin>>a>>b;
    int x=0;
    for(int i=0;i<4;i++)
    {
        int d1=a[i]-'0';
        int d2=b[i]-'0';
        d2=(d2-d1+10)%10;//防止负数和大于等于10的数
        x=x*10+d2;
    }
    cout<<dis[x]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
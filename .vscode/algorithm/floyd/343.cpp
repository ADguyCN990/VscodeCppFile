#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
int n, m;
int mp[MAXN][MAXN];
int d[MAXN][MAXN]; //求传递闭包
int vis[MAXN];     //标记每个数有没有输出过

void floyd()
{
    memcpy(d, mp, sizeof(d));
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] |= d[i][k] & d[k][j];
            }
        }
    }
}

int check()
{
    for (int i = 0; i < n; i++)
        if (d[i][i])
            return 2;//有矛盾
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (!d[i][j] && !d[j][i])
                return 0;//无法确定
            if(d[i][j] && d[j][i])
                return 2;
        }
    }
    return 1;//可以确定
}

char get()
{
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            flag = 1;
            for (int j = 0; j < n; j++)
            {
                if (!vis[j] && d[j][i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                vis[i] = 1;
                return 'A' + i;
            }
        }
    }
}

void solve()
{
    int type = 0;  //0表示无法确定，1表示唯一确定，2表示有矛盾
    int times = 0; //确定时的轮数
    int f = 0;
    memset(mp,0,sizeof(mp));
    memset(d,0,sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        if (f)
            continue;
        int a = s[0] - 'A';
        int b = s[2] - 'A';
        mp[a][b] = 1; //表示a小于b
        floyd();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<d[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        type = check();
        // cout<<"type: "<<type<<endl;
        if (type == 2)
        {
            printf("Inconsistency found after %d relations.\n", i);
            f = 1;
        }
        else if (type == 1)
        {
            printf("Sorted sequence determined after %d relations: ", i);
            memset(vis, 0, sizeof(vis));
            for (int j = 1; j <= n; j++)
                printf("%c", get());
            printf(".\n");
            f = 1;
        }
    }
    if (!f)
        printf("Sorted sequence cannot be determined.\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m)
    {
        if (!n && !m)
            return 0;
        solve();
    }

    return 0;
}
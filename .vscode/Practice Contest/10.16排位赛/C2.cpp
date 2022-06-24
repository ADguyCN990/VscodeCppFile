#include <bits/stdc++.h>
using namespace std;
#define pie acos(-1.0) / 1000 //分好1000份
#define MAXN 1005
//分成1000份然后一个个对号入座
int n;
double x[MAXN], y[MAXN];
vector<int> mp[MAXN];
int id=0;
void build()
{
    cin>>n;
    int u,v;
    for (int i = 1; i < n; ++i)
    {
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
}
int dfs(int u, int father)//遍历树
{
    for (auto v : mp[u])
    {
        if (v == father)//找到爹了
            continue;
        x[v] = x[u] + cos(id * pie), y[v] = y[u] + sin(id * pie);    //(id/1000)*pi
        id++;
        dfs(v, u);
    }
    return id + 1;//f表示他的编号
}
int main()
{
    build();
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        printf("%.8f %.8f\n", x[i], y[i]);
    }
}

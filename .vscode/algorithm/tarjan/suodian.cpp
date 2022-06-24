#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005//点
int n;//点
int key[MAXN];//之前定义的，表示这个点位于哪个强连通分量
vector <int> original_mp[MAXN];//原图
vector <int> mp[MAXN];//缩点后的图

void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(auto j:original_mp[i])
        {
            if(key[i]==key[j]) continue;
            //如果这条边的两端同属于一个强连通分量，放弃连边
            mp[key[i]].emplace_back(key[j]);
            //将两个点对应的强连通分量的编号相连，加入新图。
            //显然，单个点也属于一个强连通分量
        }
    }
}

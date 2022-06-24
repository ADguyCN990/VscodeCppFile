#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
int n,w;
ll num[MAXN],point[MAXN],lazy[MAXN],rk[MAXN],pre[MAXN];//point表示第i个人的分数，rk表示某个分数线的总体排名
double sum[MAXN];
//两个标记
//给每个人打个标记，表示上次更新后的分数
//每个分数线打个标记，表示上次更新的时间
//lazy
void solve()
{
    cin>>n>>w;
    for(int i=0;i<w;i++)//i必须从0开始算起
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x;
            cin>>x;
            num[point[x]]+=rk[point[x]]*(i-lazy[point[x]]);//更新分数point[x]的排名和
            rk[point[x]]++;//有一个人摆脱了这个分数线，这个分数线的排名减一 
            lazy[point[x]]=i;//更新分数变化时间
            sum[x] += num[point[x]] - pre[x];//更新x这个人的排名排名
            point[x]++;
            
            //原来的分数要更新一遍，现在分数+1了，这个分数的也要更新一遍
            num[point[x]]+=rk[point[x]]*(i-lazy[point[x]]);
            lazy[point[x]]=i;
            pre[x]=num[point[x]];//标记这次更新后某个人分数的排名和
        }
    }
    for(int i=1;i<=n;i++)
    {
        num[point[i]]+=rk[point[i]]*(w-lazy[point[i]]);
        lazy[point[i]]=w;
        sum[i]+=num[point[i]]-pre[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout << fixed << setprecision(9) << (1.0 + sum[i] / w) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
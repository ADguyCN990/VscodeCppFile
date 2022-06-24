#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
double length;
double v,p,cost;
int n;
double dis[MAXN],price[MAXN];
double ans=0x3f3f3f3f;
void dfs(int now,double oil,double tmp)//当前加油站，当前剩余油量
{
    if(tmp>=ans) return;//最优性剪枝
    if(now==n+1)
    {
        ans=min(ans,tmp);
        return;
    }
    if(oil*2>=v&&oil*p>=(dis[now+1]-dis[now]))//必须的不用加油
    {
        dfs(now+1,oil-(dis[now+1]-dis[now])/p,tmp);
    }
    else if(oil*2>=v&&oil*p<(dis[now+1]-dis[now]))//必须要加油
    {
        dfs(now+1,v-(dis[now+1]-dis[now])/p,tmp+20+(v-oil)*price[now]);
    }
    else if(oil*2<v&&oil*p<(dis[now+1]-dis[now]))//必须加油
    {
        dfs(now+1,v-(dis[now+1]-dis[now])/p,tmp+20+(v-oil)*price[now]);
    }
    else if(oil*2<v&&oil*p>=(dis[now+1]-dis[now]))//可加可不加
    {
        //优化搜索顺序应该是先算加的情况
        dfs(now+1,v-(dis[now+1]-dis[now])/p,tmp+20+(v-oil)*price[now]);
        dfs(now+1,oil-(dis[now+1]-dis[now])/p,tmp);
    }

}

void solve()
{
    scanf("%lf",&length);
    scanf("%lf%lf%lf%d",&v,&p,&cost,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&dis[i],&price[i]);
    }
    
    dis[n+1]=length;
    dfs(1,v-dis[1]/p,cost);
    printf("%.1lf",ans);
}

int main()
{
    solve();
    return 0;
}
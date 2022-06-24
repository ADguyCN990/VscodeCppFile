#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL ans[55];
LL adj[55][55];
LL w[55];
LL wp[55][55];
LL kcnt[55][55];
LL dis[55];
bool vis[55];
vector<vector<int>> pathv[55];
int N,M;
int main(){
    memset(adj,0x3f,sizeof(adj));
    memset(dis,0x3f,sizeof(dis));
    scanf("%d %d",&N,&M);
    for(int i=1;i<=M;i++){
        scanf("%lld",&w[i]);
    }
    for(int m=1;m<=M;m++){
        int v1,v2;
        LL wi;
        scanf("%d %d %lld",&v1,&v2,&wi);
        adj[v1][v2] = adj[v2][v1] = wi;
        wp[v1][v2] = wp[v2][v1] = w[m];
    }
    priority_queue<pair<LL,int>> pq;
    dis[1] = 0;
    vector<int> empv;
    pathv[1].emplace_back(empv);
    pq.push({0,1});
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        int v = p.second;
        if(vis[v]) continue;
        vis[v] = true;
        for(int w=1;w<=N;w++){
            if(!vis[w]&&adj[v][w]<INF&&dis[w]>=adj[v][w]+dis[v]){
                if(dis[w]>adj[v][w]+dis[v]) {
                    pathv[w].clear();
                    dis[w] = adj[v][w]+dis[v];
                    pq.push({dis[w],w});
                }
                for(auto sp:pathv[v]){
                    sp.emplace_back(v);
                    pathv[w].emplace_back(sp);
                }
            }
        }
    }
    for(int i=2;i<=N;i++){
        LL maxW = INF;
        for(auto& p:pathv[i]){
            p.emplace_back(i);
            LL tmpW = 0;
            for(int v=0;v<p.size()-1;v++){
                kcnt[p[v]][p[v+1]]++;
                kcnt[p[v+1]][p[v]]++;
                tmpW+=kcnt[p[v]][p[v+1]]*wp[p[v]][p[v+1]];
            }
            maxW = min(maxW,tmpW);
        }
        printf("%lld\n",maxW);
    }
    return 0;
}
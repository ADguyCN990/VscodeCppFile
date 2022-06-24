#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

int n, m;
int to[1000005], nxt[1000005], w[1000005], at[100005] = {0}, cnt = 0;
int dis[3][100005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int lis[100005], tot;
void dijkstra(int dist[], int S){
    while (!pq.empty()) pq.pop();
    
    dist[S] = 0;
    pq.push(make_pair(0, S));
    tot = 0;
    for (; ; ){
        while (!pq.empty()){
            if (pq.top().first > dist[pq.top().second])
                pq.pop();
            else break;
        }
        if (pq.empty()) break;
        int dd = pq.top().first, h = pq.top().second;
        pq.pop();
        lis[tot++] = h;
        for (int i = at[h]; i; i = nxt[i]){
            if (dist[to[i]] > dd + w[i]){
                dist[to[i]] = dd + w[i];
                pq.push(make_pair(dist[to[i]], to[i]));
            }
        } 
    } 
}

int seg[270005], siz, tmp[100005];
unordered_map<int, int> mp;
pair<int, pair<pair<int, int>, int> > tmp2[100005];
bool vis[100005] = {0};
void update(int k, int x){
    k += siz - 1;
    seg[k] = min(seg[k], x);
    while (k > 1){
        k >>= 1;
        seg[k] = min(seg[k << 1], seg[k << 1 | 1]);
    }
}
int query(int id, int l, int r, int b){
    if (l > b) return INF;
    if (r <= b) return seg[id];
    int mid = (l + r) >> 1;
    return min(query(id << 1, l, mid, b), query(id << 1 | 1, mid + 1, r, b));
}

void solve_2d(int l, int r){
    int pre_mini = INF;
    for (int i = l, j; i < r; i = j){
        j = i;
        while (j < r && tmp2[i].second.first == tmp2[j].second.first)
            ++j;
        // #0 the same, #2 the same, so impossible for the others
        int rb = j;
        while (j < r && tmp2[i].second.first.first == tmp2[j].second.first.first){
            vis[tmp2[j].second.second] = true;
            ++j;        
        }
        int tmp_mini = tmp2[i].second.first.second;
        if (pre_mini <= tmp_mini){
            while (i < rb) {
                vis[tmp2[i].second.second] = true;
                ++i;
            }
        } else pre_mini = tmp_mini;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, ww; i <= m; ++i){
        scanf("%d%d%d", &u, &v, &ww);
        to[++cnt] = v, nxt[cnt] = at[u], w[cnt] = ww, at[u] = cnt;
        to[++cnt] = u, nxt[cnt] = at[v], w[cnt] = ww, at[v] = cnt;
    }
    
    memset(dis, 0x3f, sizeof(dis));
    dijkstra(dis[0], 0);
    dijkstra(dis[1], 1);
    dijkstra(dis[2], 2);
    // connected graph, so tot = n
    
    // discretize the dist for #0
    for (int i = 0; i < n; ++i)
        tmp[i] = dis[0][i];
    sort(tmp, tmp + n);
    int nn = unique(tmp, tmp + n) - tmp;
    for (int i = 0; i < nn; ++i){
        mp[tmp[i]] = i + 1;
    }
    
    // initialize segment tree
    for (siz = 1; siz < nn; siz <<= 1)
        ;
    for (int i = 1; i < siz + siz; ++i)
        seg[i] = INF;
    
    // sort by #2
    for (int i = 0; i < n; ++i){
        tmp2[i].first = dis[2][i];
        tmp2[i].second.second = i;
    }
    for (int i = 0; i < n; ++i){
        tmp2[i].second.first.first = dis[0][i];
    }
    for (int i = 0; i < n; ++i){
        tmp2[i].second.first.second = dis[1][i];
    }
    sort(tmp2, tmp2 + n);
    
    // calc ans
    for (int i = 0, j; i < n; i = j){
        j = i;
        while (j < n && tmp2[i].first == tmp2[j].first)
            ++j;
        solve_2d(i, j);
        
        // use segment tree
        for (int t = i; t < j; ++t){
            int id = tmp2[t].second.second;
            if (vis[id]) continue;
            if (query(1, 1, siz, mp[tmp2[t].second.first.first]) <=
                tmp2[t].second.first.second)
                vis[id] = true;
        }
        
        // insert into segment tree
        for (int t = i; t < j; ++t){
            update(mp[tmp2[t].second.first.first], tmp2[t].second.first.second);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (!vis[i]) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}

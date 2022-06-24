#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 200005
 
int head[MAXN], nxt[MAXN], tot;
int low[MAXN], dfn[MAXN], num;
int root, cnt;
int f[MAXN];
int n, m;

ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

struct Edge {
    int u, v, sign;
} E[MAXN];
 
int findx(int x) {
    if (f[x] == x) return x;
    return f[x] = findx(f[x]);
}
 
void Union(int u, int v) {
    int fx = findx(u);
    int fy = findx(v);
    if (fx != fy)
        f[fy] = fx;
}
 
void edge_init() {
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(nxt, -1, sizeof(nxt));
}
 
void edge_add(int u, int v) {
    E[tot].u = u;
    E[tot].v = v;
    E[tot].sign = false;
    nxt[tot] = head[u];
    head[u] = tot++;
}
 
void tarjan_init() {
    cnt = 0;
    num = 0;
    memset(dfn, 0, sizeof(dfn));
}
 
int tarjan(int u, int from) {
    low[u] = dfn[u] = ++num;
 
    for(int id = head[u]; ~id; id = nxt[id]) {
        int v = E[id].v;
 
        if(!dfn[v]) {
            int lowv = tarjan(v, u);
            low[u] = min(low[u], lowv);
 
            if(lowv > dfn[u]) {
                E[id].sign = 1;
                E[id ^ 1].sign = 1;
                cnt++;
            } else {
                Union(u, v);
            }
        } else if(v != from) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    return low[u];
}
 
int work(int u, int from, int &ans) {
    int Max1 = 0, Max2 = 0;
    for(int id = head[u]; ~id; id = nxt[id]) {
        int v = E[id].v;
        if(v == from) continue;
 
        int t = work(v, u, ans) + 1;
 
        if(t > Max1) {
            Max2 = Max1;
            Max1 = t;
        } else if(t > Max2) Max2 = t;
    }
 
    ans = max(ans, Max1 + Max2);
    return Max1;
}
 
void solve() {
    n = read(), m = read();
    edge_init();
    tarjan_init();
    for (int i = 1; i <= n; i++) f[i] = i;
 
    for(int i = 1; i <= m; i++) {
        int u, v;
        u = read(), v = read();
        edge_add(u, v);
        edge_add(v, u);
    }
 
    tarjan(1, -1);
 
    int tmp = tot;
 
    edge_init();
    for(int i = 0; i < tmp; i++) {
        if(E[i].sign) {
            int u = findx(E[i].u), v = findx(E[i].v);
            edge_add(u, v);
            root = u;
        }
    }
 
    int ans = 0;
    if(cnt) work(root, -1, ans);
    printf("%d\n", cnt - ans);
}


int main() {
    int T;
    T = read();
    while (T--) {
        solve();
    }
    return 0;
}
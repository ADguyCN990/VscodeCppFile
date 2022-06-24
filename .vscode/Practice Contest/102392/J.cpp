#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 1000005
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
struct node {
    int u, v, w;
    friend bool operator< (node a, node b) {
        return a.w < b.w;
    }
}e[MAXM];

int head[MAXN], tot;
struct EDGE {
    int to, next, val;
}edge[MAXM << 1];
void add(int from, int to, int val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}

ll ans = 0;
int n, m;

int main() {
    n = read();
    m = n * (n - 1) / 2;
    for (int i = 1; i <= m; i++) {
        e[i].u = read(), e[i].v = read(), e[i].w = read();
    }    
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++) {
        add(e[i].u, e[i].v, e[i].w);
        add(e[i].v, e[i].u, e[i].w);
    }
    for (int now = 1; now <= n; now++) {
        for (int i = head[now]; i; i = edge[i].next) {
            ans += edge[i].val;
            i = edge[i].next;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
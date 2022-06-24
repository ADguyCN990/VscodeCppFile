#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
double V;
int hh = 1, tt = 0;
struct node {
    double v;
    double t;
}q[MAXN];

void solve() {
    scanf("%d%lf", &n, &V);
    V += 0.0;
    double tot = 0.0;
    double up = 0;
    //单调增队列
    for (int i = 1; i <= n; i++) {
        double v, t;
        scanf("%lf%lf", &t, &v);
        node now = {v, t};
        tot += v;
        while (hh <= tt && tot - q[hh].v > V) {
            up -= q[hh].v * q[hh].t;
            tot -= q[hh].v;
            hh++;
        }
        if (tot > V) {
            double dif = tot - V;
            up -= q[hh].t * dif;
            q[hh].v -= dif;
            tot = V;
        }
        while (hh <= tt && now.t < q[tt].t) {
            up -= q[tt].t * q[tt].v;
            now.t = (now.v * now.t + q[tt].v * q[tt].t) / (now.v + q[tt].v);
            now.v += q[tt].v;
            tt--;
        }
        q[++tt] = now;
        up += now.v * now.t;
        printf("%.6lf\n", up / V);
    }
}

int main() {
    solve();
    return 0;
}
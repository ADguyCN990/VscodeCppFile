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
ll n, m, d;
ll a[MAXN];
ll dis[MAXN];//执行i次操作后距离终点的距离
ll dp[MAXN];//执行[i, n]的操作无法到达终点距离的最小位置
void solve() {
    n = read(), d = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    dis[0] = d;
    for (int i = 1; i <= n; i++) {
        dis[i] = dis[i - 1];
        if (dis[i - 1] >= a[i]) 
            dis[i] = dis[i - 1] - a[i];
        else if (a[i] - dis[i - 1] < dis[i - 1])
            dis[i] = a[i] - dis[i - 1];
    }
    //修改第i个操作，此时位于dis[i - 1]的位置上
    //因此下个操作后，距终点有[0,dis[i - 1]]的距离
    
    dp[n + 1] = 1; //不经过任何操作，最小距离为1
    for (int i = n; i >= 1; i--) {
        //操作不执行
        if (a[i] >= dp[i + 1] * 2)
            dp[i] = dp[i + 1];
        else
            dp[i] = dp[i + 1] + a[i];
    }
    m = read();
    //若f[i+1]>=dis[i-1]说明无论如何也无法到达终点
    for (int i = 1; i <= m; i++) {
        int x = read();
        if (dp[x + 1] > dis[x - 1]) {
            puts("NO");
        }
        else
            puts("YES");
    }
    
}

int main() {
    solve();
    return 0;
}
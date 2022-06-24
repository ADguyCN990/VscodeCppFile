#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
int a[MAXN], c[MAXN];
int n, k;
vector<int> ans[MAXN];

void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= k; i++) c[i] = read();
    sort(a + 1, a + 1 + n, greater<>());
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int cnt = 1;
    q.emplace(0, 1);
    for (int i = 1; i <= n; i++) {
        pii now = q.top();
        q.pop();
        int id = now.second;
        int num = now.first;
        //如果当前还能放
        if (num < c[a[i]]) {
            ans[id].pb(a[i]);
            q.emplace(num + 1, id);
        }    
        //新开一个数组
        else {
            cnt++;
            q.emplace(1, cnt);
            q.emplace(now);
            ans[cnt].pb(a[i]);
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        printf("%d ", ans[i].size());
        for (int j = 0; j < (int)ans[i].size(); j++)
            printf("%d ", ans[i][j]);
        puts("");
    }
}

int main() {
    solve();
    return 0;
}
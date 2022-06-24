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
int n, m;
int a[MAXN];
int mx[MAXN], mn[MAXN];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        mx[i] = max(mx[i], val); //更新最大值
        mn[i] = min(mn[i], val); //更新最小值
    }
}

int querymax(int l, int r) {
    if (r > l) {
        if (r - lowbit(r) > l) //前一个区间不是l所对应的区间
            return max(mx[r], querymax(l, r - lowbit(r)));
        else
            return max(a[r], querymax(l, r - 1));
    }
    return a[l];
}

int querymin(int l, int r) {
    if (r > l) {
        if (r - lowbit(r) > l) 
            return min(mn[r], querymin(l, r - lowbit(r)));
        else 
            return min(a[r], querymin(l, r - 1));
    }
    return a[l];
} 

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) mn[i] = INF;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        update(i, a[i]);
    }
    while (m--) {
        int l = read(), r = read();
        printf("%d\n", querymax(l, r) - querymin(l, r));
    }
}

int main() {
    solve();
    return 0;
}
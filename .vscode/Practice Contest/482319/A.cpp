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
struct node {
    string id;
    ll problem;
    ll tim;
    bool friend operator< (node a, node b) {
        if (a.problem == b.problem)
            return a.tim < b.tim;
        return a.problem > b.problem;
    }
}a[MAXN];
void solve() {
    int n = read();
    for (int i = 1; i <= n; i++) {
        cin >> a[i].id >> a[i].problem >> a[i].tim;
    } 
    sort(a + 1, a + 1 + n);
    cout << a[1].id << "\n";
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
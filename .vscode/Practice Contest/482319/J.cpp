#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
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
ll n, m;
ll a[MAXN], b[MAXN];
void solve() {
    n = read(), m = read();
    
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) b[i] = read();
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    vector<pii> pa;
    int cnt = 0, id = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i] == a[i - 1]) {
            cnt++;
        }
        else {
            pa.push_back({id, cnt});
            cnt = 1;
            id++;
        }
    }
    pa.push_back({id, cnt});
    vector<pii> pb;
    cnt = 0, id = 1;
    for (int i = 1; i <= m; i++) {
        if (i == 1 || b[i] == b[i - 1]) {
            cnt++;
        }
        else {
            pb.push_back({id, cnt});
            cnt = 1;
            id++;
        }
    }
    pb.push_back({id, cnt});
    int i;
    int now = 0;
    int lenb = pb.size();
    int lena = pa.size();
    //printf("lena: %d, lenb: %d\n", lena, lenb);
    if (lena > lenb) {
        puts("NO");
        return;
    }
    for (i = 0; i < pa.size(); i++) {
        if (now == lenb) {
            puts("NO");
            return;
        }
        while (pb[now].second < pa[i].second && now < lenb)
            now++;
        if (now == lenb) {
            puts("NO");
            return;
        }
        now++;
    }
    puts("YES");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
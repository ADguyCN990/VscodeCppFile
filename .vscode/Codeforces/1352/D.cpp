#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
int a[MAXN];
ll sum[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n;
    ll alice = 0, bob = 0;
    int cnt = 0;
    ll pre = 0;
    while (l <= r) {
        cnt++;
        if (cnt == 1) {
            alice = a[1];
            pre = a[1];
            l = 2;
            continue;
        }
        if (cnt & 1) {
            //Alice的回合
            for (int j = l; j <= r; j++) {
                ll tmp = sum[j] - sum[l - 1];
                if (j == r && tmp <= pre) {
                    l = r + 1;
                    alice += tmp;
                    break;
                }
                if (tmp > pre) {
                    pre = tmp;
                    alice += tmp;
                    l = j + 1;
                    break;
                }
            }
        }
        else {
            //Bob的回合
            for (int j = r; j >= l; j--) {
                ll tmp = sum[r] - sum[j - 1];
                if (j == l && tmp <= pre) {
                    r = l - 1;
                    bob += tmp;
                    break;
                }
                if (tmp > pre) {
                    pre = tmp;
                    bob += tmp;
                    r = j - 1;
                    break;
                }
            }
        }
    }
    printf("%d %lld %lld\n", cnt, alice, bob);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
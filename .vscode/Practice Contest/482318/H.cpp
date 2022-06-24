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
ll n, W;
ll w[105], v[105];
ll zero[105], one[105], two[105], three[105];
ll sum0[105], sum1[105], sum2[105], sum3[105];
int idx0, idx1, idx2, idx3;
void solve() {
    n = read(), W = read();
    idx1 = 0, idx0 = 0, idx2 = 0, idx3 = 0;
    for (int i = 1; i <= n; i++) {
        v[i] = read(), w[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        int dif = v[i] - v[1];
        if (dif == 0)
            zero[++idx0] = w[i];
        else if (dif == 1)
            one[++idx1] = w[i];
        else if (dif == 2)
            two[++idx2] = w[i];
        else if (dif == 3)
            three[++idx3] = w[i];
    }
    sort(zero + 1, zero + 1 + idx0, greater<>());
    sort(one + 1, one + 1 + idx1, greater<>());
    sort(two + 1, two + 1 + idx2, greater<>());
    sort(three + 1, three + 1 + idx3, greater<>());
    for (int i = 1; i <= idx0; i++) sum0[i] = sum0[i - 1] + zero[i];
    for (int i = 1; i <= idx1; i++) sum1[i] = sum1[i - 1] + one[i];
    for (int i = 1; i <= idx2; i++) sum2[i] = sum2[i - 1] + two[i];
    for (int i = 1; i <= idx3; i++) sum3[i] = sum3[i - 1] + three[i];
    ll ans = 0;
    for (int i = 0; i <= idx0; i++) {
        for (int j = 0; j <= idx1; j++) {
            for (int k = 0; k <= idx2; k++) {
                for (int o = 0; o <= idx3; o++) {
                    ll totalw = sum0[i] + sum1[j] + sum2[k] + sum3[o];
                    ll totalv = v[1] * i + (v[1] + 1) * j + (v[1] + 2) * k + (v[1] + 3) * o;
                    if (totalv <= W) {
                        ans = max(ans, totalw);
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
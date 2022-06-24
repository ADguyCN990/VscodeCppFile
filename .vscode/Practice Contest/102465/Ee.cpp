#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"                                                                                                          
#define MAXN 10005
ll al[MAXN], ar[MAXN], ml[MAXN], mr[MAXN], n, cnt, suml, sumr;
ll a[MAXN];
string s[MAXN];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> a[i];
        a[i] *= 100;
        cnt += a[i];
        al[i] = max(0ll, a[i] - 50);
        ar[i] = min(10000ll, a[i] + 49);
        suml += al[i];
        sumr += ar[i];
    }
    if (suml > 10000 || sumr < 10000) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        ml[i] = max(al[i], 10000 - (sumr - ar[i]));
        mr[i] = min(ar[i], 10000 - (suml - al[i]));
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i] << " " << ml[i] / 100 << "." ;
        if (ml[i] % 100 < 10)
            cout << "0";
        cout << ml[i] % 100 << " " << mr[i] / 100 << ".";
        if (mr[i] % 100 < 10)
            cout << "0";
        cout << mr[i] % 100 << endl;
    }
    return 0;
}

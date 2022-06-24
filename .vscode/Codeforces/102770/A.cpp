#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> bad;
int month[15];

void pre() {
    month[1] = 31, month[2] = 28, month[3] = 31, month[4] = 30, month[5] = 31, month[6] = 30, month[7] = 31;
    month[8] = 31, month[9] = 30, month[10] = 31, month[11] = 30, month[12] = 31;
    for (int i = 2000; i <= 9999; i++) {
        for (int j = 1; j <= 12; j++) {
            int m = month[j];
            if ((j == 2) && (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)) m++;
            for (int k = 1; k <= m; k++) {
                string s = to_string(i * 10000 + j * 100 + k);
                if (s.find("202") != -1) bad.push_back(i * 10000 + j * 100 + k);
            }
        }
    }
}

void solve() {
    ll a, b, c;
    ll x, y, z;
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x, &y, &z);
    ll st = a * 10000 + b * 100 + c;
    ll ed = x * 10000 + y * 100 + z;
    auto pos1 = lower_bound(bad.begin(), bad.end(), st);
    auto pos2 = upper_bound(bad.begin(), bad.end(), ed);
    printf("%d\n", pos2 - pos1);
}

int main() {
    int t;
    scanf("%d", &t);
    pre();
    while (t--)
        solve();
    return 0;
}
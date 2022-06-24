#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
int n;
vector<int> num;
int a[MAXN];
int l[MAXN], r[MAXN];
int c[MAXN];
int find(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i)) c[i]++;
}

int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += c[i];
    return ans;
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), num.push_back(a[i]);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= n; i++) {
        int now = find(a[i]);
        l[i] = ask(now - 1);
        add(now);
    }
    reverse(a + 1, a + 1 + n);
    memset(c, 0, sizeof c);

    for (int i = 1; i <= n; i++) {
        int now = find(a[i]);
        r[n - i + 1] = ask(now - 1);
        add(now);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //printf("l: %d r: %d\n", l[i], r[i]);
        ans += min(l[i], r[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
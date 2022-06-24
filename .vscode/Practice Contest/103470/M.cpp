#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
int n;
ll a[MAXN];

ll read(){
    ll x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-') f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while  (ch>='0' && ch<='9');
    return x * f;
}

void solve() {
    scanf("%d", &n);
    ll sa = 0, mn = 1e18 + 1;
    bool neg = false, pos = false;
    for (int i = 1; i <= n; i++){
        a[i] = read();
        if (a[i] >= 0) pos = true;
        if (a[i] <= 0) neg = true;
        sa += abs(a[i]);
        mn = min(mn, abs(a[i]));
    }
    ll res = 0;
    if (pos && neg){
        res = sa;
    }
    else{
        res = sa - mn * 2;
    }
    printf("%lld\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}
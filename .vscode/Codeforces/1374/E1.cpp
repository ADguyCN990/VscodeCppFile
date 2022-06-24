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
int n, k;
int t[MAXN];
int a[MAXN], b[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        t[i] = read(), a[i] = read(), b[i] = read();
    }    
    vector<int> alice, bob, all;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 && b[i] == 0)
            alice.pb(t[i]);
        else if (a[i] == 0 && b[i] == 1)
            bob.pb(t[i]);
        else if (a[i] && b[i])
            all.pb(t[i]); 
    }
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    for (int i = 0; i < min(alice.size(), bob.size()); i++) {
        all.pb(alice[i] + bob[i]);
    }
    sort(all.begin(), all.end());
    if (all.size() < k) {
        puts("-1");
        return;
    }
    int sum = 0;
    for (int i = 0; i < k; i++) 
        sum += all[i];
    printf("%d\n", sum);
}

int main() {
    solve();
    return 0;
}
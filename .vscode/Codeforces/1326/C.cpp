#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define mod 998244353
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n, k;
struct node {
    int id;
    int val;
    friend bool operator< (node a, node b) {
        return a.val > b.val;
    }
}a[MAXN];
int main() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i].val = read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    ll ans = 1;
    ll sum = a[1].val;
    vector<int> pos;
    pos.push_back(a[1].id);
    for (int i = 2; i <= k; i++) {
        pos.push_back(a[i].id);
        sum += a[i].val;
    }
    sort(pos.begin(), pos.end());
    for (int i = 1; i < pos.size(); i++)
        ans = ans * (pos[i] - pos[i - 1]) % mod;
    printf("%lld %lld\n", sum, ans);
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n;
int a[MAXN], b[MAXN];
map<int, int> cnt;
vector<int> num;
ll ans = 0;
int c[MAXN];
int findx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

int lowbit(int x) {return x & -x;}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i]++;
}

int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
        b[i] = read();
        num.push_back(b[i] - a[i]);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int len = num.size();
    for (int i = 1; i <= n; i++) {
        int now = a[i] - b[i];
        int id = findx(now);
        ans += ask(id - 1);
        add(findx(b[i] - a[i]));
    }
    printf("%lld\n", ans);
}
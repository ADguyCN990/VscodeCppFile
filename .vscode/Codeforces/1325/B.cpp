#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

void solve() {
    int n = read();
    set<int> s;
    for (int i = 1; i <= n; i++) {
        int x = read();
        s.insert(x);
    }
    printf("%d\n", (int)(s.size()));
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}
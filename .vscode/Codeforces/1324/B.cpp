#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n;
int a[MAXN];
int cnt[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (cnt[a[i]] == 2 || cnt[a[i]] == 1 && a[i - 1] != a[i]) {
            flag = true;
        }
        cnt[a[i]]++;
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}
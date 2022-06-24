#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;

void solve() {
    n = read();
    if (n == 1) {
        puts("-1");
        return;
    }
    printf("2");
    for (int i = 1; i < n; i++) printf("3");
    puts("");
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}
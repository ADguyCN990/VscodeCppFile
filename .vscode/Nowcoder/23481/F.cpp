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
char s[MAXN];
void solve() {
    scanf("%s", s + 1);
    k = read();
    n = strlen(s + 1);
    int add = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '+')
            add ++;
    int sub = n - add;
    //printf("+: %d -: %d\n", add, sub);
    int opt = abs(add - sub) / 2;
    if (k <= opt) {
        printf("%d\n", abs(add - sub) - k * 2);
        return;
    }
    int extra = k - opt;
    if (extra & 1 && abs(add - sub) & 1) {
        puts("1");
    }
    else if (extra % 2 == 0 && abs(add - sub) & 1) {
        puts("1");
    }
    else if (extra & 1 && abs(add - sub) % 2 == 0) {
        puts("2");
    }
    else if (extra % 2 == 0 && abs(add - sub) % 2 == 0) {
        puts("0");
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
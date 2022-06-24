#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305
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
int a[MAXN][MAXN];

void output() {
    if (k % n == 0)
        puts("0");
    else
        puts("2");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", a[i][j]);
        }
        puts("");
    }
}

void solve() {
    n = read(), k = read();
    memset(a, 0, sizeof a);
    int len = k / n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j <= i + len - 1; j++) {
            int tmp = j % n;
            a[i][tmp] = 1;
        }
    }
    if (k % n)
    {
        int cnt = k % n;
        for (int i = 0; i < cnt; i++) {
            int tmp = (len + i) % n;
            a[i][tmp] = 1;
        }
    } 
    output();
    
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
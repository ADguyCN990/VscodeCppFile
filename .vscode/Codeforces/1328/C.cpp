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
int n;
char s[MAXN];
int a[MAXN], b[MAXN]; //a是较大的数
void solve() {
    n = read();
    scanf("%s", s + 1);
    bool flag = false;
    if (s[1] == '0') {
        flag = true;
        a[1] = 2, b[1] = 1;
    }
    else {
        if (s[1] == '1')
            a[1] = 2, b[1] = 2;
        else
            a[1] = 1, b[1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        int u = s[i] - '0';
        if (flag) {
            if (u == 0)
                a[i] = 0, b[i] = 0;
            else if (u == 1)
                a[i] = 0, b[i] = 1;
            else if (u == 2)
                a[i] = 0, b[i] = 2;
        }
        else {
            if (u == 0)
                a[i] = 0, b[i] = 0;
            else if (u == 1) {
                a[i] = 1, b[i] = 0;
                flag = true;
            }
            else 
                a[i] = 1, b[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d", a[i]);
    puts("");
    for (int i = 1; i <= n; i++) printf("%d", b[i]);
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
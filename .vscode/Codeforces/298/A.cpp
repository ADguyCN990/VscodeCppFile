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
void solve() {
    n = read();
    scanf("%s", s + 1);
    int a = 0, t = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'R' && s[i] == 'L') {
            t = i;
        }
        if (s[i] == 'L' && s[i + 1] == '.' || i == n) {
            a = i;
            break;
        }
    }
    if (a != 0 && t != 0) {
        printf("%d %d\n", a, t);
        return;
    }
    int x, y;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L' && (i == 1 || s[i - 1] == '.')) {
            x = i;
            y = i - 1;
            break;
        }
        else if (s[i] == 'R' && (i == n || s[i + 1] == '.')) {
            x = i;
            y = i + 1;
            break;
        }
    }
    printf("%d %d\n", x, y);
}

int main() {
    solve();
    return 0;
}
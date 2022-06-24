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
ll a, b, x, y;
void solve() {
    n = read();
    a = read(), b = read(), x = read(), y = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'E' && a < x)
            a++;
        else if (s[i] == 'W' && a > x)
            a--;
        else if (s[i] == 'S' && b > y)
            b--;
        else if (s[i] == 'N' && b < y)
            b++;
        if (a == x && b == y) {
            printf("%d\n", i);
            return;
        }
    }
    puts("-1");
}

int main() {
    solve();
    return 0;
}
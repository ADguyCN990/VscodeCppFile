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
string a, b;
int n, m;
void solve() {
    cin >> a >> b;
    n = a.length(), m = b.length();
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == '1')
            x++;
    for (int i = 0; i < m; i++)
        if (b[i] == '1')
            y++;
    if (x & 1 && x + 1 >= y || !(x & 1) && x >= y) {
        puts("YES");
    }
    else
        puts("NO");
}

int main() {
    solve();
    return 0;
}
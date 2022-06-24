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
void solve() {
    ll x, xx, y, yy;
    x = read(), y = read(), xx = read(), yy = read();
    ll dx = abs(x - xx);
    ll dy = abs(y - yy);
    if (dx == 2 && dy == 0 || dy == 2 && dx == 0) {
        puts("Yes");
    }
    else if (dx == 3 && dy == 1 || dy == 3 && dx == 1) {
        puts("Yes");
    }
    else if (dx == 3 && dy == 3) {
        puts("Yes");
    }
    else if (dx == 2 && dy == 4 || dx == 4 && dy == 2) {
        puts("Yes");
    }
    else if (dx == 0 && dy == 4 || dy == 0 && dx == 4) {
        puts("Yes");
    }
    else if (dx == 1 && dy == 1) {
        puts("Yes");
    }
    else
        puts("No");
}

int main() {
    solve();
    return 0;
}
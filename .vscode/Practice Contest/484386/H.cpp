#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
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
ll a[MAXN][MAXN];
ll n;
ll sum1[MAXM], sum2[MAXM];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum1[i + j] += a[i][j];
            sum2[i - j + n] += a[i][j];
        }
    }
    int x, y, xx, yy; 
    ll odd = -1, even = -1; //一条奇偶相同的线，一条奇偶不同的线
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 != j % 2) {
                //(x,y)
                if (odd < sum1[i + j] + sum2[i - j + n] - a[i][j]) {
                    x = i;
                    y = j;
                    odd = sum1[i + j] + sum2[i - j + n] - a[i][j];
                }
            }
            else {
                //(xx,yy)
                if (even < sum1[i + j] + sum2[i - j + n] - a[i][j]) {
                    xx = i;
                    yy = j;
                    even = sum1[i + j] + sum2[i - j + n] - a[i][j];
                }
            }
        }
    }
    printf("%lld\n", odd + even);
    printf("%d %d %d %d\n", x, y, xx, yy);
}

int main() {
    solve();
    return 0;
}
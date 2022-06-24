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
ll n;
string dic = "0123456789ABCDEF";
int cir[20];
void solve() {
    ll n = read();
    cir[0] = 1, cir[1] = 0, cir[2] = 0, cir[3] = 0;
    cir[4] = 1, cir[5] = 0, cir[6] = 1, cir[7] = 0;
    cir[8] = 2, cir[9] = 1, cir[10] = 1, cir[11] = 2;
    cir[12] = 0, cir[13] = 1, cir[14] = 0, cir[15] = 0;
    int ans = 0;
    while (n) {
        int num = n % 16;
        ans += cir[num];
        n /= 16;
    } 
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
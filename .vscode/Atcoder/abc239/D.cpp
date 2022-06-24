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

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void solve() {
    int a, b, c, d;
    a = read(), b = read(), c = read(), d = read();
    //先手要选一个数字，使得没有质数
    for (int i = a; i <= b; i++) {
        bool f = true;
        for (int j = c; j <= d; j++) {
            bool flag = isprime(i + j);
            if (flag) { //能选出质数
                f = false;
                break;
            }
        }
        if (f) {
            puts("Takahashi");
            return;
        }
    }
    puts("Aoki");
}

int main() {
    solve();
    return 0;
}
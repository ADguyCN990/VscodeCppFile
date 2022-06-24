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
bool isprime[MAXN];
void solve() {
    int n = read();
    for (int i = 2; i <= 200000; i++) isprime[i] = true; 
    for (int i = 2; i <= 200000; i++) {
        for (int j = 2 * i; j <= 200000; j += i) {
            isprime[j] = false;
        }
    }
    if (n <= 2) {
        puts("1");
        for (int i = 1; i <= n; i++) printf("1 ");
        puts("");
        return;
    }
    puts("2");
    for (int i = 1; i <= n; i++) {
        if (isprime[i + 1])
            printf("1 ");
        else
            printf("2 ");
    }

}

int main() {
    solve();
    return 0;
}
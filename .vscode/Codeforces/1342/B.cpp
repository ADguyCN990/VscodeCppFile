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
char t[105];
int n;
void solve() {
    scanf("%s", t + 1);
    n = strlen(t + 1);   
    bool flag = true;
    for (int i = 2; i <= n; i++) {
        if (t[i] != t[i - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        puts(t + 1);
        return;
    }
    if (t[1] == '0')
        for (int i = 1; i <= n; i++)
            printf("01");
    else
        for (int i = 1; i <= n; i++)
            printf("10");
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
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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

char s[MAXN];
int n;

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int pos = -1;//第二个不同的字符出现的位置
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            pos = i;
            break;
        }
    } 
    if (pos == -1) {
        printf("%d\n", n - 1);
        return;
    }
    int len = n - pos + 1;
    printf("%d\n", n + len);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
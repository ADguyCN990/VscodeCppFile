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
int n, k;
int cnt[30];
char s[MAXN];

bool check(int len, int num) {
    //len表示循环节长度，num表示循环节个数
    for (int i = 0; i < 26; i++) {
        len -= cnt[i] / num; //每个字符有cnt个，循环节个数有num个，对每个循环节的贡献长度就是 cnt / num 个
    }
    if (len <= 0)
        return true;
    return false;
}

void solve() {
    n = read(), k = read();
    scanf("%s", s + 1);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        int u = s[i] - 'a';
        cnt[u]++;
    }
    int ans = 0; //特判每个数字都相同的情况
    for (int i = 0; i < 26; i++) 
        ans = max(ans, cnt[i]);
    for (int i = 2; i <= k; i++) { //枚举循环节长度
        if (k % i) continue;
        int l = 1, r = n / i; //二分循环节个数
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(i, mid)) {
                ans = max(ans, mid * i);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
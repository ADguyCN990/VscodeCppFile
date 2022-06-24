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
char s[255];
int a[255];
int cnt[255]; //翻转次数
int n;

bool work(int len, int num) {
    //选定长度为len的区间，并将所有数翻转为num
    memset(cnt, 0, sizeof cnt);
    int sum = 0;
    //将前面的数都变成num
    for (int i = 1; i + len - 1 <= n; i++) {
        if ((a[i] + sum) % 10 != num) {
            cnt[i] = ((num + 10) - (a[i] + sum) % 10) % 10; 
        }
        sum += cnt[i];
        if (i - len + 1 > 0) 
            sum -= cnt[i - len + 1];
    }
    //判断后面的数是不是num
    for (int i = n - len + 2; i <= n; i++) {
        if ((sum + a[i]) % 10 != num)
            return false;
        if (i - len + 1 > 0)
            sum -= cnt[i - len + 1];
    }
    return true;
}

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    for (int k = n; k; k--) {
        for (int j = 0; j <= 9; j++) {
            bool flag = work(k, j);
            if (flag) {
                printf("%d\n", k);
                return;
            }
        }
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
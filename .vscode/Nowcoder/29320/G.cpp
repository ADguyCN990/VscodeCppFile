#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
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
char s[MAXN];
int cnt1, cnt0;
void solve() {
    n = read(), k = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    int need1 = cnt1; //直接一个个点
    int need2 = cnt0 + 1; //最后翻转
    if (need1 == k || need2 == k) {
        printf("%d\n", n);
        return;
    }
    if (need1 < k && (k - need1) % 2 == 0) {
        printf("%d\n", n);
        return;
    }
    if (need2 < k && (k - need2) % 2 == 0) {
        printf("%d\n", n);
        return;
    }
    if (!k) {
        printf("%d\n", cnt0);
        return;
    }
    if (k < need1 && k < need2) {
        int ans1 = (k - 1) + cnt1;
        int ans2 = cnt0 + k;
        printf("%d\n", max(ans1, ans2));
        return;
    }
    printf("%d\n", n - 1);
}

int main() {
    solve();
    return 0;
}
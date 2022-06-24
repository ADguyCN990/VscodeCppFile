#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int a[MAXN], n, k;
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

bool check(int mid) {
    int cnt = 0;
    int need = mid;
    int have = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] >= mid)
            have++;
        else if (a[i] == mid - 1)
            cnt++;
    //printf("mid: %d have: %d need: %d\n", mid, have, need);
    return have + min(cnt, k) >= need;
}

void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int l = 0, r = n;
    int ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
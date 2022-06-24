#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
char s[MAXN];
int cnt = 1;
ll pair_cnt, mx;

void dfs(int now, int a, int b, int red) {
    if (now == n) {
        cnt++;
        puts(s);
        return;
    }
    if (cnt > 100 || a > mx || b > mx) {
        return;
    }
    if (red & 1) {
        s[now] = 'b';
        dfs(now + 1, a, b + 1, red);
        s[now] = 'r';
        dfs(now + 1, a + 1, b, red + 1);
    }
    else {
        s[now] = 'b';
        dfs(now + 1, a + 1, b, red);
        s[now] = 'r';
        dfs(now + 1, a, b + 1, red + 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    pair_cnt = ((n + 1) / 2) * ((n + 2) / 2);
    cout << pair_cnt << endl;
    mx = (n + 2) / 2;
    dfs(0, 1, 0, 0);
    return 0;
}
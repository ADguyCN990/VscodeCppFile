#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
char s[MAXN];
vector<int> pos;
int n;

bool check(int mid) {
    int m = pos.size();
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            int dif = pos[i];
            cnt += (dif - 1) / mid;
        }
        if (i == m - 1) {
            int dif = n - pos[i];
            cnt += dif / mid;
        }
        if (i != m - 1) {
            int dif = pos[i + 1] - pos[i];
            cnt += dif / mid - 1;
        }
    }
    return cnt >= 2;
}

int main() {
    cin >> n;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)    
        if (s[i] == '1')
            pos.push_back(i);
    if (!pos.size()) {
        printf("%d\n", n - 1);
        return 0;
    }
    int l = 1, r = n;
    for (int i = 1; i < pos.size(); i++)
        r = min(r, pos[i] - pos[i - 1]);
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
    return 0;
}
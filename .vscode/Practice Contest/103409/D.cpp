#include<bits/stdc++.h>
using namespace std;
#define MAXN 2500
typedef pair<int, int> pii;
int a[MAXN], b[MAXN], pos[MAXN], d[MAXN];
int n;
vector<pii> ans;

void solve() {
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        d[b[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] > pos[i]) {
            puts("-1");
            return;
        }
        else if (d[i] < pos[i]) {
            for (int j = i + 1; j <= n; j++) {
                if (pos[j] < pos[i] && pos[j] >= d[i]) {
                    ans.push_back({pos[j], pos[i]});
                    swap(a[pos[i]], a[pos[j]]);
                    swap(pos[i], pos[j]);
                }
                if (d[i] == pos[i]) break;
            }
            if (d[i] != pos[i]) {
                puts("-1");
                return;
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}

int main() {
    int T; 
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
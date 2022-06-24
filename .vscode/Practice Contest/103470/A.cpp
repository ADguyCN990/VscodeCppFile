#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
typedef pair<int, int> pii;
int n, a, b;
pii q[10];
int get(int x, int y, int xx, int yy) {
    return abs(x - xx) + abs(y - yy);
}



void solve() {
    scanf("%d%d%d", &n, &a, &b);
    q[1].first = get(1, 1, a, b), q[1].second = 1;
    q[2].first = get(n, 1, a, b), q[2].second = 2;
    q[3].first = get(1, n, a, b), q[3].second = 3;
    q[4].first = get(n, n, a, b), q[4].second = 4;
    sort(q + 1, q + 1 + 4);
    if (q[1].second == 1) {
        for (int i = 1; i < n; i++) printf("U");
        for (int i = 1; i < n; i++) printf("L");
        for (int i = 1; i < a; i++) printf("D");
        for (int i = 1; i < b; i++) printf("R");
    }
    else if (q[1].second == 2) {
        for (int i = 1; i < n; i++) printf("D");
        for (int i = 1; i < n; i++) printf("L");
        for (int i = 1; i <= n - a; i++) printf("U");
        for (int i = 1; i < b; i++) printf("R");
    }
    else if (q[1].second == 3) {
        for (int i = 1; i < n; i++) printf("U");
        for (int i = 1; i < n; i++) printf("R");
        for (int i = 1; i < a; i++) printf("D");
        for (int i = 1; i <= n - b; i++) printf("L");
    }
    else {
        for (int i = 1; i < n; i++) printf("D");
        for (int i = 1; i < n; i++) printf("R");
        for (int i = 1; i <= n - a; i++) printf("U");
        for (int i = 1; i <= n - b; i++) printf("L");
    }
}

int main() {
    solve();
}
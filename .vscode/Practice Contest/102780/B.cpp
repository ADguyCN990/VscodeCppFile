#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
const double eps = 1e-8;

int n, R;
int a[MAXN];

bool check(double x) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        double up = x * a[i];
        double down = x + a[i];
        sum += up / down;
    }
    if (sum + eps <= R) return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &R);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    double l = 0.0, r = 500000.0;
    //(r1 * r2) / (r1 + r2)
    double ans;
    while (fabs(r - l) > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            //小于等于R
            ans = mid;
            l = mid;
        } 
        else 
            r = mid;
    }
    printf("%.7f\n", ans);
    return 0;
}
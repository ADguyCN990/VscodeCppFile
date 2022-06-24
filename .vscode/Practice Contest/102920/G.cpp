#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ZERO 1e-6

ll read(){
    ll x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-')f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while (ch>='0' && ch<='9');
    return x * f;
}

int n;
const int N = 1e6 + 5;
const ll INF = 1e16 + 1;
ll a[N], d;
double t[N];

double f1(double x){
    int L = (n + 1) / 2, R = (n + 1) / 2;
    int cnt = 0;
    while (L >= 1){
        t[L] = x - d * cnt;
        ++cnt;L--;
    }
    cnt = 0;
    while (R <= n){
        t[R] = x + d * cnt;
        ++cnt;
        ++R;
    }
    double mx = 0;
    for (int i=1;i<=n;++i){
        mx = max(mx, fabs(t[i] - a[i]));
    }
    return mx;
}

double f2(double x){
    int L = (n) / 2 + 1, R = (n) / 2 + 1;
    int cnt = 0;
    while (L >= 1){
        t[L] = x - d * cnt;
        ++cnt;L--;
    }
    cnt = 0;
    while (R <= n){
        t[R] = x + d * cnt;
        ++cnt;
        ++R;
    }
    double mx = 0;
    for (int i=1;i<=n;++i){
        mx = max(mx, fabs(t[i] - a[i]));
    }
    return mx;
}

int main(void){
    n = read(), d = read();
    for (int i=1;i<=n;++i){
        a[i] = read();
    }
    double L = -INF, R = INF, m1, m2;
    while (fabs(R - L) > ZERO){
        m1 = L + (R - L) / 3.0, m2 = L + (R - L) / 1.5;
        double r1 = f1(m1), r2 = f1(m2);
        if (r1 <= r2){
            R = m2;
        }
        else L = m1;
    }
    double mx1 = f1(L);

    L = -INF, R = INF;
    while (fabs(R - L) > ZERO){
        m1 = L + (R - L) / 3.0, m2 = L + (R - L) / 1.5;
        double r1 = f2(m1), r2 = f2(m2);
        if (r1 <= r2){
            R = m2;
        }
        else L = m1;
    }
    double mx2 = f2(L);
    // double mx2 = INF;
    // double mx = min(mx1, mx2);

    printf("%.1f %.1f\n", mx1, mx2);

    return 0;
}
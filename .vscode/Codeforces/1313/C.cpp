#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define ll long long
int n;
ll a[MAXN];
ll pre[MAXN], suf[MAXN];
int stk[MAXN], tt;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        while (tt && a[stk[tt]] >= a[i]) tt--;
        pre[i] = (i - stk[tt]) * a[i] + pre[stk[tt]];
        stk[++tt] = i;
    }
    tt = 0;
    stk[++tt] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (tt && a[stk[tt]] >= a[i]) tt--;
        suf[i] = (stk[tt] - i) * a[i] + suf[stk[tt]];
        stk[++tt] = i;
    }
    ll mx = 0;
    int id;
    for (int i = 1; i <= n; i++) {
        //printf("i: %d pre: %d suf: %d\n", i, pre[i], suf[i]);
        ll tmp = pre[i] + suf[i] - a[i];
        if (tmp > mx) {
            mx = tmp;
            id = i;
        }      
    }
    int tmp = a[id];
    for (int i = id; i >= 1; i--) {
        if (a[i] <= tmp)
            tmp = a[i];
        else
            a[i] = tmp;
    }
    tmp = a[id];
    for (int i = id; i <= n; i++) {
        if (a[i] <= tmp)
            tmp = a[i];
        else
            a[i] = tmp;
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}
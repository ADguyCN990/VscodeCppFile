#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
struct node {
    char op;
    double val;
    friend bool operator< (node a, node b) {
        if (a.val == b.val)
            return a.op < b.op;
        return a.val < b.val;
    }
}a[MAXN];
int n;

int main() {
    // scanf("%d", &n);
    // for (int i = 1; i <= n; i++) scanf("%c%lf", &a[i].op, a[i].val);
    printf("%d\n", (int)('+') - (int)('-'));
    return 0;
}
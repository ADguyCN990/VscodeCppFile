#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n;
int d[MAXN];
int a, b;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            if (a == 1) a = 0;
            else if (b == 1) b = 0;
            else a = 1;
        }
        else if (d[i] == 2) {
            if (a + b != 1) {
                puts("NO");
                return 0;
            }
        }
        else if (d[i] > 2){
            puts("NO"); return 0;
        }
    }
    if (!a && !b) puts("YES");
    else puts("NO");
    return 0;
}
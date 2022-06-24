#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105

ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n;
int a[MAXN], b[MAXN];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        puts("-1");
        return 0;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 && b[i] == 0)
            x++;
        if (a[i] == 0 && b[i] == 1)
            y++;
    }
    if (x > y) {
        puts("1");
        return 0;
    }
    if (!x) {
        puts("-1");
        return 0;
    }
    for (int i = 1; ; i++) {
        if (x * i > y) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
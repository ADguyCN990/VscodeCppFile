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
int a[MAXN], b[MAXN], q[MAXN];

int get(int now) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == now)
            now = b[i];
        else if (b[i] == now)
            now = a[i];
        if (now == q[i])
            ans++;
    }
    return ans;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        b[i] = read();
        q[i] = read();
    }
    printf("%d\n", max({get(1), get(2), get(3)}));
    return 0;
}
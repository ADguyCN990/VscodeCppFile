#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
int a[MAXN], b[MAXN];

bool work(int x, int k) {
    if (b[x] - a[x] < k)
        return true;
    if (x + k > n)
        return true;
    int tmp = max(a[x], a[x + k]);
    if (b[x] - tmp >= k && b[x + k] - tmp >= k)
        return false;
    return true; 
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
    int k = 1;
    for (int i = 1; i <= n; i++)
        while (!work(i, k))
            k++;
    printf("%d\n", k);
    return 0;
}
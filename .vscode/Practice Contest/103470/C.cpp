#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 1e6 + 5;
int a[N];
int num[N<<2];

int read(){
    int x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-') f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while  (ch>='0' && ch<='9');
    return x * f;
}

int main(void){
    n = read(), k = read();
    int cnt = 0, mx = 0;
    for (int i=1;i<=n;++i){
        a[i] = read();
        num[a[i] + N]++;
    }
    for (int i=0;i<(N<<1);++i){
        cnt = max(cnt, num[i]);
    }
    for (int i=1;i<=n;++i){
        int j = i;
        while (j<=n && a[j]==a[i]) ++j;
        int len = j - i, cur = num[a[i] + k + N] + len;
        cnt = max(cnt, cur);
        i = j - 1;
    }
    printf("%d\n", cnt);

    return 0;
}
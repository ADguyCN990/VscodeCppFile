#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int k, n;
int a[MAXN];
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}


int main() {
    n = read(), k = read();
    int ans = 0;
    int sum = 0;
    //0表示亮，1表示暗
    while (k--) {
        int x = read();
        for (int i = x; i <= n; i += x) {
            if (a[i] == 1) {
                a[i] = 0;
                sum--;
            }
            else {
                a[i] = 1;
                sum++;
            }
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int read(){
    int x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-')f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while (ch>='0' && ch<='9');
    return x * f;
}

int n;
const int N = 1e6 + 5;
int d[N];

int main(void){
    n = read();
    ll sa = 0;
    int one = 0, two = 0;
    for (int i=1;i<=n;++i){
        d[i] = read();
        sa += d[i];
        if (d[i] == 2) two++;
        else if (d[i] == 1) one++;
    }
    if (sa % 2 == 1){
        puts("NO"); return 0;
    }
    if (d[1] > 1 || d[n] > 1){
        puts("NO"); return 0;
    }
    for (int i=1;i<=n;++i){
        if (d[i] > 2){
            puts("NO"); return 0;
        }
    }
    if (two > 0){
        if (one == 0){
            puts("NO"); return 0;
        }
    }
    puts("YES");
    return 0;
}
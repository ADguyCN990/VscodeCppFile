#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(2)
#pragma G++ optimize(3)

using namespace std;
#define ll long long
#define MAXN 50005
int na, nb, nc;
int read(){
    int x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-')f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while (ch>='0' && ch<='9');
    return x * f;
}

int n;
const int N = 5e4 + 5, L = 3e4 + 5;

bitset<(L << 1)> a, b, c;

int main() {
    // test();
    // clock_t st, ed;
    
    na = read();
    int x;
    for (int i = 1; i <= na; ++i){
        x = read();
        x += L;
        a.set(x);
    }
    nb = read();
    for (int i = 1; i <= nb; ++i){
        x = read(); x += L;
        b.set(x);
    }
    nc = read();
    for (int i = 1; i <= nc; ++i){
        x = read(), x += L;
        c.set(x);
    }
    // st = clock();
    bitset<(L << 1)> tmp = (a & b) & c;
    int cnt = tmp.count();
    int cur = 0;
    for (int i=1;i<=3e4;++i){
        cur = 0;
        tmp = (a << i) & (c >> i) & (b);
        cur = tmp.count();
        tmp = (a >> i) & (c << i) & (b);
        cur += tmp.count();
        cnt += cur;
    }
    printf("%d\n", cnt);
    // ed = clock();
    // cout << (ed - st) << endl;
    
    return 0;
}
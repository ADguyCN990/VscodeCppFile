#include <bits/stdc++.h>
using namespace std;
#define ll int

ll read(){
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while (ch>='0' && ch<='9');
    return x*f;
}

ll n, m, q;
const int Max_n = 1e6 + 10;
ll v[Max_n];

void solve(){
    n = read(), m = read(), q = read();
    for (int i=1;i<=n;++i){
        v[i] = read();
    }
    ll p, k;
    for (int i=1;i<=q;++i){
        p = read(), k = read();
        long long cur = 1LL*v[k]*p;
        long long dis = cur%(2*m);
        if (dis <= m)
            printf("%lld\n", dis);
        else{
            printf("%lld\n", m+m-dis);
        }
    }
}

int main(void){
    solve();
    return 0;
}
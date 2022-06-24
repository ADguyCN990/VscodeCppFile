#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll le, k;

bool check(ll x){
    for (ll i=2;i*i<=x;++i){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

void solve(){
    cin >> le >> k;
    if (k > 3){
        puts("NO");
        return;
    }
    int ans = 0;
    bool flag = true;
    for (ll i=0;i<=2*k-1;++i){
        if (check(le+i)){
            ans++;
        }
    }
    if (ans >= k+1){
        puts("Yes");
        return;
    }
    puts("No");
}

int main(void){
    solve();
    return 0;
}
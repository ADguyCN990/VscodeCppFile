#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353, N = 1e6 + 10;

int n;
ll a[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
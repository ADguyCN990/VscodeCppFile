#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pii;
#define MAXN 2005

int g[MAXN][MAXN];

bool isPrime(ll x){
    for (ll i=2;i<=x/i;++i){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    bool x = isPrime(998244353);
    cout << x << endl;
    return 0;
}
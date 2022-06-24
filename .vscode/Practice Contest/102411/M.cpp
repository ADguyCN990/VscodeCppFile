#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 2000 + 5;
int a[N];
map<int, int> mp;

void solve(){
    scanf("%d", &n);
    mp.clear();
    for (int i=1;i<=n;++i){
        scanf("%d", &a[i]);
    }
    ll cnt = 0;
    for (int i=n;i>=1;--i){
        for (int j=1;j<i;++j){
            int cur = a[i] + a[i] - a[j];
            if (!mp.empty() && mp.count(cur)){
                cnt += mp[cur];
            }
        }
        mp[a[i]]++;
    }
    printf("%lld\n", cnt);

}

int main(void){
    int t;
    scanf("%d", &t);
    while (t--){
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18+5;
const ll mod = 1e9+7;
ll qmi(ll a,ll b){
    ll res = 1ll;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>=1;
    }
    return res%mod;
}
ll a,b;
ll ans = INF;
bool check(ll p){
    ll x = qmi(a,p);
    if(x<0||x/p>=INF) return false;
    if(x%p==0&&x/p==b)
        ans = min(ans,x);
    if(b*p<0) return false;
    return x <= b*p;
}
int main(){
    
    scanf("%lld %lld",&a,&b);
    if(b<=40&&(a*a==1<<b)){
        printf("2\n");
        return 0;
    }
    ll l = 1,r = 70;
    while(l<=r){
        ll mid = (l+r)>>1;
        if(check(mid)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if(ans!=INF)
        printf("%lld\n",ans);
    else
        printf("0\n");
    return 0;
}
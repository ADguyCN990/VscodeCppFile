#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll H,M,A;
ll exgcd(ll a,ll b,ll& x,ll& y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    ll d = exgcd(b,a%b,y,x);
    y -= a / b * x;
    return d;
}

ll mod(ll a, ll b){
    return (a % b + b) % b;
}

ll cal1(ll x){
    return (x * H * M - A) / (H - 1);
}

ll cal2(ll x){
    return (x * H * M + A) / (H - 1);
}

int main(){
    scanf("%lld %lld %lld",&H,&M,&A);
    ll r = (H*M+A)/(H-1),l = (H*M-A)/(H-1);
    if(l*(H-1)<(H*M-A)) l++;
    ll pcnt = r-l+1;
    if((H*M+A)%(H-1)==0) pcnt--;
    if((H*M-A)&(H-1)==0) pcnt--;
    pcnt = max(pcnt,0ll);
    ll inSeg = pcnt;
    // LePoint
    ll k0, w, d, a, L, mid, R, Rans, Lans, T;
    d = exgcd(H * M, 1 - H, k0, w), a = mod(A, H - 1);
    k0 = k0 * (a / d), T = abs((1 - H) / d);

    L = -10, R = 10, mid, Rans = -1;
    while (L <= R){
        mid = (L + R) >> 1;
        if (cal1(k0 + mid * T) <= H * M){
            Rans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    L = -10, R = 10;Lans = -1;
    while (L <= R){
        mid = (L + R) >> 1;
        if (k0 + mid * T >= 0){
            Lans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    ll LePoint = (k0 + Rans * T) - (k0 + Lans * T);

    // RePoint
    d = exgcd(H * M, 1 - H, k0, w), a = mod(-A, H - 1);
    k0 = k0 * (a / d), T = abs((1 - H) / d);
    L = -1e9, R = 1e9, mid, Rans = -1;
    while (L <= R){
        mid = (L + R) >> 1;
        if (cal2(k0 + mid * T) <= H * M){
            Rans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    L = -1e9, R = 1e9;Lans = -1;
    while (L <= R){
        mid = (L + R) >> 1;
        if (k0 + mid * T >= 0){
            Lans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    ll RePoint = (k0 + Rans * T) - (k0 + Lans * T) ;

    ll res = LePoint + RePoint + inSeg;
    //cout << LePoint << " " << RePoint << " " << inSeg << endl;
    cout << res << endl;

    return 0;
}
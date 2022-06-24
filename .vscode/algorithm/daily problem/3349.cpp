#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n = 7;
ll a[10];
map<ll, int> s;
void solve() {
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) s[a[i]]++;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                map<ll, int> tmp = s;
                tmp[a[i]]--;
                tmp[a[j]]--;
                tmp[a[k]]--;
                if (tmp[a[i] + a[j]] != 0)
                    tmp[a[i] + a[j]]--;
                else 
                    continue;
                if (tmp[a[i] + a[k]] != 0)
                    tmp[a[i] + a[k]]--;
                else 
                    continue;
                if (tmp[a[j] + a[k]] != 0)
                    tmp[a[j] + a[k]]--;
                else 
                    continue;    
                if (tmp[a[i] + a[j] + a[k]] != 0) {
                    vector<ll> v;
                    v.pb(a[i]), v.pb(a[j]), v.pb(a[k]);
                    sort(v.begin(), v.end());
                    printf("%lld %lld %lld\n", v[0], v[1], v[2]);
                }
                else
                    continue;                
            }
        }
    }    

}

int main() {
    solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
char s[MAXN];
vector <int> purple;
ll n, k;
void solve() 
{
    n = read(), k = read();
    scanf("%s", s + 1);
    purple.pb(0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P')
            purple.pb(i);
    }
    purple.pb(n + 1);
    ll ans = 0;
    for (int _ = 1; _ < purple.size(); _++) {
        ll l = purple[_ - 1];
        ll r = purple[_];
        int sum = 0;
        vector <int> pos;
        pos.pb(l);
        for (int i = l + 1; i < r; i++) {
            if (s[i] == 'R') {
                sum++;
                pos.pb(i);
                if (sum >= k) {
                    ll le = pos[sum - k + 1], ri = pos[sum];
                    ans += (le - pos[sum - k]) * (r - ri);
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}
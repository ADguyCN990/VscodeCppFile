#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<ll, ll> pii;
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

void solve() {
    int n = read();
    priority_queue<ll, vector<ll>, greater<ll>> q;
    //优先队列，小根堆，放药的毒性，越小越大
    int ans = 0;
    ll hp = 0;
    for (int i = 1; i <= n; i++) {
        ll x = read();
        if (hp + x >= 0) {
            hp += x;
            ans++;
            q.push(x);
        }
        else {
            if (q.size() && q.top() < x) {
                //之前喝过最毒的药比当前毒
                hp += x - q.top(); //之前的药不喝了
                q.pop();
                q.push(x);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
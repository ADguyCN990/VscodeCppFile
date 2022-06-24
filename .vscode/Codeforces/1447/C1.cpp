#include<bits/stdc++.h>
#define endl '\n'
#define null NULL
#define ll long long
#define int long long
#define pii pair<int, int>
#define lowbit(x) (x &(-x))
#define ls(x) x<<1
#define rs(x) (x<<1+1)
#define me(ar) memset(ar, 0, sizeof ar)
#define mem(ar,num) memset(ar, num, sizeof ar)
#define rp(i, n) for(int i = 0, i < n; i ++)
#define rep(i, a, n) for(int i = a; i <= n; i ++)
#define pre(i, n, a) for(int i = n; i >= a; i --)
#define IOS ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int way[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
using namespace std;
const int  inf = 0x7fffffff;
const double PI = acos(-1.0);
const double eps = 1e-6;
const ll   mod = 1e9 + 7;
const int  N = 2e5 + 5;

int t, n, w, b[N];

struct node{
    int id, da;
}a[N];

int cmp(node x, node y){
    return x.da < y.da;
}

signed main()
{
    IOS;

    cin >> t;
    while(t --){
        cin >> n >> w;
        int sum = 0;
        for(int i = 1; i <= n; i ++){
            cin >> a[i].da;
            sum += a[i].da;
            a[i].id = i;
        }
        sort(a+1, a+n+1, cmp);
        for(int i = 1; i <= n; i ++){
            b[i] = a[i].da;
//            cout << a[i].da << endl;
        }
        if(a[1].da>w || sum<w/2+bool(w%2)){
            cout << -1 << endl;
            continue;
        }
        int x = w/2+bool(w%2);
        int pos = lower_bound(b+1, b+n+1, x)-b;
        if(1<= pos&&pos<=n&&b[pos]<=w){
            cout << 1 << " " << a[pos].id << endl;
            continue;
        }
        sum = 0, pos = -1;
        for(int i = 1; i <= n; i ++){
            sum += a[i].da;
            if(sum>=x&&sum<=w) {pos = i; break;}
        }
        if(pos==-1){
            cout << -1 << endl;
            continue;
        }
        cout << pos << endl;
        for(int i = 1; i <= pos; i ++) cout << a[i].id << " ";
        cout << endl;
    }

    return 0;
}

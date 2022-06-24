#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll read(){
    ll x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-')f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while (ch>='0' && ch<='9');
    return x * f;
}

void solve() {
    int cnt = 0;
    ll a, b;
    cin >> a >> b;
    while (a && b) {
        if (a < b)
            swap(a, b);
        int mod = a % b;
        cnt += a / b;
        a = a % b;
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int n;
const int N = 10005;
string s[N];
int a[N];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int sa = 0, mn = 10000;
    for (int i=1;i<=n;++i){
        cin >> s[i] >> a[i];
        a[i] = a[i] * 100;
        sa += a[i];
        mn = min(mn, a[i]);
    }
    if (n == 1){
        if (a[1] == 10000){
            cout << s[1] << " " << "100.00 100.00" << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
        return 0;
    }
    int des = 10000 - sa;
    // if (des > 0){
    //     cout << "IMPOSSIBLE" << endl;
    //     return 0;
    // }
    int res = -100;
    for (int i=-50;i<50;++i){
        int cur = (des - i) / (n - 1);
        if (cur * (n - 1) == des - i && cur < 50){
            // if (i < 0 && mn == 0) continue;
            res = i;
            break;
        }
    }
    if (res > -100){
        int cur = (des - res) / (n - 1);
        double L = 1.0 * res / 100, R = 1.0 * cur / 100;
        for (int i=1;i<=n;++i){
            double al = 1.0 * a[i] / 100 + L, ar = 1.0 * a[i] / 100 + R;
            al = max(0.0, al), ar = min(100.0, ar);
            cout << fixed << setprecision(2) << s[i] << " " << al << " " << ar << endl;
        }
        // cout << res << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, d, s;

int main(void){
    cin >> n >> k;
    cin >> d >> s;
    ll all = d * n, has = s * k;
    double no = 1.0 * (all - has) / (n - k);
    if (no < 0 || no > 100){
        cout << "impossible" << endl;
    }
    else{
        printf("%.8lf", no);
    }
}
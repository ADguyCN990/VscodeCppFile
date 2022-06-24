#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ZERO 1e-6

double t[5];
double aver;

int main(void){
    double sumt = 0;
    for (int i=1;i<=4;++i){
        cin >> t[i];
        sumt += t[i];
    }
    cin >> aver;
    sort(t+1, t+1+4);
    if (sumt - t[1] - aver*3.0 < ZERO){
        cout << "infinite" << endl;
        return 0;
    }
    if (sumt - t[4] > aver*3.0){
        cout << "impossible" << endl;
        return 0;
    }
    double ans = (aver*3.0) - t[2] - t[3];
    cout << fixed << setprecision(2) << ans << endl;
    return 0;

}
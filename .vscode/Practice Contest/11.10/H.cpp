#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int Max_n = 1e1 + 10;
int a[Max_n], b[Max_n];
bool vis[Max_n];
vector<int> ve;

void solve(){
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int des = 3e5 + 10, inx = 0;
    for (int i=1;i<n;++i){
        if (a[i+1] - a[i] < des){
            des = a[i+1] - a[i];
            inx = i;
        }
    }
    // solution 1
    b[1] = a[inx], b[2] = a[inx+1];
    for (int i=1;i<=n;++i){
        if (i == inx || i == inx+1) continue;
        ve.push_back(a[i]);
    }
    int ed = 2;
    while (ed < n){
        int pos = lower_bound(ve.begin(), ve.end(), b[ed]) - ve.begin();
        int v1 = -1, v2 = -1;
        if (pos < n - 2) v1 = abs(ve[pos] - b[ed]);
        if (pos > 0) v2 = abs(ve[pos - 1] - b[ed]);
        int d = abs(b[ed] - b[ed - 1]);
        if (v1 < d && v2 < d){
            puts("impossible");
            return;
        }
        if (v1 < v2 && v1>=d){
            ed++;b[ed] = ve[pos];
            ve.erase(ve.begin()+pos);
        }
        else{
            ed++;b[ed] = ve[pos - 1];
            ve.erase(ve.begin()+(pos-1));
        }
    }
    for (int i=1;i<=n;++i){
        printf(i==n?"%d\n":"%d ", b[i]);
    }
}

int main(void){
    solve();
    return 0;
}
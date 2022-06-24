#include<bits/stdc++.h>
using namespace std;
#define ZERO 1e-6

int n, m;
const int Max_n = 100 + 10;
struct node {
    int id, val;
};
node a[Max_n];

bool cmp(node x, node y){
    return x.id < y.id;
}

void solve(){
    cin >> n >> m;
    int suma = 0;
    for (int i=1;i<=n;++i){
        cin >> a[i].id >> a[i].val;
        suma += a[i].val;
    }
    double aver = 1.0*suma/n;
    for (int i=1;i<=n;++i){
        if (a[i].id == m){
            if(a[i].val<60)
            a[i].val = 60;
            continue;
        }
        if (a[i].val - aver > ZERO){
            a[i].val = max(0, a[i].val-2);
        }
    }
    sort(a+1, a+1+n, cmp);
    for (int i=1;i<=n;++i){
        printf(i==n?"%d\n":"%d ", a[i].val);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
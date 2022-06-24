#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int Max_n = 1e5 + 10;
int a[Max_n], b[Max_n];
bool vis[Max_n];
vector<int> ve;

void solve(){
    scanf("%d", &n);
    for (int i=1;i<=n;++i){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+n);
    int le = 1, ri = n;
    int cnt = 0;
    while (le < ri){
        cnt++;
        b[cnt] = a[le], b[cnt+1] = a[ri];
        cnt++;
        le++, ri--;
    }
    if (n & 1){
        cnt++;
        b[cnt] = a[le];
    }
    for (int i=n;i>=1;--i){
        printf(i==1?"%d\n":"%d ", b[i]);
    }
}

int main(void){
    solve();
    return 0;
}
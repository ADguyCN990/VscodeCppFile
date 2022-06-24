#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ll long long
#define xx first
#define yy second

int n;
const int Max_n = 2e5 + 10;
pii cor[Max_n];
int ver[Max_n], hor[Max_n];
vector<pii> ve;

void solve(){
    cin >> n;
    int x, y;
    for (int i=1;i<=n;++i){
        cin >> x >> y;
        cor[i].xx = x, cor[i].yy = y;
    }
    ve.push_back(pii(0,0));
    for (int i=1;i<=n;++i){
        ll cur = ve[i-1].xx + 4;
        x = cor[i].xx, y =cor[i].yy;
        ver[x]++;hor[y]++;
        if (ver[x-1]>=ver[x]){
            cur-=2;
        }
        if (ver[x+1]>=ver[x]){
            cur-=2;
        }
        if (ver[x]>1){
            cur-=2;
        }
        ll cur2 = ve[i-1].yy + 4;
        if (hor[y-1]>=hor[y]){
            cur2-=2;
        }
        if (hor[y+1]>=hor[y]){
            cur2-=2;
        }
        if (hor[y]> 1){
            cur2-=2;
        }
        ve.push_back(pii(cur, cur2));
    }
    for (int i=1;i<=n;++i){
        printf("%d %d\n", ve[i].xx, ve[i].yy);
    }
}

int main(void){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
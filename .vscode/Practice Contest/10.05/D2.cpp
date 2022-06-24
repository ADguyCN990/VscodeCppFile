#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int n;
const int Max_n = 1e4 + 10;
ll a[Max_n];
ll bit[Max_n];
vector<ll> ve;
vector<char> ch;

void init(){
    bit[0] = 1;
    ll ans = 128;
    for (int i=1;i<=9;++i){
        bit[i] = bit[i-1]*ans;
    }
}

void solve(){
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
    }
    for (int i=1;i<=n;++i){
        vector<ll> cur;
        int j = i;
        while (j<n && a[j]>=128){
            j++;
        }
        for (int k=i;k<=j;++k){
            cur.push_back(a[k]);
        }
        int clen = cur.size();
        ll ans = 0;
        for (int k=0;k<clen-1;++k){
            ans = ans + (cur[k]-128)*bit[k];
        }
        ans = ans + cur.back()*bit[clen-1];
        if (ans&1){
            ans = ans/2 + 1;
            ch.push_back('-');
        }
        else{
            ans = ans/2;
            ch.push_back('+');
        }

        ve.push_back(ans);
        i = j;
    }
    int vlen = ve.size();
    for (int i=0;i<vlen;++i){
        if (ch[i]=='-'){
            cout << ch[i] << ve[i];
        }
        else{
            cout << ve[i];
        }
        if (1){
            cout << endl;
        }
    }
}

int main(void){
    init();
    solve();
    return 0;
}
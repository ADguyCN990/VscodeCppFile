#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define endl "\n"

int n;
const int N = 1e6 + 5;
char s[N];
int x[26];
pii p[N];

bool check(){
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> s;
    n = strlen(s);
    int num = 0, mn = N;
    for (int i=0;i<n;++i){
        x[s[i] - 'a']++;
    }
    for (int i=0;i<26;++i){
        if (x[i] > 0) ++num, mn = min(mn, x[i]);
    }
    
    int cnt = 0, mx = 0, id = -1;
    for (int i=0;i<26;++i){
        if (x[i] > mx){
            mx = x[i], id = i;
        }
    }
    if (x[id] == n){
        cout << "NO" << endl; return 0;
    }
    if (num == 2 && mn < 3 && x[id] > n / 2){
        cout << "NO" << endl; return 0;
    }
    int mid = -1;
    if (x[id] > n / 2){
        p[++cnt] = pii(id, n / 2), x[id] -= n / 2;
        for (int i=0;i<26;++i){
            if (x[i] > 0 && i != id){
                p[++cnt] = pii(i, 1);
                x[i]--;mid = i;
                break;
            }
        }
        
    }
    for (int i=0;i<26;++i){
        if (x[i] > 0 && i != mid) p[++cnt] = pii(i, x[i]), x[i] = 0;
    }
    if (mid >= 0){
        p[++cnt] = pii(mid, x[mid]);
    }
    
    if (!check()){
        cout << "NO" << endl; return 0;
    }
    else cout << "YES" << endl;
    for (int i=1;i<=cnt;++i){
        for (int j=0;j<p[i].second;++j){
            cout << char(p[i].first + 'a');
        }
    }
    cout << endl;


    return 0;
}
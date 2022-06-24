#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1000 + 10;
int suf[N];
char a[N];
set<string, greater<string> > ss;

void cal(int slen){
    set<char> ms;
    for (int i=slen;i>=1;--i){
        if (ms.count(a[i])==0){
            suf[a[i]-'a'] = ms.size();
            ms.insert(a[i]);
        }
    }
    string part;
    for (int i=1;i<=slen;++i){
        part += ('a'+suf[a[i]-'a']);
    }
    
    ss.insert(part);
}

void solve(){
    cin >> n;
    cin >> a+1;
    
    for (int i=1;i<=n;++i){
        cal(i);
    }
    // for (auto it=ss.begin();it!=ss.end();++it){
    //     cout << *it << endl;
    // }
    cout << *ss.begin() << endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
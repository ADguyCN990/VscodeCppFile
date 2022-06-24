#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s, t;
// map<char, int> mp;
set<char> ms;
void solve()
{
    getline(cin, t);
    
    getline(cin, s);
    int slen = s.size(), tlen = t.size();
    int cnt = 0, num = 0;

    for (int i=0;i<slen;++i){
        // if (s[i] == '\n'){
        //     puts("YES");
        // }
        if (s[i] == t[cnt]){
            cnt++;
        }
        else{
            ms.insert(s[i]);
        }
    }
    for (set<char>::iterator it = ms.begin();it != ms.end();++it ){
        cout << *it;
        // if (*it == ' '){
        //     puts("YES");
        // }
    }
    
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
typedef pair<string, int> psi;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    s += s;
    vector<psi> v;
    for (int i = 0; i < n - 1; i++) {
        string s1 = s.substr(i, n - i);
        string s2 = s.substr(0, i);
        int num = n - i;
        if (num & 1)
            reverse(s2.begin(), s2.end());
        v.push_back({s1 + s2, i + 1});
    }
        
    v.push_back({tmp, n});
    //k时，转k-1位
    sort(v.begin(), v.end());
    cout << v[0].first << endl << v[0].second << endl;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
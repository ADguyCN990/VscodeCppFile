#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
map<string, int> mp;
vector<string> v;
int main() {
    getline(cin, s);
    string t = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') t += s[i];
        if (s[i] == ' ' || i == s.length() - 1) {
            v.push_back(t);
            t = "";
        }
        
    }
    for (int i = 0; i < v.size(); i += 2) {
        string tmp = v[i];
        string a = v[i + 1];
        ll cnt = stoll(a);
        
        mp[tmp] += cnt;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        cout << mp[t] << endl;
    }
    return 0;
}
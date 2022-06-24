#include<bits/stdc++.h>
using namespace std;
#define ll long long
int month[15];
vector<string> ansa, ansb;
bool run(int x) {
    if ((x % 4 == 0 && x % 100) || x % 400 == 0) return true;
    return false;
}

void solve() {
    string s;
    cin >> s;
    int pos1 = upper_bound(ansa.begin(), ansa.end(), s) - ansa.begin();
    int pos2 = upper_bound(ansb.begin(), ansb.end(), s) - ansb.begin();
    cout << ansa[pos1] << "\n" << ansb[pos2] << "\n";
}

int main() {
    month[1] = 31, month[2] = 28, month[3] = 31, month[4] = 30, month[5] = 31, month[6] = 30;
    month[7] = 31, month[8] = 31, month[9] = 30, month[10] = 31, month[11] = 30, month[12] = 31;
    for (int year = 1000; year <= 8999; year++) {
        for (int mon = 1; mon <= 12; mon++) {
            int days = month[mon];
            if (mon == 2 && run(year)) days++;
            for (int day = 1; day <= days; day++) {
                string s = "";
                string ye, mo, da;
                ye = to_string(year);
                if (mon < 10) mo = "0" + to_string(mon);
                else mo = to_string(mon);
                if (day < 10) da = "0" + to_string(day);
                else da = to_string(day);
                s = ye + mo + da;
                string t = s;
                reverse(t.begin(), t.end());
                if (s == t) ansa.push_back(s);
                if (s[0] == s[2] && s[2] == s[5] && s[5] == s[7] && s[1] == s[3] && s[3] == s[4] && s[4] == s[6] && s[0] != s[1]) {
                    ansb.push_back(s);
                }            
            }
        }
    }
    sort(ansa.begin(), ansa.end());
    sort(ansb.begin(), ansb.end());
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
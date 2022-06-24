#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

bool check(string s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1) {
        cout << s << "\n";
        return;
    }
    int ans = 0;
    string res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //[0,i][j,n-1]
            string s1 = s.substr(0, i + 1);
            string s2 = s.substr(j, n - j);
            string t = s1 + s2;
            bool flag = check(t);
            if (flag) {
                if (t.length() > ans) {
                    ans = t.length();
                    res = t;
                }
                break;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    int t = read();
    while (t--)
        solve();
}
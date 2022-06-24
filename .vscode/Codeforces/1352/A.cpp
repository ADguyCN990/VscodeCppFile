#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<string> ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') continue;
        string x = "";
        x += s[i];
        for (int j = 0; j < i; j++)
            x += '0';
        ans.pb(x);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
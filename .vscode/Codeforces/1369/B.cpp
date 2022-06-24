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
int n;
char s[MAXN];
void solve() {
    n = read();
    scanf("%s", s + 1);
    string a, b;
    string tmp = "";
    for (int i = 1; i <= n; i++) tmp += s[i];
    string t = tmp;
    sort(tmp.begin(), tmp.end());
    if (t == tmp) {
        puts(s + 1);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0')
            a += s[i];
        else
            break;
    }
    for (int i = n; i >= 1; i--) {
        b = s[i] + b;
        if (s[i] == '0')
            break;
    }
    cout << a + b << endl;
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
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
    int k;
    string a, b;
    k = read();
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int lena = a.length(), lenb = b.length();
    if (lena < lenb) 
        for (int i = 1; i <= lenb - lena; i++)
            a += "0";
    else if (lena > lenb)
        for (int i = 1; i <= lena - lenb; i++)
            b += "0";
    int flag = 0;
    int len = a.length();
    vector<int> ans;
    for (int i = 0; i < len; i++) {
        int u = a[i] - '0';
        int v = b[i] - '0';
        int num = u + v + flag;
        ans.pb(num % k);
        flag = num / k;
    }
    if (flag)
        ans.pb(flag);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i]);
    }
}

int main() {
    solve();
    return 0;
}
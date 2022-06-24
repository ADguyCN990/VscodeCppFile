#include<bits/stdc++.h>
using namespace std;
#define MAXN 405
#define ll long long
typedef pair<int, int> pii;
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

void solve() {
    vector<char> v;
    int n, m, k;
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k; i++) {
        int tmp = read();
        tmp = read();
    }
    for (int i = 1; i <= k; i++) {
        int tmp = read();
        tmp = read();
    }
    for (int i = 1; i < m; i++) 
        v.push_back('L');
    for (int i = 1; i < n; i++)
        v.push_back('U');
    for (int i = 1; i <= n; i++) {
        if (i != 1)
            v.push_back('D');
        if (i & 1) 
            for (int i = 1; i < m; i++)
                v.push_back('R');
        else
            for (int i = 1; i < m; i++)
                v.push_back('L');
    }
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++)
        printf("%c", v[i]);
    puts("");
}

int main() {
    solve();
    return 0;
}
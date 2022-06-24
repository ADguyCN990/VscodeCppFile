#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
char t[MAXN];
char s[MAXN];
int a[MAXN];
map<char, int> id;
void solve() {
    scanf("%s", t + 1);
    int m = strlen(t + 1);
    for (int i = 1; i <= m; i++) id[t[i]] = i;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = id[s[i]];
    int ans = 1;
    for (int i = 2; i <= n; i++) 
        if (a[i] <= a[i - 1])
            ans++;
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
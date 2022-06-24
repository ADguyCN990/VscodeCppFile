#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
char s[MAXN];
int n;

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int mx = 0;
    int len;
    if (s[1] == 'L')
        len = 1;
    else 
        len = 0;
    for (int i = 2; i <= n; i++) {
        if (s[i] == 'L' && s[i - 1] == 'L')
            len++;
        else if (s[i] == 'L' && s[i - 1] == 'R')
            len = 1;
        else {
            mx = max(mx, len);
            len = 0;
        }
    }
    if (len)
        mx = max(mx, len);
    printf("%d\n", mx + 1);
}

int main() {
    int t = read();
    while (t--)
        solve();
}

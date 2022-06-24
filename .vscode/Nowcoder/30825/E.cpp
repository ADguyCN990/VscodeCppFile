#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
char s[MAXN];

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    s[n + 1] = '#', s[0] = '#';
    for (int i = 1; i <= n; i++) {
        if (s[i] != '?') continue;
        if (s[i - 1] != 'a' && s[i + 1] != 'a') s[i] = 'a';
        else if (s[i - 1] == 'a' || s[i + 1] == 'a') {
            if (s[i - 1] != 'b' && s[i + 1] != 'b') 
                s[i] = 'b';
            else if (s[i - 1] != 'c' && s[i + 1] != 'c')
                s[i] = 'c';
            else
                s[i] = 'd';
        }
    }
    for (int i = 1; i <= n; i++) printf("%c", s[i]);
    puts("");
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
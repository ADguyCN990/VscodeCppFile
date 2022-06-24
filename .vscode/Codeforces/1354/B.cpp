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
char s[MAXN];
int n;
void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int ans = INF;
    int l = 1, r = 1;
    if (s[1] == '1') cnt1++;
    else if (s[1] == '2') cnt2++;
    else if (s[1] == '3') cnt3++;
    for (int i = 2; i <= n; i++) {
        r = i;
        if (s[i] == '1') cnt1++;
        else if (s[i] == '2') cnt2++;
        else if (s[i] == '3') cnt3++;
        while (1) {
            if (!cnt1 || !cnt2 || !cnt3) break;
            if (s[l] == '1' && cnt1 == 1) break;
            if (s[l] == '2' && cnt2 == 1) break;
            if (s[l] == '3' && cnt3 == 1) break;
            if (s[l] == '1') cnt1--;
            else if (s[l] == '2') cnt2--;
            else if (s[l] == '3') cnt3--;
            l++; 
        }
        if (cnt1 > 0 && cnt2 > 0 && cnt3 > 0) 
            ans = min(ans, r - l + 1);
    }   
    if (ans == INF) puts("0");
    else printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
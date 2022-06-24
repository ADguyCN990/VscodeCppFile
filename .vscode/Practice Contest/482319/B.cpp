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
char s[1005];
int sumr[1005], sump[1005], sums[1005];
int n;
void solve() {
    n = read();
    scanf("%s", s + 1);
    //石头R布P剪刀S
    //布P剪刀S石头R
    for (int i = 1; i <= n; i++) {
        sumr[i] = sumr[i - 1];
        sump[i] = sump[i - 1];
        sums[i] = sums[i - 1];
        if (s[i] == 'R')
            sumr[i]++;
        else if (s[i] == 'P')
            sump[i]++;
        else
            sums[i]++;
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = i; j <= n + 1; j++) {
            //R[1,i-1] P[i,j-1] S[j,n]
            int first = max(0, sump[i - 1]) - max(0, sums[i - 1]);
            int second = max(0, (sums[j - 1] - sums[i - 1])) - max(0, (sumr[j - 1] - sumr[i - 1]));
            int third = max(0, (sumr[n] - sumr[j - 1])) - max(0, (sump[n] - sump[j - 1]));
            if (first + second + third < 0)
                ans++;
            //printf("tot: %d\n", first + second + third);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n, m, h;
int a[MAXN][MAXN], b[MAXN][MAXN];
char s[MAXN];
int cntm[MAXN], cnth[MAXN];
int main() {
    n = read(), m = read(), h = read();
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            a[i][j] = (int)(s[j] - '0');
            cnt += a[i][j];
        }
        cntm[i] = cnt;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int cnt = 0;
        for (int j = 1; j <= h; j++) {
            b[i][j] = (int)(s[j] - '0');
            cnt += b[i][j];
        }
        cnth[i] = cnt;
    }
    ll mx = 0, mn = 0;
    for (int i = 1; i <= n; i++) {
        mx += cntm[i] * cnth[i];
        mn += max(cntm[i], cnth[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (cntm[i] && !cnth[i] || !cntm[i] && cnth[i]) {
            puts("-1");
            return 0;
        }
    }
    printf("%lld\n", mx);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= h; k++)
                if (a[i][j] && b[i][k])
                    printf("%d %d %d\n", i - 1, j - 1, k - 1);
    printf("%lld\n", mn);
    for (int i = 1; i <= n; i++) {
        vector<int> ansm, ansh;
        for (int j = 1; j <= m; j++) 
            if (a[i][j])
                ansm.push_back(j);

        for (int j = 1; j <= h; j++)
            if (b[i][j])
                ansh.push_back(j);
        for (int j = 0, k = 0; j < cntm[i] && k < cnth[i]; ) {
            printf("%d %d %d\n", i - 1, ansm[j] - 1, ansh[k] - 1);
            if (cntm[i] - j == cnth[i] - k)
                j++, k++;
            else if (cntm[i] - j > cnth[i] - k)
                j++;
            else
                k++;
        }
    }
    return 0;
}


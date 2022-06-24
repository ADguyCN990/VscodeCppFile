#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll n, p, k;
ll BIT;
struct node {
    ll see, id;
    ll pos[10];
    friend bool operator< (node a, node b) {
        return a.see > b.see;
    }
}a[MAXN];
ll dp[MAXN][150];

int count(int st) {
    int cnt = 0;
    for (int i = p - 1; i >= 0; i--) {
        int u = st >> i & 1;
        cnt += u;
    }
    return cnt;
}

int main() {
    n = read(), p = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i].id = i;
        a[i].see = read();
    }
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < p; j++) 
            a[i].pos[j] = read();
    sort(a + 1, a + 1 + n);
    BIT = 1 << p;
    memset(dp, ~0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int st = 0; st < BIT; st++) {
            int cnt = count(st);
            dp[i][st] = dp[i - 1][st];
            if (cnt + k >= i) //参赛的人加上观战的人比当前枚举到的人数量多
                dp[i][st] = max(dp[i][st], dp[i - 1][st] + a[i].see);
            //若观众已经满员，则不用考虑i去当观众
            //去当队员
            for (int j = 0; j < p; j++) 
                if (st >> j & 1) 
                    dp[i][st] = max(dp[i][st], dp[i - 1][st ^ (1 << j)] + a[i].pos[j]);           
        }
    }
    printf("%lld\n", dp[n][BIT - 1]);
    return 0;
}


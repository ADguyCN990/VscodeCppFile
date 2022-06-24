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
int sum[MAXN];
void solve(){
	int n, k, cnt = 0, l, r;
	n = read(), k = read();
    scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i] - '0';
	int i=1;
	while (i <= n) {
		if(s[i]=='0') {
			//printf("i=%d\n",i);
			if (i == 1) {
				r = min(n, i + k);
				if (sum[r] - sum[i] == 0) 
                    s[i] = '1', cnt++, i += k;
			} else if (i == n) {
				l = max(1, i - k);
				if (sum[i - 1] - sum[l - 1] == 0)
                    s[i] = '1', cnt++, i += k;
			} else {
				l = max(1, i - k),r = min(n, i + k );
				//printf("i=%d l=%d r=%d\n",i,l,r);
				if (sum[i - 1] - sum[l - 1] == 0 && sum[r] - sum[i] == 0) 
                    s[i] = '1', cnt++, i += k;
			}
			//printf("i=%d cnt=%d\n",i,cnt);
		}
		i++;
	}
	printf("%d\n",cnt);
}


int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}
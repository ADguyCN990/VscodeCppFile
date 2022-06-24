#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
char mt[MAXN];
int nxt[MAXN];
int q, slen;

void init(){
	nxt[0] = -1;
	for (int i=1;i<slen;++i){
		int tmp = nxt[i-1];
		while (mt[i]!=mt[tmp+1] && tmp>-1){
			tmp = nxt[tmp];
		}
		if (mt[i]==mt[tmp+1]) { nxt[i] = tmp+1; }
		else { nxt[i] = -1;}
	}
}

void solve()
{
    scanf("%s", mt);
    scanf("%d", &q);
    slen = strlen(mt);
    init();
    int x;
    int cnt = 0;
    
    int len = slen - nxt[slen - 1] - 1;
    int allnum = (slen+len-1)/ len;
    for (int i=0;i<len;++i){
        if (mt[i]==mt[0]){
            cnt++;
        }
        else{
            break;
        }
    }
    while (q--){
        scanf("%d", &x);
        int ans = 0;
        if (slen == 1){

        }
        if (x==1 || x==slen){
            puts("0");
            continue;
        }
        int num = (x+len-1)/len;
        if (num == (slen+len-1)/len){
            int rem = (slen%len==0)?(len):(slen%len);
            int xrem = (x%len==0)?(len):(x%len);
            int st = min(rem, cnt);
            
            continue;
        }
        if (num > allnum/2){
            printf("%d\n", allnum - num);
            // cout << allnum - num << endl;
            continue;
        }
        int rem = (slen%len==0)?(len):(slen%len);
        int xrem = (x%len==0)?(len):(x%len);
        if (xrem > rem){
            ans++;
        }
        // cout << (num - 1) + ans << endl;
        printf("%d\n", num - 1 + ans);
    }
}

int main()
{
    solve();
    return 0;
}
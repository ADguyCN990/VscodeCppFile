#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
char s[MAXN];

int main() {
    n = read();
    scanf("%s", s + 1);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(')
            l++;
        else
            r++;
    }
    if (l != r) {
        puts("-1");
        return 0;
    }
    // INSERT INTO S
    // VALUES("1903330009", 'alice', 'male', 20, '86548976', 'D002');
    // INSERT INTO S (Snum, Sname, Ssex, Sage, Sphone, Dnum)
    int ans = 0;
    int pos;
    int cnt = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            cnt++;
            if (!flag && cnt == 0) {
                ans += i - pos + 1;
                flag = true;
            }
        }
        else {
            cnt--;
            if (flag && cnt < 0) {
                flag = false;
                pos = i;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

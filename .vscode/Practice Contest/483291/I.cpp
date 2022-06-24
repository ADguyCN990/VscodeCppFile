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
vector<int> zero;
vector<int> one;
vector<int> two;
char s[MAXN];
bool vis[MAXN];
void solve() {
    ll sum = 0;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) vis[i] = true;
    for (int i = 1; i <= n; i++) {
        int u = (int)(s[i] - '0');
        if (u % 3 == 0)
            zero.pb(i);
        else if (u % 3 == 1)
            one.pb(i);
        else if (u % 3 == 2)
            two.pb(i);
        sum += u;
    }
    //printf("sum: %lld\n", sum);
    vector<int> ans1, ans2;
    int lenone = one.size();
    int lentwo = two.size();
    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());
    if (sum % 3 == 0) {
        puts(s + 1);
        return;
    }
    
    else if (sum % 3 == 1) {
        if (!lenone && lentwo < 2) {
            puts("-1");
            return;
        }
        if (lenone) {
            vis[one[0]] = false;
            for (int i = 1; i <= n; i++)
                if (vis[i]) 
                    ans1.pb((int)(s[i] - '0'));
            int len = ans1.size();
            int pos = -1;
            for (int i = 0; i < ans1.size(); i++) {
                if (ans1[i] != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1 && len) {
                ans1.clear();
                ans1.pb(0);
            }
            else {
                reverse(ans1.begin(), ans1.end());
                for (int i = 1; i <= pos; i++) ans1.pop_back();
                reverse(ans1.begin(), ans1.end());
            }  
            vis[one[0]] = true;     
        }
        if (lentwo >= 2) {
            vis[two[0]] = false;
            vis[two[1]] = false;
            for (int i = 1; i <= n; i++)
                if (vis[i]) 
                    ans2.pb((int)(s[i] - '0'));
            int len = ans2.size();
            int pos = -1;
            for (int i = 0; i < ans2.size(); i++) {
                if (ans2[i] != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1 && len) {
                ans2.clear();
                ans2.pb(0);
            }
            else {
                reverse(ans2.begin(), ans2.end());
                for (int i = 1; i <= pos; i++) ans2.pop_back();
                reverse(ans2.begin(), ans2.end());
            }
        }
        int len1 = ans1.size(), len2 = ans2.size();
        if (!len1 && !len2) {
            puts("-1");
            return;
        }
        if (!len2 && len1 || len1 && len2 && len1 >= len2) {
            for (int i = 0; i < len1; i++)
                printf("%d", ans1[i]);
        }
        else if (!len1 && len2 || len1 && len2 && len2 > len1) {
            for (int i = 0; i < len2; i++)
                printf("%d", ans2[i]);
        }
    }
    else if (sum % 3 == 2) {
        if (!lentwo && lenone < 2) {
            puts("-1");
            return;
        }
        if (lentwo) {
            vis[two[0]] = false;
            for (int i = 1; i <= n; i++)
                if (vis[i]) 
                    ans1.pb((int)(s[i] - '0'));
            int len = ans1.size();
            int pos = -1;
            for (int i = 0; i < ans1.size(); i++) {
                if (ans1[i] != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1 && len) {
                ans1.clear();
                ans1.pb(0);
            }
            else {
                reverse(ans1.begin(), ans1.end());
                for (int i = 1; i <= pos; i++) ans1.pop_back();
                reverse(ans1.begin(), ans1.end());
            }
            vis[two[0]] = true;
        }
        if (lenone >= 2) {
            vis[one[0]] = false;
            vis[one[1]] = false;
            // for (int i = 1; i <= n; i++)
            //     if (vis[i]) puts("true");
            //     else puts("false");
            for (int i = 1; i <= n; i++)
                if (vis[i]) 
                    ans2.pb((int)(s[i] - '0'));
            int len = ans2.size();
            int pos = -1;
            for (int i = 0; i < ans2.size(); i++) {
                if (ans2[i] != 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1 && len) {
                ans2.clear();
                ans2.pb(0);
            }
            else {
                reverse(ans2.begin(), ans2.end());
                for (int i = 1; i <= pos; i++) ans2.pop_back();
                reverse(ans2.begin(), ans2.end());
            }
        }
        int len1 = ans1.size(), len2 = ans2.size();
        //printf("len1: %d len2: %d\n", len1, len2);
        if (!len1 && !len2) {
            puts("-1");
            return;
        }
        if (!len2 && len1 || len1 && len2 && len1 >= len2) {
            for (int i = 0; i < len1; i++)
                printf("%d", ans1[i]);
        }
        else if (!len1 && len2 || len1 && len2 && len2 > len1) {
            for (int i = 0; i < len2; i++)
                printf("%d", ans2[i]);
        }
    }
}

int main() {
    solve();
    return 0;
}
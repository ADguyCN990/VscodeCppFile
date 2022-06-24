    #include<bits/stdc++.h>
    using namespace std;
    #define MAXN 1000005
    #define ll long long
    int n;
    char s[MAXN];
     
    int L[MAXN], R[MAXN];
    bool st[MAXN];
     
    void init(){
        for (int i=0;i<=n+1;++i){
            st[i] = false;
            L[i] = R[i] = 0;
        }
    }
     
    void solve() {
        scanf("%d", &n);
        scanf("%s", s + 1);
        init();
        int cnt = 0;
        for (int i=1;i<=n;++i){
            if (s[i]=='1') ++cnt;
        }
        if (cnt == n){
            puts("0"); return ;
        }
        for (int i=1;i<=n;++i){
            if (s[i] == '1'){
                int j = i;
                while (j - 1>=1 && s[j - 1] == '0') --j;
                L[i] = i - j;
                j = i;
                while (j + 1 <=n && s[j + 1] == '0') ++j;
                R[i] = j - i;
            }
        }
        bool hasone = false, right = false;
        for (int i=1;i<=n;++i){
            if (s[i] == '1'){
                if (true){
                    if (L[i] - right >= R[i]){
                        st[i - 1] = true;
                        right = false;
                    }
                    else{
                        st[i + 1] = true;
                        right = true;
                    }
                }
                hasone = true;
            }
        }
        for (int i=1;i<=n;++i){
            if (st[i]){
                s[i] = '1';
            }
        }
        int mx = 0;
        for (int i=1;i<=n;++i){
            if (s[i] == '0'){
                int j = i;
                while (j <= n && s[j] == '0') ++j;
                if (i == 1 || j == n + 1){
                    mx = max(mx, j - i);
                }
                else{
                    int len = j - i;
                    mx = max(mx, (len + 1) / 2);
                }
                i = j - 1;
            }
        }
        printf("%d\n", mx + 1);
        // cout << s + 1 << endl;
    }
     
    int main() {
        int T;
        scanf("%d", &T);
        while (T--) {
            solve();
        }
     
        return 0;
    }
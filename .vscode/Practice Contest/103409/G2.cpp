#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
int n;
char s[MAXN], ss[MAXN];

int L[MAXN], R[MAXN];
bool st[MAXN];

void init(){
    for (int i=0;i<=n+1;++i){
        st[i] = false;
        L[i] = R[i] = 0;
    }
}

// left left
int s1() {
    scanf("%d", &n);
    scanf("%s", ss + 1);
    init();
    int cnt = 0;
    for (int i=1;i<=n;++i){
        s[i] = ss[i];
        if (s[i]=='1') ++cnt;
    }
    if (cnt == n){
        return 0;
    }
    int bg = 0, ed = 0;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (bg == 0) bg = i;
            ed = i;
            int j = i;
            while (j - 1>=1 && s[j - 1] == '0') --j;
            L[i] = i - j;
            j = i;
            while (j + 1 <=n && s[j + 1] == '0') ++j;
            R[i] = j - i;
        }
    }
    bool right = false;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (i == bg || i == ed){
                st[i - 1] = true; right = false;
                continue;
            }
            if (true){
                if (L[i] - right >= R[i]){
                    st[i - 1] = true; right = false;
                }
                else if (L[i] - right < R[i]){
                    st[i + 1] = true;
                    right = true;
                }
            }
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
    return (mx + 1);
    // printf("%d\n", mx + 1);
    // cout << s + 1 << endl;
}

// left right
int s2() {
    init();
    int cnt = 0;
    for (int i=1;i<=n;++i){
        s[i] = ss[i];
        if (s[i]=='1') ++cnt;
    }
    int bg = 0, ed = 0;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (bg == 0) bg = i;
            ed = i;
            int j = i;
            while (j - 1>=1 && s[j - 1] == '0') --j;
            L[i] = i - j;
            j = i;
            while (j + 1 <=n && s[j + 1] == '0') ++j;
            R[i] = j - i;
        }
    }
    bool right = false;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (i == bg){
                st[i - 1] = true; right = false;
                continue;
            }
            if (i == ed){
                st[i + 1] = true; right = true;
                continue;
            }
            if (true){
                if (L[i] - right >= R[i]){
                    st[i - 1] = true; right = false;
                }
                else if (L[i] - right < R[i]){
                    st[i + 1] = true;
                    right = true;
                }
            }
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
    return (mx + 1);
    // printf("%d\n", mx + 1);
}

// right left
int s3() {
    init();
    int cnt = 0;
    for (int i=1;i<=n;++i){
        s[i] = ss[i];
        if (s[i]=='1') ++cnt;
    }
    int bg = 0, ed = 0;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (bg == 0) bg = i;
            ed = i;
            int j = i;
            while (j - 1>=1 && s[j - 1] == '0') --j;
            L[i] = i - j;
            j = i;
            while (j + 1 <=n && s[j + 1] == '0') ++j;
            R[i] = j - i;
        }
    }
    bool right = false;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (i == bg){
                st[i + 1] = true; right = true;
                continue;
            }
            if (i == ed){
                st[i - 1] = true; right = false;
                continue;
            }
            if (true){
                if (L[i] - right >= R[i]){
                    st[i - 1] = true; right = false;
                }
                else if (L[i] - right < R[i]){
                    st[i + 1] = true;
                    right = true;
                }
            }
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
    return (mx + 1);
    // printf("%d\n", mx + 1);
}

// right right
int s4() {
    init();
    int cnt = 0;
    for (int i=1;i<=n;++i){
        s[i] = ss[i];
        if (s[i]=='1') ++cnt;
    }
    int bg = 0, ed = 0;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (bg == 0) bg = i;
            ed = i;
            int j = i;
            while (j - 1>=1 && s[j - 1] == '0') --j;
            L[i] = i - j;
            j = i;
            while (j + 1 <=n && s[j + 1] == '0') ++j;
            R[i] = j - i;
        }
    }
    bool right = false;
    for (int i=1;i<=n;++i){
        if (s[i] == '1'){
            if (i == bg){
                st[i + 1] = true; right = true;
                continue;
            }
            if (i == ed){
                st[i + 1] = true; right = true;
                continue;
            }
            if (true){
                if (L[i] - right >= R[i]){
                    st[i - 1] = true; right = false;
                }
                else if (L[i] - right < R[i]){
                    st[i + 1] = true;
                    right = true;
                }
            }
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
    return (mx + 1);
    // printf("%d\n", mx + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int r1 = s1(), r2 = s2(), r3 = s3(), r4 = s4();
        int res = min({r1, r2, r3, r4});
        printf("%d\n", res);
    }

    return 0;
}
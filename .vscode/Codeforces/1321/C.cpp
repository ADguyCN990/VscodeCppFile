#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int n;
char s[MAXN];
bool vis[MAXN];
int main() {
    cin >> n;
    scanf("%s", s + 1);
    vector<char> v;
    int cnt = 0;
    for (int i = 1; i <= n; i++) v.push_back(s[i]);
    for (int i = 25; i >= 1; i--) {
        for (int k = 1; k <= 100; k++) {
            for (int j = 0; j < v.size(); j++) vis[j] = true;

            for (int j = 0; j < v.size(); j++) {
                if (v[j] != 'a' + i) continue;
                if (j == 0 && v[j + 1] == 'a' + i - 1 || 
                    j == (int)(v.size() - 1) && v[j - 1] == 'a' + i - 1 ||
                    j > 0 && j < (int)(v.size() - 1) && (v[j + 1] == 'a' + i - 1 || v[j - 1] == 'a' + i - 1))
                        vis[j] = false, cnt++;
            }
            vector<char> tmp;
            for (int j = 0; j < v.size(); j++)
                if (vis[j])
                    tmp.push_back(v[j]);
            v = tmp;
        }
        
    }
    printf("%d\n", cnt);
    return 0;
}
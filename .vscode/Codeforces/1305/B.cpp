#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<char, int> pci;
vector<int> v;
char s[MAXN];
int l[MAXN], r[MAXN];
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    vector<int> ans;
    int l = 1, r = n;
    while (l <= r) {
        while (s[l] == ')' && l <= n) l++;
        while (s[r] == '(' && r >= 1) r--;
        if (s[l] == '(' && s[r] == ')' && l < r)
            ans.push_back(l), ans.push_back(r);
        l++, r--;
    }
    sort(ans.begin(), ans.end());
    if (!ans.size()) {
        puts("0");
        return 0;
    }
    puts("1");
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    return 0;
}
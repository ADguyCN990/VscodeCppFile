#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 40 + 5;
char s[N];
int a[N];
map<vector<int>, bool> mp;

bool dfs(vector<int> ve){
    sort(ve.begin(), ve.end());
    if (ve.size() == 0) return false;
    if (mp.count(ve)) return mp[ve];
    int vlen = ve.size();
    bool f = true;
    for (int i=0;i<vlen;++i){
        vector<int> t = ve;
        // move all 
        t.erase(t.begin() + i);
        f &= dfs(t);
        if (!f){
            sort(ve.begin(), ve.end());
            return mp[ve] = true;
        }
        if (ve[i] <= 1) continue;
        // move 1
        ve[i]--;
        f &= dfs(ve);
        ve[i]++;
        if (!f){
            sort(ve.begin(), ve.end());
            return mp[ve] = true;
        }
        if (ve[i] <= 2) continue;
        // move 2
        ve[i] -= 2;
        f &= dfs(ve);
        ve[i] += 2;
        if (!f){
            sort(ve.begin(), ve.end());
            return mp[ve] = true;
        }
    }
    
    return mp[ve] = false;
}

int main(void){
    scanf("%s", s);
    n = strlen(s);
    for (int i=0;i<n;++i){
        a[s[i] - 'A']++;
    }
    vector<int> ve;
    for (int i=0;i<26;++i){
        if (a[i] > 0){
            ve.push_back(a[i]);
        }
    }
    bool f = dfs(ve);
    if (f){
        puts("Alice");
    }
    else{
        puts("Bob");
    }

    return 0;
}
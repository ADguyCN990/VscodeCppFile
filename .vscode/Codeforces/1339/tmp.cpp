#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans = 0;

void dfs(int cnt){//cnt从1开始 如同dfs(1)
    for(int i=1;i<=cnt;i++)ans++;
    cout << ans << endl;
    dfs(cnt+2);
}

int main() {
    dfs(1);
}
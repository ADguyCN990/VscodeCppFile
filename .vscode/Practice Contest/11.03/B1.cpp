#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll n, k;
char s[MAXN];

void solve()
{
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int j = len;
        while (j >= 1 && (s[j]>='0'&&s[j]<='9') )
            j--;
        int x = 0;
        for (int i = j + 1; i <= len; i++)
            x = x * 10 + (s[i] - '0');
        v.emplace_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k;i++) cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
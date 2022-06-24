#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<double, int> pdi;

int main() {
    int n;
    cin >> n;
    vector<pdi> num;
    for (int i = 1; i <= 50000; i++) 
        if (sin(i) > 0)
            num.push_back({sin(i), i});
    sort(num.begin(), num.end());
    int base = num[0].second;
    vector<int> ans;
    for (int i = -25000; i <= 25000; i++)
        ans.push_back(i * num[0].second);
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
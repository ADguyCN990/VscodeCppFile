#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    string s;
    s.resize(1000005);
    scanf("%s", &s[0]);
    for (int i = 1; i <= s.length() / 2; i++)
    {
        if (s.substr(0, i) == s.substr(s.length() - i))
        {
            vec.emplace_back(i);
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        unsigned long long t;
        scanf("%d", &t);
        t = min(t, s.length() - t + 1) - 1;
        printf("%d\n", upper_bound(vec.begin(), vec.end(), t) - vec.begin());
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            s = s.substr(0, s.find('/'));
            reverse(s.begin(), s.end());
            vec.emplace_back(stoi(s));
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < k; i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << vec[i];
        }
        cout << endl;
    }
}
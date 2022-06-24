#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> my_map;
    set<int> head;
    set<int> unused;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        my_map[l] = r;
        head.insert(l);
        unused.insert(r);
    }
    for (auto i : unused)
    {
        head.erase(i);
    }
    int a[100005] = {};
    int prior = 1;
    for (auto i : head)
    {
        int cur = i;
        while (my_map.count(cur) != 0 && a[cur] == 0)
        {
            a[cur] = prior;
            cur = my_map[cur];
        }
        for (int i = cur; i <= n; i++)
        {
            if (a[i] == 0)
            {
                a[i] = prior;
            }
        }
        prior++;
    }
    prior--;
    int last = 0;
    bool is_zero = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            if (is_zero)
            {
                a[i] = last;
            }
            else
            {
                is_zero = true;
                last = ++prior;
                a[i] = last;
            }
            if (i == 1)
            {
                cout << a[i];
            }
            else
            {
                cout << " " << a[i];
            }
        }
        else
        {
            if (i == 1)
            {
                cout << a[i];
            }
            else
            {
                cout << " " << a[i];
            }
            is_zero = false;
        }
    }
    cout << endl;
}
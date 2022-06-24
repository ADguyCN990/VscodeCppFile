#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    int y;
};

int main()
{

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<node> brack;
    int x = 0;
    int y = 0;
    int length = 1024;
    for (auto ch : s)
    {
        switch (ch)
        {
        case 'R':
            brack.emplace_back(node{x - 1, y});
            if (y == 0 && x * (x - length) < 0)
            {
                cout << "impossible" << endl;
                return 0;
            }
            x -= length;
            break;
        case 'L':
            if (y == 0 && x * (x + length) < 0)
            {
                cout << "impossible" << endl;
                return 0;
            }
            brack.emplace_back(node{x + 1, y});
            x += length;
            break;
        case 'U':
            if (x == 0 && y * (y - length) < 0)
            {
                cout << "impossible" << endl;
                return 0;
            }
            brack.emplace_back(node{x, y + 1});
            y -= length;
            break;
        case 'D':
            if (x == 0 && y * (y + length) < 0)
            {
                cout << "impossible" << endl;
                return 0;
            }
            brack.emplace_back(node{x, y - 1});
            y += length;
            break;
        default:
            break;
        }
    }

    cout << x << " " << y << endl;
    cout << brack.size() << endl;
    for (auto it : brack)
    {
        cout << it.x << " " << it.y << endl;
    }

    return 0;
}

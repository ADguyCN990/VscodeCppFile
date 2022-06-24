#include <bits/stdc++.h>

using namespace std;

char a[3][3];
int n;
int who;

int count()
{
    int alice = 0, bob = 0;

    // ver

    if (a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == 'O')
    {
        alice++;
    }
    if (a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X')
    {
        bob++;
    }
    if (a[1][0] == 'O' && a[1][1] == 'O' && a[1][2] == 'O')
    {
        alice++;
    }
    if (a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X')
    {
        bob++;
    }
    if (a[2][0] == 'O' && a[2][1] == 'O' && a[2][2] == 'O')
    {
        alice++;
    }
    if (a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X')
    {
        bob++;
    }

    // par

    if (a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == 'O')
    {
        alice++;
    }
    if (a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X')
    {
        bob++;
    }
    if (a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == 'O')
    {
        alice++;
    }
    if (a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X')
    {
        bob++;
    }
    if (a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == 'O')
    {
        alice++;
    }
    if (a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X')
    {
        bob++;
    }
    if (a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O')
    {
        alice++;
    }
    if (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X')
    {
        bob++;
    }
    if (a[2][0] == 'O' && a[1][1] == 'O' && a[0][2] == 'O')
    {
        alice++;
    }
    if (a[2][0] == 'X' && a[1][1] == 'X' && a[0][2] == 'X')
    {
        bob++;
    }
    return alice - bob;
}

int dfs(int alice, int bob)
{
    if (alice + bob == n)
    {
        if (who == 0)
        {
            if (alice == bob + 1 || alice == bob)
            {
                return count();
            }
            else
            {
                return -99999;
            }
        }
        else
        {
            if (bob == alice + 1 || alice == bob)
            {
                return count();
            }
            else
            {
                return -99999;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == '.')
            {
                a[i][j] = 'O';
                int m = dfs(alice + 1, bob);
                a[i][j] = 'X';
                m = max(m, dfs(alice, bob + 1));
                a[i][j] = '.';
                return m;
            }
        }
    }
    return -9999;
}

/*
* map[0][0]
* map[0][1]
* map[0][2]

map[0][3]
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> who;
        n = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '.')
                {
                    n++;
                }
            }
        }
        cout << dfs(0, 0) << endl;
    }
}
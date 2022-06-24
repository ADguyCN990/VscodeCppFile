#include <algorithm>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 4e5 + 7;
int vis[maxn];
vector<int> v1, v2;
int n;
int check(int mid)
{ //让v1前mid个和v2后mid个配对
    for (int i = 0; i < mid; i++)
    {
        if (v1[i] > v2[n - mid + i])
        {
            return 1; //需要更小的x
        }
    }
    for (int i = 0; i < n - mid; i++)
    {
        if (v1[i + mid] < v2[i])
            return 2; //需要更大x
    }
    return 0; //mid成立
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        v1.clear();
        v2.clear();
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++)
            vis[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            vis[x] = 1;
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            if (vis[i])
            {
                v1.push_back(i);
            }
            else
            {
                v2.push_back(i);
            }
        }
        int l = 0, r = n;
        int L = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid) != 2)
            {
                L = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        l = 0, r = n;
        int R = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid) != 1)
            {
                R = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << "L " << L + 1 << " R " << R + 1 << endl;
        printf("%d\n", R - L + 1);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int t, n, l, r;
    scanf("%d", &t);
    while (t--)
    {
        int f = 0, ff = 1, ff1 = 1;
        scanf("%d", &n);
        l = 1, r = n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        while (l < r)
        {

            if (a[l] == a[r])
            {
                l++, r--;
            }
            else if (f == 0)
            {
                f = a[l];
                l++;
            }
            else
            {
                ff1 = 0;
                break;
            }
            while (a[l] == f)
            {
                l++;
            }
            while (a[r] == f)
            {
                r--;
            }
        }
        if (ff1)
        {
            printf("YES\n");
            continue;
        }
        l = 1, r = n, f = 0;
        while (l < r)
        {

            if (a[l] == a[r])
            {
                l++, r--;
            }
            else if (f == 0)
            {
                f = a[r];
                r--;
            }
            else
            {
                ff = 0;
                printf("NO\n");
                break;
            }
            while (a[l] == f)
            {
                l++;
            }
            while (a[r] == f)
            {
                r--;
            }
        }
        if (ff)
            printf("YES\n");
    }
}
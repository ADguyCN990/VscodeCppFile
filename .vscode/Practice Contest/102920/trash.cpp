#include <bits/stdc++.h>
using namespace std;
char a[2000010], b[2000010];
int calc_min(char *s) {
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        s[n + i] = s[i]; //将一条链变成一个区间,或者说将这个区间翻一倍.
    int i = 1, j = 2, k;
    while (i <= n && j <= n)  {
        //在合法区间里面
        for (k = 0; k <= n && s[i + k] == s[j + k]; k++) //找出最大的不满足两个数相等的位置
            ;
        if (k == n) //如果完全一模一样
            break;
        if (s[i + k] > s[j + k])  {
            //如果大的话
            i += k + 1; //那么前面的数,肯定都不是最小表示.
            if (i == j)
                i++;
        }
        else {
            j += k + 1; //同理
            if (i == j)
                j++;
        }
    }
    return min(i, j);
}
int main() {
    scanf("%s", a + 1);
    int n = strlen(a + 1), x = calc_min(a);
    scanf("%s", b + 1);
    int m = strlen(b + 1), y = calc_min(b);
    a[x + n] = b[y + m] = 0;
    if (n == m && !strcmp(a + x, b + y)) {
        puts("Yes");
        puts(a + x);
    }
    else
        puts("No");
    return 0;
}

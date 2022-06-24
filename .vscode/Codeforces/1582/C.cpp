#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
string s;
int a[MAXN];
int b[MAXN];
int cnt;//不同的字符个数
int ans;
int flag;//是否可以经过题目给出的操作变成一个回文串
map<char, int> mp;
void solve()
{
    mp.clear();
    cin >> n >> s;
    cnt = 0;
    ans = 0x3f3f3f3f;
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] == 0)
        {
            mp[s[i]] = ++cnt;
        }
        a[i + 1] = mp[s[i]];
    }
    //上面为离散化操作（应该叫映射），将字符映射为其在字符串中出现的顺序大小如xyzxyz映射为 1 2 3 1 2 3,abac 映射为 1 2 1 3
    for (int k = 1; k <= cnt; k++) //当前可以删除的为k
    {
        int temp = 0;
        int i = 1;
        int j = n;
        while(i<j)
        {
            if(a[i]==a[j])//如果匹配上了，那么双指针向前一步
            {
                i++;j--;
            }
            else if(a[i]!=a[j])
            {
                if(a[i]==k)//a[i]为可以删除的数，必须跳过
                {
                    i++;temp++;
                }
                else if(a[j]==k)//a[j]为可以删除的数，必须跳过
                {
                    j--;temp++;
                }
                else//匹配不上，且a[i],a[j]都不能删除，非法！
                    break;
            }
        }

        if (i >= j)//到最后双指针碰上了，可以构成回文，打上标记
        {
            flag = 1;
            ans = min(ans, temp);
        }
    }
    if (flag == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
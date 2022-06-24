#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const double eps = 1e-6;
const ll inf = 0x3f3f3f3f;
const ll N = 1e6 + 10;

int arr[N], sign[N];
int vis[N], pri[N], tot;
void solve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            sign[i] = 1;
            pri[++tot] = i;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * pri[j] > n)
                break;
            vis[i * pri[j]] = pri[j]; //纪录最小的素因子
            if (i % pri[j] == 0)
                break;
        }
    }
}
int sum[N];
vector<int> vec;
int main()
{
    solve(1000000); //欧拉筛
    int T;
    scanf("%d", &T);
    while (T--)
    {
        vec.clear();
        int n;
        scanf("%d", &n);
        
        int ans0 = 0, ans1 = 0; //ans0 表示出现此处最多的数字的出现次数
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            ll temp=arr[i];
            int tmp = 1, j = 1;
            while (arr[i] >= pri[j])
            { //只保留奇数次幂质因子
                int num = 0;
                while (arr[i] % pri[j] == 0)
                {
                    num++;
                    arr[i] /= pri[j];
                }
                if (num % 2)
                    tmp *= pri[j];
                j++;
                if (sign[arr[i]])
                {
                    tmp *= arr[i];
                    break;
                }
            }
            vec.pb(tmp);
            ans0 = max(ans0, ++sum[tmp]);
            //cout<<"hash for "<<temp<<" : "<<tmp<<endl;
        }
        int even = 0;
        for (int v : vec)
        {
            if (v != 1)
            {
                if (sum[v] % 2 == 0) //未变化时出现次数为偶数且非 1 的数字数量
                    even++;
            }
            else
            {
                ans1++; //未变化时 1 的数量
            }
        }
        cout<<ans0<<" "<<ans1<<" "<<even<<endl;
        for (int v : vec)
        {
            sum[v] = 0;
        }
        int q;
        scanf("%d", &q);
        while (q--)
        {
            ll w;
            scanf("%lld", &w);
            if (w == 0)
            {
                printf("%d\n", ans0);
            }
            else
            {
                printf("%d\n", max(ans0, ans1 + even));
            }
        }
    }
    return 0;
}
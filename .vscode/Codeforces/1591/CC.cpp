#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+100;
int a[N];
vector<int> vt1,vt2,ans;
signed main()
{
    int T,n,k;
    scanf("%lld",&T);
    while(T--)
    {
        vt1.clear();
        vt2.clear();
        ans.clear();
        scanf("%lld%lld",&n,&k);
        int mmax = 0;
        for(int i = 1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i] < 0)
            {
                vt1.push_back(-a[i]);
            }
            else if(a[i] > 0)
            {
                vt2.push_back(a[i]);
            }
        }
        sort(vt1.begin(),vt1.end());
        sort(vt2.begin(),vt2.end());
        if(vt1.size() >= 0)
        {
            for(int i = vt1.size()-1;i>=0;i-=k)
            {
                ans.push_back(vt1[i]);
            }
        }
        if(vt2.size() >= 0)
        {
            for(int i = vt2.size()-1;i>=0;i-=k)
            {
                ans.push_back(vt2[i]);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size() == 0)
        {
            printf("0\n");
            continue;
        }
        int fans = 0;
        for(int i = 0;i<ans.size()-1;i++)
        {
            fans += ans[i] * 2;
        }
        fans+=ans[ans.size()-1];
        printf("%lld\n",fans);
    }
    return 0;
}
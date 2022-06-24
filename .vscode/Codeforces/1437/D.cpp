#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
int n;
void solve()
{
    cin>>n;
    int ans=1;
    int rt;
    int pre_num=0;int now_num=0;
    int pre=0;//上一个数字的值
    cin>>rt;
    for(int i=2;i<=n;i++)
    {
        int now;
        cin>>now;
        if(now<pre)
        {
            if(pre_num==0)
            {
                pre_num=now_num-1;now_num=1;ans++;
            }
            else if(pre_num>0)
            {
                pre_num--;now_num++;
            }
        }
        else
            now_num++;
        pre=now;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
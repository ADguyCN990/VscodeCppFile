#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
char s[MAXN];
int n;
int cnt;

void solve()
{
    vector <int> v;//缩点，缩点后的值为连通块的个数
    cin>>n;
    cin>>s+1;
    cnt=1;
    int x=s[1]-'0';
    for(int i=2;i<=n;i++)
    {
        if(s[i]-'0'==x)
            cnt++;
        else
        {
            v.emplace_back(cnt);
            cnt=1,x^=1;
        }
    }   
    v.emplace_back(cnt);
    int r=0;//右指针表示的是当前删的东西，如果等于1就继续往右扫
    int l=0;//左指针表示的是当前删的前缀
    int ans=0;
    n=v.size();//缩点后n要更新
    while(l<=r&&r<n)
    {   
        if(v[l]>1)
        {
            ans++;
            l++;
            if(r<l) r++;
            continue;
        }

        while(r<n&&v[r]==1)
            r++;
        if(r==n)//从l到r个数全为1，那么贡献为个数除以2（向上取整）
        {
            ans+=(r-l+1)/2;
            break;
        }
        else
        {
            l++,v[r]--,ans++;
        }

    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
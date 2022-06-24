#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,k,x;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>k;
        ll contribution=k/x;//一个人对烦躁值的贡献
        if(contribution>n)//一个人把所有人都得罪了
        {
            cout<<(n-1)*n/2<<endl;
            continue;
        }
        //右边contribution个人（等差数列），左边n-contribution个人
        ll left_ans=(n-contribution)*contribution;
        ll right_ans=(contribution-1)*contribution/2;
        cout<<left_ans+right_ans<<endl;
    }
    return 0;
}
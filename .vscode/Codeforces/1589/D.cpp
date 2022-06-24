#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll get(int l,int r)
{
    ll ans;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>ans;
    cout.flush();
    return ans;
}

void solve()
{
    cin>>n;
    int i,j,k;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int tmp=get(mid,n);
        if(tmp==0)
        {
            k=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    int tot=get(1,n);//总共的逆序对数量
    int dif=tot-get(1,k-1);//k能贡献的逆序对个数
    j=k-dif;

    //计算[i,j-1]中j-1能够贡献的逆序对个数
    int num1=get(1,j-1);
    int num2=get(1,j-2);
    dif=num1-num2;
    i=j-1-dif;

    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
    cout.flush();
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
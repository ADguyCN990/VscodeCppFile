#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll id;
int query(int l,int r)
{
    if(r<=l) return -1;//防止越界
    cout<<"? "<<l<<" "<<r<<endl;//找出[L,R]区间内第二大元素的位置
    cin>>id;
    cout.flush();
    return id;
}

void solve()
{
    int ans=0;
    cin>>n;
    int l=1;int r=n;
    int se=query(l,r);//根据se的值来确定l和r
    if(se==0||query(1,se)!=se)//在se的右边
    {
        l=se;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(query(se,m)==se)
            {
                r=m;
            }
            else l=m;
        }
        int now=query(l,r);
        if(now==l) cout<<"! "<<r<<endl;
        else cout<<"! "<<l<<endl;
    }
    else//在se的右边
    {
        r=se;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(query(m,se)==se)
            {
                l=m;
            }
            else r=m;
        }
        int now=query(l,r);
        if(now==l) cout<<"! "<<r<<endl;
        else cout<<"! "<<l<<endl;
    }
    

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

    // while(r-l>1)
    // {
    //     int m=(l+r)/2;
    //     int se=query(l,r);

    //     if(se<=m)
    //     {
    //         if(query(l,m)==se) r=m;
    //         else l=m;
    //     }
    //     else
    //     {
    //         if(query(m+1,r)==se) l=m;
    //         else r=m;
    //     }
    // }
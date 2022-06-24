#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n,m;
ll a[MAXN];
ll dx,ddx;
void solve()
{
    cin>>n;
    m=-1;
    dx=-1;ddx=-1;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            ll temp=a[i]-a[i-1];
            if(dx==-1)
            {
                dx=temp;
            }
            else
            {
                if(temp!=dx)//出现了差值不相等的情况
                {
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        else//要处理mod了
        {
            if(ddx==-1)
            {
                ddx=a[i-1]-a[i];
            }
            else
            {
                if(ddx!=a[i-1]-a[i])
                {
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    if(ddx==-1||dx==-1)
    {
        cout<<0<<endl;
        return;
    }
    m=ddx+dx;
    if(a[1]>=m)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=2;i<=n;i++)
    {   
        ll temp=(a[i-1]+dx)%m;
        if(temp!=a[i])
        {
            cout<<-1<<endl;
            return;
        }
    }

    cout<<m<<" "<<dx<<endl;
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
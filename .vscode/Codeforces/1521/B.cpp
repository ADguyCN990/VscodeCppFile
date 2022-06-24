#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005

void solve()
{
    ll n;
    ll minx=0x3f3f3f3f;
    ll min_id=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll temp;
        cin>>temp;
        if(temp<minx)
        {
            min_id=i;
            minx=temp;
        }
    }
    cout<<n-1<<endl;
    if(minx==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==min_id) continue;
            cout<<min_id<<" "<<i<<" "<<minx<<" "<<minx<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==min_id) continue;
        if(i<min_id)//ai=x,aj=y       
        {
            if(min_id%2==1&&i%2==1)
                cout<<i<<" "<<min_id<<" "<<minx<<" "<<minx<<endl;
            else if(min_id%2==1&&i%2==0)
                cout<<i<<" "<<min_id<<" "<<minx+1<<" "<<minx<<endl;
            else if(min_id%2==0&&i%2==1)
                cout<<i<<" "<<min_id<<" "<<minx+1<<" "<<minx<<endl;
            else if(min_id%2==0&&i%2==0)
                cout<<i<<" "<<min_id<<" "<<minx<<" "<<minx<<endl;
        }
        else if(i>min_id)
        {
            if(min_id%2==1&&i%2==0)
                cout<<min_id<<" "<<i<<" "<<minx<<" "<<minx+1<<endl;
            else if(min_id%2==1&&i%2==1)
                cout<<min_id<<" "<<i<<" "<<minx<<" "<<minx<<endl;
            else if(min_id%2==0&&i%2==1)
                cout<<min_id<<" "<<i<<" "<<minx<<" "<<minx+1<<endl;
            else if(min_id%2==0&&i%2==0)
                cout<<min_id<<" "<<i<<" "<<minx<<" "<<minx<<endl;
        }
            
    }
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
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
typedef pair<int,int> pii;
pii a[MAXN];//first为权值，second为编号
int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
        
    sort(a+1,a+1+n);
    if(a[1].first==a[n].first)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int pos=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i].first!=a[i-1].first)
        {
            pos=i;
            break;
        }
    }
    for(int i=1;i<pos;i++)
    {
        cout<<a[i].second<<" "<<a[pos].second<<endl;
    }
    for(int i=pos+1;i<=n;i++)
        cout<<a[1].second<<" "<<a[i].second<<endl;
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
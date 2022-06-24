#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;pair<int,int> a[MAXN];
int cnt[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        a[i]=make_pair(temp,i);
        cnt[temp]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(cnt[a[i].first]==1)
        {
            cout<<a[i].second<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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
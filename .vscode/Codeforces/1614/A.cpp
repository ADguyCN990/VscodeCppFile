#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,l,r,k;
int a[MAXN];
void solve()
{
    cin>>n>>l>>r>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int cnt=0;
    int pos=lower_bound(a+1,a+1+n,l)-(a);
    //cout<<"pos: "<<pos<<endl;
    for(int i=pos;i<=n;i++)
    {
        k-=a[i];
        if(k<0) break;
        if(a[i]>r) break;
        cnt++;
    }
    cout<<cnt<<endl;
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
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f

void solve()
{
    int n;
    cin>>n;
    int a=1,b=2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==a||j==b)
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
        a++,b++;
        if(a>n) a=1;
        if(b>n) b=1;
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
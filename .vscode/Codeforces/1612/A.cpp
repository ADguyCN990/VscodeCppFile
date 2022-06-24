#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int x,y;
void solve()
{
    cin>>x>>y;
    int d=x+y;
    if(d&1)
    {
        cout<<"-1 -1"<<endl;
        return;
    }
    if(x&1&&y&1)
    {
        if(x>=y)
        {
            cout<<x-(x+y)/2<<" "<<y<<endl;
        }
        else
            cout<<x<<" "<<y-(x+y)/2<<endl;
    }
    else
    {
        cout<<x/2<<" "<<y/2<<endl;
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
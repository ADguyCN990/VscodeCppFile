#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n;
string s;
void solve()
{
    cin>>n;
    if(!(n%2))
    {
        cout<<0<<endl;
        return;
    }

    s=to_string(n);
    if((s[0]-'0')%2==0)
    {
        cout<<1<<endl;
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        if((s[i]-'0')%2==0)
        {
            cout<<2<<endl;
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
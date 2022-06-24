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
    int x=n%3;
    int a=n/3;
    if(n==1||n==2||n==4)
        cout<<-1<<endl;
    else if(x==0)
    {
        cout<<a<<" "<<0<<" "<<0<<endl;
    }
    else if(x==1)
    {
        cout<<a-2<<" "<<0<<" "<<1<<endl;
    }   
    else if(x==2)
    {
        cout<<a-1<<" "<<1<<" "<<0<<endl;
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
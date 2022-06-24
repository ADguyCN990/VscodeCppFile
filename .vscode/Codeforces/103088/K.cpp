#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MAXN 1005
int m,l,n;
int a[MAXN];

void solve()
{
    cin>>m>>l>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    a[n+1]=l;
    int dx=0;
    for(int i=1;i<=n+1;i++)
    {
        dx=max(dx,a[i]-a[i-1]);  
    }
    
        if(dx>=m)
        {
            cout<<"Y"<<endl;
            return;
        }
        cout<<"N"<<endl;
        
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
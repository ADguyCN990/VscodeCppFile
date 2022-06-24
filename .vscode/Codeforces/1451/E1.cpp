#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n;
int a[MAXN];

void solve()
{
    cin>>n;
    int x,y,z;
    int xx,yy,zz;
    int xxx,yyy,zzz;
    cout<<"XOR 1 2"<<endl;
    cin>>xx;
    cout.flush();
    cout<<"XOR 1 3"<<endl;
    cin>>yy;
    cout.flush();
    zz=xx^yy;
    cout<<"AND 1 2"<<endl;
    cin>>xxx;
    cout.flush();
    cout<<"AND 1 3"<<endl;
    cin>>yyy;
    cout.flush();
    cout<<"AND 2 3"<<endl;
    cin>>zzz;
    cout.flush();
    x=xx+2*xxx;
    y=yy+2*yyy;
    z=zz+2*zzz;
    a[1]=(x+y-z)/2;a[2]=(x+z-y)/2;a[3]=(y+z-x)/2;
    for(int i=4;i<=n;i++)
    {
        cout<<"XOR 1 "<<i<<endl;
        int tmp;
        cin>>tmp;
        cout.flush();
        a[i]=tmp^a[1];
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
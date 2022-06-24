#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
char s[MAXN][MAXN];
int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i]+1;
    char a=s[1][2],b=s[2][1],c=s[n][n-1],d=s[n-1][n];
    int x=a-'0'+b-'0';
    int y=c-'0'+d-'0';
    if(x==y&&(x==0||x==2))
    {
        cout<<2<<endl;
        cout<<"1 2"<<endl;
        cout<<"2 1"<<endl;
    }
    else if(x==y&&x==1)
    {
        cout<<2<<endl;
        if(a=='1') cout<<"1 2"<<endl;
        else cout<<"2 1"<<endl;
        if(c=='0') cout<<n<<" "<<n-1<<endl;
        else cout<<n-1<<" "<<n<<endl;
    }
    else if(x==2&&y==1)
    {
        cout<<1<<endl;
        if(c=='1') cout<<n<<" "<<n-1<<endl;
        else cout<<n-1<<" "<<n<<endl;
    }
    else if(x==1&&y==2)
    {
        cout<<1<<endl;
        if(a=='1') cout<<"1 2"<<endl;
        else cout<<"2 1"<<endl;
    }
    else if(x==0&&y==1)
    {
        cout<<1<<endl;
        if(c=='0') cout<<n<<" "<<n-1<<endl;
        else cout<<n-1<<" "<<n<<endl;
    }
    else if(x==1&&y==0)
    {
        cout<<1<<endl;
        if(a=='0') cout<<"1 2"<<endl;
        else cout<<"2 1"<<endl;
    }
    else cout<<0<<endl;
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
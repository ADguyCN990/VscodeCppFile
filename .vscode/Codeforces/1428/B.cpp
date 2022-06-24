#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
char s[MAXN];
int n;
void solve()
{
    cin>>n>>s;
    int cnt=0;
    int f1=0,f2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='<') f1=1;
        else if(s[i]=='>') f2=1; 
    }
    if(f1==0||f2==0)
    {
        cout<<n<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='-'||s[(i+1)%n]=='-')
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
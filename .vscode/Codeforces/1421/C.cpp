#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
string s;
void solve()
{
    cin>>s;
    int len=s.length();
    cout<<3<<endl;
    cout<<"R "<<len-1<<endl;
    cout<<"L "<<len<<endl;
    cout<<"L "<<2<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;
char s[MAXN];
ll n;

vector<int> pos;
void solve()
{
    cin >> n;
    cin >> s + 1;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='a'&&s[i+1]=='a')
        {
            cout<<2<<endl;
            return;
        }
    }
    for(int i=1;i<n-1;i++)
    {
        if(s[i]=='a'&&s[i+2]=='a')
        {
            cout<<3<<endl;
            return;
        }
    }
    for(int i=1;i<n-2;i++)
    {
        if(s[i]=='a'&&(s[i+1]=='b'&&s[i+2]=='c'||s[i+1]=='c'&&s[i+2]=='b')&&s[i+3]=='a')
        {
            cout<<4<<endl;
            return;
        }
    }
    for(int i=1;i<n-5;i++)
    {
        if(s[i]=='a'&&s[i+3]=='a'&&s[i+6]=='a'&&((s[i+1]=='b'&&s[i+2]=='b'&&s[i+4]=='c'&&s[i+5]=='c')||(s[i+1]=='c'&&s[i+2]=='c'&&s[i+4]=='b'&&s[i+5]=='b')))
        {
            cout<<7<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
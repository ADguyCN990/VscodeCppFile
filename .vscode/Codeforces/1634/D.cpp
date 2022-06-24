#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll query(ll i, ll j, ll k)
{
    cout << "? " << i << " " << j << " " << k << endl;
    ll ans;
    cin >> ans;
    return ans;
}
void output(ll i, ll j)
{
    cout << "! " << i << " " << j << endl;
}

ll n;
void solve()
{
    cin >> n;
    int pos1 = 1, pos2 = 2;
    int pos3 = 0;
    int x, y;
    int mxdx = 0;
    for (int i = 3; i <= n; i ++)
    {
        int dx = query(pos1, pos2, i);
        if (dx > mxdx)
        {
            mxdx = dx;
            pos3 = i;
        }
        //printf("pos1: %d pos2 : %d pos3: %d\n", pos1, pos2, pos3);
    }
    for (int i = 3; i <= n; i ++)
    {
        if (i == pos3) continue;
        int dx = query(i, pos1, pos3);
        if (dx > mxdx)
        {
            mxdx = dx;
            pos2 = i;
        }
        //printf("pos1: %d pos2 : %d pos3: %d\n", pos1, pos2, pos3);
    }
    int mid;
    for (int i = 1; i <= n; i ++)
    {
        if (i != pos1 && i != pos2 && i != pos3)
        {
            mid = i;
            break;
        }
    }
    int tmp = query(pos2, pos3, mid);
    if (tmp == mxdx)
    {
        output(pos2, pos3);
        return;
    }
    tmp = query(pos1, pos3, mid);
    if (tmp == mxdx)
    {
        output(pos1, pos3);
        return;
    }
    output(pos1, pos2);
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T --)
    {
        solve();
    }
    return 0;
}
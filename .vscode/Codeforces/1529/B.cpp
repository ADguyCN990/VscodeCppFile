#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll a[MAXN];
int t, n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (a[1] > 0)
    {
        cout << 1 << endl;
        return;
    }
    int pos=upper_bound(a+1,a+1+n,0)-a;//第一个大于0的数的位置
    ll min_dx=0x3f3f3f3f;
    for(int i=1;i<pos;i++)
    {
        min_dx=min(min_dx,a[i+1]-a[i]);
    }
    if(pos>n)
    {
        cout<<n<<endl;
        return;
    }
    if(min_dx>=a[pos])
    {
        cout<<pos<<endl;
        return;
    }
    else if(min_dx<a[pos])
    {
        cout<<pos-1<<endl;
        return;
    }
    //cout<<pos<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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
int n;

int query(int num)
{
    int ans;
    cout << "+ " << num << endl;
    cin >> ans;
    cout.flush();
    return ans;
}

void output(int ans)
{
    cout << "! " << ans << endl;
    cout.flush();
}

void solve()
{
    cin >> n;
    int l = 1, r = n - 1;
    int sum = 0;
    int pre = 0;
    // through observation, it is easy to know that get * n <= x + c < (get + 1) * n 
    // c is the num we add, get is the result we query, n is known, x is the answer we need to know
    // we can use binary search to confirm the range [l,r] of x
    // from the last theory, it is obvious that if (l == r - 1) then l = x;
    // after that, let sum = add1 + add2 + add3 + ... + addm, m is the time we need to query
    // it can be proved that the REAL ANSWER = sum + l 
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        int add = (pre + 1) * n - sum - mid;
        int tmp = query(add);
        if (tmp > pre) // now/n > pre/n
            l = mid;
        else
            r = mid - 1;
        pre = tmp;
        sum += add;
    }
    output(sum + l);
}

int main()
{
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();

    return 0;
}
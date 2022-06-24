#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 1000005
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int head[MAXM];int cnt;
struct node
{
    ll to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}

void solve()
{

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
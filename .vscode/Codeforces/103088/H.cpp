#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,k;

struct node
{
    int color;
    int id;
}a[MAXN];
bool cmp1(node a,node b) {return a.id<b.id;}
int base[MAXN];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i].id>>a[i].color;
        base[i]=a[i].color;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)
        if(a[i].color!=base[i])
        {
            cout<<"N"<<endl;
            return;
        }
    cout<<"Y"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
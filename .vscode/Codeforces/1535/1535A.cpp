#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
struct node
{
    int id;
    int val;
}a[MAXN];
bool cmp(node a,node b){return a.val>b.val;}
int t,n;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        
        for(int i=1;i<=4;i++)
        {
            a[i].id=i;
            cin>>a[i].val;
        }
        sort(a+1,a+1+4,cmp);
        if(a[1].id<=2&&a[2].id<=2||a[1].id>2&&a[2].id>2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
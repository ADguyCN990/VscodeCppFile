#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
ll t,n;
struct node
{
    int order;
    int val;
    int id;
}a[MAXN*2];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
struct nodee
{
    ll l;
    ll r;
    ll dx;
};
bool cmpp(node a,node b) {return a.id<b.id;}
vector <nodee> v;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i].val;
            a[i].id=i;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            a[i].order=i;
        }
        sort(a+1,a+1+n,cmpp);
        for(int i=n+1;i<2*n;i++) a[i]=a[i-n];
        ll last_pos=0;
        for(int i=1;i<n;i++)
        {
            ll pos=0;
            ll last_pos=0;
            for(int j=last_pos;j<2*n;j++)
            {
                if(a[j].order==i)//找到了当前要找的东西
                {
                    pos=j;
                    break;
                }
            }
            int temp=0;
            for(int j=last_pos+1;j<pos;j++) if(a[j].order<i-1) temp++;
            ll dx=pos-last_pos-1-temp;
            if(dx>0) v.push_back(nodee{i,n,dx});
            if(pos>n) pos-=n;
            last_pos=pos;

            // if(pos-i!=0)
            // {
            //     node temp[MAXN];
            //     for(int j=i;j<=n;j++)
            //     {
            //         temp[j]=a[(j+pos-i-1)%(n-i+1)+1];
            //     }   
            //     for(int j=i;j<=n;j++) a[j]=temp[j];
            // }
            
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++) cout<<v[i].l<<" "<<v[i].r<<" "<<v[i].dx<<endl;
    }
    return 0;
}
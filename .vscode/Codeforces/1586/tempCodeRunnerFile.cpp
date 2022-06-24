#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define ll long long
ll n;
struct node
{
    int next_pos=0;
    int pre_pos=0;
    int val;
}a[MAXN];
void query1(int dx)
{
    cout<<"?";
    for(int i=1;i<n;i++) cout<<" "<<1+dx;
    cout<<" "<<1<<endl;
    
    cout.flush();
}
void query2(int dx)
{
    cout<<"?";
    for(int i=1;i<n;i++) cout<<" "<<n-dx;
    cout<<" "<<n<<endl;
    cout.flush();
}
void solve()
{
    cin>>n;
    int now=n;
    int dx=1;
    while(1)
    {     
        if(n-dx==0)
        {
            a[n].val=n-dx+1;
            break;
        }   
        query2(dx);
        int index;
        cin>>index;
        if(index==0)
        {
            a[n].val=n-dx+1;
            break;
        } 
        else
        {
            a[now].next_pos=index;
            now=index;
            dx++;
        }
    }
    now=n;dx=1;
    while(1)
    {
        if(1+dx==n) break;
        
        query1(dx);
        int index;
        cin>>index;
        if(index==0) break;
        a[now].pre_pos=index;
        now=index;
        dx++;
    }
    dx=0;
    for(int i=n;i;i=a[i].pre_pos)
    {
        a[i].val=a[n].val-dx;
        dx++;
    }
    dx=0;
    for(int i=n;i;i=a[i].next_pos)
    {
        a[i].val=a[n].val+dx;
        dx++;
    }
    cout<<"!";
    for(int i=1;i<=n;i++)
    {
        cout<<" "<<a[i].val;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    solve();
    

    return 0;
}
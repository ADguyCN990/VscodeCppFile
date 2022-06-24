#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n;
int a[MAXN];
int sum=0;
struct node
{
    int x,y,val;
};
vector <node> ans;
void work(int x,int y,int val)
{
    a[x]-=x*val;
    a[y]+=x*val;
    ans.push_back({x,y,val});
}

void solve()
{
    ans.clear();
    sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n!=0)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]%i==0)
            work(i,1,a[i]/i);
        else 
        {
            work(1,i,i-a[i]%i);
            //cout<<"!!! "<<a[1]<<" "<<a[i]<<endl;
            work(i,1,a[i]/i);
        }
        //cout<<"!!! "<<a[1]<<" "<<a[i]<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        work(1,i,sum/n);
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it.x<<" "<<it.y<<" "<<it.val<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}
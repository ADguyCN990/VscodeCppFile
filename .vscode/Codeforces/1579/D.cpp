#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll t,n;
vector <pair<int,int>> ans;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        priority_queue <pair<int,int>> q;
        ans.clear();
        for(int i=1;i<=n;i++)
        {
            int temp;
            cin>>temp;
            if(temp>0)
            q.push(make_pair(temp,i));
        }
        while(q.size()>1)
        {
            pair <int,int> a=q.top();q.pop();
            pair <int,int> b=q.top();q.pop();
            a.first--;b.first--;
            ans.push_back(make_pair(a.second,b.second));
            if(a.first>0) q.push(a);
            if(b.first>0) q.push(b);
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
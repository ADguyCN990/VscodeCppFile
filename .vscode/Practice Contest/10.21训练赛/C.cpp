#include<bits/stdc++.h>
using namespace std;
vector <pair<int,int>> ans;
#define ll long long
ll k,n;

void solve()
{
    cin>>k;
    n=1;
    if(k==2)
    {
        cout<<1<<endl;
        return;
    }
    if (k<5){
        cout << k-1 << endl;
        for (int i=2;i<k;++i){
            cout << i-1 << " " << i << endl;
            // printf("%d %d\n", i-1, i);
        }
        return;
    }
    while(k)
    {   
        if(k<5) break;
        if((k-1)%2==0)
        {
            ans.emplace_back(make_pair(n,n+1));
            ans.emplace_back(make_pair(n,n+2));
            
            k=(k-1)/2;
            n+=2;
        }
        else if((k-1)%2==1)
        {
            ans.emplace_back(make_pair(n,n+1));
            n++;
            k--;
        }
    }
    
    
    if (k>0){
        for (int i=n+1;i<k+n-1;++i){
            ans.emplace_back(make_pair(i-1, i));
        }
    }
    int alen = ans.size()+1;
    cout<<alen<<endl;
    for(auto x:ans)
    {
        cout<<x.first<<' '<<x.second<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
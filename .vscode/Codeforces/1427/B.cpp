#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,k;
char s[MAXN];

void solve()
{
    cin>>n>>k>>s+1;
    int cnt=0;
    int cnt1=0,cnt2=0;
    if(n==1)
    {
        if(s[1]=='W'||s[1]=='L'&&k) cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    vector <int> v;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='W')
        {
            cnt++;
            int j=i+1;
            while(j<=n&&s[j]=='W')
            {
                cnt+=2;
                j++;
            }
            i=j-1;
        }
        if(!cnt&&s[i]=='L') {cnt1++;continue;}
        if(cnt&&s[i]=='L')
        {
            int tmp=1;
            int j=i+1;
            while(j<=n&&s[j]=='L')
            {
                tmp++;
                j++;
            }
            i=j-1;
            if(j>n) 
            {
                cnt2=tmp;
                break;
            }
            v.emplace_back(tmp);
        }
    }
    if(!cnt)
    {
        cout<<max((k-1)*2+1,0)<<endl;
        return;
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        if(!k) break;
        int tmp=min(k,x);
        
        if(tmp==x)
        cnt+=3+(tmp-1)*2;
        else if(tmp==k)
        cnt+=tmp*2;
        k-=tmp;
    }
    cnt+=min(k,cnt1+cnt2)*2;
    cout<<cnt<<endl;
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
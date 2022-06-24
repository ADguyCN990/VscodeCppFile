#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
int t,n;
char c;
string s;
vector <int> v;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>c>>s;
        v.clear();
        int id=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=c) v.emplace_back(i+1);
            if(s[i]==c) id=i+1;
        }
        if(v.size()==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(s[n-1]==c)
        {
            cout<<1<<endl;
            cout<<n<<endl;
        }
        else if(s[n-1]!=c&&s[n-2]==c)
        {
            cout<<1<<endl;
            cout<<n-1<<endl;
        }
        else 
        {
            if(id>n/2)
            {
                cout<<1<<endl;
                cout<<id<<endl;
            }
            else
            {
                cout<<2<<endl;
                cout<<n<<" "<<n-1<<endl;
            }
        }
        

    }
    return 0;
}
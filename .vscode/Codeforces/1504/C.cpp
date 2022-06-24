#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;
string s;
int cnt;
void solve()
{
    cin>>n>>s;
    int len=s.length();
    if(s[0]=='0'||s[len-1]=='0') 
    {
        cout<<"No"<<endl;
        return;
    }
    cnt=0;
    for(int i=0;i<len;i++) if(s[i]=='1') cnt++;
    if(cnt%2==1) 
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    string s1="";string s2="";
    int cnt_0=0;int cnt_1=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='1')
        {
            if(cnt_1<cnt/2)
            {
                s1+='(';s2+='(';
            }
            else
            {
                s1+=')';s2+=')';
            }
            cnt_1++;
        }
        else if(s[i]=='0')
        {
            if(cnt_0%2==0)
            {
                s1+=')';s2+='(';
            }
            else if(cnt_0%2==1)
            {
                s1+='(';s2+=')';
            }
            cnt_0++;
        }
    }
    cout<<s1<<endl<<s2<<endl;
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
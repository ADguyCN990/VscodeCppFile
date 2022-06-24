#include<bits/stdc++.h>
using namespace std;
string s,t;
map <char,string> mp;
int a[55];
int b[200005];
void pre()
{
    mp['0']="0000";
    mp['1']="0001";
    mp['2']="0010";
    mp['3']="0011";
    mp['4']="0100";
    mp['5']="0101";
    mp['6']="0110";
    mp['7']="0111";
    mp['8']="1000";
    mp['9']="1001";
    mp['A']="1010";
    mp['B']="1011";
    mp['C']="1100";
    mp['D']="1101";
    mp['E']="1110";
    mp['F']="1111";
}

void solve()
{
    cin>>s>>t;
    int len=s.length();
    for(int i=0;i<len;i++) a[i]=s[i]-'0';
    int lenb=t.length()*4;
    memset(b,0,sizeof b);
    for(int i=0;i<t.length();i++)
    {
        string tmp=mp[t[i]];
        for(int j=i*4,k=0;k<4;k++,j++)
        {
            b[j]=tmp[k]-'0';
        }
    }
    for(int i=0;i<lenb;i++)
    {
        if(b[i]==1)
        {
            for(int j=0;j<len;j++)
            {
                b[i+j]^=a[j];
            }
        }
    }
    for(int i=lenb;i<len+lenb-1;i++) cout<<b[i];
    cout<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    pre();
    while(T--)
    {
        solve();
    }

    return 0;
}
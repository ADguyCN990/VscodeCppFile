#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
void solve()
{
    ll p1=0;ll p2=0;ll p3=0;
    cin>>n;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    string s="";
    int i=0;
    int cnt=0;
    //三指针，把多的放入构造字符串，对应指针增加，有两个指针到结尾就退出，构造完成
    while(1)
    {
        //000
        if(s1[p1]=='0'&&s2[p2]=='0'&&s3[p3]=='0')
        {
            s+='0';
            p1=min(2*n,p1+1);p2=min(2*n,p2+1);p3=min(2*n,p3+1);
        }

        //001
        if(s1[p1]=='0'&&s2[p2]=='0'&&s3[p3]=='1')
        {
            s+='0';
            p1=min(2*n,p1+1);p2=min(2*n,p2+1);
        }

        //010
        if(s1[p1]=='0'&&s2[p2]=='1'&&s3[p3]=='0')
        {
            s+='0';
            p1=min(2*n,p1+1);p3=min(2*n,p3+1);
        }

        //011 
        if(s1[p1]=='0'&&s2[p2]=='1'&&s3[p3]=='1')
        {
            s+='1';
            p2=min(2*n,p2+1);p3=min(2*n,p3+1);
        }

        //100
        if(s1[p1]=='1'&&s2[p2]=='0'&&s3[p3]=='0')
        {
            s+='0';
           p2=min(2*n,p2+1);p3=min(2*n,p3+1);
        }

        //101
        if(s1[p1]=='1'&&s2[p2]=='0'&&s3[p3]=='1')
        {
            s+='1';
            p1=min(2*n,p1+1);p3=min(2*n,p3+1);
        }

        //110
        if(s1[p1]=='1'&&s2[p2]=='1'&&s3[p3]=='0')
        {
            s+='1';
            p1=min(2*n,p1+1);p2=min(2*n,p2+1);
        }

        //111
        if(s1[p1]=='1'&&s2[p2]=='1'&&s3[p3]=='1')
        {
            s+='1';
            p1=min(2*n,p1+1);p2=min(2*n,p2+1);p3=min(2*n,p3+1);
        }       
        if(p1>=2*n||p2>=2*n||p3>=2*n) break;
    }
    //cout<<p1<<" "<<p2<<" "<<p3<<endl;
    if(p1==2*n&&p2!=2*n&&p3!=2*n) 
    {
        if(p2>p3) s=s+s2.substr(p2,2*n);
        else s=s+s3.substr(p3,2*n);
    }
    else if(p1!=2*n&&p2==2*n&&p3!=2*n) 
    {
        if(p1>p3) s=s+s1.substr(p1,2*n);
        else s=s+s3.substr(p3,2*n);
    }
    else if(p1!=2*n&&p2!=2*n&&p3==2*n) 
    {
        if(p1>p2) s=s+s1.substr(p1,2*n);
        else s=s+s2.substr(p2,2*n);
    } 
    cout<<s<<endl;

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
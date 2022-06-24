#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        //每次减去当前数的一个因数，谁先减到质数谁获胜。
       ll cnt=0;
       if(n%2==1)
       {
           cout<<"Bob"<<endl;
           continue;
       }
       while(n%2==0)
       {
           n/=2;
           cnt++;
       } 
       if(n>1) cout<<"Alice"<<endl;
       else if(cnt%2==1) cout<<"Bob"<<endl;
       else cout<<"Alice"<<endl;
    }
    return 0;
}
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
        ll temp=0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0) 
            {
                temp=n/i;
                break;
            }
        }
        if(temp%2==1) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
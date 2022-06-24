#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,y,z,xx,yy,zz;
    cin>>x>>y>>z;
    cin>>xx>>yy>>zz;
    int a=y*zz-yy*z;
    int b=xx*z-x*zz;
    int c=x*yy-xx*y;
    cout<<a<<" "<<b<<" "<<c<<endl;

    return 0;
}
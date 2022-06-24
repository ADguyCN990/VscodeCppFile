#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
long long a,b,c;
long long x0,x1,y0,y1,y2;
long long cal(long long xx) {return a*xx*xx+b*xx+c;}
long long al,ar,am;
int main() {
  scanf("%d",&t);
  while(t--) 
  {
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld%lld%lld%lld%lld",&x0,&x1,&y0,&y1,&y2);
    al=cal(x0);ar=cal(2*x1-x0),am=cal(x1);
    //cout<<al<<" "<<am<<" "<<ar<<endl;
    if(al<=y0) {puts("No");continue;}
    if(am>=y2) {puts("No");continue;}
    if(ar>=y0) {puts("No");continue;}
    puts("YES");
  }  
} 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Point{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
};
ll cross(Point& a,Point& b){
    return a.x*b.y-a.y*b.x;
}
vector<Point> polv[1005];

int main(void){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int P;
        scanf("%d",&P);
        while(P--){
            ll x,y;
            scanf("%lld %lld",&x,&y);
            polv[i].emplace_back(Point(x,y));
        }
    }
    ll ans = 0;
    for(int i=1;i<=N;i++){
        int p = polv[i].size();
        int tmpAns = 0;
        for(int j=0;j<p;j++){
            tmpAns+=cross(polv[i][j],polv[i][(j+1)%p]);
        }
        ans += abs(tmpAns);
    }
    ans /= 2;
    printf("%lld\n",ans);
    return 0;
}
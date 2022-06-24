#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

ll a[9] = {-1,0,2,4,6,8,10,12,14};
ll dis[9];

ll get(int x,int y)
{
    ll t;
    cout<<x<<" "<<y<<endl;
    cout.flush();
    cin>>t;
    return t;
}

void cal(int x1, int x2){
    ll bottom = (x2 - x1)*2, t, h;
    if (dis[x1] > dis[x2]){
        t = (dis[x1]-dis[x2]-bottom*bottom) / (2*bottom);
        h = (dis[x2] - t);
        get(x2+sqrt(t), h);
    }
    else if (dis[x1] < dis[x2]){
        t = (dis[x2]-dis[x1]-bottom*bottom) / (2*bottom);
        h = (dis[x1] - t);
        get(x1-sqrt(t), sqrt(h));
    }
    else{
        t = (x1+x2) / 2;
        h = dis[x1] - (x2-x1)*(x2-x1);
        get(x1+t, sqrt(h));
    }
    
}

void f(){
    for (int i=1;i<=8;++i){
        ll d = get(a[i], 0);
        if (d == 0){
            return;
        }
        dis[i] = d;
    }
    for (int i=1;i<=8;++i){
        for (int j=i+1;j<=8;++j){
            cal(i, j);
        }
    }
}

void solve(){
    for (int i=1;i<=n;++i){
        f();
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    solve();

    return 0;
}
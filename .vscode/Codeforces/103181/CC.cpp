#include<bits/stdc++.h>
#define pb push_back
#define mpi make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const ll mod=1000000007;
const int INF=0x3f3f3f3f;
typedef pair<int,int> P;
inline ll lowbit(ll x){return x&(-x);}
int n,m,k;
int fa[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct dots{
	double x,y;
}a[maxn];
bool check(double r){
	for(int i=1;i<=k+4;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		if(m-a[i].y<r){//如果该点与上边界的距离小于半径，则将该点与上边界连通 
			int u=find(i);
			int v=find(k+1);
			if(u!=v) fa[u]=v;
		}
		if(a[i].y<r){//如果该点与下边界的距离小于半径，则将该点与下边界连通
			int u=find(i);
			int v=find(k+2);
			if(u!=v) fa[u]=v;
		}
		if(a[i].x<r){//如果该点与左边界的距离小于半径，则将该点与左边界连通
			int u=find(i);
			int v=find(k+3);
			if(u!=v) fa[u]=v;
		}
		if(a[i].x>n-r){//如果该点与右边界的距离小于半径，则将该点与右边界连通
			int u=find(i);
			int v=find(k+4);
			if(u!=v) fa[u]=v;
		}
		for(int j=1;j<i;j++){
			double dis=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
			if(dis<4*r*r){//如果两点间的距离小于直径，则将这两个点连通 
				int u=find(i);
				int v=find(j);
				if(u!=v) fa[u]=v;
			}
		} 
	}
	cout<<"mid: "<<r<<endl;
	cout<<find(k+1)<<" "<<find(k+2)<<" "<<find(k+3)<<" "<<find(k+4)<<endl;
	if(find(k+1)==find(k+2)||find(k+3)==find(k+4)||find(k+1)==find(k+4)||find(k+3)==find(k+2)) return 0;
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	double l=0,r=max(n,m);
	while(r-l>=1e-6){//二分法搜答案 
		double mid=(l+r)/2.0;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.6lf\n",l);
    return 0;
}

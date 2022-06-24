#include<bits/stdc++.h>
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/(__gcd(a,b))
#define rep(i,s,e) for(int i=s;i<e;i++)
#define mem(a,n) memset(a, n ,sizeof a)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
priority_queue <int,vector<int>,greater<int> > Q;
const int INF= 0x3f3f3f3f;
const int maxn= 1e5+5;
int a[maxn],a1[maxn],a2[maxn];
int h[maxn],n,t1,t2;
vector<pair<int,int> > ans;//存弹射点 
int main()
{
	IOS;
	cin>>n;
	rep(i,1,n+1)	cin>>a[i];
	int nh=n+1;//从后开始,逆序处理 
	for(int i=n;i>=1;i--) 
	{
		if(a[i]==1)
		{
			h[i]=--nh;
			a1[++t1]=i;//存入a1并计数 
			ans.push_back({i,h[i]});
		}
		else if(a[i]==2)
		{
			if(!t1)
			{
				cout<<-1;
				return 0;
			}
			h[i]=h[a1[t1--]];//与弹射1的点同高度,更新可用点数量
			a2[++t2]=i;//存入a2并计数 
			ans.push_back({i,h[i]});
		}
		else if(a[i]==3)
		{
			if(!t1 && !t2)
			{
				cout<<-1;
				return 0;
			}
			h[i]=--nh;
			ans.push_back({i,h[i]});//当前列放置对应高度弹射点 
			int j;
			if(t2)	j=a2[t2--];//优先用a2 
			else	j=a1[t1--]; 
			ans.push_back({j,h[i]});//第二次弹射的点,同高度 
			a2[++t2]=i;
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].second<<' '<<ans[i].first<<endl;
	return 0;
}

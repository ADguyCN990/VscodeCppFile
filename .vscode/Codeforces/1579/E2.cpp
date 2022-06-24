#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll t,n;
ll a[MAXN];//存放离散化后的数据
ll tree[MAXN];// 树状数组
ll lowbit (ll x) {return x&(-x);}
ll sum(ll x)//小于等于x的元素个数
{
	ll temp=0;
	for(ll i=x;i>0;i-=lowbit(i))
	{
		temp+=tree[i];
	}
	return temp;
}
ll add(ll x,ll c)//往树状数组中添加数据,c为权值本题单纯求逆序对设为1
{
	for(ll i=x;i<=n;i+=lowbit(i)) tree[i]+=c;
}
void clear()//初始化树状数组
{
	for(ll i=1;i<=n;i++) tree[i]=0;
}
void pre()//对输入数据进行离散化处理
{
	cin>>n;
	clear();
	ll b[MAXN];
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	ll m=unique(b+1,b+1+n)-(b+1);
	for(ll i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
		//cout<<"__"<<a[i]<<" ";
	}
	//cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		pre();
		ll ans=0;//逆序对个数
		for(ll i=1;i<=n;i++)
		{
			ll x=sum(a[i]-1);//插入前面产生的代价
			ll y=sum(n)-sum(a[i]);//插入后面产生的代价
			//cout<<"______"<<x<<" "<<y<<endl;
			add(a[i],1);
			ans+=(ll)min(x,y);
		}
		cout<<ans<<endl;
	}

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[100005], t[100005], s;
vector<int> v[100005];
int flag = 0;
int dfs(int now, int fa){
	t[now] = a[now];
	for(int it : v[now])
	{
		if(it == fa) continue;
		t[now] ^= dfs(it, now);
	}
	return t[now];
};
//dfs用来更新异或和数组

void find(int now, int fa){
	for(int it : v[now])
	{
		if(it == fa) continue;
		find(it, now);
		if(t[it] == s && flag == 0)
		{
			flag = 1;
			v[now].erase(find(v[now].begin(), v[now].end(), it));
			return;
		}
	}
}
//find用来找一棵子树，其异或和为s。
//采用后序遍历，即保证找到的是最深的节点。
//并且切断其与父节点的联系，划分为一个区域。
//如果成功， 置flag = 1。

void solve()
{
	int n,k;cin>>n>>k;
	s = 0;
	for(int i=1;i<=n;i++) cin>>a[i], s ^= a[i];
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1, x, y;i<n;i++) 
	{
		cin>>x>>y;
		v[x].push_back(y); 
		v[y].push_back(x);
	}
	if(s == 0)
	{
		cout<<"YES\n";
		return;
	}
	if(k == 2)
	{
		cout<<"NO\n";
		return;
	}
	dfs(1, 1);
	find(1, 1);
	if(flag == 1)
	{
		flag = 0;
		dfs(1, 1);
		find(1, 1);
		//两次寻找符合条件的子树，flag = 1表示找到。
		if(flag == 1)
		{
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
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
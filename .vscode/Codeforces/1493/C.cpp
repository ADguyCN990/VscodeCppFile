#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
string s;
int cnt[30];//每个字符出现的次数
//构造一个长度为n的字符串，每个字符出现的次数都要能够被k整除，且满足这个构造出的字符串是大于s的字典序最小的字符串

ll cal(int now)//返回这个字母至少还要出现几次的值
{
    //k-k%now
    return (k-now%k)%k;//再模k是因为每个字符出现的次数不能小于k，必须大于等于k，那些次数不够的还得再加（我也不知道为啥）
}

void solve()
{
    cin>>n>>k>>s;
    memset(cnt,0,sizeof(cnt));
    if(n%k!=0)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<n;i++) cnt[s[i]-'a']++;
    ll tot=0;//总共需要额外添加几个字符
    for(int i=0;i<26;i++) 
    {
        tot+=cal(cnt[i]);
    }
    if(tot==0)//本身就是合法序列，直接输出原串
    {
        cout<<s<<endl;
        return;
    }

    for(int i=n-1;i>=0;i--)//如果替换掉的是第i位字符
    {
        tot=tot-cal(cnt[s[i]-'a'])+cal(--cnt[s[i]-'a']);//删除第i位字符，自然地要更新tot的值
        for(int j=s[i]-'a'+1;j<26;j++)//枚举替换后的字符
        {
            int copy_tot=tot;//暂时记录下当前的tot，如果之后非法直接CV覆盖
            tot=tot-cal(cnt[j])+cal(++cnt[j]);
            if(i+1+tot<=n)//合法
            {
                for(int pos=0;pos<i;pos++) cout<<s[pos];
                cout<<(char)('a'+j);
                //剩下n-i-1个字符，一共要替换tot个字符，可以输出n-i-1-tot个a
                for(int pos=1;pos<=n-i-1-tot;pos++) cout<<'a';
                //现在只剩下tot个字符需要替换了，abcd...xyz遍历过去，那个字符需要被遍历一次性输出完就行
                for(int pos=0;pos<26;pos++)
                {
                    int now=cal(cnt[pos]);
                    while(now)
                    {
                        cout<<(char)('a'+pos);
                        now--;
                    }
                }
                cout<<endl;
                return;
            }
            cnt[j]--;tot=copy_tot;//换掉这个字符不行，换回之前的备份数据
        }
    }
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
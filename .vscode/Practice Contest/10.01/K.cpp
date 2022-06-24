#include<bits/stdc++.h>
using namespace std;
//求出每种可能出现的字符串类型，把他们的sg值异或一下得到答案。大字符串可以分解为若干小字符串，这就是组合游戏的并。
//sg值定义：x节点的SG值是去除x节点的后继值的SG值后最小的非负整数。由于这题没有规则，任意子串都是大串的后继，就把所有子串的sg值都求出来
//通过记忆化搜索的方式求子串的sg值，避免重复计算
#define ll long long
#define MAXN 45
int t,n;
string s;
map<vector<int>,ll> remember;//记忆化搜索用，记录已经运算过的sg值
ll sg(vector<int> now)
{
    if(remember.count(now))//他妈的sg值可以为0，给老子卡了半天
    {
        return remember[now];
    }
    //取走一个字母的情况，并求出这些新字符串的sg值
    set <ll> check;//记录now的后继节点（子串）的sg值，sg值貌似挺大的，数组开不了
    for(int i=0;i<now.size();i++)
    {
        if(now[i]==0) continue;//这个字符未出现在字符串中
        now[i]--;
        vector <int> temp;
        for(int j=0;j<now.size();j++) temp.emplace_back(now[j]);//移走了一个字符，生成了一种子串    
        sort(temp.begin(),temp.end());//见64行注释
        check.insert(sg(temp));//求出这个子串的sg值
        //在移走一个字符的情况下，移走另一个不同的字符，并且记录下这个子串的sg值
        for(int j=i+1;j<now.size();j++)
        {
            if(now[j]==0) continue;
            now[j]--;
            vector <int> tmp;
            for(int k=0;k<now.size();k++) tmp.emplace_back(now[k]);
            sort(tmp.begin(),tmp.end());//见64行注释
            check.insert(sg(tmp));
            now[j]++;//删完了还原
        }
        now[i]++;//删完了还原
    }
    //x节点的SG值是去除x节点的后继值的SG值后最小的非负整数 上面已经求完了x所有后继值的SG值 现在只需找出这个非负整数并输出即可
    for(ll i=0;;i++)
    {
        if(!check.count(i)) return remember[now]=i;
    }
   
}

int main()
{   
    std::iostream::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        int xor_sg=0;//sg值的异或和
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            vector <int> cnt(26,0);//记录字母出现的个数
            for(int i=0;i<s.length();i++)
            {
                cnt[s[i]-'a']++;
            }
            sort(cnt.begin(),cnt.end());//点睛之笔，本题只和字符出现的个数有关，这样可以将多种情况缩为一点，如aabb和ccdd
            xor_sg=xor_sg^(sg(cnt));
        }
        if(xor_sg==0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }

    return 0;
}
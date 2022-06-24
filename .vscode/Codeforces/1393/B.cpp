#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int cnt[MAXN];
int n, q;
struct node
{
    int id;
    int num;
    bool operator< (const node& a) const{
        if (num == a.num)
            return id < a.id;
        return num > a.num;
    }
};
set <node> s;
char opt;

bool check() //8 6+2 4+4 4+2+2
{
    //printf("size: %d", s.size());
    int len = s.size();

    if (len < 1) return false;
    auto one = s.begin();
    node first = *one;
    if (first.num >= 8)
        return true;

    if (len < 2) return false;
    one ++;
    node second = *one;
    //printf("id: %d num: %d id: %d num: %d\n", first.id, first.num, second.id, second.num);
    if (first.num >= 6 && second.num >= 2 || first.num >= 4 && second.num >= 4)
        return true;
    
    if (len < 3) return false;
    one ++;
    node third = *one;
    if (first.num >= 4 && second.num >= 2 && third.num >= 2)
        return true;

    return false;

}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        int tmp = read();
        if (s.count({tmp, cnt[tmp]}));
            s.erase({tmp, cnt[tmp]});
        cnt[tmp] ++;
        s.insert({tmp, cnt[tmp]});
    }  
    q = read();
    while (q --)
    {
        scanf("%c", &opt);
        if (opt == '+')
        {
            int tmp = read();
            if (s.count({tmp, cnt[tmp]}))
                s.erase({tmp, cnt[tmp]});
            cnt[tmp] ++;
            s.insert({tmp, cnt[tmp]});

            bool flag = check();
            if (flag) puts("YES");
            else puts("NO");
        }
        else
        {
            int tmp = read();
            s.erase({tmp, cnt[tmp]});
            cnt[tmp] --;
            s.insert({tmp, cnt[tmp]});

            bool flag = check();
            if (flag) puts("YES");
            else puts("NO");
        }
    }
}

int main()
{
    solve();
    return 0;
}
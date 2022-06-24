#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
int n, num, x;
char ch;
stack<int> v;
int ans[MAXN];
void solve()
{
    cin >> n;
    num = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> ch;
        if (ch == '+')
        {
            v.push(num++);
            //如果是加的话，就代表向栈中添加元素，num表示这是第num个进栈的元素
        }
        else
        {
            cin >> x;
            if (v.empty())
            {
                //如果顾客要买手里剑时，柜台却空了，那显然是不合理的
                cout << "NO"<<endl;
                return;
            }
            else if (x < ans[v.top() + 1])//如果之前x没出栈
            {
                //ans[n]表示第n个放进栈的元素的价格
                //v.top()表示当前栈顶元素的序号,v.top()+1表示当前栈顶元素的下一个元素的序号
                
                cout << "NO"<<endl;
                return;
            }
            ans[v.top()] = x; //第v.top()个进栈的元素的价格确定了
            v.pop();          //他被买走了，所以出栈
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i]<<" ";
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}

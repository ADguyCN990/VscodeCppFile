#include <bits/stdc++.h>
#define MAXN 50
using namespace std;
int n, m;
struct Node
{
    int u;
    int val;
    Node(int u = 0, int val = 0) : u(u), val(val) {}
};
vector<int> vec[MAXN];
int ru[MAXN];
int sum;
int ans;
int k;
set<int> s1;
int have;
int ru2[MAXN];
void init()
{
    for(int i=0;i<MAXN;i++)
    {
        vec[i].clear();
        ru[i]=0;
        ru2[i]=0;
    }
    s1.clear();
    have=0;ans=0;sum=0;
}

void make()
{
    queue<int> q;
    int ru1[MAXN];
    memset(ru1, 0, sizeof(ru1));
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            ru1[vec[i][j]]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (ru1[i] == 0 && s1.count(i))
        {
            q.push(i);
            cout << char(i + 'A');
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < vec[u].size(); i++)
        {
            int v = vec[u][i];
            ru1[v]--;
            if (ru1[v] == 0)
            {
                q.push(v);
                cout << char(v + 'A');
            }
        }
    }
}

bool topo()
{
    queue<Node> q;
    for (int i = 0; i < 26; i++)
    {
        if (ru[i] == 0 && s1.count(i))
        {
            q.push(Node(i, 1));
            sum++;
        }
    }
    while (!q.empty())
    {
        int u = q.front().u;
        int val = q.front().val;
        q.pop();
        for (int i = 0; i < vec[u].size(); i++)
        {
            int v = vec[u][i];
            ru[v]--;
            if (ru[v] == 0)
            {
                sum++;
                q.push(Node(v, val + 1));
                ans = max(ans, val + 1);
            }
        }
    }
    if (ans == n)
    {
        printf("Sorted sequence determined after %d relations: ", k);
        make();
        cout << "."<<endl;
        return true;
    }
    if (sum != have)
    {
        printf("Inconsistency found after %d relations.\n", k);
        return true;
    }
    return false;
}

int main()
{
    while (cin >> n >> m)
    {
        init();
        bool flag=false;
        for (int i = 1; i <= m; i++)
        {
            string s;
            cin >> s;
            k = i;
            vec[s[0] - 'A'].push_back(s[2] - 'A');
            s1.insert(s[0] - 'A');
            s1.insert(s[2] - 'A');
            have = s1.size();
            ru2[s[2] - 'A']++;
            sum = 0;
            ans = 0;
            memcpy(ru, ru2, sizeof(ru2));
            bool f=topo();
            if(f==true) flag=true;
            if(flag==true)
                break;
        }

        if(flag==false)
            printf("Sorted sequence cannot be determined.\n");
    }

    return 0;
}

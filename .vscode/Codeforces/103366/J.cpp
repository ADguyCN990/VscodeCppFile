#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;
int seq[maxn];
struct Node
{
    int id, time;
    bool operator<(const Node &n) const
    {
        return time < n.time;
    }
};
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &seq[i]);
    int l = 1, r = N;
    int ans = N + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        map<int, int> bmap;
        priority_queue<Node> pq;
        int hitCnt = 0;
        for (int i = 1; i <= N; i++)
        {
            while (!pq.empty() && pq.top().time != bmap[pq.top().id])
            {
                pq.pop();
            }
            if (bmap.find(seq[i]) == bmap.end())
            {
                if (pq.size() < mid)
                {
                    bmap.insert(make_pair(seq[i], i));
                    pq.push(Node{seq[i], i});
                }
                else
                {
                    bmap.erase(pq.top().id);
                    pq.pop();
                    bmap.insert(make_pair(seq[i], i));
                    pq.push(Node{seq[i], i});
                }
            }
            else
            {
                hitCnt++;
                bmap[seq[i]] = i;
                pq.push(Node{seq[i], i});
            }
        }
        if (hitCnt >= K)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (ans < N + 1)
        printf("%d\n", ans);
    else
        printf("cbddl\n");
    return 0;
}
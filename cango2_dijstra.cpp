#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;

        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    int n, e;

    cin >> n >> e;

    for (int i = 0; i < N; i++)
    {
        dis[i] = INT_MAX;
    }

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    int src;
    cin >> src;

    dijkstra(src, n);

    int T;
    cin >> T;

    while (T--)
    {
        int D, DW;
        cin >> D >> DW;

        if (dis[D] <= DW)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1005;
const long long INF = 1e18;
long long dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> Edgelist;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        Edgelist.push_back(Edge(u, v, c));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }

    int src;
    cin >> src;
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : Edgelist)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge ed : Edgelist)
    {

        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INF && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int t;
        cin >> t;
        while (t--)
        {
            int des;
            cin >> des;
            if (dis[des] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[des] << endl;
            }
        }
    }

    return 0;
}
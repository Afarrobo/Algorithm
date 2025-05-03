#include <bits/stdc++.h>
using namespace std;

bool vis[100][100];
int dis[100][100];

vector<pair<int, int>> d = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int bfs(int ki, int kj, int qi, int qj)
{
    queue<pair<int, int>> q;
    q.push({ki, kj});
    vis[ki][kj] = true;
    dis[ki][kj] = 0;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        int si = current.first;
        int sj = current.second;
        q.pop();

        if (si == qi && sj == qj)
        {
            return dis[si][sj];
        }

        for (int i = 0; i < 8; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[si][sj] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        cin >> n >> m;

        int ki, kj;
        cin >> ki >> kj;

        int qi, qj;
        cin >> qi >> qj;

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        int result = bfs(ki, kj, qi, qj);

        cout << result << endl;
    }

    return 0;
}

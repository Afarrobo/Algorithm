#include <bits/stdc++.h>
using namespace std;

bool vis[1000][1000];
vector<pair<int, int>> d = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[1000][1000];

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '-' || vis[i][j])
        return false;
    return true;
}

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();

        if (a == di && b == dj)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }

    return false;
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    int di, dj;
    cin >> di >> dj;

    memset(vis, false, sizeof(vis));

    if (a[si][sj] == '-' || a[di][dj] == '-')
    {
        cout << "NO" << endl;
    }
    else
    {

        if (bfs(si, sj, di, dj))
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

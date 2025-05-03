#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()

{

    ll n, e;

    cin >> n >> e;

    ll adj[n][n];

    const long long INF = 1e18;

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j < n; j++)

        {

            adj[i][j] = INF;

            if (i == j)

                adj[i][j] = 0;
        }
    }

    while (e--)

    {

        ll a, b, c;

        cin >> a >> b >> c;

        adj[a][b] = c;
    }

    for (int k = 0; k < n; k++)

    {

        for (int i = 0; i < n; i++)

        {

            for (int j = 0; j < n; j++)

            {

                if (adj[i][k] + adj[k][j] < adj[i][j])

                {

                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        if (adj[x][y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {

            cout << adj[x][y] << endl;
        }
    }
    return 0;
}
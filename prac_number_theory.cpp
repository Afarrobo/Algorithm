#include <bits/stdc++.h>
using namespace std;

#define optimize()               \
  ios_base ::sync_with_stdio(0); \
  cin.tie(0);                    \
  cout.tie(0);
// we have to declare it globally ... for our large input

vector<int> divisors[123];

int main()
{
  optimize();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int sq = sqrt(i);
    for (int j = 1; j <= sq; j++)
    {
      if (i % j == 0)
      {
        // here, we are keeping j in the ith index
        divisors[i].push_back(j);
      }
      if (i / j != j)

      {
        divisors[i].push_back(i / j);
      }
    }
    sort(divisors[i].begin(), divisors[i].end());
  }

  // printing everything here
  for (int i = 1; i <= n; i++)
  {
    cout << i << " :";
    cout << endl;

    for (auto u : divisors[i])
      cout << u << "  ";
    cout << endl;
  }
}
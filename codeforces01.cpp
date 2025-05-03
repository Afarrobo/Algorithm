#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int score = 0;

        int min_value = a[0];
        int max_value = a[0];

        for (int i = 0; i < n; ++i)
        {
            min_value = a[i];
            max_value = a[n - 1];
            score += (max_value - min_value);
        }
        cout << score << endl;
    }

    return 0;
}

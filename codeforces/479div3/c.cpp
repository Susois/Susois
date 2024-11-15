#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> se(n + 1);
    se[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> se[i];
    }
    sort(se.begin(), se.end());
    if (k == 0)
    {
        if (se[1] != 1 )
        {
            cout << se[1] - 1 << '\n';
            return;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    if (se[k] == se[k + 1])
    {
        cout << "-1\n";
        return;
    }
    else
    {
        cout << se[k] << '\n';
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
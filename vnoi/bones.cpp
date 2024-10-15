#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    map<int, int> freq;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            for (int k = 1; k <= z; ++k) {
                int sum = i + j + k;
                freq[sum]++;
            }
        }
    }

    int max_freq = 0;
    int result = 0;
    for (const auto& pair : freq) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
            result = pair.first;
        } else if (pair.second == max_freq) {
            result = min(result, pair.first);
        }
    }

    cout << result << endl;
    return 0;
}
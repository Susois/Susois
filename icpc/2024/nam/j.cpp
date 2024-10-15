#include <bits/stdc++.h>
using namespace std;

int countBeautifulSubstrings(const string &s) {
    int n = s.length();
    int beautifulCount = 0;

    for (int start = 0; start < n; ++start) {
        unordered_map<char, int> freq;
        for (int end = start; end < n; ++end) {
            freq[s[end]]++;
            int count = freq[s[start]];
            bool beautiful = true;

            for (const auto& p : freq) {
                if (p.second != count) {
                    beautiful = false;
                    break;
                }
            }

            if (beautiful) beautifulCount++;
        }
    }

    return beautifulCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    cout << countBeautifulSubstrings(s) << "\n";
    return 0;
}

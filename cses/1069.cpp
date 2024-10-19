#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string dna_sequence;
    cin >> dna_sequence;

    int max_length = 1;
    int current_length = 1;

    for (int i = 1; i < dna_sequence.size(); ++i) {
        if (dna_sequence[i] == dna_sequence[i - 1]) {
            current_length++;
        } else {
            max_length = max(max_length, current_length);
            current_length = 1;
        }
    }
    max_length = max(max_length, current_length); // Update for the last sequence

    cout << max_length << endl;

    return 0;
}

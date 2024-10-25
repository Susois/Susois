#include <iostream>
#include <string>
using namespace std;

int main() {
    string situation;
    cin >> situation; // Input the string of players' positions

    // Check for 7 consecutive '0's or '1's in the string
    if (situation.find("0000000") != string::npos || situation.find("1111111") != string::npos) {
        cout << "YES" << endl; // Dangerous situation
    } else {
        cout << "NO" << endl;  // Not dangerous
    }

    return 0;
}

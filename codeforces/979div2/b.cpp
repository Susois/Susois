#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;  
        for (int i = 0; i < n; ++i) {
            cout << (i % 2);  
        }
        cout << endl;
    }
    return 0;
}

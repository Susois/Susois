#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Số lượng test cases
    while (t--) {
        int n;
        cin >> n;  // Độ dài chuỗi

        // Xây dựng chuỗi xen kẽ giữa '0' và '1'
        for (int i = 0; i < n; ++i) {
            cout << (i % 2);  // In ra '0' cho vị trí chẵn, '1' cho vị trí lẻ
        }
        cout << endl;
    }
    return 0;
}

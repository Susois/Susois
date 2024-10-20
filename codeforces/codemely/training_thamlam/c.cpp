#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n; 
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_buy = a[n - 1]; 
    long long total_chocolates = max_buy;  

    for (int i = n - 2; i >= 0; --i) {
        max_buy = min(max_buy - 1, a[i]);  
        if (max_buy < 0) max_buy = 0; 
        total_chocolates += max_buy; 
    }

    cout << total_chocolates << endl; 

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     long long res = 0;
//     vector<int> A(n);
//     unordered_map<int, int> freq;

//     for (int i = 0; i < n; ++i) {
//         cin >> A[i];
//         A[i] ^= i; // A_i = A_i ⊕ i
//         if(freq[A[i]] >= 1)res += freq[A[i]];
//         freq[A[i]]++;
//     }

//     // long long result = 0;
//     // for (const auto &entry : freq) {
//     //     long long count = entry.second;
//     //     result += (count * (count - 1)) / 2; // C(n, 2) = n * (n - 1) / 2
//     // }

//     cout << res << "\n";
//     return 0;

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> se;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;cin>>n;
    long long res = 0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>a[i];
        a[i] = a[i]^i;
    }
    for(int i=1;i<=n;i++)
    {
        if(binary_search(se.begin(),se.end(),a[i]))
        {res += se[a[i]];
        se[a[i]]++;}
        else se.insert({se[a[i]],1});
    }    
    cout<<res;
    return 0;
}
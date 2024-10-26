// #include<bits/stdc++.h>
// #define ll long long
// #define lli int64_t
// #define fi first 
// #define se second
// #define sz(x) (int)x.size()
// #define all(x) x.begin(), x.end()
// #define fint(i,x) for(int i=1;i<=x;i++)
// #define fstr(i,s) for(int i=0;i<sz(s);i++)
// #define mp make_pair
// #define pb push_back
// #define vec vector<int> 
// #define pii pair<int,int>
// #define re return
// #define br break
// #define fast                        \
// ios_base::sync_with_stdio(false);   \
// cin.tie(0);cout.tie(0);             \
// const int N = 1e5 + 5;
// const int INF = 1e9 + 7;
// const double EPS = 1e-9;
// const double PI = acos(-1.0);

// using namespace std;
// bool check = true;
// void solve(){
//     string s;cin>>s;
//     fstr(i,s){
//         if(s[i] != '4' &&  s[i] != '7' ){
//             check = false;
//             re;
//         }
//     }
// }
// int main(){
//     fast

//     // int t;cin>>t;
//     // while(t--){
//     // solve();
//     // cout<<'\n';
//     // }
//     solve();
//     if(check) cout<<"YES";
//     else cout<<"NO";
//     return 0;
// }
#include <iostream>
#include <string>

using namespace std;

// Function to check if a given number (in string format) consists only of lucky digits (4 and 7)
bool isLuckyNumber(int num) {
    string numStr = to_string(num);
    for (char digit : numStr) {
        if (digit != '4' && digit != '7') {
            return false;
        }
    }
    return true;
}

// Function to check if the number is nearly lucky
bool isNearlyLucky(long long n) {
    string nStr = to_string(n);
    int luckyDigitCount = 0;

    // Count lucky digits (4 or 7) in n
    for (char digit : nStr) {
        if (digit == '4' || digit == '7') {
            luckyDigitCount++;
        }
    }

    // Check if the count of lucky digits itself is a lucky number
    return isLuckyNumber(luckyDigitCount);
}

int main() {
    long long n;
    cin >> n;

    if (isNearlyLucky(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define vec vector<int> 
#define pii pair<int,int>
#define re return
#define br break
#define fast                        \
ios_base::sync_with_stdio(false);   \
cin.tie(0);cout.tie(0);             
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

void solve() {
    string t;
    cin >> t;

    string s = "";
    int n = t.size();
    if(n==1){
        cout<<t;
        re;
    }
    int left = (n - 1) / 2;  // Vị trí giữa xâu, bắt đầu từ giữa ra
    int right = left + 1;

    for (int i = 0; i < n/2; i++) {
            s = s + t[left] ;  
            left--;
            s = s + t[right]; 
            right++;
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

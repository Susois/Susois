#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s=" ";
int se[N]; // Re-initialize the `se` array to zero

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string ss;
    cin >> ss;
    s+=ss;
    int t;
    cin >> t;
    while (t--) 
    {
        memset(se,0,sizeof(se));
        int a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << "0\n";
        continue;
    }

    long long sum = 0; // Corrected the sum variable

    // Loop to handle parentheses counting
    for (int i = a; i <= b; i++) {
        if (s[i] == '(') {
            int j = i + 1, cnt = 1;
            while (j <= b && s[j] == '(') {
                j++;
                cnt++;
            }
            while (j <= b && s[j] == ')') {
                j++;
                cnt++;
            }
            i = j - 1;
            se[i] += cnt;
        }
    }
    for(int i=1;i<= (int)ss.length();i++)sum+=se[i];
    cout << sum << endl;
    }
    return 0;
}

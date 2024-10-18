// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int MOD = 1e9 + 7;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);

//     int n;cin>>n;
//     char val[n+1][n+1];
//     int dp[n+1][n+1];
//     memset(dp,0,sizeof(dp));
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin>>val[i][j];
//         }
//     }

//     dp[1][1] = 0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(val[i][j]=='*')continue;
//             else 
//                 {
//                     if(val[i-1][j]=='.' && val[i][j-1]=='.' )dp[i][j] = max(dp[i-1][j]+2,dp[i][j-1] +2);
//                     else if(val[i-1][j]=='.') dp[i][j] = (dp[i-1][j]+1)%MOD;
//                     else if(val[i][j-1]=='.') dp[i][j] = (dp[i][j-1]+1)%MOD;
//                 }
//         }
//     }
//     cout<<dp[n][n];
    
//     return 0;
// }
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int countPaths(vector<vector<char>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    if (grid[0][0] == '*') return 0;
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') continue;
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[n - 1][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << countPaths(grid) << endl;
    return 0;
}

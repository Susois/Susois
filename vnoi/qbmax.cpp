// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
    
//     int n,m,res =INT_MIN;cin>>n>>m;
//     int se[n+2][m+2];
//     int dp[n+2][m+2];
//     memset(dp,0,sizeof(dp));
//     memset(se,0,sizeof(se));
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//             cin>>se[i][j];
//     }

//     // for(int i=1;i<=m;i++)
//     // {
//     //     for(int j=1;j<=n;j++)
//     //     {
//     //         // dp[i][j] = max( dp[i-1][j-1]+se[i][j], max(dp[i][j-1]+se[i][j] , dp[i+1][j]+se[i][j]));
//     //         dp[i][j] = max( dp[j-1][i-1] + se[j][i] , max(dp[j-1][i] + se[j][i], dp[j-1][i+1] + se[j][i]));
//     //     }
//     // }

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++){
//             dp[i][j] = max( dp[i][j-1] +se[i][j], max( dp[i-1][j-1] + se[i][j] , dp[i+1][j-1] +se[i][j]));
//             // dp[i][j] = max ( dp[i][j] + se[i][j+1] , max( dp[i][j] + se[i-1][j+1], dp[i][j] + se[i+1][j+1]));
//         }
//     }

//     cout<<'\n';
//     // for(int i=1;i<=n;i++)
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<'\n';
//     }
//     // res = min(res ,dp[i][m]);
//     cout<<res;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> se(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, INT_MIN));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> se[i][j];
        }
    }

    // Khởi tạo cột đầu tiên của dp với giá trị của se
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = se[i][1];
    }

    // Điền giá trị cho dp
    for (int j = 2; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + se[i][j]); // Ô bên trái
            if (i > 1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + se[i][j]); // Ô chéo trên trái
            }
            if (i < n) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + se[i][j]); // Ô chéo dưới trái
            }
        }
    }

    // Tìm giá trị lớn nhất ở cột cuối cùng
    int res = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        res = max(res, dp[i][m]);
    }

    cout << res << '\n';

    return 0;
}

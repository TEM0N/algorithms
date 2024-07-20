#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int mas[n + 1][3];
    int dp[n + 1][n + 1];
    for (int i = 1; i <= n; ++ i)
        {
            cin >> mas[i][1] >> mas[i][2];
        }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++j)
            dp[i][j] = 1000000000;
        dp[i][i] = 0;
    }
    for (int i = 2; i <= n; ++ i)
        for (int j = 1; j <= n - i + 1; ++ j) {
            int r = j + i - 1;
        for (int k = j; k < r; ++ k)
            {
                dp[j][r] = min(dp[j][r], dp[j][k] + dp[k + 1][r] + (mas[j][1] * mas[k][2] * mas[r][2]));
            }
        }
    cout << dp[1][n];
}

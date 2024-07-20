#include<bits/stdtr1c++.h>
using namespace std;
int a[1002][1002];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int d, l, r;
    cin >> d >> l >> r;
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size() + 2;
    int m = s2.size() + 2;
    for(int i = 0;i < n; ++ i)
    {
        a[i][0] = i * d;
    }
    for(int i = 0;i < m; ++ i)
    {
        a[0][i] = i * l;
    }
    for(int i = 1; i < n; ++ i)
    {
        for(int j = 1; j < m; ++ j)
        {
            int k = 0;
            if(s1[i - 1] != s2[j - 1]) k = 1;
            a[i][j] = min(min(a[i - 1][j] + d, a[i][j - 1] + l),a[i - 1][j - 1] + k * r);
        }
    }
    cout << a[n - 1][m - 1];
    return 0;
}

#include <bits/stdtr1c++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long m, c, n;
    cin >> m >> c >> n;
    long long a[m];
    for(int i = 0;i < m; ++ i)
    {
        a[i] = -1;
    }
    for(int i = 0; i < n; ++ i)
    {
        long long x;
        cin >> x;
        long long j = 0;
        while(j < m)
        {
            long long index = (x % m + c * j) % m;
        if(a[index] == -1 or a[index] == x)
            {
                a[index] = x;
                break;
            }
        j++;
        }
    }
    for(int i = 0;i < m; ++ i)
    {
        cout << a[i] << " ";
    }
    return 0;
}

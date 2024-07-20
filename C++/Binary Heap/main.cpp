#include <bits/stdtr1c++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n; ++ i)
     {
        cin >> a[i];
     }
    for(int i = 0; i < n / 2 + 1; ++ i)
    {
        if(2 * (i + 1) < n){
            if(a[i] > a[2 * (i + 1)]) {cout << "No";return 0;}
        }
        if(2 * (i + 1) - 1 < n){
            if(a[i] > a[2 * i + 1]){cout << "No";return 0;}
        }
    }
    cout << "Yes";
    return 0;
}

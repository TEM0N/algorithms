#include <bits/stdc++.h>
using namespace std;
int a[3000002];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int index = -1;
    cin >> n;
    string s,s1;
    cin >> s >> s1;
    s1 = s1 + "," + s + s;
    int k;
    for (int i = 1; i < 3 * n; i++) {
        k = a[i - 1];
        while (k > 0) {
            if (s1[i] == s1[k]) {
                a[i] = k + 1;
                break;
            }
            else {
                k = a[k - 1];
            }
        }
        if (k == 0 and s1[i] == s1[0]) {
                a[i] = 1;
            }
            else if (k == 0 and s1[i] != s1[0]){
                a[i] = 0;

        }
            if (a[i] == n) {
                index = i - 2 * n;
                break;
            }
    }
  cout << index;
    return 0;
}

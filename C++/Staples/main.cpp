#include <bits/stdc++.h>

using namespace std;

int main()
{
    string ss;
    cin >> ss;
    if (ss.size() == 0)
    {
        cout << 0;
        return 0;
    }
    int m = ss.size();
    vector <vector <int> > a(m + 1, vector <int> (m, 101));
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j + i - 1 < m; j ++){
            int r = j + i - 1;
            if (i == 1){
                a[j][r] = 1;
            }
            else if (i == 2){
                if ((ss[j] == '(' and ss[r] == ')') or (ss[j] == '[' and ss[r] == ']') or (ss[j] == '{' and ss[r] == '}')){
                    a[j][r] = 0;
                }
                else{a[j][r] = 2;}
            }
            else{
                if ((ss[j] == '(' and ss[r] == ')') or (ss[j] == '[' and ss[r] == ']') or (ss[j] == '{' and ss[r] == '}')){
                    a[j][r] = min(a[j][r], a[j + 1][r - 1]);
                }
                for (int r1 = j; r1 < r;r1 ++){
                    int l2 = r1 + 1;
                    a[j][r] = min(a[j][r], a[j][r1] + a[l2][r]);
                }
            }
        }
    }
    cout << a[0][m - 1];
    return 0;
}

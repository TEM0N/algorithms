#include <bits/stdc++.h>
using namespace std;
int mas[7002][7002];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    string s1;
    s1 = s;
    reverse(s1.begin(), s1.end());
    int n = s.size();
 for(int i = 0; i < n; ++ i)
 {
     for(int j = 0;j < n; ++ j)
     {
         if(s[i] == s1[j]) mas[i + 1][j + 1] = mas[i][j]+1;
         else mas[i + 1][j + 1] = max(mas[i][j + 1],mas[i + 1][j]);
     }
 }
 cout << mas[n][n] << endl;
 string s2;
 int i = n,j = n;
 while(i * j != 0)
 {
     if(s[i - 1] == s1[j - 1]) {s2 = s2 + s[i-1]; i --; j --;}
     else{
        if(mas[i][j] == mas[i-1][j]){ i --;}
        else j --;
     }
 }
 cout << s2;
return 0;
}

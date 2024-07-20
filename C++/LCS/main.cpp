#include <bits/stdc++.h>
using namespace std;

int a[1002];
int b[1002];
int mas[1002][1002];
int a1[1002],b1[1002];

int main()
{
 int n;
 cin >> n;
 for(int i = 1;i <= n; ++ i)
 {
     cin >> a[i];
 }
 for(int i = 1; i <= n; ++ i)
 {
     cin >> b[i];
 }
 for(int i = 0; i <= n; ++ i)
 {
     mas[i][0] = 0;
     mas[0][i] = 0;
 }
 int k = 0;
 for(int i = 1;i <= n; ++ i)
 {
     for(int j = 1; j <= n; ++ j)
     {
         if(a[i] == b[j]) mas[i][j] = mas[i-1][j-1] + 1;
         else mas[i][j] = max(mas[i - 1][j], mas[i][j - 1]);
     }
 }
 cout << mas[n][n] << endl;
 int i = n, j = n;
 while(i * j != 0)
 {
     if(a[i] == b[j]) {a1[k] = i;b1[k] = j; i --; j --; k ++;}
     else{
        if(mas[i][j] == mas[i - 1][j]){ i --;}
        else j --;
     }
 }
 for(int t = k - 1; t >= 0;t --)
 {
     cout << a1[t] - 1<< " ";
 }cout << endl;
 for(int t = k - 1; t >= 0; t --)
 {
     cout << b1[t] - 1 << " ";
 }
return 0;
}

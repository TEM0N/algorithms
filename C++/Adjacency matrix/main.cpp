#include <bits/stdc++.h>
using namespace std;
int mas[101][101];
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; ++ i)
  {
      int a, b;
      cin >> a >> b;
      mas[a - 1][b - 1] = 1;
      mas[b - 1][a - 1] = 1;
  }
  for(int i = 0; i < n; ++ i)
  {
      for(int j = 0; j < n; ++ j)
      {
          cout << mas[i][j] << " ";
      }
      cout << endl;
  }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> vis(n);
    vector<int> d(n);
    int t = 1;
    int mas[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
           cin >> mas[i][j];
    for (int i = 0; i < n; i++)
    {
        if (!vis[i]) {
            d[i] = t++;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (size_t j = 0; j<n; ++j) {
                    int to = mas[v][j];
                    if (mas[v][j] == 1 and !vis[j]){
                            vis[j] = true;
                            q.push(j);
                            d[j] = t++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    return 0;
}

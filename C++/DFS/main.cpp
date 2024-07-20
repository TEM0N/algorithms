#include <bits/stdc++.h>
using namespace std;
void dfs( vector<vector<int>>& mas, vector<bool>& vis, vector<int>& labs, int node, int& lab) {
    vis[node] = true;
    labs[node] = lab ++;
    for (int i = 0; i < mas.size(); i++) {
        if (mas[node][i] == 1 && !vis[i]) {
            dfs(mas, vis, labs, i, lab);
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<bool> visited(n, false);
    vector<int> labels(n, 0);
    int lab = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(a, visited, labels, i, lab);
        }
    }
    for (int i = 0; i < n; i++)
        cout << labels[i] << " ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int grath[1001][1001][2], res[1001];
bool vis[1001], vis2[1001];
int func1(int i, int NN) {
    if (vis[i]) return i;
    int start = 0;
    vis[i] = true;
    for (int j = 1; j <= grath[i][0][0]; ++j) {
        if (grath[i][j][1] != NN) {
            start = func1(grath[i][j][0], grath[i][j][1]);
            if (start != 0) return start;
        }
    }
    return start;
}
void func2(int i, int NN) {
    vis2[i] = true;
    for (int j = 1;j <= grath[i][0][0]; ++ j) {
        if (grath[i][j][1] != NN) {
            if (res[grath[i][j][1]] == 0) res[grath[i][j][1]] = grath[i][j][0];
            if (!vis2[grath[i][j][0]]) func2(grath[i][j][0], grath[i][j][1]);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, u, v;
    cin >> r >> c;
    for (int i = 1; i <= c; i++) {
        cin >> u >> v;
        grath[u][0][0]++;
        grath[v][0][0]++;
        grath[u][grath[u][0][0]][0] = v;
        grath[u][grath[u][0][0]][1] = i;
        grath[v][grath[v][0][0]][0] = u;
        grath[v][grath[v][0][0]][1] = i;
    }
    for (int i = 1; i <= r; i++) {
        if (!vis[i]) {
                int p = func1(i,0);
                if(p == 0){cout<<"No";return 0;
                }
            func2(p, 0);
            for (int i = 0; i <= 1001; i++)
                vis2[i]=false;
        }
    }
    for (int i = 1; i <=c; i++)
        cout << res[i] << " ";
    return 0;
}

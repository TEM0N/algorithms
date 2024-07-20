#include <bits/stdc++.h>
using namespace std;
const long long N = 1e10;
vector<vector<pair<long long, long long>>> mas(200002);
vector<long long> dist(200002, N);
void Dijkstra(vector<vector<pair<long long, long long>>>& mas, vector<long long>& dist, long long start) {
    int n = mas.size();
    dist[start] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        long long d = pq.top().first;
        long long u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (pair<long long, long long>& ma : mas[u]) {
            long long  v = ma.first;
            long long weight = ma.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mas[v].push_back({u, w});
        mas[u].push_back({v, w});
    }
    Dijkstra(mas, dist, 1);
    cout << dist[n];
    return 0;
}

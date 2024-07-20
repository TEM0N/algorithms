#include <bits/stdtr1c++.h>
using namespace std;
int comp=0;
class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            comp--;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    comp = n;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u - 1, v - 1);
        cout<<comp<<endl;
    }
    return 0;
}

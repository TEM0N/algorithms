#include <bits/stdtr1c++.h>
using namespace std;
int comp = 0;
int mas[750000][2];
int a[750000];
int b[750000];
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
    int n,m, q;
    cin >> n >> m >> q;
    DSU dsu(n);
    comp = n;
    for (int i = 0; i < m; i++) {
        cin >> mas[i][0] >> mas[i][1];
    }
    for(int i = 0; i < q; ++ i)
    {
        cin >> a[i];
        b[a[i] - 1] = 1;
    }
     for(int i = 0; i < m; ++ i)
    {
        if(b[i] == 0){dsu.unite(mas[i][0] - 1, mas[i][1] - 1);}
    }
    string s = "";
    for(int i = q - 1; i >= 0; i --){
        int u = a[i] - 1;
        if(comp != 1) s += "0";
        else s += "1";
        dsu.unite(mas[u][0] - 1, mas[u][1] - 1);
    }
    for(int i = s.size() - 1; i >= 0;i --)
    {
        cout << s[i];
    }
    return 0;
}

#include <bits/stdtr1c++.h>
using namespace std;
struct Node {
    int value;
    long long left;
    long long right;
};
int main()
{
    freopen("bst.in", "r", stdin);
    freopen("bst.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ver;
    cin >> n >> ver;
    vector<Node> nodes(n);
    nodes[0].value = ver;
    nodes[0].left = -2147483649;
    nodes[0].right = 2147483648;
    int val, b;
    char c;
    for (int i = 1; i < n;i++) {
        cin >> val >> b >> c;
        nodes[i].value = val;
        if (c == 'L')
        {
            nodes[i].right = nodes[b - 1].value;
            nodes[i].left = nodes[b - 1].left;
        }
        else
        {
            nodes[i].right = nodes[b - 1].right;
            nodes[i].left = nodes[b - 1].value;
        }
        if (val < nodes[i].left or val >= nodes[i].right) {cout << "NO";return 0;}
    }
    cout << "YES";
    return 0;
}

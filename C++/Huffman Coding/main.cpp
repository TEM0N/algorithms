#include <bits/stdtr1c++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    long long n;
    cin >> n;
    queue<long long> first;
    queue<long long> second;
    long long sum = 0;
    long long l, r;
    for (int i = 0; i < n; i++) {
        cin >> l;
        first.push(l);
    }
    while ((first.size() + second.size()) != 1) {
        long long s = 0;
        if (second.empty()) {
            r = -1;
        }
        else {
            r = second.front();
        }
        if (first.empty()) {
            l = -1;
        }
        else {
            l = first.front();
        }
        if (l == -1) {
            s += r;
            second.pop();
        }
        else if (r == -1) {
            s += l;
            first.pop();
        }
        else if (l <= r) {
            s += l;
            first.pop();
        }
        else {
            s += r;
            second.pop();
        }
        if (second.empty()) {
            r = -1;
        }
        else {
            r = second.front();
        }
               if (first.empty()) {
            l = -1;
        }
        else {
            l = first.front();
        }
        if (l == -1) {
            s += r;
            second.pop();
        }
        else if (r == -1) {
            s += l;
            first.pop();
        }
        else if (l <= r) {
            s += l;
            first.pop();
        }
        else {
            s += r;
            second.pop();
        }
        sum += s;
        second.push(s);
    }
    cout << sum;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long const k = 263;
long long const m = 1e9+7;
long long const m1 = 1073741824;
long long binpow (long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1)
            res = (res * a) % 1000000007;
        a = (a * a ) % 1000000007;
        n >>= 1;
    }
    return res % 1000000007;
}
long long binpow1 (long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1)
            res = (res * a) % 1073741824;
        a = (a * a) % 1073741824;
        n >>= 1;
    }
    return res % 1073741824;
}
    long long mas[200001];
    long long mas1[200001];
int main() {
    string s;
    cin >> s;
    int left = 0;
    int right = s.length();
    bool b = true;
    for(int i = 1;i <= s.size(); ++i)
    {
        mas[i] = (mas[i - 1] * k + (s[i - 1] - 64)) % m;
        mas1[i] = (mas1[i - 1] * k + (s[i - 1] - 64)) % m1;
    }
    while (left < right) {
        b = true;
        int mid = (left + right) / 2;
        unordered_set<long long> seen;
        seen.reserve(s.length());
        unordered_set<long long> seen1;
        seen1.reserve(s.length());
        for (int i = 0; i <= s.length() - mid; i++) {
            long long substring = (mas[i + mid] + m - (mas[i] * binpow(k, mid)) % m) % m;
            long long substring1 = (mas1[i + mid] + m1 - (mas1[i] * binpow1(k, mid)) % m1) % m1;
            long long hashValue = hash<long long>{}(substring);
            long long hashValue1 = hash<long long>{}(substring1);
            if (seen.count(hashValue) > 0 and seen1.count(hashValue1) > 0) {
                b = false;
            }
            seen.insert(hashValue);
            seen1.insert(hashValue1);
        }
        if (b) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left;
    return 0;
}

#include <iostream>
using namespace std;
long long binpow (long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1)
            res = (res * a) % 1000000007;
        a = (a * a )% 1000000007;
        n >>= 1;
    }
    return res%1000000007;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >>k;
    unsigned long long pr = 1;
    for(int i = n - k + 1; i <= n; ++ i)
    {
        pr = (pr * i) % 1000000007;
    }
    unsigned long long fac = 1;
    for(int i = 2;i <= k; ++ i)
    {
        fac *= i;
        fac = fac % 1000000007;
    }
   pr = (pr * binpow (fac, 1000000007 - 2)) % 1000000007;
    cout << pr;
    return 0;
}

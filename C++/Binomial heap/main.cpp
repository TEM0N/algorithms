#include <bits/stdtr1c++.h>
using namespace std;
 long long a[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    long long p=0;
    cin>>n;
    long long count = 0;
    while(n > 0){
        if(n % 2 == 1){
            cout << count << endl;
        }count ++; n /= 2;
    }
    return 0;
}

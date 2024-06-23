#include <iostream>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++ i)
        cin >> a[i];
    int m;
    cin >> m;
    for(int j = 0;j < m; ++ j)
    {
        int ch;
        cin >> ch;
        int l = 0,r = n;
        int l1 = 0,r1 = n;
        int l2 = 0,r2 = n;
        int k = 0;
        while(l < r){
            if(a[(l + r) / 2 ] == ch) {cout << "1 ";k = 1;break;}
            else if( a[(l + r) / 2] > ch) r = (l + r) / 2;
            else l = (l+r)/2 +1;
        }
        if(k == 0){cout << "0 ";}
        while (l1 < r1) {
        if (ch <= a[(l1 + r1) / 2]) {
            r1 = (l1 + r1) / 2;
        }
        else {
            l1 = (l1 + r1) / 2 + 1;
        }
    }
    cout << l1 << " ";
        while (l2 < r2) {
        if (ch < a[(l2 + r2) / 2]) {
            r2 = (l2 + r2) / 2;
        }
        else {
            l2 = (l2 + r2) / 2 + 1;
        }
    }
    cout << l2 << endl;
    }
    return 0;
}

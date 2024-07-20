#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        b[i] = -1;
    }
    b[2] = 0;
    b[3] = 0;
    if(n == 2){
            cout << -1; return 0;
            }
    a[2] = a[0] + a[2];
    b[2] = 0;
    if(n >= 4){
            a[3] += a[0];
            b[3] = 0;
    }
    if(n >=5 ){
            a[4] += a[2];
            b[4] = 2;
    }
    for(int i = 5;i < n;++ i)
    {
        if(a[i - 2] > a[i - 3]){
        a[i] += a[i - 2];
        b[i] = i - 2;
    }
    else{
        a[i] += a[i - 3];
        b[i] = i - 3;
    }}
    int p = n - 1;
    c[0] = n - 1;
    int k = 0;
    while(p > 0)
    {
        p = b[p];
        k ++;
        c[k] = p;
    }
    cout << a[n - 1] << endl;
    for(int i = k;i >= 0;i --)
    {
        cout << c[i] + 1 << " ";
    }
    return 0;
}

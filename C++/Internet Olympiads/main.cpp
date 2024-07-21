#include <bits/stdc++.h>

using namespace std;

vector <long long> k;

int main(){
long long n, m;
cin >> n >> m;
long long a[n + 1][3];
long long c[m + 1][3];
long long d[n + 1];
long long h = 0;
for (long long i = 0; i < n; i ++)
{
    for (int j = 0; j < 3; j ++)
    {
        cin >> a[i][j];
    }
    if (a[i][1] != 0) {d[h] = a[i][1]; h ++;}
}
h--;
for (long long i = 0; i < m; i ++)
{
    for (int j = 0; j < 3; j ++)
    {
        cin >> c[i][j];
    }
}
sort(d + 0, d + h + 1);
for (long long i = 0; i < n; i ++)
{
    if (a[i][1]>d[(h+2)/2] and a[i][1]!=0) k.push_back(a[i][0]);
    else if (a[i][1]==d[h] and a[i][1]!=0) k.push_back(a[i][0]);
}
for (long long i = 0; i < m; i ++)
{
    if (c[i][1] >= 1) k.push_back(c[i][0]);
}
sort(k.begin(), k.end());
cout << k.size() << endl;
for (long long i = 0; i < k.size(); i++)
{
    cout << k[i] << " ";
}
    return 0;
}

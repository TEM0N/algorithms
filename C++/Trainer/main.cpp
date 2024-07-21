#include <bits/stdc++.h>

using namespace std;

int main()
{
int n;
cin>>n;
pair <int, string> p[n];
pair <int, string> p1[n];
for(int i = 0; i < n; ++ i)
{
    cin >> p[i].second >> p[i].first;
}
int m;
cin >> m;
int b[m][3];
for(int i = 0; i < m; ++ i)
{
    cin >> b[i][0] >> b[i][1] >> b[i][2];
}

for(int i = 0; i < n; ++ i)
{
    for(int j = 0; j < m; ++ j)
    {
        if(p[i].first >= b[j][0] and p[i].first <= b[j][1]) {
            p[i].first = b[j][2];
            break;
        }
    }
}
string t = "";
int l = 0;
int k = 0;
for(int i = 0; i < n; ++i)
{
    for(int j = 0; j < n; ++j)
    {
        if(p[j].first > l)
        {
            l=p[j].first,k=j;
            t=p[j].second;
        }
        if(p[j].first == l and p[j].second < t)
        {
            l = p[j].first, k = j;
            t = p[j].second;}
        }
    cout << p[k].second << " " << p[k].first << endl;
    p[k].first = 0;
    t = "";
    l = 0;
}
    return 0;
}

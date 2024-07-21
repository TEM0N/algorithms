#include <bits/stdc++.h>
using namespace std;
int complong(int lena, int lenb, int *a, int *b)
{
    if(lena < lenb)
       return -1;

    if(lena > lenb)
       return 1;

        for(int i = lena; i >= 1; i --)
        {
            if(a[i] < b[i]) return -1;
            if(a[i] > b[i]) return 1;
        }
    return 0;
}
int main()
{
    string s, t, ma = "1", mi = "m";
    cin >> s >> t;
    int ss = s.size();
    string S = s + s;
    for(int i = 0; i < ss; ++ i)
    {
        string c = S;
        c.erase(0, i);
        c.erase(ss);
        ma = max(ma, c);
    }
    int tt = t.size();
    string T = t + t;
    for(int i = 0; i < tt; ++ i)
    {
        string c = T;
        c.erase(0, i);
        c.erase(tt);
        if(c[0] != '0')
        {
            mi = min(mi, c);
        }
    }
    string s1 = ma;
    string s2 = mi;
    int maxsize = 30002;
    int lena;
    lena = s1.length();
    int a[maxsize];
    for(int i = 0; i < lena; i ++)
        a[lena - i] = int(s1[i]) - 48;

    int lenb;
    lenb = s2.length();
    int b[maxsize];
    for(int i = 0; i < lenb; i++)
        b[lenb - i]= int(s2[i]) - 48;

    int maxx = max(lena, lenb);
    if(maxx == lena)
    for(int i = lenb + 1; i <= lena; i++)
        b[i] = 0;

    else
       for(int i = lena + 1; i <= lenb; i++)
        a[i] = 0;

    if(complong(lena, lenb, a, b) < 0)
    {
        cout << "-";
        for(int i = 1; i <= maxx; ++ i)
            swap(a[i], b[i]);
    }

    int c = 0;
    for(int i = 1; i <= maxx; ++ i)
    {
        c = c + a[i] - b[i] + 10;
        a[i] = c % 10;
        if(c <= 9)c =- 1;
        else c = 0;
    }

    while(a[maxx] == 0 && maxx > 1)
        maxx --;

    for(int i = maxx; i >= 1; i --)
        cout << a[i];

    return 0;
}

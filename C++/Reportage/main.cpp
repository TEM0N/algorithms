#include<bits/stdtr1c++.h>
using namespace std;
int mas[100001];
int rev[100001];
int ind[100001];
int indrev[100001];
int a[100001];
int pos[100001];
int a1[100001];
int pos1[100001];
int prev1[100001];
int main() {
  freopen("report.in", "r", stdin);
  freopen("report.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
    rev[n - 1 - i] = mas[i];
  }
  vector<int> arr(n + 2);
  arr[0] = -1;
  for (int i = 1; i < n + 2; i ++) {
    arr[i] = 100001;
  }
  int count = 0;
  for (int i = 0; i < n; i ++) {
    int j = int(upper_bound(arr.begin(), arr.end(), mas[i]) - arr.begin());
        if (arr[j - 1] < mas[i] and  mas[i] < arr[j])
      {arr[j] = mas[i];
      count = max(count, j);}
            ind[i] = count;
  }
  vector<int> arr1(n + 2);
  arr1[0] = -1;
  for (int i = 1; i < n + 2; i++) {
    arr1[i] = 100001;
  }
  count = 0;
  for (int i = 0; i < n; i++) {
    int j = int(upper_bound(arr1.begin(), arr1.end(), rev[i]) - arr1.begin());
        if (arr1[j - 1] < rev[i] and  rev[i] < arr1[j])
      {
          arr1[j] = rev[i];
          count = max(count,j);
      }
        indrev[n - 1 - i] = count;
  }
    int index;
    int ma = 0;
    for (int i = 0; i < n; i++) {
        if(min(ind[i], indrev[i]) > ma)
            {
                ma=min(ind[i], indrev[i]);
                index = i;
            }
  }
  cout << ma - 1 << endl;
  if( ma - 1 == 0){cout << 1;return 0;}
  int n1 = n;
  int n2 = n;
  n = index;
  for (int i = 0; i < n; i++) {
    a[i] = mas[i];
  }
  int prev[n - 1];
  int length = 0;
  pos[0] = -1;
  vector<int> d(n + 2);
  d[0] = -1;
  for (int i = 1; i < n + 2; i++) {
    d[i] = 100001;
  }
   for (int i = 0;i < n;++i){
    int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
       if (d[j - 1] < a[i] and a[i] < d[j]){
           d[j] = a[i];
           pos[j] = i;
           prev[i] = pos[j - 1];
           length = max(length, j);}
   }
   vector<int> answer;
   int p = pos[length];
   while(p != -1){
       answer.push_back(p + 1);
       p = prev[p];
   }
   reverse(answer.begin(), answer.end());
   for (int i = 0; i < ma - 1; i ++)
    {
       cout<<answer[i]<<" ";
    }
  n = n2 - index;
  int a1[n];
  for (int i = 0; i < n; i++)
  {
    a1[i]=rev[i];
  }
 int pos1[n];
 int prev1[n - 1];
 int length1 = 0;
 pos1[0] = -1;
vector<int> d1(n + 2);
  d1[0] = -1;
  for (int i = 1; i < n + 2; i++)
   {
      d1[i] = 100001;
   }
   for (int i = 0; i < n; ++i){
    int j = int(upper_bound(d1.begin(), d1.end(), a1[i]) - d1.begin());
       if (d1[j - 1] < a1[i] and a1[i] < d1[j]){
           d1[j] = a1[i];
           pos1[j] = i;
           prev1[i] = pos1[j - 1];
           length1 = max(length1, j);}
   }
   vector<int> answer1;
   int p1 = pos1[length1];
   while(p1 != -1){
       answer1.push_back(n2 - 1 - p1 + 1);
       p1 = prev1[p1];

   }reverse(answer1.begin(), answer1.end());
   int num;
   int zn = -1;

   for(int i = answer[ma - 2]; i < answer1[ma - 2] - 1; ++ i)
    {
        if(mas[i] > zn){zn = mas[i]; num = i;}
    }
   cout << num + 1 << " ";
   for (int i = ma - 2; i >= 0; i --)
    {
        cout << answer1[i] << " ";
    }
  return 0;
}

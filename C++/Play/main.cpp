#include <bits/stdc++.h>
using namespace std;

enum Play{ First, Second };
Play nPlay(Play current) {
  return current == First ? Second : First;
}
int get(const vector<int>& num,int pos, Play play) {
  if (play == First)
    return num[pos];
  return -num[pos];
}
struct Sc {
  bool is;
  int v;
  Sc() : is(false) {
  }
};
int step(const vector<int>& num,int l,int r, Play play, vector<vector<Sc>>& results) {
  if (results[l][r].is == true)
    return results[l][r].v;
  if (l > r)
    return 0;
  if (l == r)
    return get(num, l,play);
  int lRes = step(num, l + 1, r, nPlay(play), results) + get(num, l, play);
  int rRes= step(num, l,r - 1, nPlay(play), results) + get(num, r, play);
  results[l][r].is = true;
  if (play == First) {
    results[l][r].v = max(lRes, rRes);
  }
  else {
    results[l][r].v = min(lRes, rRes);
  }
  return results[l][r].v;
}
int main() {
  int n;
  cin >> n;
  vector<int> num;
  num.resize(n);
  for (int i = 0;i < n; ++ i) {
    cin >> num[i];
  }
  vector<vector<Sc>>results;
  results.resize(n);
  for (int i = 0;i < n; ++ i) {
    results[i].resize(n);
  }
  int result = step(num, 0, num.size() - 1, First, results);
  if (result > 0)
    cout << "1";
  else if (result < 0)
    cout << "2";
  else
    cout << "0";
}

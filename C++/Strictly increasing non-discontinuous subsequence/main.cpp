#include<bits/stdtr1c++.h>
using namespace std;
int mas[700001];
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    vector<int> arr(n + 2);
    arr[0] = -1000000001;
    for (int i = 1; i < n + 2; i ++) {
        arr[i] = 1000000001;
    }
    int count = 0;
    for (int i = 0; i < n; i ++) {
        int j = int(upper_bound(arr.begin(), arr.end(), mas[i]) - arr.begin());
        if (arr[j - 1] < mas[i] and  mas[i] < arr[j])
            {arr[j] = mas[i];
            count = max(count, j);}
    }
    cout << count;
    return 0;
}

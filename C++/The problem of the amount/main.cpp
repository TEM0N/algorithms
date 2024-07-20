#include <bits/stdtr1c++.h>
using namespace std;
long long findSum(const vector<long long>& A, const vector<long long>& blockSum, const vector<long long>& prefixSum, long long l, long long r, long long blockSize) {
    long long startBlock = l / blockSize,endBlock = (r - 1) / blockSize;
    long long sum = 0;
    if (startBlock == endBlock) {
        for (long long i = l; i < r; i++) {
            sum += A[i];
        }
    } else {
        for (long long i = startBlock + 1; i < endBlock; i++) {
            sum += blockSum[i];
        }
        for (long long i = l; i < (startBlock + 1) * blockSize; i++) {
            sum += A[i];
        }
        for (long long i = (endBlock * blockSize); i < r; i++) {
            sum += A[i];
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    long long blockSize = sqrt(n);
    long long numBlocks = ceil((double)n / blockSize);
    vector<long long> blockSum(numBlocks, 0);
    vector<long long> prefixSum(n, 0);
    for (int i = 0; i < n; i++) {
        blockSum[i / blockSize] += A[i];
        prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0) + A[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++ i){
        string query;
        cin >> query;
        if (query == "Add") {
            long long index, value;
            cin >> index >> value;
            A[index] += value;
            blockSum[index / blockSize] += value;
        } else if (query == "FindSum") {
            long long l, r;
            cin >> l >> r;
            long long sum = findSum(A, blockSum, prefixSum, l, r, blockSize);
            cout << sum << endl;
        }
    }
    return 0;
}

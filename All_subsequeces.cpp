#include <iostream>
#include <vector>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

void generateSubsequencesOfLengthK(vector<int>& arr, int k) {
    int n = arr.size();
    int totalSubsequences = 1 << n;

    for (int i = 0; i < totalSubsequences; ++i) {
        if (countSetBits(i) == k) {
            vector<int> subsequence;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subsequence.push_back(arr[j]);
                }
            }
            cout << "{ ";
            for (int num : subsequence) {
                cout << num << " ";
            }
            cout << "}" << endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 4, 4};
    int k = 2;

    cout << "All subsequences of length " << k << " are:" << endl;
    generateSubsequencesOfLengthK(arr, k);

    return 0;
}

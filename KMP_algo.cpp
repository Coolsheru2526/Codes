#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KMP {
private:
    // Function to build the LPS array
    void buildLPSArray(string pattern, vector<int>& lps) {
        int length = 0;  // length of the previous longest prefix suffix
        lps[0] = 0;      // lps[0] is always 0

        int i = 1;
        while (i < pattern.length()) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    // Function to perform KMP search
    vector<int> search(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        vector<int> lps(m);
        buildLPSArray(pattern, lps);

        vector<int> result;
        int i = 0;  // index for text
        int j = 0;  // index for pattern

        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};

int main() {
    KMP kmp;
    string text = "ababcababcabc";
    string pattern = "abc";

    vector<int> result = kmp.search(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> data;
    int n;

    // Function to build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Recursively build the left and right subtrees
            build(leftChild, start, mid);
            build(rightChild, mid + 1, end);

            // Combine the results of the left and right children
            tree[node] = combine(tree[leftChild], tree[rightChild]);
        }
    }

    // Function to perform range queries
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            // If the range is completely outside the current node range
            return defaultValue(); // e.g., 0 for sum, INT_MAX for min, INT_MIN for max
        }

        if (l <= start && end <= r) {
            // If the range is completely inside the current node range
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        // Query the left and right subtrees
        int leftResult = query(leftChild, start, mid, l, r);
        int rightResult = query(rightChild, mid + 1, end, l, r);

        // Combine the results of the left and right children
        return combine(leftResult, rightResult);
    }

    // Function to update a value in the array and segment tree
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            // Leaf node
            data[idx] = value;
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (start <= idx && idx <= mid) {
                // Update the left child
                update(leftChild, start, mid, idx, value);
            } else {
                // Update the right child
                update(rightChild, mid + 1, end, idx, value);
            }

            // Combine the results of the left and right children
            tree[node] = combine(tree[leftChild], tree[rightChild]);
        }
    }

    // Combine function (modify according to the problem, e.g., sum, min, max)
    int combine(int left, int right) {
        return left + right; // For range sum queries
        // return min(left, right); // For range minimum queries
        // return max(left, right); // For range maximum queries
    }

    // Default value function (modify according to the problem)
    int defaultValue() {
        return 0; // For range sum queries
        // return INT_MAX; // For range minimum queries
        // return INT_MIN; // For range maximum queries
    }

public:
    SegmentTree(const vector<int>& input) {
        data = input;
        n = input.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Public query function
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    // Public update function
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of values in range [1, 3]: " << segTree.query(1, 3) << endl;

    segTree.update(1, 10);
    cout << "After update, sum of values in range [1, 3]: " << segTree.query(1, 3) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
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

    // Function to apply pending updates
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node]; // For sum queries
            // tree[node] += lazy[node]; // For max/min queries, depending on operation

            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    // Function to perform range queries with lazy propagation
    int query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (r < start || l > end) {
            return defaultValue(); // Completely outside the range
        }

        if (l <= start && end <= r) {
            return tree[node]; // Completely inside the range
        }

        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftResult = query(leftChild, start, mid, l, r);
        int rightResult = query(rightChild, mid + 1, end, l, r);

        return combine(leftResult, rightResult);
    }

    // Function to perform range updates with lazy propagation
    void updateRange(int node, int start, int end, int l, int r, int value) {
        propagate(node, start, end);

        if (r < start || l > end) {
            return; // Completely outside the range
        }

        if (l <= start && end <= r) {
            tree[node] += (end - start + 1) * value; // For sum queries
            // tree[node] += value; // For max/min queries, depending on operation

            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        updateRange(leftChild, start, mid, l, r, value);
        updateRange(rightChild, mid + 1, end, l, r, value);

        tree[node] = combine(tree[leftChild], tree[rightChild]);
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
        lazy.resize(4 * n, 0); // Initialize lazy array with 0
        build(0, 0, n - 1);
    }

    // Public query function
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    // Public range update function
    void updateRange(int l, int r, int value) {
        updateRange(0, 0, n - 1, l, r, value);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of values in range [1, 3]: " << segTree.query(1, 3) << endl;

    segTree.updateRange(1, 3, 10); // Add 10 to elements in range [1, 3]
    cout << "After range update, sum of values in range [1, 3]: " << segTree.query(1, 3) << endl;

    return 0;
}

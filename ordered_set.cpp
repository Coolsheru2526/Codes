#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define an ordered set type
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_set<int> os;

    // Inserting elements
    os.insert(10);
    os.insert(20);
    os.insert(15);

    // Finding the k-th smallest element (0-indexed)
    cout << "0th smallest element: " << *os.find_by_order(0) << endl; // 10
    cout << "1st smallest element: " << *os.find_by_order(1) << endl; // 15
    cout << "2nd smallest element: " << *os.find_by_order(2) << endl; // 20

    // Finding the number of elements strictly less than x
    cout << "Number of elements less than 15: " << os.order_of_key(15) << endl; // 1
    cout << "Number of elements less than 17: " << os.order_of_key(17) << endl; // 2

    // Checking existence and size
    if (os.find(20) != os.end()) {
        cout << "20 exists in the set." << endl;
    }
    cout << "Size of the set: " << os.size() << endl;

    // Erasing an element
    os.erase(15);
    cout << "Size after erasing 15: " << os.size() << endl;

    return 0;
}

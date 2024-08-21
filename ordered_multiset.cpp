#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define an ordered multiset type
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_multiset<int> oms;

    // Inserting elements
    oms.insert(10);
    oms.insert(20);
    oms.insert(15);
    oms.insert(10); // duplicate element

    // Finding the k-th smallest element (0-indexed)
    cout << "0th smallest element: " << *oms.find_by_order(0) << endl; // 10
    cout << "1st smallest element: " << *oms.find_by_order(1) << endl; // 10
    cout << "2nd smallest element: " << *oms.find_by_order(2) << endl; // 15
    cout << "3rd smallest element: " << *oms.find_by_order(3) << endl; // 20

    // Finding the number of elements strictly less than x
    cout << "Number of elements less than 15: " << oms.order_of_key(15) << endl; // 2
    cout << "Number of elements less than 17: " << oms.order_of_key(17) << endl; // 3

    // Finding the number of occurrences of a particular element
    int count_10 = oms.order_of_key(11) - oms.order_of_key(10);
    cout << "Number of occurrences of 10: " << count_10 << endl; // 2

    // Erasing one occurrence of an element
    oms.erase(oms.find_by_order(oms.order_of_key(10))); // erase one '10'
    cout << "Number of occurrences of 10 after erasing one: " << (oms.order_of_key(11) - oms.order_of_key(10)) << endl; // 1

    // Checking size
    cout << "Size of the multiset: " << oms.size() << endl;

    return 0;
}

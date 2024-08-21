#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define an ordered map type
template <typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_map<int, string> omap;

    // Inserting key-value pairs
    omap[1] = "one";
    omap[2] = "two";
    omap[3] = "three";
    omap[5] = "five";
    omap[4] = "four";

    // Finding the k-th smallest key (0-indexed)
    cout << "0th smallest key: " << omap.find_by_order(0)->first << " -> " << omap.find_by_order(0)->second << endl; // 1 -> one
    cout << "2nd smallest key: " << omap.find_by_order(2)->first << " -> " << omap.find_by_order(2)->second << endl; // 3 -> three

    // Finding the number of keys strictly less than a given key
    cout << "Number of keys less than 4: " << omap.order_of_key(4) << endl; // 3

    // Erasing a key-value pair by key
    omap.erase(2); // Erase the key 2
    cout << "After erasing key 2, number of keys less than 4: " << omap.order_of_key(4) << endl; // 2

    // Checking the size of the map
    cout << "Size of the ordered map: " << omap.size() << endl;

    // Iterating over the ordered map
    for (const auto &p : omap) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}

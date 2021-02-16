#include <ext/pb_ds/assoc_container.hpp> ///Header file.
using namespace __gnu_pbds;

typedef tree< ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > ordered_set; 
/// ll            ==> to any data type
/// less_equal    ==> for multiset increasing order
/// less          ==> for set increasing order
/// greater_equal ==> for multiset decreasing order
/// greater       ==> for set decreasing order

/// cout<<*X.find_by_order(1)<<endl; // iterator to the k-th largest element
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item

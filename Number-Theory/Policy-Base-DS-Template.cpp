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


Some Applications:
=======================
  //Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> ///Header file.
using namespace __gnu_pbds;

typedef tree< long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int main()
{
    ordered_set ps;

    ///insert a date.
    
    ps.insert( 1 );
    ps.insert( 3 );
    ps.insert( 3 );
    ps.insert( 2 );
    ps.insert( 5 );
    ps.insert( 5 );
    ps.insert( 5 );
    ps.insert( 4 );

    ///cout << ps.size() << endl;///Print size of the data set. Repeated data will be removed.
    
               ///Print data

    ///Set Increasing Order (for using less in the ordered_set).
    ///for(auto i : ps)cout << i << " "; cout << endl ; ///1 2 3 4 5

    ///Set Decreasing Order (for using greater in the ordered_set).
    ///for(auto i : ps)cout << i << " "; cout << endl ; ///5 4 3 2 1

    ///Multiset Increasing Order (for using less_equal in the ordered_set).
    ///for(auto i : ps)cout << i << " "; cout << endl ; ///1 2 3 3 4 5 5 5

    ///Multiset Decreasing Order (for using greater_equal in the ordered_set).
    ///for(auto i : ps)cout << i << " "; cout << endl ; ///5 5 5 4 3 3 2 1


     /// Number of Elements Less than 5 and 100  for Set (less)
    cout << ps.order_of_key( 5 ) << endl; ///1 2 3 4 = Total 4 Elements.
    cout << ps.order_of_key( 100 ) << endl;/// 1 2 3 4 5 = All Elements = Total 5 Elements

    /// Number of Elements Less than 5 and 100  for Multiset (less_equal)
    cout << ps.order_of_key( 5 ) << endl; ///1 2 3 3 4 = Total 5 Elements.
    cout << ps.order_of_key( 100 ) << endl;/// 1 2 3 3 4 5 5 5 = All Elements = Total 8 Elements
}

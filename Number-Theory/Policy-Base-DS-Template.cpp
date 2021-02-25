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

23 use of PBDS
=================
//youtube video of pbds: youtube.com/watch?v=MiBrJTNOEP0
#include<bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using    namespace __gnu_pbds;
 
using    namespace std;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int k, value;
int main()
{
    ordered_set os;
 
    // 1. insert a number in the list
    os.insert(5);
    os.insert(2);
    os.insert(4);
 
    // 2. delete a given number from the list
    os.erase(5);
 
    // 3. check if the list is empty
    if(os.empty()) cout << "set is empty\n";
    
    // 4. count of a given number(7) in the list
    // unfortunately pbds don't support count() method like set;
    if(os.find(7)==os.end())
        cout << "0\n";
    else cout << "1\n";
 
    // 5. delete all the numbers from the list, i.e. clear the list
    //os.clear();
 
 
    // 6. how many distinct numbers in the list
    cout << os.size() << "\n";
 
    // 7. what is the smallest number in the list
    if(os.size()>0)
        cout << *os.begin() << "\n";
 
    // 8. what is the greatest number in the list
    if(os.size()>0)
        cout << *os.rbegin() << "\n";
    //or,
    if(os.size()>0)
    {
        auto pos = os.end();
        pos--;
        cout << *pos << "\n";
    }
 
    // 9. find a given number(7) or say if it is not found
    if(os.find(7)==os.end())
        cout << "not found\n";
    else auto idx = os.find(7);
 
    // 10. how many numbers are smaller than a given value(7)
    cout << os.order_of_key(7);
 
    // 11. how many numbers are smaller than or equal to a given value(7)
    int cnt = os.order_of_key(7);
    if(os.find(7)!=os.end()) cnt++;
    cout << cnt << "\n";
    //or,
    cnt = os.order_of_key(8);
    cout << cnt << "\n";
 
    // 12. how many numbers are greater than a given value(7)
    cout << os.size() - os.order_of_key(8) << "\n";
 
    // 13. how many numbers are greater than or equal to a given value(7)
    cout << os.size() - os.order_of_key(7) << "\n";
 
    // 14. if the given numbers are sorted in ascending order, what is the k'th number
    //5 1 5 2 1 6
//    1 2 5 6
//    0 1 2 3
 
    cout << *os.find_by_order(2) << "\n";
 
    // 15. if the given numbers are sorted in descending order, what is the k'th number
    // if we use greater<int> 
    cout << *os.find_by_order(k) << "\n";
 
//    or, if numbers are sorted in ascending order
//    1 3 4 6 7
//    0 1 2 3 4 => size-1
//    4 3 2 1 0
    cout << *os.find_by_order(os.size()-1-k) << "\n";
 
    // 16. delete the k'th smallest number
    os.erase(os.find_by_order(k));
 
    // 17. delete the k'th greatest number
 
    // if sorted in ascending order
    os.erase(os.find_by_order(os.size()-1-k));
    //or, if sorted in descending order
    os.erase(os.find_by_order(k));
 
    // 18. delete the smallest number from the list
    os.erase(os.begin());
 
    // 19. delete the greatest number from the list
    os.erase(os.rbegin());
 
    // 20. print all the numbers in ascending order
    for(auto itr=os.begin();itr!=os.end();itr++)
        cout << *itr << " ";
    cout << "\n";
 
    // 21. print all the numbers in descending order
    for(auto itr=os.rbegin();itr!=os.rend();itr++)
        cout << *itr << " ";
    cout << "\n";
 
    // 22. what is the smallest number which is greater than or equal to a given number(7) 
 
    cout << *os.lower_bound(7) << "\n";
 
 
    // 23. what is the smallest number which is greater than to a given number(7)
    cout << *os.upper_bound(7) << "\n";
 
    return 0;
}

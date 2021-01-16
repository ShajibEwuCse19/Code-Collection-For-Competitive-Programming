Iterative Implementatio:
========================
  //Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mx = 1e5+123;
int a[mx];

bool Binary_Search(int x , int n)
{
    int l = 0 , r = n - 1;

    while(l <= r)
    {
        int mid = ( l + r ) / 2;

        if( a[mid] == x )return true;
        else if ( a[mid] > x )r = mid - 1;
        else l = mid + 1 ;
    }
    return false;
}

int main()
{
    FAST;
    int n ; cin >> n;
    for( int i = 0 ; i < n ; i++ )cin >> a[i];
    sort( a , a+n );

    int x;cin>>x;
    if( Binary_Search( x , n )) cout << "YES" << endl;
    else cout << "NO" << endl;
}


Recursive Implementation:
=========================
//Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mx = 1e5+123;
int ara[mx];

int Binary_Search(int ara[] , int x , int l , int r)
{

    if(r >= l)
    {
        int mid = l + ( r - l ) / 2;

        if(ara[mid] == x)return mid;

        else if( ara[mid] > x )return Binary_Search( ara , x , l , mid-1);
        
        else Binary_Search( ara , x , mid+1 , r);
    }
    return -1;
}

int main()
{
    FAST;
    int n ; cin >> n;
    for(int i = 0 ; i < n ; i++)cin >> ara[i];
    sort( ara , ara+n );

    int x ; cin >> x;

    int r = n - 1 , l = 0 ;

    int ans = Binary_Search( ara , x , l , r );

    if ( ans == -1 ) cout << "Invalid Number" << endl;
    else cout << "The number present in index " << ans+1 << endl;
}

STL:
=====
  sort(v.begin() , v.end());
  bool ans = binary_search(v.begin() , v.end() , num);

//Complexity log(n)


Lower Bound:
============
  //Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int Lower_Bound(int a[] , int sz , int x)
{
    int l = 0, r = sz - 1;

    int ans = sz; //max index
    while( l <= r)
    {
        int mid = l + (r - l) / 2;

        if( a[mid] >= x )
        {
            ans = min( ans , mid );
            r = mid - 1;//if we get x then we'll take the minimum index. So, we'll go to left.
        }
        else l = mid + 1;
    }

    return ans;
}

int main()
{
    FAST;
    int n ;cin >> n ;
    int a[n];
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    sort( a , a + n );

    int x ; cin >> x;

    int ans = Lower_Bound( a , n , x );

    cout << "Lower Bound = " << ans+1 << endl;
}


Upper Bound:
=============
  //Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int Upper_Bound(int a[] , int sz , int x)
{
    int l = 0, r = sz - 1;

    int ans = -1;//minimum index.
    while( l <= r)
    {
        int mid = l + (r - l) / 2;

        if( a[mid] <= x )
        {
            ans = max( ans , mid );//if we get x then we'll take the maximum index. So, we'll go to right to get max index.
            l = mid + 1;
        }
        else r = mid - 1; 
    }

    return ans;
}

int main()
{
    FAST;
    int n ;cin >> n ;
    int a[n];
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    sort( a , a + n );

    int x ; cin >> x;

    int ans = Upper_Bound( a , n , x );

    cout << "Upper Bound = " << ans+1 << endl;
}


STL:
=====
  sort(v.begin(), v.end());

	auto lower = lower_bound(v.begin(), v.end(), 10) - v.begin() + 1;
	auto upper = upper_bound(v.begin(), v.end(), 10) - v.begin() + 1;




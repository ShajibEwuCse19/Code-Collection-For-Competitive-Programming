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


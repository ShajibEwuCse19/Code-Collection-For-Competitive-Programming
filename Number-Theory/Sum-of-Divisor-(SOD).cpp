Code (Fast):
==============
//Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl             '\n'
#define loop(i,n)        for(int i=0;i<n;i++)
#define CASE_PRINT       cout<<"Case "<<C<<": "
#define CASE_PRINT2      cout<<"Case "<<C<<":"<<endl
#define ll               long long
#define ld               long double
#define Pi               2*acos(0.0) // acos(-1.0)
#define err              1e-9
int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

const int mx = 1e7+123;

bitset<mx> isPrime; ///if boolean array use n memory, bitset will use (n/32) memory. initially all index 0
vector<int> prime; ///store all prime.

///sieve Function..
void sieve ( int n )
{
    n += 100;

    isPrime[2] = 1;
    prime.push_back(2);

    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;

    int lim = sqrt(n*1) + 2;

    for ( int i = 3; i <= n; i += 2 ) {
        if ( isPrime[i] == 1 ) {

           prime.push_back(i);

           if(i<=lim)
           {
               for ( int j = i*i; j <= n; j += ( i + i ) )isPrime[j] = 0;
           }
        }
    }
}

ll SOD (ll n)
{
    ll ret = 1; ///Total sum.

    for ( auto p : prime ) {
        if ( 1LL * p * p > n ) break;

        if ( n % p == 0 ) {

                ll pawP = p;

            while ( n % p == 0 ) {

                pawP   = ( pawP * p ) ; ///p^1 x p^1 = p^2 x p^1 = p^3 x p^1 = p^4.......Here, p means p^1

                n /= p;
            }

            ret = ( ret * (( pawP -1 ) / ( p - 1 ) ) ) ; /// common pattern = a.( r^(n+1) - 1 ) / r - 1 ) Here, a = p^0 = 1 and powP = n + 1 + 1 and ret = r;
        }
    }

    if ( n > 1 ) ret = ret * ( 1 + n ); /// ( 1 + n ) = p^0 + p^1 . Here, P^1 = remaining part of n which greater than 1.

    return ret;
}

int main()
{
    FAST;
    ll lim = 1e7;
    sieve(lim); ///it'll work for (1e14).

    ll n = 12;
    cout<<SOD(n)<<endl;
}

Complexity: Complexity of Sive + Prime Factorization = (sqrt(n) / ln(sqrt(n))) + log(n). [2 based log] 
  
  
===================================================================================================================================================================

Let, n = 12;

Divisors of 12 = 1 2 3 4 6 12
Sum of Divisor, SOD(12) = 1 + 2 + 3 + 4 + 6 + 12 = 28
  
Now, Prime Factor of 12 = 2 , 2 , 3 কারণ (2 x 2 x 3 = 12 )
                        = (2^2 , 3^1)
  
    SOD(12)             = sum of all combination of  (2^2 , 3^1) /// Details in NOD tutorial. 
                        = (2^0 x 3^0) + (2^1 x 3^0) + (2^2 x 3^0) + (2^0 x 3^1) + (2^1 x 3^1) + (2^2 x 3^1) = 1 + 2 + 4 + 3 + 6 + 12 = 28
                        = 2^0 (3^0 + 3^1) + 2^1 (3^0 + 3^1) + 2^2 (3^0 + 3^1) -> Common numbers 
                        = (3^0 + 3^1) x (2^0 + 2^1 + 2^2) -> Common (3^0 + 3^1) then we'll get the common pattern.
                        = (1 + 3 ) x ( 1 + 2 + 4 )
                        = 4 x 7
                        = 28 (From Prime Factorization).
  
Common Pattern for all numbers,
SOD(x) = a^n , b^m , c^o
       = (a^0 + a^1 + --- + a^n)         x    (b^0 + b^1 + --- + b^m)       x    (c^0 + c^1 + --- + c^o)
       = { ( a ^ (n+1) - 1) / (a - 1) }  x  { ( b ^ (m+1) - 1) / (b - 1) }  x  { ( c ^ (o+1) - 1) / (c - 1) } 
            -> Geometric Series ( a x ( r^n - 1 ) / (r - 1) ) here, a = a^0 or b^0 or c^0 = 1 and n = n + 1 or m+1 or o+1 (গুণত্তর ধারা)।
  
How it works,
Let, SOD(x) = (a , b) x (c , d) -> Common pattern Let, a = 1, b = 2, c = 3, d = 4
            = (a + b) x (c + d)                  = SOD(x) = (1 + 2 ) x ( 3 + 4 ) = 3 x 7 = 21
            = (ac + ad) + (bc + bd)              = (1x3 + 1x4 + 2x3 + 2x4) 
            = SOD(x)                             = 3 + 4 + 6 + 8 = 21
  
=====================================================================================================================================================================
  
Code:
=====
//Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl             '\n'
#define loop(i,n)        for(int i=0;i<n;i++)
#define CASE_PRINT       cout<<"Case "<<C<<": "
#define CASE_PRINT2      cout<<"Case "<<C<<":"<<endl
#define ll               long long
#define ld               long double
#define Pi               2*acos(0.0) // acos(-1.0)
#define err              1e-9
int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

const int mx = 1e7+123;

bitset<mx> isPrime; ///if boolean array use n memory, bitset will use (n/32) memory. initially all index 0
vector<int> prime; ///store all prime.

///sieve Function..
void sieve ( int n )
{
    n += 100;

    isPrime[2] = 1;
    prime.push_back(2);

    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;

    int lim = sqrt(n*1) + 2;

    for ( int i = 3; i <= n; i += 2 ) {
        if ( isPrime[i] == 1 ) {

           prime.push_back(i);

           if(i<=lim)
           {
               for ( int j = i*i; j <= n; j += ( i + i ) )isPrime[j] = 0;
           }
        }
    }
}

ll SOD (ll n)
{
    ll ret = 1; ///Total sum.

    for ( auto p : prime ) {
        if ( 1LL * p * p > n ) break;

        if ( n % p == 0 ) {

                ll curSum = 1; ///update current sum when we get new prime. curSum = 1 means don't need to work for p^0 = 1
                ll pawP   = 1; ///initial power p = 1 for p^0;

            while ( n % p == 0 ) {

                pawP   = ( pawP * p ) ; ///p^0 x p^1 = p^1 x p^1 = p^2 x p^1 = p^3.......Here, p means p^1
                curSum = ( curSum + pawP ) ; ///1 + p^0 + p^1 + p^2 + ...... + p^n

                n /= p;
            }

            ret = ( ret * curSum ) ; /// sum of all common pattern or all combination of prime factorization.
        }
    }

    if ( n > 1 ) ret = ret * ( 1 + n ); /// ( 1 + n ) = p^0 + p^1 . Here, P^1 = remaining part of n which greater than 1.

    return ret;
}

int main()
{
    FAST;
    sieve(1e7); ///it'll work for (1e14).

    ll n = 12; /// 1 + 2 + 3 + 4 + 6 + 12 = 28 = Prime Factorization ( (2^0 + 2^1 + 2^2) x (3^0 + 3^1) ) = 1 + 2 + 4 + 3 + 6 + 12 = 28.

    cout << "Sum of Divisor of "<<n<<" = "<<SOD(n)<<endl;
}


Complexity: same as before.

            



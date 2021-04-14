Code-1:
=============
    
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
    n += 100;///for safety.

    isPrime[2] = 1;
    prime.push_back(2);
    ///all even no composite except 2. loop through only odd no.
    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;///initially all odd are prime.

    int lim = sqrt(n*1) + 2;///for divisor

    for ( int i = 3; i <= n; i += 2 ) {
        if ( isPrime[i] == 1 ) {

           prime.push_back(i);///if we get (i) it must be prime.

           if(i<=lim)///if we don't do it, (i*i) may overflow.
           {
               for ( int j = i*i; j <= n; j += ( i + i ) )isPrime[j] = 0;///cutting all divisor of the prime(i).
           }
        }
    }
}

vector<ll> factor (ll n)
{
    vector<ll> ret;

    for ( auto p : prime ) {
        if ( 1LL * p * p > n ) break;

        if ( n % p == 0 ) {
            ///ret.push_back (p); ///store just one divisor from same type multiple divisors. remove duplicate

            while ( n % p == 0 ) {
                ret.push_back (p);
                n /= p;
            }
        }
    }

    if ( n > 1 ) ret.push_back(n);

    return ret;
}

int main()
{
    FAST;
    sieve(1e7); ///it'll work for (1e14).

    ll n = 100;
    vector < ll > ans = factor(n);

    for(auto i : ans)cout<<i<<" ";cout<<endl;
}




Code-2
============
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
    n += 100;///for safety.

    isPrime[2] = 1;
    prime.push_back(2);
    ///all even no composite except 2. loop through only odd no.
    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;///initially all odd are prime.

    int lim = sqrt(n*1) + 2;///for divisor

    for ( int i = 3; i <= n; i += 2 ) {
        if ( isPrime[i] == 1 ) {

           prime.push_back(i);///if we get (i) it must be prime.

           if(i<=lim)///if we don't do it, (i*i) may overflow.
           {
               for ( int j = i*i; j <= n; j += ( i + i ) )isPrime[j] = 0;///cutting all divisor of the prime(i).
           }
        }
    }
}

vector<ll>factor;///store all Prime factor here.

///Prime Factorization Function..
void primeFactor(ll n)
{
    for(auto i : prime)
    {
        if( ( 1LL*i*i ) > n) break ; ///All factor ==> i <= sqrt(n) ==> i*i <= n.

        while( (n % i) == 0) ///such as, n= 36 and i = 2 then 36/2 = 18/2 = 9.....9/3 = 3/3 = 1 / 3 != 0. break;
        {
            factor.push_back(i);/// i is prime. so push(i). such as, n=36 then push(2,2,3,3).

            n = ( n / i );///such as, n = 36 then, 36/2 = 18/2 = 9/3 = 3/3
        }
    }

    if( n>1 ) factor.push_back(n);///such as, n = 38 then, 38/2 = 19 (pre-calculate). then 19>1 which must be a prime factor of 38.
}

int main()
{
    FAST;
    sieve(1e7); ///it'll work for (1e14).

    ll n;
    cin >> n ;
    
    primeFactor( n ) ;

    for(auto i : factor)cout<<i<<" ";cout<<endl; ///output all prime factor from factor array(vector).
    
    
    factor.clear();///must use this function for clear factor vector.
}


Complexity: (sqrt(n) / ln(sqrt(n))) + log(n). [2 based log]
==========

উপরের কোডে ৫২ নং লাইনে প্রাইম সংখ্যা জেনারেট হবে । আমরা জানি , মোট প্রাইম বের করার সূত্র = sqrt(n) / ln(n). কিন্তু যেহেতু এখানে শুধুমাত্র প্রাইম ডিভাইজর লাগবে 
তাই n পর্যন্ত লুপ না চলে sqrt(n) পর্যন্তপ্রাইম জেনারেট করলেই চলবে । যা কপ্লেক্সিটির প্রথম অংশ।

উপরের কোডে ৬০ নং লাইনে প্রাইমে সংখ্যা দ্বারা বার বার ভাগ হচ্ছে। সর্বনিম্ন প্রাইম হচ্ছে ২। এর জন্য worst-case কপ্লেক্সিটি হবে 2^n এর n যা log(n) [2 based]  থেকে সহজে বের করা যায়।
অর্থ্যাত ২ দ্বারা n কত বার ভাগ হচ্ছে তা log(n) দিয়ে বের করা হয়। যেমন ,  log(64) = 6 কারন , 64 = 2 x 2 x 2 x 2 x 2 x 2 = 2^6. 
    
    








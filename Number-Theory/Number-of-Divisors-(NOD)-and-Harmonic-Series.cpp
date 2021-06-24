Number of Divisor for a Natural Number:
===============================================

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl             '\n'

const int mx = 1e7+123;
vector < int > divisor[mx];
vector < int > divisible_Num[mx];

int cnt[mx]; /// Total Number of Divisor.

int main()
{
    FAST;
    int n = 10;

    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = i ; j <= n ; j += i )
        {
            divisor[j].push_back(i); /// i will go to the set which j divisible by i. such as, 1 will go every set, 2 will go 2,4,6,8 etc set.

            divisible_Num[i].push_back(j); /// Numbers that are divisible by i. all are divisible by 1, 2,4,6 etc are divisible by 2.

            cnt[j]++;///Count Total NOD
        }
    }


    cout << " Divisor of Every Numbers " << endl ;

    for( int i = 1; i <= n; i++ )
    {
        cout << " Total Divisor of " << i << " = " << cnt[i] << " : " ;

        for( auto x : divisor[i] )
        {
            cout << x << " " ;
        }

        cout << endl ;
    }

    cout << endl << endl ;

    cout << " Divisible of every number in range 1 to " << n << endl ;

    for( int i = 1 ; i <= n ; i++ )
    {
        cout << " Divisible by " << i << " : " ;

        for( auto x : divisible_Num[i] )
        {
            cout<< x << " ";
        }

        cout<<endl;
    }

    ///Find all numbers that is divisible 2 and smaller than 10 when n>=10 in input.

    cout << " Total number that is divisible by 2 and smaller than 10 = " << 10/2 << endl; ///formula = n/x
    ///Here, n/x = index of n = 10 . such as, 2 = 2 4 6 8 10. index of 10 = 10/2 = 5.

    int index = 10 / 2 ;
    cout << " Numbers are : " ;
    for( int i = 0 ; i < index ; i++ ) cout << divisible_Num[2][i] << " " ;
    cout << endl ;
}


Output:
Divisor of Every Numbers
Divisor of 1 : 1
Divisor of 2 : 1 2
Divisor of 3 : 1 3
Divisor of 4 : 1 2 4
Divisor of 5 : 1 5
Divisor of 6 : 1 2 3 6
Divisor of 7 : 1 7
Divisor of 8 : 1 2 4 8
Divisor of 9 : 1 3 9
Divisor of 10 : 1 2 5 10


Divisible of every number in range 1 to 10
Divisible by 1 : 1 2 3 4 5 6 7 8 9 10
Divisible by 2 : 2 4 6 8 10
Divisible by 3 : 3 6 9
Divisible by 4 : 4 8
Divisible by 5 : 5 10
Divisible by 6 : 6
Divisible by 7 : 7
Divisible by 8 : 8
Divisible by 9 : 9
Divisible by 10 : 10
Total number that is divisible by 2 and smaller than 10 = 5 ///10/2 = 5
Numbers are : 2 4 6 8 10 ///index 0 to 4
  
  
  
  Complexity Analysis:
========================
  n = 1 এর জন্য লুপ চলবে (n/1)=n বার
  n = 2 এর জন্য লুপ চলবে (n/2) বার
  n = 3 এর জন্য লুপ চলবে (n/3) বার
  .   .                  .
  .   .                  .
  .   .                  .
  n = n এর জন্য লুপ চলবে (n/n)=1 বার
  
  
  So, Complexity = (n + n/2 + n/3 + .....1)
                 = n * ( 1 + 1/2 + n/3 + .....1) = n * Harmonic Series.
                 = n * { ln(n) + gama + 1/2n + 1/12n^n + ..... }
                 = n * ln(n) + too small part.
                 = nln(n).
 easily it'll run in 1 second.
                     
 এই পদ্ধতি ব্যাবহার করে প্রাইম নাম্বার জেনারেট করা যাবে। সব সংখ্যার ডিভাইজর চেক করে যাদের ডিভাইজর (Divisor of 7 : 1 7) ২ এর বেশি (১ এবং উক্ত সংখ্যা) তারা প্রাইম না। 
 কিন্তু এর থেকে ভাল পদ্ধতি হচ্ছে সিভ মেথড। 


Number of Divisor (NOD) from Prime Factorization:
===================================================
n এর ডিভাইজর হচ্ছে সেই সব সংখ্যা যে সংখ্যাগুলো দ্বারা n কে ভাগ করলে ভাগফল নিঃশ্বেষে বিভাজ্য হয়। যেমন, ২ হচ্ছে ৬ এর ডিভাইজর কারণ ( ৬ / ২ = ০ ).
    
-> How many Divisor of n = 60 have? Using Prime factorization.
    
আমরা ১ থেকে n পর্যন্ত লুপ চালিয়ে ( n % i == 0 ) হয় কিনা চেক করে সব ডিভাইজর বের করে ফেলতে পারি। কিন্তু এর কপ্লেক্সিটি অনেক বেশি হবে। নিচে ইফিশিয়েন্ট Algo আলোচনা করা হলো,

 n = 60 = 2 x 2 x 3 x 5 = 2^2 x 3^1 x 5^ 1
    
Here,  
Set of divisor,     2  = 2^0 x 2^1 x 2^2  = set2 -> ২ এর সেটে মোট উপাদান ৩টি ( 1 , 2 , 4 )
                    3  = 3^0 x 3^1        = set3 -> "  "   "     "   "     2টি ( 1 , 3 )
                    5  = 5^0 x 5^1        = set5 -> "  "   "     "   "     2টি ( 1 , 5 )
                    
Total NOD  =  set2 x set3 x set5 = ৩টি x ২টি x ২টি = ১২টি । সুতরাং ৬০ এর মোট ১২টি ডিভাইজর এবং কম্বিনেশন আছে। নিচে নির্ণয় করা হল,

২,৩,৫ এর সেটের উপাদানের সব রকম কম্বিনেশন করলে ১২ টি ডিভাইজর বের হবে । কম্বিনেশনগুলো,

1 -> 1 x 1 x 1 = 1
2 -> 1 x 1 x 5 = 5
3 -> 1 x 3 x 1 = 3
4 -> 1 x 3 x 5 = 15
    
1 -> 2 x 1 x 1 = 2
2 -> 2 x 1 x 5 = 10
3 -> 2 x 3 x 1 = 6
4 -> 2 x 3 x 5 = 30
    
1 -> 4 x 1 x 1 = 4
2 -> 4 x 1 x 5 = 20
3 -> 4 x 3 x 1 = 12
4 -> 4 x 3 x 5 = 60
    
ALL Divisor, NOD ( 60 ) = 1 , 5 , 3 , 15 , 2 , 10 , 6 , 30 , 4 , 20 , 12 , 60 মোট ১২টি ডিভাইজর ৬০ এর যা Prime Factor of 60 (2 , 3 , 5 ) থেকে নির্ণয় করা হয়েছে । 


Upper Bound for NOD:
=========================
একটি সংখ্যার সর্বোচ্চ N^(1/3) or CubicRoot(N) টি ডিভাইজর থাকতে পারে। 

যেমন, 10^9 এর সর্বোচ্চ (10^9)^(1/3) = cubicRoot(10^9) = 10^3 = 1000 টি ডিভাইজর থাকতে পারে।

Code:
==========
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

vector<int> fact(mx);///store all prime divisor here.

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

ll NOD (ll n) ///Let, n = 60
{
    ll Total_NOD = 1; /// for multiply initial NOD = 1

    for ( auto p : prime ) { /// p = 2 , 3 , 5
        if ( 1LL * p * p > n ) break;

        if ( n % p == 0 ) { 
            int cnt = 1; ///cnt = 1 for (d^0 = 1) 

            while ( n % p == 0 ) {
                    
                n /= p; /// n = 60/2 -> 30/2 -> 15/3 -> 5/5 -> 1
                
                cnt++;  /// cnt = 3 + 2 + 2
            }

            Total_NOD = ( cnt * Total_NOD ); /// Total_NOD = ( 1 * 3 * 2 * 2 ) = 12
        }
    }

    if ( n > 1 ) Total_NOD = ( 2 * Total_NOD ); ///it will increase 2 times. coz ( 1 * sometnig ) = somethig 

    return Total_NOD; 
}

int main()
{
    FAST;
    sieve(1e7); ///it'll work for (1e14).

    ll n = 60;
    ll ans = NOD(n);

    cout<<ans<<endl;///3 x 2 x 2 = 12 for n = 60
}


    


  

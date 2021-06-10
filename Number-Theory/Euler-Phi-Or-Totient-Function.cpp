Code Using Prime Factorization and Sieve Method :
==========================================================
const int mx = 1e7+123 ;
bitset<mx> isPrime ; ///if boolean array use n memory, bitset will use (n/32) memory. initially all index 0
vector<int> prime ; ///store all prime.

void sieve ( int n )
{
    n += 100 ;///for safety.

    isPrime[2] = 1 ;
    prime.push_back(2) ;
    ///all even no composite except 2. loop through only odd no.
    for ( int i = 3 ; i <= n ; i += 2 ) isPrime[i] = 1;///initially all odd are prime.

    int lim = sqrt( n * 1 ) + 2 ;///for divisor

    for ( int i = 3 ; i <= n ; i += 2 ) {
        if ( isPrime[i] == 1 ) {

           prime.push_back(i) ;///if we get (i) it must be prime.

           if( i <= lim )///if we don't do it, (i*i) may overflow.
           {
               for ( int j = i*i ; j <= n ; j += ( i + i ) )isPrime[j] = 0;///cutting all divisor of the prime(i).
           }
        }
    }
}

int Phi ( int n )
{
    int ret = n ; /// Global Formula, Phi ( n ) = n x ( ( P - 1 ) / P ) x ( ( Q - 1 ) / Q ) x ( ( R - 1 ) / R ) .... where P,Q,R are Prime Numbers and n = ret.

    for ( auto p : prime )
    {
        if ( 1LL * p * p > n and n == 0 ) break;

        if ( n % p == 0 ) /// Phi ( n ) = p1^a X p2^b X p3^c X -----> Create base and power.
        {
            ret = ( ret / p ) ;
            ret = ret * ( p - 1 ) ; /// N x ( ( P - 1 ) ) / P = ( N / P ) x ( P - 1 ) Where P is Prime.

            while ( n % p == 0 ) n = ( n / p ) ;
        }
    }

    if ( n > 1 )
    {
        ret = ( ret / n ) ;
        ret = ret * ( n - 1 ) ;
    }

    return ret ;
}

int main()
{
    FAST;
    sieve( 1e6 ) ;

    int n = 120 ;

    cout << Phi ( n ) <<endl ; /// ans = 32 for n = 120 ;
}


Complexity: Complexity of Prime Fact = O ( sqrt( n ) / ln ( sqrt ( n ) ). 




Theory Part:
=================
Phi ( N ) = Number of Total Co-Prime or Relatively Prime of N in renge 1 to N. 
  
Co-Prime or Relatively Prime : 
Let, x and y are two numbers. x and y will be Co-Prime or Relatively Prime if GCD ( x , y ) = 1. That's mean, there is no common divisor of x and y. 
  
Phi ( a x b x c x ----- x N ) = Phi ( a ) x Phi ( b ) x Phi ( c ) x ----------------- Phi ( N ). So, Phi is a multiplicative function.
    
  
If, N is a Prime Number, Phi ( N ) = ? 
All numbers are Co-Prime except N because, GCD ( N , N ) = N. but, GCD ( N , 1 to ( N -1 ) ) = 1 where N is Prime.
Phi ( N ) = N - 1 ( All numbers except N where N is Prime ).
  
  
If, N is a Prime Number, Phi ( N ^ a ) = ?
Let, N = 2 and a = 3 then, ( 2 ^ 3 ) = 8 and Phi ( 2 ^ 3 ) = ?.
All Numbers = 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 . Here, Numbers Divisible by N = 2 , 4 , 6 , 8 has at least one divisor which is N = 2. Though, N is a prime, So, 1 , 3 , 5, 7 are 
not divisible by 2 ( N ) and all numbers are Co-Prime of N^a . 
Total Numbers divisible by 2 ( N or base ) is ( 8 / 2 ) = 4 ( 1 , 3 , 5, 7 ).
Phi ( N ^ a ) = N^a - ( N^a / N ) = 8 - ( 8 / base) = 8 - ( 8 / 2 ) = 8 - 4 = 4 ( Total Numbers those are not divisible by N ( base ) where N is a Prime ).
              = N^a ( 1 - 1 / N )
              = N^a { ( N - 1 ) / N } ---> Another Formula.
              = (N^a / N) x ( N - 1 ) ---> Used in the Programming Code.
              = 2^3 x ( (2 - 1 ) / 2 ) = 8 x (1 / 2 ) = 8 x 0.5 = 4
  
  
  
Phi ( P^a x Q^b x R^c ) = ? Where P , Q , R are prime numbers. একটি সংখ্যার প্রাইম ফ্যাক্টোরাইজ হচ্ছে ( P^a x Q^b x R^c ) = N .
Phi ( P^a x Q^b x R^c ) = Phi ( P^a ) x  Phi ( Q^b ) x  Phi ( R^c )
                        = P^a ( ( P - 1 ) / P )    x     Q^b ( ( Q- 1 ) / Q )    x    R^c ( ( R - 1 ) / R )
                        = ( P^a x Q^b x R^c ) x [ ( ( P - 1 ) / P ) x ( ( Q- 1 ) / Q ) x ( ( R - 1 ) / R ) ] Here, ( P^a x Q^b x R^c ) is Prime Factorization of N.
                        = N x [ ( ( P - 1 ) / P ) x ( ( Q - 1 ) / Q ) x ( ( R - 1 ) / R ) ] ---> Global Equation of Phi.
                        = Phi ( N ).
  
একটি সংখ্যাকে প্রাইম ফ্যাক্টোরাইজেশন করলে বিভিন্ন সংখ্যার পাওয়ার আকারে নির্নয় করতে পারবো যেটি Phi ( P^a x Q^b x R^c ) এই সূত্র দ্বারা প্রকাশ করতে পারবো।

  
Iterative solution: 
====================
১ থেকে N পর্যন্ত লুপ চালিয়ে তাদের GCD চেক করে দেখতে হবে GCD ( x , y ) = 1 হয় কিনা। 
Complexity: O ( loop x GCD ) = O ( N . log ( N ) ).


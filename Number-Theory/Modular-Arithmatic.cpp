Applications:
==============
1. ans = ( a + b ) % m = ( ( a % m ) + ( b % m ) ) % m 

2. ans = ( a - b ) % m = ( a % m ) - ( b % m ) ; 
        if ( ans < 0 ) ans = ( ans + m ) ; 
        ans = ans % m;

3. ans = ( a * b ) % m = ( ( a % m ) * ( b % m ) ) % m 
   ans = ( a * b * c ) = ( ( ( ( a % m ) * b ) % m ) * c ) % m
   
4. Modular Exponentiation or Big MOD : ( pow ( a , b ) % MOD ) or ( a ^ b ) % MOD 
==================================================================================
Easy Solution : ( a ^ b ) হওয়ায় a কে  b সংখ্যক বার লুপ চালিয়ে গুণ করলে ( a ^ b ) পাওয়া যাবে। 
যেমন, ( 3 ^ 5 ) = 3 x 3 x 3 x 3 x 3 ; এক্ষেত্রে ans কে বার বার MOD ( % ) করতে হবে সাতে ans অনেক বড় না হয়।
এই সমাধান সব ক্ষেত্রে কাজ করবে না।

Complexity হবে O ( Power ) ; Power, b = 1e9 হলে এটি 1s এ চলবে না। 

Efficient Solution :

ll power ( ll num , ll pwr , ll mod)
{
    num = num % mod ; /// update num (base) if it's more than MOD.
    if ( num == 0 ) return 0; ///In case num is divisible by power. 

    ll ans = 1 ; /// Initial Result

    while( pwr > 0 )
    {
        if ( pwr & 1 ) ans = (( num % mod ) * ans ) % mod ;/// If power is odd, multiply num with result and make it even. reduce power 1.

        pwr = ( pwr >> 1 ) ;/// power must be even now. pwr = pwr / 2

        num = ( ( num % mod ) * ( num % mod) ) % mod; /// num ^ 2 -> num ^ 4 -> num ^ 8 ......
    }

    return ans;
}

int main()
{
    FAST;
    int b , p , m ;
    cin >> b >> p >> m ; /// input base , power , MOD
    
    ll ans = power( b , p , m ) ;

    cout << ans << endl;
}

Complexity : O ( log ( Power ) ).

এখানে , Power odd হলে প্রথমেই তাকে Power 1 কমিয়ে even বানানো হয়েছে । সেই অংশ রেজাল্ট এ আগেই যুক্ত করা হয়েছে । 

পাওয়ার যখন জোড় হয় , তখন রেজাল্ট প্রতি ক্ষেত্রে দ্বিগুণ করে আপডেট হতে থাকে। কারণ a ^ 4 এর রেজাল্ট পেয়ে গেলে এর পরবর্তী রেজাল্ট যা পাওয়া যাবে সেটি a^8 এর। মাঝের অংশ নিয়ে 
চিন্তা করা লাগতেছে না।

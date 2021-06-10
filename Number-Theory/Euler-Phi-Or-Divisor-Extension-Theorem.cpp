Theory:
=========
মনে করি একটি সংখ্যা N এবং d হচ্ছে N এর যে কোন একটি ডিভাইজর যার রেঞ্জ 1 to N এর মধ্যে। এখন এমন কতগুলো সংখ্যা আছে রেঞ্জ 1 to N এর মধ্যে যাদের GCD ( a , N ) = d হয় , এখনে a হচ্ছে 
1 to N এর মধ্যে যে কোন সংখ্যা। এর উত্তর হবে ϕ ( N / d ) .
Given a number N, let d be a divisor of N. Then the number of pairs a , N , where 1 ≤ a ≤ N and gcd( a , N ) = d , is ϕ ( N / d ).
  
Example: Let, N = 12 , Divisor, d = 3 , a = 1 ≤ a ≤ 12
  
  GCD ( 3 , 12 ) = 3 = d
  GCD ( 9 , 12 ) = 3 = d
  GCD ( others, 12 ) not equal to d.
  
  Answer = 2 ( ২ টা পেয়ার পাওয়া গেছে )। 
  
Using Formula,
ϕ ( N / d ) = ϕ ( 12 / 3 )
            = ϕ ( 4 )
            = ϕ ( 2^2 ) ---> Prime Factorization.
            = 4 x ( ( 2 - 1 ) / 2 )  ---> Using ϕ Formula = ϕ ( P ^ a ) = P ^ a x { ( P - 1 ) / P } 
            = 4 x ( 1 / 2 ) = 4 x 0.5
            = 2 ( ২ টা পেয়ার পাওয়া গেছে )
 
 Extra theory,
কোন সংখ্যাকে তাদের GCD দ্বারা ভাগ দিলে যা অবশিষ্ট থাকে তাদের GCD হবে ১ এবং তারা পরস্পরের Co-Prime or Relatively Prime. 
Prove,
600  = 2^3 x 3^1 x 5^2  ---> Prime Factorization.
4500 = 2^2 x 3^2 x 5^3

Now, GCD ( 600 , 4500 )     = 2^2 x 3^1 x 5^2 --> Minimum and Common divisor.
                            = 300
  
600 / GCD ( 600 , 4500 )    = ( 2^3 x 3^1 x 5^2 ) / ( 2^2x 3^1 x 5^2 ) = 2^1 x 3^0 x 5^0 = 2 x 1 x 1 = 2
4500 / GCD ( 600 , 4500 )   = ( 2^2 x 3^2 x 5^3 ) / ( 2^2x 3^1 x 5^2 ) = 2^0 x 3^1 x 5^1 = 1 x 3 x 5 = 15
Here, 2 and 15 are Relatively Prime or Co-Prime because GCD ( 2 , 15 ) = 1.No common divisor in ( 2^1 x 3^0 x 5^0 = 2 x 1 x 1 = 2 ) and ( 2^0 x 3^1 x 5^1 = 1 x 3 x 5 = 15 ) Part

  
Same as,
( 3 , 12 ) / GCD ( 3 , 12 ) = ( 1 x 3 , 4 x 3 ) / GCD ( 3 , 12 ) = ( 1 x 3 , 4 x 3 ) / 3 = ( 1 , 4 ).
Now, GCD ( 1 , 4 ) = 1 . So, ( 1 , 4 ) are Relatively Prime or Co-Prime. অর্থ্যাৎ কোন সংখ্যাকে তাদের GCD দ্বারা ভাগ করার পর যা অবশিষ্ট থাকে তারা পরস্পরের Co-Prime.
  
Formula : GCD ( a / GCD ( a , b ) , b / GCD ( a , b ) ) =  1. Here,  ( a / GCD ( a , b ) and  ( b / GCD ( a , b ) ) are Co-Prime.

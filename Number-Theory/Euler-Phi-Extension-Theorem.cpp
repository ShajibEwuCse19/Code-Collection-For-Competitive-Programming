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
            = 4 x ( ( 2 - 1 ) / 2 )  = 4 x ( 1 / 2 ) = 4 x 0.5
            = 2 ( ২ টা পেয়ার পাওয়া গেছে )



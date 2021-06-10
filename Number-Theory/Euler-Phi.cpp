Theory Part:
=================
Phi ( N ) = Number of Total Co-Prime of Relatively Prime of N in renge 1 to N. 
  
Co-Prime or Relatively Prime : 
Let, x and y are two numbers. x and y will be Co-Prime or Relatively Prime if GCD ( x , y ) = 1. That's mean, there is no common divisor of x and y. 
  
Phi ( a x b x c x ----- x N ) = Phi ( a ) x Phi ( b ) x Phi ( c ) x ----------------- Phi ( N ). So, Phi is a multiplicative function.
  

If, N is a Prime Number, Phi ( N ) = ? 
All numbers are Co-Prime except N because, GCD ( N , N ) = N. but, GCD ( N , 1 to ( N -1 ) ) = 1 where N is Prime.
Phi ( N ) = N - 1 ( All numbers except N where N is Prime ).
  
  
If, N is a Prime Number, Phi ( N ^ a ) = ?
Let, N = 2 and a 3 then, 2 ^ 3 = 8 and Phi ( 2 ^ 3 ) = ?.
All Numbers = 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 . Here, Numbers Divisible by N = 2 , 4 , 6 , 8 has at least one divisor which is N = 2. Though, N is a prime, So, 1 , 3 , 5, 7 are 
Co-Prime of N^a . 
Total Numbers divisible by N = 2 ( base ) is ( 8 / 2 ) = 4.
Phi ( N ^ a ) = N^a - ( N^a / N ) = 8 - ( 8 / base) = 8 - ( 8 / 2 ) = 8 - 4 = 4 ( Total Numbers are not divisible by N ( base ) where N is a Prime ).
              = N^a ( 1 - 1 / N )
              = N^a { ( N - 1 ) / N } ---> Another Formula.
              = 2^3 x ( (2 - 1 ) / 2 ) = 8 x (1 / 2 ) = 8 x 0.5 = 4
  
  
  
Phi ( P^a x Q^b x R^c ) = ? Where P , Q , R are prime numbers.
Phi ( P^a x Q^b x R^c ) = Phi ( P^a ) x  Phi ( Q^b ) x  Phi ( R^b )
                        = P^a ( ( P - 1 ) / P )    x     Q^b ( ( Q- 1 ) / Q )    x    R^c ( ( R - 1 ) / R )
                        = ( P^a x Q^b x R^c ) x [ ( ( P - 1 ) / P ) x ( ( Q- 1 ) / Q ) x ( ( R - 1 ) / R ) ] Here, ( P^a x Q^b x R^c ) is Prime Factorization of N.
                        = N x [ ( ( P - 1 ) / P ) x ( ( Q - 1 ) / Q ) x ( ( R - 1 ) / R ) ] ---> Global Equation of Phi.
                        = Phi ( N ).
  
একটি সংখ্যাকে প্রাইম ফ্যাক্টোরাইজেশন করলে বিভিন্ন সংখ্যার পাওয়ার আকারে নির্নয় করতে পারবো যেটি Phi ( P^a x Q^b x R^c ) এই সূত্র দ্বারা প্রকাশ করতে পারবো।

  
Iterative solution: 
====================
১ থেকে N পর্যন্ত লুপ চালিয়ে তাদের GCD চেক করে দেখতে হবে GCD ( x , y ) = 1 হয় কিনা। 
Complexity: O ( loop x GCD ) = O ( N . log ( N ) ).


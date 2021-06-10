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
Phi ( N ^ a ) = 8 - ( 8 / base) = 8 - ( 8 / 2 ) = 8 - 4 = 4 ( Total Numbers are not divisible by N ( base ) where N is a Prime ).
  
Iterative solution: 
====================
১ থেকে N পর্যন্ত লুপ চালিয়ে তাদের GCD চেক করে দেখতে হবে GCD ( x , y ) = 1 হয় কিনা। 
Complexity: O ( loop x GCD ) = O ( N . log ( N ) ).


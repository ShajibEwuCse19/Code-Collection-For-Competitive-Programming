Phi(N) = Number of Total Co-Prime of Relatively Prime of N in renge 1 to N. 
  
Co-Prime or Relatively Prime : 
Let, x and y are two numbers. x and y will be Co-Prime or Relatively Prime if GCD ( x , y ) = 1. That's mean, there is no common divisor of x and y. 
  
Iterative solution: 
====================
১ থেকে N পর্যন্ত লুপ চালিয়ে তাদের GCD চেক করে দেখতে হবে GCD ( x , y ) = 1 হয় কিনা। 
Complexity: O ( loop x GCD ) = O ( N . log ( N ) ).

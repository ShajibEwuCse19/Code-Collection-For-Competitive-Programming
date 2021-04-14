Theory:
==========
Let, a,b,c এর Greatest Common Divisor (GCD) and Loweast Common Multiple (LCM) বের করতে হবে।

GCD => সর্বোচ্চ (Greatest) একটি common সংখ্যা যা দ্বারা a,b,c কে ভাগ করলে নিঃশ্বেষে বিভাজ্য হয়। 

Now,       a = 2 x 2 x 2 x 3 x 3 x 5 x 1 x 1 = 2^3 x 3^2 x 5^1 x 7^0   -> All are prime factor of a
           b = 2 x 2 x 1 x 3 x 3 x 5 x 7 x 1 = 2^2 x 3^2 x 5^1 x 7^1
           c = 2 x 2 x 2 x 3 x 1 x 5 x 7 x 7 = 2^3 x 3^1 x 5^1 x 7^1
 ----------------------------------------------------------------------
 GCD(a,b,c)  = 2 x 2 x 1 x 3 x 1 x 5 x 1 x 1 = 2^2 x 3^1 x 5^1 x 7^0   = Num  -> Common Divisors (All loweast power). কারণ a % Num == b % Num == c % Num == 0    
 
 LCM => সর্বনিম্ন (Loweast) একটি common সংখ্যা যাকে a,b,c দ্বারা ভাগ করলে নিঃশ্বেষে বিভাজ্য হয়। 

Now,       a = 2 x 2 x 2 x 3 x 3 x 5 x 1 x 1 = 2^3 x 3^2 x 5^1 x 7^0   -> All are prime factor of a
           b = 2 x 2 x 1 x 3 x 3 x 5 x 7 x 1 = 2^2 x 3^2 x 5^1 x 7^1
           c = 2 x 2 x 2 x 3 x 1 x 5 x 7 x 7 = 2^3 x 3^1 x 5^1 x 7^1
 ----------------------------------------------------------------------
 LCM(a,b,c)  = 2 x 2 x 2 x 3 x 3 x 5 x 7 x 7 = 2^3 x 3^2 x 5^1 x 7^2  = Num  -> All highest power. কারণ Num % a == Num % b == Num % c == 0  
  
  Relation Between GCD and LCM:
----------------------------------------
  
  LCM ( a , b ) = ( a x b ) / GCD ( a , b )
  
  C++ STL:
============
__gcd( a , b );

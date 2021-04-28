Let, n = 12;

Divisors of 12 = 1 2 3 4 6 12
Sum of Divisor, SOD(12) = 1 + 2 + 3 + 4 + 6 + 12 = 28
  
Now, Prime Factor of 12 = 2 , 2 , 3 কারণ (2 x 2 x 3 = 12 )
                        = (2^2 , 3^1)
  
    SOD(12)             = sum of all combination of  (2^2 , 3^1)
                        = (2^0 x 3^0) + (2^1 x 3^0) + (2^2 x 3^0) + (2^0 x 3^1) + (2^1 x 3^1) + (2^2 x 3^1) = 1 + 2 + 4 + 3 + 6 + 12 = 28
                        = 2^0 (3^0 + 3^1) + 2^1 (3^0 + 3^1) + 2^2 (3^0 + 3^1) -> Common numbers 
                        = (3^0 + 3^1) x (2^0 + 2^1 + 2^2) -> Common (3^0 + 3^1) the we'll get the common pattern.
                        = (1 + 3 ) x ( 1 + 2 + 4 )
                        = 4 x 7
                        = 28 (From Prime Factorization).
  
Common Pattern for all numbers,
SOD(x) = a^n , b^m , c^o
       = (a^0 + a^1 + --- + a^n)         x    (b^0 + b^1 + --- + b^m)       x    (c^0 + c^1 + --- + c^o)
       = { ( a ^ (n+1) - 1) / (a - 1) }  x  { ( b ^ (m+1) - 1) / (b - 1) }  x  { ( c ^ (o+1) - 1) / (c - 1) } 
            -> Geometric Series ( a x ( r^n - 1 ) / (r - 1) ) here, a = a^0 or b^0 or c^0 = 1 and n = n + 1 or m+1 or o+1 (গুণত্তর ধারা)।
  
How it works,
Let, SOD(x) = (a , b) x (c , d) -> Common pattern Let, a = 1, b = 2, c = 3, d = 4
            = (a + b) x (c + d)                  = SOD(x) = (1 + 2 ) x ( 3 + 4 ) = 3 x 7 = 21
            = (ac + ad) + (bc + bd)              = (1x3 + 1x4 + 2x3 + 2x4) 
            = SOD(x)                             = 3 + 4 + 6 + 8 = 21
            



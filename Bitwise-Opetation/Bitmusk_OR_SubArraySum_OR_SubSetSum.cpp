Problem : Given s ( Sum of SubSet/SubArray). Define No. of SubSetSum / SubArraySum = s from the Given Array.
int main()
{
   FAST;
   int n , s ; cin>> n >> s ; /// Max n will be 20, otherwise TLE 
   int a[n], cnt = 0;

  for(int i=0;i<n;i++)cin>>a[i];

  for(int musk = 0; musk<(1<<n); musk++) /// Total Combination = 2^n
  {
      int sum = 0;

      for(int i=0;i<n;i++) /// Check all the bit 0 to n-1 pos
      {
          if( ( musk >> i ) & 1 )sum+=a[i]; /// If current bit=1 (ON) then add a[pos] with sum
          else sum-=a[i];
      }
      if(sum == s) cnt++;
  }

   cout<< cnt <<endl;
}

Complexity: O(n*2^n)

How it works:
------------
    Line-10 : Loop -> 1 to total Combination
              for 4 bit total combination = 2^4 = 16
              for 2 bit total combination = 2^2 = 4 (00, 01, 10, 11), using Truth Table
              
     Line-14 : Loop -> 0 to n-1 position. Such as, for 4 bit Number ( 0 to 3) , for 16 bit Number ( 0 to 15 ), n will be same as total bit in any combination. For n = 4, We'll get
                                                   Total 2^4 = 16 combinations where all combination have 16 Bits with index 0 to n-1 ( 0 to 15 ).
     Line-16 : Check nth bit ON/ OFF ( nth বিটকে শেষ pos এ নিয়ে এসে ১ এর সাথে AND করা হয়েছে)। If ON then add this index value of the array in our sum. 
         
 এই প্রব্লেমে Bitwise operation এর মাধ্যমে যত ধরনের কম্বিনেশন পসিবল সব চেক করা হচ্ছে। 
 যেহেতু Length = 2^n তাই এই প্রব্লেম সর্বোচ্চ n = 20 (2^20) পর্যন্ত কাজ করবে। 
         

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl             '\n'

const int mx = 1e7+123;
vector < int > divisor[mx];
vector < int > divisible_Num[mx];

int main()
{
    FAST;
    int n = 10;

    for(int i=1; i<=n; i++)
    {
        for(int j = i; j <= n; j += i)
        {
            divisor[j].push_back(i); /// J দ্বারা যে সব সংখ্যা (i) নিঃশ্বেষে বিভাজ্য তারা সেই সেটে চলে যাবে । যেমন, ১ সব সেটে যাবে। ২ যবে ২,৪,৬....এর সেটে।

            divisible_Num[i].push_back(j); /// i দ্বারা যে সব সংখ্যা (j) নিঃশ্বেষে বিভাজ্য তাদের সেট। যেমনঃ ২ = ২ ৪ ৬ ৮ ... 
        }
    }

    cout<<"Divisor of Every Numbers"<<endl;
  
    for(int i = 1; i <= n; i++)
    {
        cout<< "Divisor of "<< i <<" : ";

        for(auto x : divisor[i])
        {
            cout<< x << " ";
        }

        cout<<endl;
    }

    cout<<endl<<endl;

    cout<<"Divisible of every number in range 1 to "<<n<<endl;
  
    for(int i = 1; i <= n; i++)
    {
        cout<< "Divisible by "<< i <<" : ";

        for(auto x : divisible_Num[i])
        {
            cout<< x << " ";
        }

        cout<<endl;
    }

    ///Find all numbers that is divisible 2 and smaller than 10 when n>=10 in input.

    cout << "Total number that is divisible by 2 and smaller than 10 = " << 10/2 <<endl; ///formula = n/x
    ///Here, n/x = index of n=10. such as, 2 = 2 4 6 8 10. index of 10 = 10/2 = 5.

    int index = 10/2 ;
    cout << "Numbers are : " ;
    for(int i = 0 ; i < index ; i++) cout << divisible_Num[2][i] << " " ;
    cout << endl ;
}

Output:
Divisor of Every Numbers
Divisor of 1 : 1
Divisor of 2 : 1 2
Divisor of 3 : 1 3
Divisor of 4 : 1 2 4
Divisor of 5 : 1 5
Divisor of 6 : 1 2 3 6
Divisor of 7 : 1 7
Divisor of 8 : 1 2 4 8
Divisor of 9 : 1 3 9
Divisor of 10 : 1 2 5 10


Divisible of every number in range 1 to 10
Divisible by 1 : 1 2 3 4 5 6 7 8 9 10
Divisible by 2 : 2 4 6 8 10
Divisible by 3 : 3 6 9
Divisible by 4 : 4 8
Divisible by 5 : 5 10
Divisible by 6 : 6
Divisible by 7 : 7
Divisible by 8 : 8
Divisible by 9 : 9
Divisible by 10 : 10
Total number that is divisible by 2 and smaller than 10 = 5 ///10/2 = 5
Numbers are : 2 4 6 8 10 ///index 0 to 4
  
  
  
  Complexity Analysis:
========================
  n = 1 এর জন্য লুপ চলবে (n/1)=n বার
  n = 2 এর জন্য লুপ চলবে (n/2) বার
  n = 3 এর জন্য লুপ চলবে (n/3) বার
  .   .                  .
  .   .                  .
  .   .                  .
  n = n এর জন্য লুপ চলবে (n/n)=1 বার
  
  
  So, Complexity = (n + n/2 + n/3 + .....1)
                 = n * ( 1 + 1/2 + n/3 + .....1) = n * Harmonic Series.
                 = n * { ln(n) + gama + 1/2n + 1/12n^n + ..... }
                 = n * ln(n) + too small part.
                 = nln(n).
 easily it'll run in 1 second.
                     
 এই পদ্ধতি ব্যাবহার করে প্রাইম নাম্বার জেনারেট করা যাবে। সব সংখ্যার ডিভাইজর চেক করে যাদের ডিভাইজর (divisible_Num[mx]) ২ এর বেশি (১ এবং উক্ত সংখ্যা) তারা প্রাইম না। কিন্তু এর থেকে ভাল পদ্ধতি হচ্ছে সিভ মেথড। 
  

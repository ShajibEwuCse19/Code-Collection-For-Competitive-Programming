///MEX of a string or shortest string that does not appear as a contiguous substring in the input
///Output : a,b,c...z,aa,ab,ac....az,ba,bb,bc...bz,ca,cb,cc,...cz....

#include<bits/stdc++.h>
using namespace std;

string str;
void number_to_String ( int n )
{
    if( n )
    {
        number_to_String ( ( n - 1 ) / 26 );
        str += ( 'a' + ( n - 1 ) % 26 );///cout<<str<<endl;cout<<n<<endl;
    }
}

int main()
{
    number_to_String(1);///a
    cout<<str<<endl;
    str.clear();

    number_to_String(2);///b
    cout<<str<<endl;
    str.clear();

    number_to_String(26);///z
    cout<<str<<endl;
    str.clear();

    number_to_String(27);///aa
    cout<<str<<endl;
    str.clear();

    number_to_String(28);///ab
    cout<<str<<endl;
    str.clear();

    number_to_String(26+26+26+1);///ca---recursion divide: (79-1)/26 = 3 , (3-1)/26 = 0.
    cout<<str<<endl;             /// Here, a + (3-1) = c and a + (79-1) = a. Answer : ca
    str.clear();
}


Details:
========
Recursion প্রথমে n কে (n-1)/26 দ্বারা ভাঙ্গতে থাকবে যতক্ষণ না 0 হয়। এরপর str += ('a' + (n-1)%26) এ n সবচেয়ে ছোট থেকে বড় তে যেতে থাকবে।
যেমন,
n = 26+26+26+1 = 79.

Recursion Divide : 
n = 79 (initial), 
n = ( 79 - 1 ) / 26 = 3
n = ( 3 - 1 ) / 26 = 0 (finish)

Now,
str = 'a' + ( 3 - 1 ) % 26 = 'a' + 2 = c ///% 26 use করার কারণ যদি n < 26 হয়। 
str = 'a' + ( 79 - 1 ) % 26 = 'a' + 0 = a
So, str = c + a = ca

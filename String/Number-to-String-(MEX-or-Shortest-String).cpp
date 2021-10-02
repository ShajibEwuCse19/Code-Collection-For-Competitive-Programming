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
        str += ( 'a' + ( n - 1 ) % 26 );
    }
}

int main()
{
    number_to_String(1);
    cout<<str<<endl;
    str.clear();

    number_to_String(2);
    cout<<str<<endl;
    str.clear();

    number_to_String(26);
    cout<<str<<endl;
    str.clear();

    number_to_String(27);
    cout<<str<<endl;
    str.clear();

    number_to_String(28);
    cout<<str<<endl;
    str.clear();

    number_to_String(26+26+26+1);
    cout<<str<<endl;
    str.clear();
}


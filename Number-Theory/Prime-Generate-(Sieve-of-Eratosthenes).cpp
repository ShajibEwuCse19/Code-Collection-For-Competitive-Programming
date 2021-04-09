Code-1:
=============================
const int mx = 1e6+123;
bool isPrime[mx];
vector<int> prime; ///store all primes here.

void sieve()
{
    memset(isPrime,1,sizeof isPrime);///initially all no. are 1 means prime.
    isPrime[1] = 0; ///1 is not prime.
    prime.push_back(2);///2 is only even prime.

    for(int i = 4 ; i <= mx ; i += 2)isPrime[i] = 0;///all even are composite except 2.
    for(int i = 3 ; i <= mx ; i += 2) ///The loop will go on odd numbers.
    {
        if(isPrime[i])///if i (3) is prime then go into the loop. the divisors of i(9 , 15 , 21..etc)are not prime (isPrime[divisor of i]=0).
        {
            prime.push_back ( i ); ///store all prime if it's prime.
            
            for(int j = i + 2 * i ; j <= mx ; j += 2 * i)isPrime[j] = 0;///Here, i=3, 2*i=2*3=6(even),2*odd = odd + odd = even.
            ///no need to consider even but (i+2*i) = (3+2*3) (odd + even -> odd) = (3+6) = 9(odd).
        }
    }
}

int main()
{
    FAST;
    sieve();

    for(int i=1;i<=25;i++)cout << prime[i] << " " ;///first 25 prime numbers = 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101
}

Complexity: n * Harmonic Series = nln(n)  ///We can do 1e8 operations in 1sec easily.
  
 Code-2:
===================
  
const int mx = 1e5+123;

int prime[mx],nPrime, mark[mx];

void sieve(int n)
{
    int limit = sqrt(n*1) + 2;
    memset(mark, 1, sizeof mark); ///initially all marked.

    ///1 is not prime.
    mark[1] = 0;

    ///all even are composite except 2;
    prime[nPrime++] = 2; ///store 2 in prime array and increase no of prime 1.
    for(int i = 4; i <= n; i+=2) mark[i] = 0;

    ///run loop only for odd.
    for(int i = 3; i <= n; i+=2)
    {
        ///if mark[i] = 1 then it is prime and it's multiple are not prime.
        if(mark[i])
        {
            prime[nPrime++] = i; ///store i in prime array and increase no. of prime by 1.

            ///if we don't do it following, i*i may overflow.

            if(i <= limit)
            {
                ///loop through all odd multiples of i and mark as not prime.

                for(int j = i * i; j <= n; j += 2*i)///3 -> 9 (3+2*3) -> 15(9+2*3) -----
                {
                    ///mark j not prime
                    mark[j] = 0;
                }
            }
        }
    }
}

int main()
{
    FAST;
    int n = 100;

    sieve(n);

    ///all prime in range n
    cout << "Prime form mark : ";
    for(int i = 1; i <= n; i++) if(mark[i]) cout << i <<" ";cout<<endl;

    ///is n prime or not prime.
    mark[n] ? cout << n << " is a Prime" <<endl : cout << n << " is Not a Prime" <<endl;

    ///output all prime smaller than n
    cout << "Prime from Prime array : ";
    for(int i=1; i<=n; i++) if(prime[i]>0)cout<< prime[i] <<" ";cout<<endl;///some index are zero.

    ///output total prime number in range n;
    cout <<"Total Prime = "<< nPrime << endl;
}

Complexity : same as before = nloglog(n).

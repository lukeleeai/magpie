#include "stdc++.h"

#define ll long long

#define endl "\n"

#define Max 1000000

using namespace std ;

const int N = 1e5 + 5 ;

void FastInputOutput()

{

    ios_base :: sync_with_stdio( 0 ) ;

    cin.tie( 0 ) ;

    cout.tie( 0 ) ;

}

inline ll LLD()

{

    ll ret;

    scanf("%lld", &ret);

    return ret;

}

inline int D()

{

    int ret;

    scanf("%d", &ret);

    return ret;

}

void ReadInputOutput()

{

    freopen("input.txt", "r", stdin) ;

    freopen("output.txt", "w", stdout) ;

}

void bin( int x )

{

    if(!x)

        return;

    bin( x / 2 );

    cout << x % 2 ;

}

//ostringstream str ;

//str << n ;

//string s = str.str() ;

bool checkPrimeNumber(int n)

{

    bool flag = true;

    for(int j = 2 ; j <= n ; ++j)

    {

        if (n % j == 0)

        {

            flag = false;

            break;

        }

    }

    return flag;

}

bool cmp(string last, string first)

{

    if(last.size() < first.size())

        return 1;

    return 0;

}

int calculateDigit(int n)

{

    double temp = (double)(n);

    double a = 0.39908-(0.434294 * n);

    double b = log10( n ) ;

    double c = ( n + 0.5 ) * b ;

    double ans = c - abs( a ) ;

    return ceil(ans) ;

}

int findDigits(int n)

{

    double E = 2.71828182845904523536;

    double PI = 3.141592654;



    if (n < 0)

        return 0;

    if (n <= 1)

        return 1;



    double x = ((n * log10(n / E) +

                 log10(2.0 * PI * n) /

                 2.0));



    return floor(x) + 1;

}

ll fact(ll n)

{

    ll ans = 1 ;

    for(ll i = 1 ; i <= n ; ++i)

        ans *= i ;

    return ans ;

}

unsigned long long Factorial(int n)

{

    const unsigned int M = 1000000007;

    unsigned long long f = 1;

    for (int i = 1; i <= n; i++)

        f = (f*i) % M;



    return f;

}

ll GCD(ll a, ll b)

{

    return b ? GCD(b, a % b) : a;

}

ll LCM(ll a, ll b)

{

    return a / GCD(a, b) * b;

}

vector< int > getDivisors(int n)

{

    vector< int > ret;

    for(int i = 1; i <= sqrt( n ); ++i)

    {

        if(n % i == 0)

        {

            ret.push_back(i);

            if(n / i != i)

                ret.push_back(n / i);

        }

    }

    return ret;

}

int sumDigits(int n)

{

    int sum = 0 ;

    while(n)

    {

        ll d = n % 10 ;

        sum += d ;

        n /= 10 ;

    }

    return sum ;

}

bool primes[ Max ] ;

int digitPrimes[ Max ] ;

void sieve()

{

    memset(primes, 1, Max);

    primes[ 0 ] = 0 ;

    primes[ 1 ] = 0 ;

    int cnt = 0;

    for (int i = 2; i <= (int)sqrt(Max) + 1; i++){

        if(primes[ i ])

            for (int j = i * i ; j <= Max ; j += i)

                primes[j] = false;

    }

    for (int i = 0; i <= Max ; ++i){

        if(primes[ i ] && primes[ sumDigits( i )])

            ++cnt ;

        digitPrimes[ i ] = cnt ;

    }

}

bool isPrime(ll n)

{

    for(ll i = 2 ; i * 1LL * i <= n ; ++i)

        if(n % i == 0)

            return 0;

    return n > 1;

}

int reverseDigits(int num)

{

    int rev = 0;

    while (num > 0) {

        rev = rev * 10 + num % 10;

        num = num / 10;

    }

    return rev;

}

int isPalindrome(int n)

{

    int rev = reverseDigits(n);

    if (rev == n)

        return 1;

    else

        return 0;

}

int main()

{

   FastInputOutput();

   int a , b ;

   cin >> a >> b ;

   int cnt = 0 ;

   for(int i = a ; i <= b ; ++i)

    if(isPalindrome( i )) ++cnt ;

   cout << cnt << endl ;



    return 0 ;

}

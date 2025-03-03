

/**

 *    Creator :  bizarre

 *    Date : 3/2020

 *    Problem Number : 388

**/

#include "stdc++.h"

using namespace std;

#define bizarre     ios_base::sync_with_stdio( false ), cin.tie( nullptr ), cout.tie( nullptr );

/*

const int inf = 2e9, mod = 1e9 + 7,N=1e6+5;

long long fact[N], inv[N];

vector<int> prime_Numbers;

int primes[1000005];

void prime(int n)

{

    primes[1]=primes[0]=0;

    for(int i=2; i<=n; i++)

        primes[i]=true;

    for(int i=2; i<=n; i++)

    {

        if(primes[i]==true)

        {

            prime_Numbers.push_back(i);

            for(int j=i+i; j<=n; j+=i)

                primes[j]=false;

        }

    }

    for(int i=2; i<=n; i++)

        primes[i]+=primes[i-1];

}



void move1step(long long& a, long long& b, long long q)

{

    long long c= a-q*b;

    a=b;

    b=c;

}

long long egcd(long long r0,long long r1,long long& x0,long long& y0)

{

    long long x1=0,y1=1;

    x0=1;

    y0=0;

    while(r1)

    {

        long long q=r0/r1;

        move1step(r0,r1,q);

        move1step(x0,x1,q);

        move1step(y0,y1,q);

    }

    return r0;

}

bool  solve (long long a, long long b, long long c,long long&x, long long& y)

{

    long long g=egcd(a,b,x,y);

    int m=c/g;

    x*=m;

    y*=m;

    return c%g==0;

}

int npr(long long n, long long r)

{

    return (fact[n] * inv[n - r]) % mod;

}



int gcd(int a, int b)

{

    if(b==0)

        return a;

    return gcd(b,a%b);

}

int ncr(long long n, long long r)

{

    return (((fact[n] * inv[n - r]) % mod) * inv[r]) % mod;

}

void pre(long long n)

{

    fact[0] = 1;

    inv[0] = 1;

    for (long long i = 1; i <= n; i++)

    {

        fact[i] = (i * fact[i - 1]) % mod;

        inv[i] = fp(fact[i], mod - 2);

    }

}

*/

map<long long,long long>mp;

const long long mod=1e9+7;

long long fp(long long base, long long exp)

{

    if (exp == 0)

        return 1;

    long long ans = fp(base, exp / 2);

    ans = (ans * ans) % mod;

    if (exp % 2 != 0)

        ans = (ans * (base % mod)) % mod;

    return ans;

}

void PrimeFactorization(int n)

{

    for(int i=2;i*i<=n;i++)

    {

        int c=0;

        if(n%i==0)

        {

            while(n%i==0)

            {

                n/=i;

                c++;

            }

            if(c)

                mp[i]=max(mp[i],(long long)c);

        }

    }

    if(n)

        mp[n]=max(mp[n],1ll);

}



int main()

{

    long long n;

    cin>>n;

    vector<long long>v(n);

    for(int i=0;i<n;i++)

    {

        cin>>v[i];

        PrimeFactorization(v[i]);

    }

    long long lcm=1;

    for(auto it:mp)

    {

        lcm*=fp(it.first,it.second);

        lcm%=mod;

    }

    long long ans=0;

    for(int i=0;i<n;i++)

    {

        ans+=lcm*fp(v[i],mod-2)%mod;

        ans%=mod;

    }

    cout << ans;

    return 0;

}

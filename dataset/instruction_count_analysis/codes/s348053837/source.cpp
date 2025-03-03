#include "stdc++.h"

using namespace std;

/*

#define mod 7

typedef long long ll;



ll fact[1000006], inv[1000006];



ll fp(ll base, ll exp)

{

    if (exp == 0)

        return 1;

    ll ans = fp(base, exp / 2);

    ans = (ans * ans) % mod;

    if (exp % 2 != 0)

        ans = (ans * (base % mod)) % mod;

    return ans;

}



void calcFacAndInv(ll n)

{

    fact[0] = inv[0] = 1;

    for (ll i = 1; i <= n; i++)

    {

        fact[i] = (i * fact[i - 1]) % mod;

        inv[i] = fp(fact[i], mod - 2);

    }

}



ll ncr(ll n, ll r)

{

    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;

}



ll npr(ll n, ll r)

{

    return (fact[n] * inv[n - r]) % mod;

}



int main()

{

    calcFacAndInv(100000);

     cout<<inv[3];

    return 0;

}

*/





// GCD



int gcd(long long a,long long b)

{

    if (b==0)

        return a;

    return gcd (b,a%b);

}

//fast power

/*

#define mod 1000000007

long long fp(long long  base, long long exp)

{

    if (exp == 0)

        return 1;

    long long  ans = fp(base, exp / 2);

    ans = (ans * ans);

    if (exp % 2 != 0)

        ans = (ans * (base )) ;

    return ans;

}

*/

//prime factoriation

/*

set<int >s;

bool prime factorization (int x)

{

    for (int j=2; j*j<=x; ++j)

    {

        while (x%j==0)

        {

            s.insert(j);

            x/=j;

        }

    }

    if (x>1)

    {

        s.insert(x);

    }

    if (s.size()==2)

        return true ;

    else

        return false ;

}



#define ll long long

int a,b,q,p,n;

int countDivisorss(int x,int y)

{

    ll cnt = 0;

    for (int i = min(x,y); i <= sqrt(n); i++)

    {

        if (x % i == 0&&y%i==0)

        {

            if (x / i == i||y / i == i)

                cnt++;



            else

                cnt = cnt + 2;

        }

    }

    return cnt;

}

int countDivisors(int x)

{

    ll cnt = 0;

    int tmp=n;

    if (n-x>10000000)  tmp=sqrt(n);

    for (int i = x; i <= tmp; i++)

    {

        if (x % i == 0)

        {

         if (x/i==i)

            cnt++;

         else

            cnt = cnt + 2;

        }

    }

    return cnt;

}

*/



/*

        int s =n/2,e=n-1;

        while (s<=e&&e<=n-1)

        {

            int mid =s+e/2;



            if (arr[mid]==arr[n/2])

            {

                s=mid;

                num +=mid -s;

            }

            else

                e=mid-1;

        }

        */









const int N = 1e5 + 5;



vector<int> adj[N];

bool visited[N];

int nodesNum;

void dfs(int node)

{

   if (visited[node])

       return;

   visited[node] = true;

   for (int child: adj[node])

       dfs(child);

}



int main()

{

   int n;

   cin>>n;

   if (n%2==0)

    cout<<n/2;

   else 

    cout<<n/2+1;

   return 0;

}





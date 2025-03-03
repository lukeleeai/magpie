#include"stdc++.h"

using namespace std;



#define FastRead        ios_base::sync_with_stdio(0);cin.tie(NULL);

#define endl            "\n"

#define NUM             1000005

typedef long long ll;



map<ll,ll>mp;



void primeFactors(ll A)

{

    while(A%2==0)

    {

        mp[2]++;

        A/=2;

    }



    for(ll i=3;i<=sqrt(A);i+=2)

    {

        while(A%i==0)

        {

            mp[i]++;

            A/=i;

        }

    }



    if(A>2)

        mp[A]++;

}



int main()

{

    FastRead



    ll a,b,ans=1;



    cin>>a>>b;



    ll gcd = __gcd(a,b);



    primeFactors(gcd);



    ans+=mp.size();



    cout<<ans<<endl;

}

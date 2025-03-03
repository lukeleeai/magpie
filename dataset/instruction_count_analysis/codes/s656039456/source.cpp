#define GODSPEED ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

#define pb push_back

#define f(i,x,n) for(i=x;i<n;i++)

#define rf(i,x,n) for(i=n;i>x;i--)

#define ll long long

#define GCD(a,b) __gcd(a,b)

#define adios return 0;



/*

SHERAJUL ARIFIN

Dept. of CSE,

IUT.

*/





#include "stdc++.h"

using namespace std;



int main()

{

    GODSPEED;

    ll t,n,a,b,c,d,s=0,i,j,flag;

    cin>>n;

    for(i=1;i<=n;i++)

    {

        if(i%15!=0 and i%3!=0 and i%5!=0) s+=i;

    }

    cout<<s<<endl;







    adios;

}

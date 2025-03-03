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

    cin>>t>>n;

    while(n--)

    {

        cin>>a;

        s+=a;

    }

    if(s>t) cout<<"-1\n";

    else cout<<t-s<<endl;









    adios;

}

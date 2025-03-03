#include "stdc++.h"

using namespace std;





#define ONSPEED ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

#define pb push_back

#define f(i,x,n) for(i=x;i<n;i++)

#define rf(i,x,n) for(i=n;i>x;i--)

#define ll long long

#define GCD(a,b) __gcd(a,b)

#define ff first

#define ss second

#define adios return 0;



/*

tacet aquilae

*/



int main()

{

    ONSPEED;

    ll t,n,k,a,b,c,d,s=0,i,j,flag;

    string x,y;

    cin>>n;

    std::vector<ll> v1(n),v2;

    f(i,0,n) 

    {

    	cin>>v1[i];

    }

    v2=v1;

    sort(v2.begin(), v2.end());

    f(i,0,n)

    {

    	if(v1[i]!=v2[i])s++;

    }

    if(s<=2) cout<<"YES";

    else cout<<"NO";









    adios;

}

	

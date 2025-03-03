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

    cin>>n>>a>>b;

    if(n==1)

    {

    	if(a==b) cout<<"1\n";

    	else cout<<"0\n";

    }

    else{

    	if(a>b) cout<<"0\n";

    	else{

    		cout<<(b-a)*(n-2)+1;

    	}

    }



    adios;

}

	

#include"stdc++.h"

using namespace std;

#define ll        long long

#define  sci(x)   scanf("%d", &x)

#define  scl(x)   scanf("%lld", &x)

#define  scd(x)   scanf("%lf", &x)

#define l0(i,n)   for(ll i=0; i<n; i++)

 

int main ()

{

	ios::sync_with_stdio(0);

	cin.tie(0);

	//CODE TONOY

	ll n,k;

	cin >> n >> k;

	cout<<(ll) min(n%k,k-(n%k));

	return 0;

}

 
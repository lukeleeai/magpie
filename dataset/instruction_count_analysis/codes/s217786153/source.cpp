#include <stdio.h>

#include <math.h>

#include <algorithm>

using namespace std;

#define ll long long

const int N=2e5+10;

ll a[N];

int main()

{

	ll n,m,i,j,k,s,t,sum,l,r;

      scanf("%lld",&n);

	{

		sum=0;

		for(i=1;i<=n;i++)

		scanf("%lld",&a[i]),sum+=a[i];

		l=0;

		m=1e15;

		for(i=1;i<n;i++)

		 {

		 	l+=a[i];

		 	r=sum-l;

		 	m=min(m,llabs(l-r));

		 }

		 printf("%lld\n",m);

	}

	return 0;

}
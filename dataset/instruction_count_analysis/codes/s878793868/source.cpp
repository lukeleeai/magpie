#include "stdc++.h"

#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)

#define per(i,n) for ((i)=n;(i)>=(1);(i)--)

using namespace std;

long long n,i,a,b,c,d,t,l,r;

int main()

{

	cin>>n>>a>>b>>c>>d;

	b-=a;n--;

	for(i=0;i<=n;i++)

	{

		t=c*i-c*(n-i);

		l=t-(d-c)*(n-i);

		r=t+(d-c)*i;

		if(l<=b&&b<=r)

		{

			puts("YES");

			return 0;

		}

	}

	puts("NO");

	return 0;

}
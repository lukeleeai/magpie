#include "bits/stdc++.h"

using namespace std;



const int N=2e5+20,MOD=1e9+7;



int n,zero;

long long a,b,p[N],ans=1;

map <pair <long long,long long>,int> negative,positive;



int get(long long a,long long b)

{

	a*=-1;

	if(positive.find({b,a})==positive.end()) return 0;



	long long ans=positive[{b,a}];

	positive.erase({b,a});

	return ans;

}



int main()

{

	p[0]=1;

	for(int i=1;i<N;i++) p[i]=(p[i-1]*2)%MOD;



	scanf("%d",&n);

	while(n--)

	{

		scanf("%lld%lld",&a,&b);



		if(a==0 and b==0)

		{

			zero++;

			continue;

		}



		long long g=__gcd(a,b);

		a/=g,b/=g;

		if(b<0) a*=-1,b*=-1;

		if(a<=0) negative[{a,b}]++;

		else positive[{a,b}]++;

	}



	for(auto i:negative)

	{

		a=i.first.first,b=i.first.second;

		ans*=(p[i.second]+p[get(a,b)]-1ll)%MOD;

		ans%=MOD;

	}



	for(auto i:positive)

	{

		a=i.first.first,b=i.first.second;

		ans*=p[i.second];

		ans%=MOD;

	}



	ans=(ans+zero-1)%MOD;

	if(ans<0) ans+=MOD;

	printf("%lld",ans);

}
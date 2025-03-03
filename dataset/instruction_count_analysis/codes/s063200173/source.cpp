#include "bits/stdc++.h"

using namespace std;



const int N=2e5+20,MOD=1e9+7;



int n,zero,p[N];

long long a,b,ans=1;

map <pair <long long,long long>,pair <int,int>> m;



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

		if(a<=0) m[{b,-a}].second++;

		else m[{a,b}].first++;

	}



	for(auto i:m)

	{

		auto pr=i.second;

		ans*=(p[pr.first]+p[pr.second]-1ll)%MOD;

		ans%=MOD;

	}



	ans=(ans+zero-1)%MOD;

	if(ans<0) ans+=MOD;

	printf("%lld",ans);

}
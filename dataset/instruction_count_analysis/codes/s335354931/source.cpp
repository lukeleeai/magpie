#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 100005

#define LL long long

LL n,X;

LL x[MAXN];

LL ans;

LL gcd(LL a,LL b)

{

	if(b==0) return a;

	return gcd(b,a%b);

}

LL Abs(LL p)

{

	if(p>=0) return p;

	return -p;

}

int main()

{

	scanf("%lld %lld",&n,&X);

	for(int i=1;i<=n;i++)

	{

		scanf("%lld",&x[i]);

		x[i]=Abs(x[i]-X);

		if(i==1) ans=gcd(x[1],x[2]);

		else ans=gcd(ans,x[i]);

	}

	printf("%lld\n",ans);

	return 0;

}

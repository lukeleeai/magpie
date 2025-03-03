#include<cstdio>

#include<algorithm>

using namespace std;



long long gcd(long long x,long long y)

{

	if(!y) return x;

	return gcd(y,x%y);

}



int main()

{

	long long a,b,c,d;

	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);

	long long e=c*d/gcd(c,d);a--;

	long long ans=(b-a+1)-((b-(b%c))-(a-(a%c)))/c-1-((b-(b%d))-(a-(a%d)))/d-1+((b-(b%e))-(a-(a%e)))/e+1;

	printf("%lld\n",ans);

	return 0;

}

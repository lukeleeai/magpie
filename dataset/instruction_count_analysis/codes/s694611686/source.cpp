#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long ll;

int main()

{

	ll n;

	double x,d;

	scanf("%lld%lf%lf",&n,&x,&d);

	double ans=0;

	ll m=2*n;

	while(m){

		ans+=(2*x+(m-1)*d)*1.0/2;

        x=((m+2)*x+5*d)*1.0/m;

        d=(m+4)*d*1.0/m;

        m-=2;

	}

	printf("%.10f",ans);

}

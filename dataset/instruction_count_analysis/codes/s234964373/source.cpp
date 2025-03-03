#include<cstdio>

#define LL long long

#define eps 1e-6

int main(){

	LL a,b,c;

	double d;

	scanf("%lld%lf",&a,&d);

	d+=eps;

	b=d*100;

	c=a*b/100;

	printf("%lld\n",c);

}
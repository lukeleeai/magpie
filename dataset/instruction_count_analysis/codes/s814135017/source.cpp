#include<stdio.h>



long long int max(long long int a, long long int b, long long int c, long long int d)

{

	if(a > b && a > c && a > d) return a;

	else if(b > a && b > c && b > d) return b;

	else if(c > b && c > a && c > d) return c;

	else return d;

}



int main()

{

	long long int a, b, c, d;

	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	printf("%lld\n", max(a*c, a*d, b*c, b*d));

}
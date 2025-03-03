#include <stdio.h>

int main ()

{

	long long x,i;

	int ans = 0;	

	scanf ("%lld",&x);

	for (i = 100; i < x;ans++)

	{

		i = i+i/100;

	}

	printf ("%d",ans);

	return 0;

}
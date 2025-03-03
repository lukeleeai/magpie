#include <stdio.h>





int main()

{	 

	long long x, y;

	int ans = 0;

	

	scanf("%lld%lld", &x, &y);

	while(x <= y){

		ans++;

		x <<= 1;

	}

	printf("%d\n", ans);	

		

	return 0;

}
#include<stdio.h>

#include<string.h>



int main()

{

	long long int n, num, sum = 0;

	scanf("%lld", &n);

	

	num = n;

	while(num != 0)

	{

		sum += num % 10;

		num /= 10;

	}

	

	if(n % sum == 0) printf("Yes\n");

	else printf("No\n");

}
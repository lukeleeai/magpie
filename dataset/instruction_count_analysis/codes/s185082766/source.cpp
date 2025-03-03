#include<stdio.h>

int main()

{

	long long int N,K,count=0,a;

	scanf("%lld %lld",&N,&K);

	if(N==0){

		printf("1");

		return 0;

	}

	else{

	while(1){

			a=N/K;

			N=a;

			count++;

			if(N==0) break;

	}

	}

	printf("%lld",count);

	return 0;

		

}
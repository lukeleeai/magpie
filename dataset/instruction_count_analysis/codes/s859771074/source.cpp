#include<stdio.h>

#include<math.h>

int main(int argc, char *argv[])

{

	long long int N,a,i;

	scanf("%lld",&N);

	a=sqrt(N);

	for(i=a;i>=0;i--){

		if(N%i==0){

			 printf("%lld\n",i+(N/i)-2);

			 break;

		}

	}

	return 0;

}
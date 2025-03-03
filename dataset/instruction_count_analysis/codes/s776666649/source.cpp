#include<stdio.h>

int max(int a,int b){return a>b?a:b;}

int main()

{

	long long n,k,sum=0;

	scanf("%lld%lld",&n,&k);

	if(k==0)sum=n*n;

	else for(int i=k+1;i<=n;i++)sum+=(n/i)*(i-k)+max(0,(int)n%i-(int)k+1);

	printf("%lld\n",sum);

}
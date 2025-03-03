#include<cstdio>

long long a[100001],k,cnt,now=2,max=2,min=2;

int main()

{

	scanf("%lld",&k);

	for(int i=1;i<=k;++i)scanf("%lld",a+i);

	for(int i=k;i>=1;--i){

		max=(max/a[i]+1)*a[i]-1;

		min=((min-1)/a[i]+1)*a[i];

		if(max<min){puts("-1");return 0;}

	}

	printf("%lld %lld\n",min,max);

	return 0;

}
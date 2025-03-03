#include<cstdio>

long long a[100010]={0,1,2,3,4,5,6,7,8,9}; 

int main()

{

	int k,id=1;scanf("%d",&k);

	for(int i=10; i<=k; )

	{

		long long x=a[id]*10,y=a[id++]%10;

		if(y==0) a[i++]=x,a[i++]=x+1;

		else if(y==9) a[i++]=x+8,a[i++]=x+9;

		else a[i++]=x+y-1,a[i++]=x+y,a[i++]=x+y+1;

	}

	printf("%lld\n",a[k]);

	return 0;

}

//快速幂,2^n

#include<cstdio>

#define MOD 1000000007

long long fast(int a,int b)

{

	long long ans=1,x=a;

	while(b)

	{	

		if(b&1)     //奇数 

		{

			ans=(ans*x)%MOD;

		}

		x=(x*x)%MOD;

		b=b/2;

	}

	return ans;

 }	

int vis[100000+5];

int main()

{

	long long n,flag=0;

	scanf("%lld",&n);

	for(int i=0;i<n;i++)

	{

		int x;

		scanf("%d",&x);

		vis[x]++;

	}

	for(int i=1;i<=n;i++)

	{

		if(vis[i]==0||vis[i]==2)

		{

			continue;

		}

		else

		{

			flag=1;

		}

	}

	if(n%2==0&&vis[0]!=0)

	{

		flag=1;

	}

	if(n%2==1&&vis[0]!=1)

	{

		flag=1;

	}

	if(flag)

	printf("0\n");

	else

	{

		n=n/2;

		long long ans=fast(2,n);

		printf("%lld\n",ans);

	 } 

	return 0;

//	long long a,b;

//	scanf("%lld%lld",&a,&b);

//	printf("%lld\n",fast(a,b));

 } 
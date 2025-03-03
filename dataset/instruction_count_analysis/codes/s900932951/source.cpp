#include<cstdio>

#include<cstring>

using namespace std;

#define MAXN 100000

long long n,l;

long long fl=0;

long long a[MAXN+5];

long long read()

{

	long long x=0,f=1;

	char c=getchar();

	while('0'>c||c>'9'){if(c=='-') f=-1;c=getchar();}

	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}

	return x*f;

}

int main()

{

	n=read(),l=read();

	for(int i=1;i<=n;i++)

	a[i]=read();

	for(int i=1;i<n;i++)

	{

		if(a[i]+a[i+1]>=l)

		{

			fl=i;

			break;

		}

	}

	if(!fl)

	{

		printf("Impossible\n");

	}

	else 

	{

		printf("Possible\n");

		for(int i=1;i<=fl-1;i++)

			printf("%d\n",i);

		for(int i=n-1;i>=fl;i--)

			printf("%d\n",i);

	}

}

//
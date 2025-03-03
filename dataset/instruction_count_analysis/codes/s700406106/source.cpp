#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define INF 100000000000000000LL

using namespace std;

typedef long long LL;

LL f(LL b,LL n)

{

	if(n<b)

		return n;

	return f(b,n/b)+n%b;

}

bool Check(LL b,LL n,LL s)

{

	if(f(b,n)==s)

		return true;

	return false;

}

int main()

{

	LL n,s;

	scanf("%lld %lld",&n,&s);

	if(s>n)

	{

		printf("-1\n");

		return 0;

	}

	if(s==n)

	{

		printf("%lld\n",n+1LL);

		return 0;

	}

	LL n1=n-s;

	LL ans=INF;

	for(LL i=1LL;i*i<=n1;i++)

	{

		if(n1%i==0)//i=b-1

		{

			if(Check(i+1,n,s)==true)

				ans=min(ans,i+1LL);

			if(n1/i!=i&&Check(n1/i+1LL,n,s)==true)

				ans=min(ans,n1/i+1LL);

		}

	}

	if(ans==INF)

		printf("-1\n");

	else

		printf("%lld\n",ans);

	return 0;

}

/*

100000000000 3

*/
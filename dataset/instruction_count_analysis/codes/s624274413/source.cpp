#include<cstdio>

#include<algorithm>

using namespace std;

int main()

{

	long long n,x,ans;

	scanf("%lld%lld",&n,&x);

	n-=x;

//	if(x<n)

//	{

		ans=x+n;

		while(x)

		{

			ans+=(n/x*x)<<1;

			n%=x;

			swap(n,x);

		}

		ans-=n;

//	}

//	else

//	{

//		ans=x+n;

//		while(x%n)

//		{

//			ans+=(x/n*n)<<1;

//			x%=n;

//			swap(n,x);

//		}

//		ans-=n;

//	}

	

	printf("%lld\n",ans);

}

/*

5 2

*/

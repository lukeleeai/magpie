#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

long long n,a[100002],b[100002],ans;

int main()

{

	scanf("%lld",&n);

	for(int i=1;i<=n;i++)

		scanf("%lld%lld",&a[i],&b[i]);

	long long t;

	for(long long i=n;i>=1;i--)

	{

		a[i]+=ans;

		long long j;

		for(j=a[i]/b[i];;j++)

			if(j*b[i]>=a[i])

				break;

		t=j*b[i]-a[i];

		ans+=t;

	}

	printf("%lld",ans);

}
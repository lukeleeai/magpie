#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define MAXN 1000

#define INF 1000000000000000000LL

using namespace std;

typedef long long LL;

LL A[MAXN+5],B[MAXN+5];

int main()

{

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%lld %lld",&A[i],&B[i]);

	LL k;

	for(int i=2;i<=n;i++)

	{

		k=-1LL;

		if(A[i]>=A[i-1]&&B[i]>=B[i-1])

			continue;

		LL L=1LL,R=INF,mid;

		while(L+1<R)

		{

			mid=(L-R)/2LL+R;

			if((A[i]*mid>=A[i-1]&&B[i]*mid>=B[i-1])||(A[i]*mid<=0||B[i]*mid<=0))

				R=mid;

			else

				L=mid;

		}

		k=R;

		A[i]*=k;

		B[i]*=k;

	}

	printf("%lld\n",A[n]+B[n]);

	return 0;

}
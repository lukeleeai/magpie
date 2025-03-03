#include<cstdio>

using namespace std;

const int maxn = 100000;

long long b[maxn + 10];

long long w[maxn + 10];

int main()

{

	int n,k;

	long long x;

	scanf("%d%d",&n,&k);

	for(int i = 1;i <= n;++i)

	{

		w[i] += w[i - 1];

		b[i] += b[i - 1];

		scanf("%lld",&x);

		if(x > 0)

			w[i] += x;

		if(x < 0)

			b[i] -= x;

	}

	long long mina = b[k] - b[0];

	if(w[k] - w[0] < mina)

		mina = w[k] - w[0];

	for(int i = 1;i <= n - k;++i)

	{

		long long temp = b[k + i] - b[i];

		if(temp < mina)

			mina = temp;

		temp = w[k + i] - w[i];

		if(temp < mina)

			mina = temp;

	}

	printf("%lld",w[n] - mina);

	return 0;

}
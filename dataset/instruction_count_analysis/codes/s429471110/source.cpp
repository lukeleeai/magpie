#include <cstdio>

#include <cmath>

using namespace std;

const int N=205;

int n;

int a[N];

int ans,chk;

int main()

{

	scanf("%d",&n);

	for (int i=1;i<=n;i++)

	{

		scanf("%d",&a[i]);

		chk=1;

		for (int j=1;j<i;j++)

			chk&=(a[j]<=a[i]);

		ans+=chk;

	}

	printf("%d\n",ans);

	return 0;

}
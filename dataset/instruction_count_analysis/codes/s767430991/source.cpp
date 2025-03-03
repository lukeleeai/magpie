#include<cstdio>

#include<algorithm>



const int N=2e5,inf=1<<30;



int a,b;

int mini=inf;

long long sum;



int main()

{

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%d %d",&a,&b);

		sum+=a;

		if(a>b)

			mini = std::min(mini,b);

	}

	if(mini == inf)

		printf("0\n");

	else

		printf("%lld\n",sum-mini);

	return 0;

}
#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long ll;

ll cun[1000000];

ll hero[1000000];

int main()

{

	int n;

	ll sum=0;

	scanf("%d",&n);

	for(int i=0;i<n+1;i++)

	{

		scanf("%lld",&cun[i]);

	}

	for(int i=0;i<n;i++)

	{

		scanf("%lld",&hero[i]);

	}

	

	for(int i=0;i<n;i++)

	{

		if(hero[i]>cun[i])

		{

			sum+=cun[i];

			hero[i]-=cun[i];

			cun[i]=0;

			//printf("heroi1=%d\n",hero[i]);

			

			if(cun[i+1]>hero[i])

			{

				sum+=hero[i];

			//	printf("heroi2=%d\n",hero[i]);

				cun[i+1]-=hero[i];

				hero[i]=0;

			}

			else

			{

				sum+=cun[i+1];

				hero[i]-=cun[i+1];

				cun[i+1]=0;

			}

		}

		else

		{

			sum+=hero[i];

			cun[i]-=hero[i];

		}

	//	printf("test%d %d\n",sum,hero[i]);

	}

	printf("%lld",sum);

}
#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 100000

using namespace std;

int cnt[MAXN+5];

int main()

{

	int N,M;

	scanf("%d %d",&N,&M);

	int a,b;

	for(int i=1;i<=M;i++)

	{

		scanf("%d %d",&a,&b);

		cnt[a]++,cnt[b]++;

	}

	for(int i=1;i<=N;i++)

		if(cnt[i]%2==1)

		{

			printf("NO\n");

			return 0;

		}

	printf("YES\n");

	return 0;

}
#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 200000

using namespace std;

int seq[MAXN+5],cnt[MAXN+5],N,M;

int A[MAXN+5];

int main()

{

	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;i++)

		scanf("%d",&seq[i]),cnt[seq[i]]++;

	for(int i=1;i<=N;i++)

		for(int j=max(1,i-cnt[i]+1);j<=i;j++)

			A[j]++;

	int ans=0;

	for(int i=1;i<=N;i++)

		if(A[i]==0)

			ans++;

	int X,Y;

	for(int i=1;i<=M;i++)

	{

		scanf("%d %d",&X,&Y);

		if(seq[X]-cnt[seq[X]]+1>=1)

		{

			A[seq[X]-cnt[seq[X]]+1]--;

			if(A[seq[X]-cnt[seq[X]]+1]==0)

				ans++;

		}

		cnt[seq[X]]--;

		seq[X]=Y;

		cnt[seq[X]]++;

		if(seq[X]-cnt[seq[X]]+1>=1)

		{

			if(A[seq[X]-cnt[seq[X]]+1]==0)

				ans--;

			A[seq[X]-cnt[seq[X]]+1]++;

		}

		printf("%d\n",ans);

	}

	return 0;

}
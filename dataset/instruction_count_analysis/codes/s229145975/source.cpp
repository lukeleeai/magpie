#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 300000

using namespace std;

int n,seq[MAXN+5],lsh[MAXN+5],lcnt;

int a[MAXN+5],b[MAXN+5],la,lb;

int main()

{

//	freopen("sort.in","r",stdin);

//	freopen("sort.out","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&seq[i]);

		lsh[++lcnt]=seq[i];

	}

	sort(lsh+1,lsh+1+lcnt);

	lcnt=unique(lsh+1,lsh+1+lcnt)-lsh-1;

	for(int i=1;i<=n;i++)

		seq[i]=lower_bound(lsh+1,lsh+1+lcnt,seq[i])-lsh;

	int ans=0;

	for(int i=1;i<=n;i+=2)

		if(seq[i]%2==0)

			ans++;

	printf("%d\n",ans);

	return 0;

}
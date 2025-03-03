#include<cstdio>

#include<cmath>

#include<algorithm>

using namespace std;

int n,ans=400000;

char a[300010];

int cnt[300010];

int main()

{

	scanf("%d%s",&n,a);

	if (a[0]=='E') cnt[0]=1;

	for (int i=1;i<n;i++)

	{

		if (a[i]=='E') cnt[i]=cnt[i-1]+1;

		else cnt[i]=cnt[i-1];

	}

	for (int i=0;i<n;i++)

	{

		int t;

		if (i!=0) t=cnt[n-1]-cnt[i]+i-cnt[i-1];

		else t=cnt[n-1]-cnt[i];

		if (ans>t) ans=t;

	}

	printf("%d",ans);

	return 0;

}
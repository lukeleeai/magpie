#include<stdio.h> 

const int maxn=1e5+6;

int a[maxn];

int main()

{

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&a[i]);

	}

	int x=1,cnt=0;

	for(int j=1;j<=n;j++)

	{

		x=a[x];

		cnt++;

		if(x==2)break;

	}

	if(x==2)printf("%d\n",cnt);

	else printf("-1\n");

	return 0;

}
#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

struct Node

{

	int t,x,y;

}p[100010];

bool cmp(Node a,Node b)

{

	return a.t <b.t ;

}

int main()

{

	int n;

	while(scanf("%d",&n)!=EOF)

	{

		int f=1;

		memset(p,0,sizeof(p));

		for(int i = 1; i <= n; i++)

		{

			scanf("%d%d%d",&p[i].t ,&p[i].x,&p[i].y);

		}

		sort(p+1,p+n+1,cmp);

		for(int i = 1; i <= n; i++)

		{

			int ans=(p[i].x+p[i].y)-(p[i-1].x+p[i-1].y);

			if((p[i].t-p[i-1].t-ans)%2!=0||(p[i].t-p[i-1].t)<ans)

			f=0;

		}

		if(f)

		printf("Yes\n");

		else

		printf("No\n");

	}

	return 0;

}
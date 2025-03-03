#include<cstdio>

#include<algorithm>

using namespace std;

int n,x[1005],y[1005],p[36],len;

bool f[2];

inline int abs(int a1)

{

	return a1>0?a1:-a1;

}

inline void print(int x1,int y1)

{

	for(int i=1;i<=len;i++)

		if(abs(x1)>abs(y1))

		{

			if(x1>0)

				putchar('R'),x1-=p[i];

			else

				putchar('L'),x1+=p[i];

		}

		else

		{

			if(y1>0)

				putchar('U'),y1-=p[i];

			else

				putchar('D'),y1+=p[i];

		}

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%d%d",&x[i],&y[i]);

		f[(x[i]+y[i])%2]=1;

	}

	if(f[1]&&f[0])

	{

		printf("-1\n");

		return 0;

	}

	for(int i=30;i>=0;i--)

		p[++len]=(1<<i);

	if(f[0])

		p[++len]=1;

	printf("%d\n",len);

	for(int i=1;i<len;i++)

		printf("%d ",p[i]);

	printf("%d\n",p[len]);

	for(int i=1;i<=n;i++)

	{

		print(x[i],y[i]);

		printf("\n");

	}

	return 0;

}
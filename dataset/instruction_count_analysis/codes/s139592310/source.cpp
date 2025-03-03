#include<cstdio>

#include<algorithm>

#define MAXN 100006

#define MAXK 2006

using namespace std;

int n,k;

char c;

int map[MAXK][MAXK],a,b,black,maxone,minone=MAXN;

int main()

{

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

	{

		scanf("%d%d %c",&a,&b,&c);

		black=0;

		if(c=='B') black=1;

		a%=k*2;

		b%=k*2;

		if(a>=k)

		{

			a%=k;

			black^=1;

		}

		if(b>=k)

		{

			b%=k;

			black^=1;

		}

		if(black)

		{

			map[a][k-1]+=1;

			map[k-1][b-1]+=1;

			map[a][b-1]-=2;

		}

		else

		{

			map[k-1][k-1]+=1;

			map[a][k-1]-=1;

			map[k-1][b-1]-=1;

			map[a][b-1]+=2;

		}

	}

	for(int i=k-1;i>=0;i--)

		for(int j=k-1;j>=0;j--)

		{

			map[i][j]+=map[i+1][j]+map[i][j+1]-map[i+1][j+1];

			maxone=max(maxone,map[i][j]);

			minone=min(minone,map[i][j]);

		}

	printf("%d",max(maxone,(n-minone)));

}
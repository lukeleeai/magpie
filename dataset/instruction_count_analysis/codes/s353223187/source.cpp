#include<cstdio>

#include<cstring>

#include<algorithm>

#define inlien inline

#define retrun return

#define cpnst const

typedef long double ld;

int a[111],n,c;

ld dp[555][555];

inline int min(int x,int y)

{return(x<y)?x:y;}

inline int max(int x,int y)

{return(x>y)?x:y;}

int main()

{

	scanf("%d%d",&n,&c);

	register int i,ii,S;

	for(i=1;i<=n;i++)scanf("%d",&a[i]);

	ld fac=0,pwd=1;

	for(i=1;i<n;i++)pwd*=c;

	std::sort(a+1,a+n+1);

	ld ans=0;

	do

	{

		memset(dp,0,sizeof(dp)),

		fac++,dp[a[n]*n][0]=1;

		for(i=1;i<=n*c;i++)

		{

			int v=i%n;

			if(!v)continue;

			for(ii=i;ii<=n*c;ii++)

				for(S=0;S<(1<<(n-1));S++)

				{

					if(S&(1<<(v-1)))continue;

					int to=min(n*c,max(ii,i+n*a[v]));

					dp[to][S|(1<<(v-1))]+=dp[ii][S];

				}

		}ans+=dp[n*c][(1<<(n-1))-1]/pwd;

	}while(std::next_permutation(a+1,a+n));

	printf("%.15Lf\n",ans/fac);

}

/*

Giving the world a better yourself is giving yourself a better world. 

*/
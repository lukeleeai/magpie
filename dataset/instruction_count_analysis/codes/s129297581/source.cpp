#include<cstdio>

#include<cstring>

#include<cmath>

#include<cstdlib>

#include<algorithm>

#include<iostream>

using namespace std;

int n,m,p;

int num[20000+10];

double dp[20000+10];

struct E

{

	int u,v;

}e[100+10];

double qpow(double d,int c)

{

	if(c==0)return 1;

	if(c==1)return d;

	double ret=qpow(d,c/2);

	ret=ret*ret;

	if(c&1)ret=ret*d;

	return ret;

}

int main()

{

	while(scanf("%d%d%d",&n,&m,&p)!=EOF)

	{

		memset(num,0,sizeof(num));

		memset(dp,0,sizeof(dp));

		for(int i=1;i<=m;i++)

		{

			scanf("%d%d",&e[i].u,&e[i].v);

		}

		for(int i=1;i<(1<<n);i++)

		{

			for(int j=1;j<=m;j++)

			{

				if(i&(1<<(e[j].u-1))&&i&(1<<(e[j].v-1)))num[i]++;

			}

		}

	//	for(int i=1;i<=n;i++)dp[1<<(i-1)]=1;

		for(int i=1;i<(1<<n);i++)

		{

			for(int j=i&(i-1);j;j=i&(j-1))

			{

				if(j&(i&(-i)))

				dp[i]+=(1-dp[j])*qpow(p*1.0/100,num[i]-num[j]-num[i&(~j)]);

			}

		}

		printf("%.12f\n",1-dp[(1<<n)-1]);

	}

	return 0;

}
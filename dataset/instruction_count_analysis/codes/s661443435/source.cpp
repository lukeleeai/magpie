#include<iostream>

#include<string.h>

#include<stdio.h>

using namespace std;

long long c,x[100005],maxx,shun[100005],ni[100005];

long long v[100005],val[100005],rval[100005];

int main()

{

	int i,j,n;

	while(scanf("%d%lld",&n,&c)!=EOF)

	{

		memset(shun,0,sizeof(shun));

		memset(ni,0,sizeof(ni));

		memset(val,0,sizeof(val));

		memset(rval,0,sizeof(rval));

    for(i=1;i<=n;i++)

    {

        scanf("%lld%d",&x[i],&v[i]);

        val[i]=val[i-1]+v[i];

        shun[i]=max(shun[i-1],val[i]-x[i]);

    }

    for( i=n;i>=1;i--)

    {

    	

        rval[i]=rval[i+1]+v[i];

        ni[i]=max(ni[i+1],rval[i]-c+x[i]);

    }

    maxx=0;

    for(i=n;i>=1;i--)

    {

        maxx=max(maxx,rval[i]-2*(c-x[i])+shun[i-1]);

        maxx=max(maxx,ni[i]);

    }

    for(i=1;i<=n;i++)

    {

        maxx=max(maxx,val[i]-2*x[i]+ni[i+1]);

        maxx=max(maxx,shun[i]);

    }

   printf("%lld\n",maxx);

	}

	

	return 0;

}
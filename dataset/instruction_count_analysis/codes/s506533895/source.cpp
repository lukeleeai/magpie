#include<cstdio>

#include<cstring>

#include<cstdlib>

using namespace std;

int p1[110000],p2[110000];

int a[110000];

int lb[110000];

inline void jio(){puts("0");exit(0);}

bool lowb[110000];

long long ff[110000];

int ljrose[110000];

long long renleizhihui[110000];

int main()

{

	int n;scanf("%d",&n);

	memset(p1,0,sizeof(p1));

	memset(p2,0,sizeof(p2));

	int lben=0;

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&a[i]);

		if(a[i]<1||a[i]>n)jio();

		if(a[i]==i)lb[++lben]=i;

		if(p1[a[i]]==0)p1[a[i]]=i;

		else if(p2[a[i]]==0)p2[a[i]]=i;

		else jio();

	}

	int ss=0;

	memset(lowb,false,sizeof(lowb));

	for(int i=1;i<=lben;i++)

	{

		lowb[lb[i]]=true;

		if(p1[lb[i]]!=lb[i])p1[lb[i]]^=p2[lb[i]]^=p1[lb[i]]^=p2[lb[i]];

		if(p2[lb[i]]!=0)lowb[p2[lb[i]]]=true;

		if(p2[lb[i]]==0)ss++;

		else if(p1[p2[lb[i]]]!=0)jio();

	}

	long long lbsl=1;

	for(int i=1;i<=n;i++)

	{

		int xx=0,yy=0;

		long long s=2;

		if(p2[i]!=0&&lowb[i]==false)

		{

			lowb[i]=true;

			xx=p1[i];yy=p2[i];

			lowb[xx]=lowb[yy]=true;

			while(true)

			{

				if(yy>0)

				{

					int xr=xx,yr=yy;

					if(p2[xr]!=0&&p1[yr]!=0)jio();

					if(p1[xr]!=0&&p2[yr]!=0)jio();

					if(p1[xr]!=0&&p1[yr]!=0)xx=p1[xr],yy=p1[yr];

					else if(p2[xr]!=0)xx=p1[xr],yy=p2[xr];

					else if(p2[yr]!=0)xx=p1[yr],yy=p2[yr];

					else if(p1[xr]!=0)xx=p1[xr],yy=0;

					else if(p1[yr]!=0)xx=p1[yr],yy=0;

					else xx=yy=0;

				}

				else

				{

					int xr=xx;

					if(p2[xr]!=0)xx=p1[xr],yy=p2[xr],s=s*2%1000000007;

					else if(p1[xr]!=0)xx=p1[xr],yy=0;

					else xx=yy=0;

				}

				lowb[xx]=lowb[yy]=true;

				if(xx==0&&yy==0)jio();

				if(xx==i||yy==i)

				{

					if(yy==i)xx^=yy^=xx^=yy;

					if(yy==0)break;

					if(p1[yy]!=0)jio();

					else

					{

						if(s%2==0)s=s/2;

						else s=(s+1000000007)/2;

						break;

					}

				}

			}

			lbsl=lbsl*s%1000000007;

		}

	}

	ff[0]=1;ff[1]=1;ff[2]=2;

	for(int i=3;i<=n;i++)ff[i]=(ff[i-1]+ff[i-2]*(i-1)%1000000007)%1000000007;

	memset(ljrose,0,sizeof(ljrose));

	for(int i=1;i<=n;i++)

	{

		if(lowb[i]==false)

		{

			long long sr=1;int j=a[i];

			lowb[i]=true;

			while(j!=i)lowb[j]=true,j=a[j],sr++;

			ljrose[sr]++;

		}

	}

	for(int i=2;i<=n;i++)

	{

		if(i%2==1)

		{

			renleizhihui[0]=1;renleizhihui[1]=2;renleizhihui[2]=4+i;

			for(int j=3;j<=ljrose[i];j++)renleizhihui[j]=(renleizhihui[j-1]*2+renleizhihui[j-2]*(j-1)%1000000007*i%1000000007)%1000000007;

			lbsl=lbsl*renleizhihui[ljrose[i]]%1000000007;

			continue;

		}

		renleizhihui[0]=1;renleizhihui[1]=1;renleizhihui[2]=1+i;

		for(int j=3;j<=ljrose[i];j++)renleizhihui[j]=(renleizhihui[j-1]+renleizhihui[j-2]*(j-1)%1000000007*i%1000000007)%1000000007;

		lbsl=lbsl*renleizhihui[ljrose[i]]%1000000007;

	}

	lbsl=lbsl*ff[ss]%1000000007;

	printf("%lld\n",lbsl);

	return 0;

}
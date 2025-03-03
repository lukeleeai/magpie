#include "stdc++.h"

using namespace std;



int n,p[100010],cnt,vis[100010];

long long a[100010],l[100010],r[100010],ans;//l为原数，r为与l乘积为完全立方数的数 

map<long long,int> mp;

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;++i)

	scanf("%lld",&a[i]);

	vis[1]=1;

	for(int i=2;i<=2200;++i)

	{

		if(!vis[i])

		p[++cnt]=i;

		for(int j=1;j<=cnt&&p[j]*i<=2200;++j)

		{

			vis[p[j]*i]=1;

			if(i%p[j]==0)

			break;

		}

	}

	for(int i=1;i<=n;++i)

	{

		long long ji=a[i],qwq=1,ovo=1;

		for(int j=1;j<=cnt;++j)

		{

			int gg=0;

			while(ji%p[j]==0)

			{

				++gg;

				ji/=p[j];

			}

			gg%=3;

			if(gg)

			{

				for(int k=gg;k<3;++k)

				{

					qwq*=p[j];

					if(qwq>1e10)

					qwq=0;

				}

				while(gg)

				{

					ovo*=p[j];

					--gg;

				}

			}

		}

		l[i]=ovo*ji;

		mp[l[i]]++;

		r[i]=qwq;

		long long qaq=(long long)sqrt(ji);

		if(qaq*qaq!=ji)

		{

			if(ji*r[i]<=1e10)

			r[i]*=ji;

			else

			r[i]=0;

			if(ji*r[i]<=1e10)

			r[i]*=ji;

			else

			r[i]=0;

		}

		else

		{

			if(qaq*r[i]<=1e10)

			r[i]*=qaq;

			else

			r[i]=0;

		}

	}

	for(int i=1;i<=n;++i)

	{

		if(l[i]==1)

		continue;

		ans+=max(mp[l[i]],mp[r[i]]);

		mp[l[i]]=0;

		mp[r[i]]=0;

	}

	if(mp[1])

	ans++;

	printf("%lld\n",ans);

	return 0;

}
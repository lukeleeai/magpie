#include"stdc++.h"

using namespace std;



#define PB(x) push_back(x)

#define MP(x,y) make_pair(x,y)



map<long long,long long> mp;

long long ty[5];

long long nty;

vector<long long> a[5];



main()

{

	long long n;

	long long w;

	scanf("%lld %lld",&n,&w);

	for(long long i=0;i<n;i++)

	{

		long long v;

		long long w;

		scanf("%lld %lld",&w,&v);

		if(mp[w]==0)

		{

			nty++;

			ty[nty]=w;

			mp[w]=nty;

			a[mp[w]].PB(v);

		}

		else

		{

			a[mp[w]].PB(v);

		}

	}

	for(long long i=1;i<=nty;i++)

		sort(a[i].begin(),a[i].end());

	long long ans=0;

	a[1].PB(0);

	a[2].PB(0);

	a[3].PB(0);

	a[4].PB(0);

	long long s1=0,s2=0,s3=0,s4=0;

	for(long long i=a[1].size()-1,ni=0;i>=0;i--,ni++)

	{

		long long all=0;

		long long wei=ni*ty[1];

		s1+=a[1][i];

		all=s1;

		if(wei>w)break;

		s2=0;

		ans=max(ans,all);

		for(long long j=a[2].size()-1,nj=0;j>=0;j--,nj++)

		{

			long long wei2=nj*ty[2];

			s2+=a[2][j];

			long long all2=s2;

			if(wei+wei2>w)break;

			s3=0;

			ans=max(ans,all+all2);

			for(long long k=a[3].size()-1,nk=0;k>=0;k--,nk++)

			{

				long long wei3=nk*ty[3];

				s3+=a[3][k];

				long long all3=s3;

				if(wei+wei2+wei3>w)break;

				s4=0;

				ans=max(ans,all+all2+all3);

				for(long long l=a[4].size()-1,nl=0;l>=0;l--,nl++)

				{

					long long wei4=nl*ty[4];

					s4+=a[4][l];

					long long all4=s4;

					if(wei+wei2+wei3+wei4>w)break;

					ans=max(ans,all+all2+all3+all4);

				}

			}

		}	

	}

	printf("%lld",ans);

}
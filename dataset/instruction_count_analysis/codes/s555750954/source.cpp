#include<iostream>

using namespace std;

int N;

long A,B,S;

long ok[2][2];

main()

{

	for(int i=0;i<2;i++)for(int j=0;j<2;j++)ok[i][j]=-1;

	cin>>N>>A>>B;

	for(int i=2;i<N;i++)

	{

		long T;cin>>T;S^=T;

	}

	long uA=A>>20,dA=A&(1<<20)-1;

	long uB=B>>20,dB=B&(1<<20)-1;

	long uS=S>>20,dS=S&(1<<20)-1;

	for(long k=0;k<=uA;k++)

	{

		for(int i=0;i<2;i++)for(int j=0;j<2;j++)

		{

			if(k+i>uA)continue;

			if((uA-k-i^uB+k+j)==uS&&ok[i][j]==-1)ok[i][j]=k;

		}

	}

	long ans=A;

	for(long k=0;k<1<<20;k++)

	{

		if(dA>=k)

		{

			if(((dA-k)^(dB+k)&(1<<20)-1)==dS)

			{

				int j=dB+k>=1<<20;

				if(ok[0][j]!=-1)

				{

					long tmp=ok[0][j]<<20|k;

					if(ans>tmp)ans=tmp;

				}

			}

		}

		else

		{

			if(((dA+(1<<20)-k)^(dB+k)&(1<<20)-1)==dS)

			{

				int j=dB+k>=1<<20;

				if(ok[1][j]!=-1)

				{

					long tmp=ok[1][j]<<20|k;

					if(ans>tmp)ans=tmp;

				}

			}

		}

	}

	if(ans==A)ans=-1;

	cout<<ans<<endl;

}

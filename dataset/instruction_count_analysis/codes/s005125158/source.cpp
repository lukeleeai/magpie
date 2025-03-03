#include<iostream>

#include<algorithm>

using namespace std;

int N;

long A,B,S;

long dp[50][2][2];

main()

{

	cin>>N>>A>>B;

	for(int i=2;i<N;i++)

	{

		long x;cin>>x;S^=x;

	}

	for(int i=0;i<50;i++)

	{

		int a=A>>i&1,b=B>>i&1;

		for(int j=0;j<2;j++)for(int k=0;k<2;k++)

		{

			long now=A;

			for(int J=0;J<2;J++)for(int K=0;K<2;K++)for(int x=0;x<2;x++)

			{

				int aa=a+2*j-x-J,bb=b-2*k+x+K;

				if(0<=aa&&aa<=1&&0<=bb&&bb<=1&&(aa^bb)==(S>>i&1))

				{

					if(i==0)

					{

						if(J==0&&K==0)now=min(now,(long)x);

					}

					else

					{

						now=min(now,dp[i-1][J][K]+((long)x<<i));

					}

				}

			}

			dp[i][j][k]=now;

		}

	}

	long ans=dp[49][0][0];

	cout<<(ans<A?ans:-1)<<endl;

}

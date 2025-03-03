#include "stdc++.h"

using namespace std;



long long F[60][2601],n,K,a[210];

long long ans,tmp[60][2601];

int main()

{

	scanf("%lld%lld",&n,&K);

	for(int i=1;i<=n;i++) scanf("%lld",&a[i]); F[0][0]=1;

	for(int i=1;i<=n;i++)

	{

		memset(tmp,0,sizeof tmp);

		for(int j=0;j<i;j++)

			for(int k=0;k<=2501;k++)

			{		

				tmp[j+1][k+a[i]]+=F[j][k];

				tmp[j][k]+=F[j][k];

			}

		for(int j=0;j<=i;j++)

			for(int k=0;k<=2501;k++) 

				F[j][k]=tmp[j][k];

	}

	for(int i=1;i<=n;i++) if(i*K<=2500) ans+=F[i][i*K];

	cout << ans << endl; return 0;

}
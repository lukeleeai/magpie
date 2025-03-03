#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 100

#define MO 1000000007

using namespace std;

typedef long long LL;

int a[MAXN+5],n;

LL f[MAXN+5][MAXN+5][MAXN+5];

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=2*n-1;i++)

		scanf("%d",&a[i]);

	sort(a+1,a+2*n);

	f[n][1][0]=1;

	LL t;

	for(int i=n-1;i>=1;i--)

	{

		int al=(a[i]!=a[i+1]),ar=(a[2*n-i]!=+a[2*n-i-1]);

		for(int l=0;l<=2*n-1;l++)

			for(int r=0;l+r<=2*n-1;r++)

				if(f[i+1][l][r])

				{

					t=f[i+1][l][r];

					for(int dl=1;dl<=l+al;dl++)

					{

						f[i][l+al-dl+1][r+ar+(dl>1)]+=t;

						f[i][l+al-dl+1][r+ar+(dl>1)]%=MO;

					}

					for(int dr=1;dr<=r+ar;dr++)

					{

						f[i][l+al+1][r+ar-dr]+=t;

						f[i][l+al+1][r+ar-dr]%=MO;

					}

				}

	}

	LL ans=0;

	for(int l=0;l<=2*n-1;l++)

		for(int r=0;l+r<=2*n-1;r++)

			ans=(1LL*ans+1LL*f[1][l][r])%MO;

	printf("%lld\n",ans);

	return 0;

}
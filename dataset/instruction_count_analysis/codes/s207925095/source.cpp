#include <cstdio>

#define int long long

using namespace std;

int n,m,a[55],f[55][8005],ans;

signed main(){

	scanf("%lld %lld",&n,&m);

	f[0][0]=1;

	for(int i=1;i<=n;i++)

		scanf("%lld",&a[i]);

	for(int i=1;i<=n;i++)

		for(int j=i;j>0;j--)

			for(int k=m*n;k>=a[i];k--)

				f[j][k]+=f[j-1][k-a[i]];

	for(int i=1;i<=n;i++)

		ans+=f[i][i*m];

	printf("%lld\n",ans);

	return 0;

}
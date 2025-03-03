/*Lucky_Glass*/

#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define MAXN int(1e5)

typedef long long ll;

int n;

ll rod;

struct Sushi{ll pos,val;}poi[MAXN+5];

ll a[MAXN+5],b[MAXN+5];

int main()

{

	scanf("%d%lld",&n,&rod);

	for(int i=1;i<=n;i++)

		scanf("%lld%lld",&poi[i].pos,&poi[i].val);

	poi[n+1].pos=rod;poi[n+1].val=0;

	for(int i=1;i<=n;i++)

		a[i]=a[i-1]-(poi[i].pos-poi[i-1].pos)+poi[i].val;

	for(int i=n;i>=1;i--)

		b[i]=b[i+1]-(poi[i+1].pos-poi[i].pos)+poi[i].val;

	for(int i=2;i<=n;i++)

		a[i]=max(a[i],a[i-1]);

	for(int i=n-1;i>=1;i--)

		b[i]=max(b[i],b[i+1]);

	ll ans=0;

	for(int i=1;i<=n;i++)

	{

		ans=max(ans,max(a[i],b[i]));

		ans=max(ans,max(a[i]-poi[i].pos+b[i+1],b[i]-(rod-poi[i].pos)+a[i-1]));

	}

	printf("%lld\n",ans);

	return 0;

}

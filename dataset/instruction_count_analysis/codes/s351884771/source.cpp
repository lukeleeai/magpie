

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define inf 20021225

#define ll long long

#define mxn 100010

using namespace std;

 

ll a[mxn],n;

 

int main()

{

	scanf("%lld",&n);ll ans=0;

	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);

	for(int i=1;i<=n;i++)

	{

		ll cnt=a[i];

		while(i<n && a[i+1]!=0)	cnt+=a[i+1],i++;

		ans+=cnt/2;

	}

	printf("%lld\n",ans);

	return 0;

}

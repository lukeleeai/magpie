#include <stdio.h>

#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair

int x[100005],y[100005];

int a[100005],b[1000005];

int main(){

	int n,m,k;

	scanf("%d%d%d",&n,&m,&k);

	for(int i=0;i<k;i++) scanf("%d%d",&x[i],&y[i]);

	for(int i=0;i<k;i++) a[i]=x[i],b[i]=y[i];

	sort(a,a+k); sort(b,b+k);

	ll ret=1e15; int rx,ry;

	for(int i=(k-1)/2;i<=(k+1)/2;i++)

	{

		for(int j=(k-1)/2;j<=(k+1)/2;j++)

		{

			ll sum=0LL,gen=0LL;

			for(int s=0;s<k;s++)

			{

				sum+=2LL*(abs(x[s]-a[i])+abs(y[s]-b[j]));

				gen=max(gen,1LL*(abs(x[s]-a[i])+abs(y[s]-b[j])));

			}

			if(sum-gen<ret){ rx=a[i]; ry=b[j]; ret=sum-gen;}

			else if(sum-gen==ret && mp(rx,ry)>mp(a[i],b[j])) rx=a[i],ry=b[j];

		}

	}

	printf("%lld\n%d %d\n",ret,rx,ry);

}
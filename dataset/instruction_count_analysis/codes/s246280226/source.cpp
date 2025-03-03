#include<cstdio>

#include<algorithm>

#define maxn 300005

using namespace std;

int n,a[maxn],t[maxn],ans;

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&a[i]);

		t[i]=a[i];

	}

	sort(t+1,t+n+1);

	for(int i=1;i<=n;i++)

	{

		int tmp=lower_bound(t+1,t+n+1,a[i])-t;

		if((tmp+i)%2) ans++;

	}

	printf("%d\n",ans/2);

}
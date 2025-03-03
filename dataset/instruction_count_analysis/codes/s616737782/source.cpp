#include<cstdio>

int n;

bool a[100010];

signed main()

{

	scanf("%d",&n);int t,ans(0);bool f(0);

	while(n--)

		scanf("%d",&t),!a[t]?a[t]=1,ans++:f=!f;

	return printf("%d\n",ans-f),0;

}